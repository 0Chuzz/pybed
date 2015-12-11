/* 
 *  Copyright (c) 1996 - 2000 Technical University of Denmark
 *  Copyright (c) 1999 - 2000 IT University of Copenhagen
 *
 * by Poul Frederick Williams, Henrik Hulgaard, Henrik Reif Andersen
 * IT University of Copenhagen
 * Glentevej 67
 * DK-2400 Copenhagen NV, Denmark
 * 
 * e-mail: {pfw,henrik,hra}@it-c.dk
 */


#include "math.h"

#ifdef PI2
#undef PI2
#endif

#include <signal.h>
#include <setjmp.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <ctype.h>
#include <strings.h>
#include <stdlib.h>

#include "shell.h"

#include "help.h"
#include "lex.h"
#include "getline.h"
#include "timer.h"
#include "ilist.h"
#include "darray.h"
#include "hash.h"
#include "version.h"
#include "Malloc.h"

#include "bed.h"
#include "bedio.h"
#include "bedfsm.h"
#include "kernel.h"
#include "upall.h"
#include "upone.h"
#include "upsome.h"
#include "replace.h"
#include "simplify.h"
#include "cache.h"
#include "quant.h"


/* === Global variables === */

FILE*			shell_out;			/* Where should the shell print output */
FILE*			shell_err;			/* Where should the error go */

/* === Local variables === */

static jmp_buf		env;
static const int	LEX_FLAGS	= LEX_FLAGS_LONG_PUNCT | LEX_FLAGS_REALS;

static int		display_time	= 10;		/* CPU time for command taking longer
							   than 10 secs is printed */

static int		max_sat_size	= 0;		/* Max BED size for bedsat --
							   less and we use bed_upall.
							   0 = never bed_upall */
static int		max_sat_depth	= 0;		/* Max depth (number of variables to
							   split on. 0 = unbounded */
static int		max_sat_time	= 0;		/* Max runtime for bedsat and bedunsat
							   0 = no limit */

static int		gmc_tries	= 50;		/* GMC number of tries */
static int		gmc_flips	= 100;		/* GMC number of flips */
static Boolean		gmc_delta	= true;		/* Output delta or full vectors */

static uint		view_number	= 0;		/* To make each 'view' command unique */

static Boolean		halt_flag	= false;	/* Set by the 'halt' command */

static HashTable*	VarNameTable;			/* Table of variable names */
static HashTable*	RootNameTable;			/* Table of root names */

static HashTable*	Commands;			/* New commands */

static Boolean		bed_support_low_first	= true;	/* Left or right support */
static Boolean		bed_sort_roots		= true;	/* Sort roots before processing */


/* Defines */

#define TAG_DEPTH		128		/* Cache tag */
#define TAG_SWAP_VARS		129		/* Cache tag */


/* Prototypes */

static int parse_command( Lex *l );


/*
 * ===[ Handlining of variables and roots ]=========================================
 */

static dArray*		Root2Node;
static unsigned int	r2n_freelist;
static char**		root2name_array;		/* Table which maps roots to names */


static void r2n_clear()
{
  int i;
  for ( i = 0; i < Root2Node->n_alloc; i++ ) {
    da_set_elem( Root2Node, i, -(i+1) );
    root2name_array[ i ] = NULL;
  }

  r2n_freelist = 0;
}

static inline bed_node r2n_lookup( bed_root root )
{
  register bed_node node;
  if ( root == BED_UNDEFINED )
    return root;

  assert( root < Root2Node->n_alloc );

  node = da_get_elem( Root2Node, root );
  return ( node >= 0 ) ? node : BED_UNDEFINED;
}

bed_node shell_root2node( bed_root root )
{
  return r2n_lookup( root );
}

static void r2n_expand()
{
  int size = Root2Node->n_alloc;
  int i;

  root2name_array = realloc( root2name_array, size*2 * sizeof( char * ) );
  assert( root2name_array != NULL );

  for ( i = size; i < size*2 - 1; i++ ) {
    da_set_elem( Root2Node, i, -(i+1) );
    root2name_array[ i ] = NULL;
  }

  da_set_elem( Root2Node, size*2 - 1, -r2n_freelist );
  r2n_freelist = size;
}

static bed_root r2n_insert( bed_node node )
{
  register int next;
  register int root;

  if ( ( next = -da_get_elem( Root2Node, r2n_freelist ) ) >= Root2Node->n_alloc ) {
    r2n_expand();
    next = -da_get_elem( Root2Node, r2n_freelist );
  }
  
  root = r2n_freelist;
  da_set_elem( Root2Node, root, node );
  r2n_freelist = next;

  return root;
}

static inline void r2n_update( bed_root root, bed_node node )
{
  bed_ref( node );
  bed_deref( r2n_lookup( root ) );  
  da_set_elem( Root2Node, root, node );
}

void shell_root_update( bed_root root, bed_node node )
{
  r2n_update( root, node );
}

static inline void r2n_remove( bed_root root )
{
  da_set_elem( Root2Node, root, -r2n_freelist );
  r2n_freelist = root;
}


static bed_node_list* r2n_list( bed_root_list *roots )
{
  int i, node;
  bed_node_list *nodes = il_new();
  IL_ITER( roots, i )
    if ( !il_has( nodes, ( node = r2n_lookup( il_elem( roots, i ) ) ) ) )
      il_append( nodes, node );

  return nodes;
}


char* shell_root2name( bed_root root )
{
  return root2name_array[ root ];

#if 0
  HashTableElement *p;
  int i;

  for ( i = 0; i < RootNameTable->size; i++ )
    for ( p = RootNameTable->hash_table[ i ]; p; p = p->next )
      if ( HT_VALUE( p ) == root )
	return HT_KEY( p );

  return NULL;
#endif
}


static uint lookup_var( char* name )
{
  HashTableElement* elem = ht_lookup( VarNameTable, name );

  if ( elem == NULL )
    return BED_UNDEFINED;

  return HT_VALUE( elem );
}

static bed_root lookup_root( char* name )
{
  HashTableElement* elem = ht_lookup( RootNameTable, name );

  if ( elem == NULL )
    return BED_UNDEFINED;

  return HT_VALUE( elem );
}

void shell_insert_var( char* name, bed_var var )
{
  ht_insert_int( VarNameTable, name, var );
}

bed_root shell_insert_root( char* name, bed_node node )
{
  HashTableElement *p;
  bed_root root = r2n_insert( node );
  bed_ref( node );
  ht_insert_int( RootNameTable, name, root );

  p = ht_lookup( RootNameTable, name );
  root2name_array[ root ] = HT_KEY( p );

  return root;
}

static inline void remove_var( char* name )
{
  ht_remove( VarNameTable, name );
}

static inline void remove_root( char* name )
{
  bed_root root = lookup_root( name );
  bed_deref( r2n_lookup( root ) );
  r2n_remove( root );
  ht_remove( RootNameTable, name );

  root2name_array[ root ] = NULL;
}

static iList *ht_2_il( HashTable *ht )
{
  iList *result = il_new();

  HashTableElement *p;
  int i;

  for ( i = 0; i < ht->size; i++ ) {
    for ( p = ht->hash_table[ i ]; p; p = p->next )
      il_append( result, HT_VALUE( p ) );
  }

  return result;
}


static int roots_compare( const void *a, const void *b )
{
  bed_root r1 = *( ( const bed_root *) a );
  bed_root r2 = *( ( const bed_root *) b );

  return strcmp( shell_root2name( r1 ), shell_root2name( r2 ) );
}

static bed_root_list* root_list_sort( bed_root_list *root_list )
{
  if ( bed_sort_roots )
    qsort( (void*) root_list->arr, root_list->info.len, sizeof( bed_root ), roots_compare );

  return root_list;
}

static char* variable_map( bed_var var )
{
  static char buf[20];

  HashTableElement *p;
  int i;

  for ( i = 0; i < VarNameTable->size; i++ )
    for ( p = VarNameTable->hash_table[ i ]; p; p = p->next )
      if ( HT_VALUE( p ) == var )
	return HT_KEY( p );
  
  sprintf( buf, "%d", var );
  return buf;
}

static char* node_map( bed_node node )
{
  static char buf[20];

  int i;

  /* In case of multiple matches, the first one found is used */
  for ( i = 0; i < Root2Node->n_alloc; i++ )
    if ( r2n_lookup( i ) == node ) {
      register HashTableElement *p;
      register int j;

      for ( j = 0; j < RootNameTable->size; j++ )
	for ( p = RootNameTable->hash_table[ j ]; p; p = p->next )
	  if ( HT_VALUE( p ) == i )
	    return HT_KEY( p );
    }
  
  sprintf( buf, "%d", node );
  return buf;
}


/*
 * ===[ Shell Clear ]=======================================================
 */

void shell_clear_bed()
{
  bed_clear();

  ht_free( VarNameTable );
  ht_free( RootNameTable );
  da_free( Root2Node );

  VarNameTable = ht_new( 256 );
  RootNameTable = ht_new( 256 );
  Root2Node = da_new( 256 );
  r2n_clear();
}


/*
 * ===[ New commands ]=======================================================
 */

void shell_register_command( char *command_name, void (*fct)( Lex *l ) )
{
  /* Remove old version of command (if any) */
  if ( ht_lookup( Commands, command_name ) != NULL )
    ht_remove( Commands, command_name );

  ht_insert_ptr( Commands, command_name, fct );
}


/*
 * ===[ Support ]=============================================================
 */

static void support( bed_node node, bed_var_list *list, int mark )
{
  if ( kernel_get_mark( node ) == mark )
    return;

  if ( bed_get_op( node ) == BED_VAR ) {
    bed_var var = bed_get_var( node );
    if ( ! il_has( list, var ) )
      il_append( list, var );
  }

  if ( bed_support_low_first ) {
    support( bed_get_low( node ), list, mark );
    support( bed_get_high( node ), list, mark );
  } else {
    support( bed_get_high( node ), list, mark );
    support( bed_get_low( node ), list, mark );
  }

  kernel_set_mark( node, mark );
}

static bed_var_list* shell_support( bed_node node )
{
  int mark = kernel_reserve_marks( 1 );
  bed_var_list* support_list = il_new();

  assert( ! IS_GARBAGE( node ) );

  kernel_set_mark( bed_one, mark );
  kernel_set_mark( bed_zero, mark );

  support( node, support_list, mark );

  kernel_clear_marks();

  return support_list;
}



/*
 * ===[ Fanin ordering ]===================================================
 */

static uint depth( bed_node u )
{
  uint res, low, high;
  register Cache *p;

  if ( IS_TERMINAL( u ) )
    return 0;

  p = cache_get( TAG_DEPTH, u, 0, 0, 0 );
  if ( cache_match( p, TAG_DEPTH, u, 0, 0, 0 ) )
    return p->r1;

  low = depth( bed_get_low( u ) );
  high = depth( bed_get_high( u ) );

  res = 1 + ( ( low > high ) ? low : high );

  cache_insert( p, TAG_DEPTH, u, 0, 0, 0, res, 0 );

  return res;
}

static bed_var_list* fanin( bed_node node, int mark )
{
  uint low, high;
  uint l, h;
  bed_var_list *res, *llist, *hlist;

  if ( kernel_get_mark( node ) == mark )
    return il_new();

  kernel_set_mark( node, mark );

  low = bed_get_low( node );
  high = bed_get_high( node );

  l = depth( low );
  h = depth( high );

  if ( bed_get_op( node ) == BED_VAR ) {
    bed_var var = bed_get_var( node );

    res = il_new();
    il_append( res, var );
  } else {
    if ( l > h ) {
      llist = fanin( low, mark );
      hlist = fanin( high, mark );
      res = il_concat( llist, hlist );
    } else {
      hlist = fanin( high, mark );
      llist = fanin( low, mark );
      res = il_concat( hlist, llist );
    }
    il_free( llist );
    il_free( hlist );
  }

  return res;
}

static bed_var_list* shell_fanin( bed_node node )
{
  int mark = kernel_reserve_marks( 1 );
  bed_var_list* res;

  assert( ! IS_GARBAGE( node ) );

  kernel_set_mark( bed_one, mark );
  kernel_set_mark( bed_zero, mark );

  res = fanin( node, mark );

  kernel_clear_marks();

  return res;
}



/*
 * ===[ (Depth) Fanout ordering ]=========================================
 */

static double *fanout_node_weights;
static double *fanout_var_weights;
static bed_var_list *fanout_list;
static iStack *fanout_nodes;
static HashTable *fanout_hashtable;
static int fanout_count;

static int fanout_node2index( bed_node node )
{
  char key[32];
  HashTableElement* he;

  sprintf( key, "%d", node );
  he = ht_lookup( fanout_hashtable, key );

  assert( he != NULL );
  return HT_VALUE( he );
}

static void fanout( bed_node node, int nov, int non )
{
  int i, j;
  int big;
  int node_index;

  node_index = fanout_node2index( node );

  for ( i = 0; i < nov; i++ ) {
    /* Propage 1.0 downwards */

    fanout_node_weights[node_index] = 1.0;

    for ( j = fanout_nodes->top - fanout_nodes->arr - 1; j >= 0; j-- ) {
      bed_node u;
      bed_node low, high;
      int u_index, low_index, high_index;
      Boolean low_is_okay, high_is_okay;

      u = is_elem( fanout_nodes, j );
      u_index = fanout_node2index( u );

      if ( IS_TERMINAL( u ) || ( fanout_node_weights[u_index] < 0.0 ) )
	continue;

      if ( IS_VARIABLE( u ) ) {
	fanout_var_weights[bed_get_var(u)] += fanout_node_weights[u_index];

      } else {
	low = bed_get_low( u );
	high = bed_get_high( u );
      
	low_index = fanout_node2index( low );
	high_index = fanout_node2index( high );

	low_is_okay = ( fanout_node_weights[low_index] >= 0.0 );
	high_is_okay = ( fanout_node_weights[high_index] >= 0.0 );

	if ( low_is_okay && high_is_okay ) {
	  fanout_node_weights[low_index] += fanout_node_weights[u_index]/2.0;
	  fanout_node_weights[high_index] += fanout_node_weights[u_index]/2.0;
	  
	} else if ( low_is_okay ) {
	  fanout_node_weights[low_index] += fanout_node_weights[u_index];
	  
	} else /* high_is_okay */ {
	  fanout_node_weights[high_index] += fanout_node_weights[u_index];
	}
      }

    }

    /* Find variable with highest weight, remove it, and clear other vars */


    big = 0;
    for ( j = 0; j < nov; j++ ) {
      if ( fanout_var_weights[j] > fanout_var_weights[big] )
	big = j;
    }

    for ( j = 0; j < nov; j++ )
      if ( fanout_var_weights[j] > 0.0 )
	fanout_var_weights[j] = 0.0;

    fanout_var_weights[big] = -1.0;
    il_append( fanout_list, big );

    IS_ITER( fanout_nodes, j ) {
      bed_node u = is_elem( fanout_nodes, j );
      if ( IS_VARIABLE( u ) && ( VAR(u) == big ) )
	fanout_node_weights[ fanout_node2index( u ) ] = -1.0;
    }

    IS_ITER( fanout_nodes, j ) {
      bed_node u, low, high;
      int u_index, low_index, high_index;
      Boolean low_is_okay, high_is_okay;

      u = is_elem( fanout_nodes, j );
      if ( IS_TERMINAL( u ) )
	continue;

      u_index = fanout_node2index( u );

      if ( IS_VARIABLE( u ) ) {
	if ( fanout_node_weights[u_index] > 0.0 )
	  fanout_node_weights[u_index] = 0.0;
	continue;
      }
      
      low = bed_get_low( u );
      high = bed_get_high( u );
      
      low_index = fanout_node2index( low );
      high_index = fanout_node2index( high );

      low_is_okay = ( fanout_node_weights[low_index] >= 0.0 );
      high_is_okay = ( fanout_node_weights[high_index] >= 0.0 );

      if ( !low_is_okay && !high_is_okay )
	fanout_node_weights[u_index] = -1.0;
      else if ( fanout_node_weights[u_index] > 0.0 )
	fanout_node_weights[u_index] = 0.0;
    }
  }
}

static void fanout_stacknode( FILE *fp, bed_node node )
{
  char key[32];

  sprintf( key, "%d", node );
  ht_insert_int( fanout_hashtable, key, fanout_count );
  fanout_count++;  
  is_push( fanout_nodes, node );
}

static bed_var_list* shell_fanout( bed_node node )
{
  int i, non, nov;

  assert( ! IS_GARBAGE( node ) );

  non = bed_node_count( node )+2;
  nov = bed_get_info().number_of_variables;
  fanout_var_weights = MALLOC_ARRAY( nov, double );
  fanout_node_weights = MALLOC_ARRAY( non, double );
  fanout_nodes = is_new();
  fanout_hashtable = ht_new( 2*non );

  fanout_count = 0;

  fanout_stacknode( NULL, ZERO );
  fanout_stacknode( NULL, ONE );

  kernel_dfs( NULL, node, fanout_stacknode );
  kernel_clear_marks();

  for ( i = 0; i < nov; i++ )
    fanout_var_weights[i] = 0.0;

  for ( i = 0; i < non; i++ )
    fanout_node_weights[i] = 0.0;

  fanout_list = il_new();

  fanout( node, nov, non );

  free( fanout_var_weights );
  free( fanout_node_weights );
  is_free( fanout_nodes );
  ht_free( fanout_hashtable );

  return fanout_list;
}


/*
 * ===[ Write BED information ]================================================
 */

static void bed_stat( FILE *fp )
{
  bed_info info = bed_get_info();

  fprintf( fp, "BED has %d nodes (%d entries allocated).", 
	   info.node_count, info.number_of_nodes );
  if ( info.node_count < info.number_of_nodes )
    fprintf( fp, " %u nodes are on the free-list.", info.number_of_nodes - info.node_count );
  fprintf( fp, " Highest node-count is %u.", info.highest_node_count );
  fprintf( fp, " There are %d variables reserved.", info.number_of_variables );
  fprintf( fp, " Garbage collection has been done %d time%s for a total of %ld.%03ld seconds.\n", info.number_of_gc, info.number_of_gc == 1 ? "" : "s", info.gc_time / 1000, info.gc_time % 1000 );

#ifdef COLLECT_STATS
  fprintf( fp, "Number of calls to Addnode: \t%d\n", number_addnodes );
  fprintf( fp, "Number of calls to Makenode: \t%d\n", number_makenodes );
  fprintf( fp, "Number of calls to Makenode with two terminal children: \t%d\n", number_makenodes_terminal );
  fprintf( fp, "Number of calls to Upall: \t%d\n", number_upall_parts );
#endif
}

static void bed_cache_stat( FILE *fp )
{
  fprintf( fp, "The cache has %d entries.\n", cache_size() );
}


/*
 * ===[ Parse functions ]================================================
 */

/*
 * resolve_user: turns ~<user>  into a pathname obtained from
 * the password-file 'passwd'
 */

static char *resolve_user( Lex *l, char *user, char *buf )
{
  struct passwd *pwd;
 
  (void)setpwent();
  if ((user == NULL) || (user[0] == EOL))
    pwd = getpwuid(getuid());
  else
    pwd = getpwnam(user);
    
  if (pwd) {    /* Found an entry */
    char *p = buf;
    char *r = pwd->pw_dir;
    while (*r != EOL)
      *p++ = *r++;
    *p = EOL;
  } else {
    sprintf( buf, "/home/%s", user );
    lex_warning( l, "Can't resolve path for user \"~%s\", using \"/home/%s\" instead\n", user, user); 
  }
  (void)endpwent();
  
  return buf;
}

static char *parse_up_to_separators( Lex *l, char *buf, char *seps )
{
  char *p = buf;

  skip_white_spaces( l );

  while ( current_char( l ) != EOL &&			/* Not at EOF */
	  (index( seps, current_char( l )) == NULL )) {	/* Not a separator */
    *p++ = current_char( l );
    next_char( l );
  }
  *p = EOL;

  get_token(l);

  return buf;
}


/* expand_meta_chars: expands leading ~-chars and $<name> */
static char *expand_meta_chars( Lex *l, char *buf1, char *buf2 )
{
  char *q = buf1;	/* Source */
  char *p = buf2;	/* Target */
  Boolean beginning_of_word = true;

  while ( *q != EOL ) {
    if ( beginning_of_word && (*q  == '~') ) {
      q++;

      if ( (*q == '/') || (*q == EOL) ) {
	char *path = getenv( "HOME" );
	while ( (*p++ = *path++) );
	p--;	/* Skip back over the null-terminator */

      } else if ( isalpha( *q )) {

	/* Get user name */
	char user[9], path[256];
	char *uptr = user, *pptr = path;
	
	while ( isalnum( *q ) && ( uptr - user < 8 ))
	  *uptr++ = *q++;
	*uptr++ = EOL;

	if ( uptr - user == 9 ) 
	  lex_warning( l, "Username too long. Truncated to '%s'", user );
	
	pptr = resolve_user( l, user, path );
	while ( (*p++ = *pptr++) );
	p--;

      } else {
	lex_error( l, "Illegal path specification: '~%c%c...'", *q, *(q+1));
	buf2[0] = EOL;
	return buf2;
      }	

    } else if ( *q == '$' ) {
      /* Resolve shell variable */
      char variable[256];
      char *v = variable;

      q++;
      while( *q && *q != ';' && *q != '/' ) {
	*v++ = *q++;
      }
      *v = EOL;

      if ( (v = getenv( variable ))) {
	while ( (*p++ = *v++) );
      } else {
	lex_error( l, "No variable '$%s'", variable );
	buf2[0] = EOL;
	return buf2;
      }

    } else {
      beginning_of_word = isspace( *q );
      *p++ = *q++;      
    }
  }
  *p = EOL;

  return buf2;
}


char *parse_full_path( Lex *l )
{
  char buf1[MAX_STRING];
  static char buf2[MAX_STRING];

  parse_up_to_separators( l, buf1, ";\n\t " );

  return expand_meta_chars( l, buf1, buf2 );
}


/*
 * ===[ I/O ]============================================================
 */

static FILE *open_file( Lex *l, char *filename )
{
  FILE *fp;

  if ( filename == NULL || (strlen(filename) == 0) )	/* No file specified */
    return shell_out;
  
  fp = fopen( filename, "w" );
  if ( fp == NULL ) {
    lex_error( l, "Cannot create file '%s'", filename );
    l->err_no = LEX_ERR_OPEN_FILE;
  }
  return fp;
}

static void close_file( FILE *fp )
{
  if ( fp && ( fp != shell_out ))
    fclose( fp );
}

/* source_file -- read commands from file. File must exists 
 */
 
static void source_file( char *filename ) 
{
  Lex *l = lex_open_from_file( filename, LEX_FLAGS );

  l->errstream = shell_err;
  parse_command( l );
  lex_close( l );
}


/*
 * ===[ Initialize ]=====================================================
 */

static void welcome( FILE *fp )
{
  /*  fprintf( fp, "%s\n", bed_libshell_version() ); */
  /*  fprintf( fp, "%s\n", bed_version() ); */
  fprintf( fp, "%s\n", bed_author() );
  fprintf( fp, "Web: www.it-c.dk/research/bed\n" );
  fprintf( fp, "%s\n", bed_addr() );
  fprintf( fp, "%s\n\n", bed_copyright() );
  fprintf( fp, "This is LGPL'ed software -- see the BED_LICENSE file for details\n\n" );
}

static int gl_tab(char *buffer, int offset, int *loc)
/* Command completion */
{
  /*   printf( "\ngl_tab: buf = \"%s\", offset = %d, loc = %d\n", buf, offset, *loc ); */
  return -1; /* complete( buf, loc ); */
}

static void signal_handler( int sig )
{
    (void) signal(SIGINT, SIG_IGN);  
    longjmp(env, 1);
}

static Boolean read_access( char *filename )
{
  if ( access( filename, R_OK  )) {
    fprintf( shell_out, "*** Error: Cannot open file '%s'\n", filename );
    return false;
  }
  return true;
}

static void parse_io_info( bed_io_read_info *info )
{
  bed_io_var_entry *var;
  bed_io_root_entry *root;

  var = info->vars;
  while ( var != NULL ) {
    shell_insert_var( var->name, var->var );
    var = var->next;
  }

  root = info->roots;
  while ( root != NULL ) {
    shell_insert_root( root->name, root->root );
    root = root->next;
  }
}

static void read_bedrc_file()
{
  char buf[256];
  char *bedrc_file = NULL;

  if ( access( "./.bedrc", R_OK  ) == 0 )
    bedrc_file = "./.bedrc";
  else {   
    sprintf( buf, "%s/.bedrc", getenv( "HOME" ) );

    if ( access( buf, R_OK ) == 0 )
      bedrc_file = buf;
  }

  /* if bedrc_file != NULL, then bedrc_file exists and is readable */

  if (bedrc_file)
    source_file( bedrc_file );
}

void shell_init()
{
  Commands = ht_new( 32 );
}

static void init_shell( char *BED_filename, char *command_filename )
{
  int i;

  shell_out	= stdout;
  shell_err	= stdout;

  welcome( shell_out );			/* Print Welcome message */

  VarNameTable = ht_new( 256 );
  RootNameTable = ht_new( 256 );

  root2name_array = MALLOC_ARRAY( 256, char* );
  for ( i = 0; i < 256; i++ )
    root2name_array[ i ] = NULL;

  Root2Node = da_new( 256 );
  r2n_clear();

  bed_var2name = variable_map;
  bed_node2name = node_map;

  read_bedrc_file();

  if ( BED_filename && read_access( BED_filename )) {
    bed_io_read_info *info = bed_io_read( BED_filename );
    if ( info != NULL ) {
      parse_io_info( info );
      bed_io_read_done( info );
      bed_stat( shell_out );
    }
  }

  if ( command_filename && read_access( command_filename ))
    source_file( command_filename );
  
  gl_tab_hook = gl_tab;

  (void) signal(SIGINT, SIG_IGN);	/* Disable Ctrl-C */
}
 
static void end_shell()
{
  ht_free( VarNameTable );
  ht_free( RootNameTable );

  ht_free( Commands );

  da_free( Root2Node );

  free( root2name_array );
}


/*
 * ===[ Basic parse functions ]==========================================
 */


char *shell_parse_ofile_name( Lex *l, char *default_filename )
{
  if ( lookahead( l, (Token) '>' )) {
    char *filename = parse_full_path( l );
    if ( strlen( filename ) == 0 )
      lex_error( l, "No filename specified after '>'" );
    return filename;
  } 
  return default_filename;
}

char *shell_parse_ifile_name( Lex *l )
{
  char *filename = parse_full_path( l );
 
  if ( (strlen(filename ) == 0) || access( filename, R_OK  )) {
    lex_error( l, "Cannot open file '%s'", filename );
    l->err_no = LEX_ERR_OPEN_FILE;
    return NULL;
  }
 
  return filename;
}


bed_root shell_parse_root( Lex *l )
{
  bed_root root = BED_UNDEFINED;

  if ( lex_ok( l )) {
    if ( ! have( l, T_NAME ) )
      mustbe( l, T_STRING );

    root = lookup_root( get_name( l ) );
      
    if ( root == BED_UNDEFINED ) {
      lex_error( l, "No root named '%s'", get_name( l ));
      root = BED_UNDEFINED;
    }
  }

  return root;
}


bed_node shell_parse_node( Lex *l )
{
  bed_node u;

  if ( have( l, T_INTEGER ) ) {
    /* Referring to nodes by numbers instead of names is for testing and debugging only. */
    /* A node referred to by a number is not ref. counted and may not survive a GC. */
    u = get_int( l );

    if ( !IS_GARBAGE( u ))
      return u;
    else {
      lex_error( l, "Node '%d' is undefined.", u );
      return BED_UNDEFINED;
    }
  }

  if ( lookahead( l, T_NAME ) || lookahead( l, T_STRING ) )
    return r2n_lookup( shell_parse_root( l ) );
  else {
    lex_error( l, "Expected a bed node" );
    return BED_UNDEFINED;
  }
}


bed_var shell_parse_variable( Lex *l )
{
  bed_var var = BED_UNDEFINED;
  
  if ( lex_ok( l )) {

    if ( ! have( l, T_NAME ) )
      mustbe( l, T_STRING );
    var = lookup_var( get_name( l ) );
      
    if ( lex_ok( l ) && ( var == BED_UNDEFINED ) )
      lex_error( l, "No variable named '%s'", get_name( l ));
  }
  return var;
}

bed_var_list *shell_parse_variable_list( Lex *l )
{
  if ( lex_ok( l )) {
    if ( have( l, T_STAR ) || have_keyword( l, "vars" ) || have_keyword( l, "inputs" )) {
      return bed_get_ordering();

    } else if ( have_keyword( l, "support" )) {
      bed_root r;
      bed_var_list *list;

      mustbe( l, T_LPAR );
      r = shell_parse_root( l );
      mustbe( l, T_RPAR );
      
      list = ( lex_ok( l ) ? shell_support( r2n_lookup( r ) ) : NULL );

      return list;

    } else if ( have_keyword( l, "fanin" )) {
      bed_root r;
      bed_var_list *list;

      mustbe( l, T_LPAR );
      r = shell_parse_root( l );
      mustbe( l, T_RPAR );
      
      list = ( lex_ok( l ) ? shell_fanin( r2n_lookup( r ) ) : NULL );

      return list;

    } else if ( have_keyword( l, "fanout" )) {
      bed_root r;
      bed_var_list *list;

      mustbe( l, T_LPAR );
      r = shell_parse_root( l );
      mustbe( l, T_RPAR );
      
      list = ( lex_ok( l ) ? shell_fanout( r2n_lookup( r ) ) : NULL );

      return list;

    } else {
      bed_var_list *vars = il_new();

      if  ( have( l, T_LBRK ) ) {      
	while ( !have( l, T_RBRK )) {
	  bed_var x = shell_parse_variable( l );
	
	  if ( lex_err( l ))
	    break;
	  
	  il_append( vars, x );
	}
      } else if ( have( l, T_LBRK_RBRK ) ) {
	/* The empty list -- append nothing */
      } else if ( lookahead( l, T_NAME ) || lookahead( l, T_STRING ) ) {
	bed_var v = shell_parse_variable( l );
	if ( v != BED_UNDEFINED )
	  il_append( vars, v );
      } else {
	/* Unknown -- ignore */
      }

      if ( lex_err( l )) {
	il_free( vars );
	vars = NULL;
      }

      return vars;
    }
  } 

  return NULL;
}

bed_root_list *shell_parse_root_list( Lex *l )
{
  if ( lex_ok( l )) {
    if ( have( l, T_STAR ) || have_keyword( l, "roots" ) || have_keyword( l, "outputs" )) {
      return root_list_sort( ht_2_il( RootNameTable ) );
      
    } else if ( (l->current_token == T_NAME) &&
		( *l->ptr == '*' ) ) {
      int i;
      bed_root_list *roots, *allroots;

      allroots = root_list_sort( ht_2_il( RootNameTable ) );
      if ( allroots == NULL )
	return NULL;
      roots = il_new();

      IL_ITER( allroots, i ) {
	bed_root r = il_elem( allroots, i );
	if ( 0 == strncmp( lex_quote( shell_root2name( r ) ), l->current_name,
			   strlen( l->current_name ) ) )
	  il_append( roots, r );
      }

      mustbe( l, T_NAME );
      mustbe( l, T_STAR );
      il_free( allroots );
      return roots;

    } else  if ( have( l, T_EOF ) || have( l, T_SEMI ) ) {
      return NULL;

    } else {
      bed_root_list *roots = il_new();
      
      if  ( have( l, T_LBRK ) ) {      
	while ( !have( l, T_RBRK )) {
	  bed_root r = shell_parse_root( l );
	  
	  if ( lex_err( l ))
	    break;
	  
	  il_append( roots, r );
	}
      } else if ( have( l, T_LBRK_RBRK ) ) {
	/* The empty list -- append nothing */
      } else if ( lookahead( l, T_NAME ) || lookahead( l, T_STRING ) ) {
	bed_root r;
	r = shell_parse_root( l );
	if ( r != BED_UNDEFINED )
	  il_append( roots, r );
      } else {
	/* Unknown -- ignore */
      }
      
      if ( lex_err( l )) {
	il_free( roots );
	roots = NULL;
      }

      return roots;
    }
  }
  return NULL;
}


bed_node_list *shell_parse_node_list( Lex *l )
{
  if ( lex_ok( l )) {
    if ( have( l, T_STAR ) || have_keyword( l, "roots" ) || have_keyword( l, "outputs" )) {
      bed_root_list *roots = root_list_sort( ht_2_il( RootNameTable ) );
      bed_node_list *nodes = il_new();

      int i;

      IL_ITER( roots, i )
	il_append( nodes, r2n_lookup( il_elem( roots, i ) ) );

      il_free( roots );
      return nodes;

    } else {
      bed_node_list *nodes = il_new();
      
      if  ( have( l, T_LBRK ) ) {      
	while ( !have( l, T_RBRK )) {
	  bed_node n = shell_parse_node( l );
	  
	  if ( lex_err( l ))
	    break;
	  
	  il_append( nodes, n );
	}
      } else {
	il_append( nodes, shell_parse_node( l ) );
      }
      
      if ( lex_err( l )) {
	il_free( nodes );
	nodes = NULL;
      }
      
      return nodes;
    }
  }
  return NULL;
}



/*
 * ===[ Commands ]======================================================
 */


/*===[ Source command ]==================================================*/

static void parse_source_command( Lex *l )
{
  char *filename = shell_parse_ifile_name( l );

  if ( lex_ok( l ))
    source_file( filename );
}

/*===[ Writeorder command ]==============================================*/

static void parse_writeorder_command( Lex *l )
{
  if ( lex_ok( l )) {
    char *filename = parse_full_path( l );
    FILE *fp = open_file( l, strlen(filename) ? filename : "TMP.order" );

    if ( lex_ok( l ) && fp ) {
      int i;
      bed_var_list *var_list = bed_get_ordering();
      fprintf( fp, "order [ " );
      IL_ITER( var_list, i )
	fprintf( fp, "%s ", lex_quote( bed_var2name( il_elem( var_list, i ) ) ) );
      fprintf( fp, "];\n" );
      if ( var_list ) il_free( var_list );
    }

    close_file( fp );
  }
}

/*===[ Help command ]===================================================*/

static void parse_help_command( Lex *l )
{
  if ( have( l, T_NAME ))
    help( get_name( l ), shell_out );  
  else
    help_general( shell_out );
}

/*===[ Clear command ]===================================================*/

static void parse_clear_command( Lex *l )
{
  if ( have_keyword( l, "cache" ) && lex_ok( l ) )
    kernel_clear_caches();				/* For debugging only */
  else if ( lex_ok( l )) {
    bed_clear();
    r2n_clear();
    ht_free( VarNameTable );
    ht_free( RootNameTable );
    VarNameTable = ht_new( 256 );
    RootNameTable = ht_new( 256 );
  } 
}

/*===[ Read command ]===================================================*/

static void parse_read_command( Lex *l )
{
  char *filename = shell_parse_ifile_name( l );

  if ( lex_ok( l )) {
    bed_io_read_info *info;
    ht_clear( VarNameTable );
    ht_clear( RootNameTable );

    r2n_clear();

    bed_clear();

    info = bed_io_read( filename );
    if ( info != NULL ) {
      parse_io_info( info );
      bed_io_read_done( info );
      bed_stat( shell_out );
    }
  } 
}

static void parse_write_command( Lex *l )
{
  if ( lex_ok( l )) {
    bed_root_list *roots;
    char *filename;
    FILE *fp;

    roots = shell_parse_root_list( l );
    if ( roots == NULL )
      return;

    filename = parse_full_path( l );
    fp = open_file( l, strlen(filename) ? filename : "TMP.bed" );

    if ( lex_ok( l ) && fp ) {
      int i;
      bed_io_root_entry *rentry = NULL;
      bed_io_root_entry *last = NULL;

      IL_ITER( roots, i ) {
	bed_io_root_entry *r = MALLOC( bed_io_root_entry );
	r->root = r2n_lookup( il_elem( roots, i ) );
	r->next = NULL;
	r->name = strdup( shell_root2name( il_elem( roots, i ) ) );
	if ( last == NULL )
	  rentry = r;
	else
	  last->next = r;
	last = r;
      }

      bed_io_write( fp, rentry );

      close_file( fp );
    }
    if ( roots ) il_free( roots );
  }
}


/*===[ Vars/roots command ]=============================================*/

static void print_vars()
{
  int i;
  bed_var_list *var_list = bed_get_ordering();
  if ( var_list == NULL )
    return;
  IL_ITER( var_list, i )
    fprintf( shell_out, "%s ", lex_quote( bed_var2name( il_elem( var_list, i ) ) ) );
  fprintf( shell_out, "\n" );
  if ( var_list ) il_free( var_list );
}

static void parse_vars_command( Lex *l )
{
  print_vars();
}

static void print_roots( bed_root_list *root_list )
{
  int i;

  IL_ITER( root_list, i ) {
    bed_root root = il_elem( root_list, i );
    fprintf( shell_out, "%s : %d\n", lex_quote( shell_root2name( root ) ), r2n_lookup( root ) );
  }

  fprintf( shell_out, "\n" );
}

static bed_root parse_root_name( Lex *l )
{
  bed_root root = BED_UNDEFINED;

  if ( lex_ok( l ))
    if ( ! have( l, T_NAME ) )
      mustbe( l, T_STRING );
  root = lookup_root( get_name( l ) );

  if ( ( lex_ok( l ) ) && ( root == BED_UNDEFINED ) )
    lex_error( l, "No output named '%s'", get_name( l ) );

  return root;
}

static void parse_roots_command( Lex *l )
{
  bed_root_list* root_list;

  root_list = shell_parse_root_list( l );
  if ( root_list == NULL )
    root_list = ht_2_il( RootNameTable );

  print_roots( root_list_sort(root_list) );

  if ( root_list ) il_free( root_list );
}


/*===[ Stat command ]===================================================*/

/* Prints statistics about BED... */

static void parse_stat_command( Lex *l )
{
  /* subcommands: bed, hash, ..? */
  if ( have_keyword( l, "bed" )) {
    bed_stat( shell_out );
    COUNT_REDUCTIONS( reduction_stat( shell_out ) );
    
  } else if ( have_keyword( l, "hash" )) {
    if (lex_ok( l ))
      kernel_hash_stat( shell_out );			/* For debugging only */

  } else if ( have_keyword( l, "reductions" )) {
    if (lex_ok( l ))
      kernel_reduction_stat();				/* For debugging only */

  } else if ( have_keyword( l, "cache" )) {
    if (lex_ok( l ))
      bed_cache_stat( shell_out );			/* For debugging only */
    
  } else if ( have_keyword( l, "roots" ) || have_keyword( l, "outputs" ) ) {
    if (lex_ok( l )) {
      int i;
      int taut = 0, cont = 0, neither = 0;
      bed_root_list* root_list = ht_2_il( RootNameTable );

      IL_ITER( root_list, i ) {
	bed_root root = il_elem( root_list, i );
	bed_node node = r2n_lookup( root );
	if ( node == bed_one )
	  taut++;
	else if ( node == bed_zero )
	  cont++;
	else
	  neither++;
      }

      fprintf( shell_out, "Tautologies    : %d\nContradictions : %d\nUnknown        : %d\nTotal          : %d\n", taut, cont, neither, taut+cont+neither );
      if ( root_list ) il_free( root_list );
    }
    
  } else {
    if ( !lookahead( l, T_SEMI ) )
      if ( !lookahead( l, T_EOF ) )
	lex_error( l, "Unknown parameter '%s'", get_name( l ) );
    if ( lex_ok( l ) )
      bed_stat( shell_out );
  }
}



/*===[ Dump commands ]==================================================*/


static void dump( FILE *fp, bed_node low, bed_node high )
{
  register bed_node u;

  if ( high == BED_UNDEFINED )
    high = bed_get_info().highest_node_count;

  fprintf( fp, "       u   var op      low     high\n" );
  fprintf( fp, "-------- ----- -- -------- --------\n" );

  for ( u = low; u < high; u++ ) {
    bed_node l = bed_get_low( u );
    bed_node h = bed_get_high( u );
    bed_var v = bed_get_var( u );
    bed_op op = bed_get_op( u );

    /*            u   var op  low high */
    fprintf( fp, "%8d %5d %2d %8d %8d ", u, v, op, l, h );

    if ( IS_TERMINAL( u ))
      fprintf( fp, "\t= %c\n", '0'+u );
    else if ( OP( u ) == GARBAGE )
      fprintf( fp, "\t(garbage)\n" );
    else if ( IS_OPERATOR( u )) {
      if ( OP( u ) == EXIST )
        fprintf( fp, "\t(op = ? '%s')\n", lex_quote( bed_var2name( v ) ) );
      else if ( OP( u ) == SUBST )
	fprintf( fp, "\t(op = '%s' :=)\n", lex_quote( bed_var2name( v ) ) );
      else
        fprintf( fp, "\t(op = %s)\n", bed_op2name( op ) );
    } else 
      fprintf( fp, "\t(var = '%s')\n", lex_quote( bed_var2name( v ) ) );
  }
  
  fflush( fp );  
}

static void parse_dump_command( Lex *l ) 
{
  uint low, high;
  FILE *fp;

  if ( lookahead( l, T_EOF ) || lookahead( l, T_SEMI ) ) {
    low = 0;
    high = BED_UNDEFINED;
  } else {
    low = shell_parse_node( l );

    if ( have( l, T_MINUS ) )
      high = shell_parse_node( l ) + 1;
    else
      high = low + 1;
    
    if ( !lex_ok( l )) return;

    if ( low > high )
      lex_error( l, "Not an inteval ( %d > %d ) !", low, high );
  }

  fp = open_file( l, shell_parse_ofile_name( l, NULL ));

  dump( fp, low, high );
  close_file( fp );
}


static void parse_dumpnode_command( Lex *l ) 
{
  Boolean only_one_node = have( l, T_LBRK );

  bed_node node = shell_parse_node( l );
  FILE *fp = open_file( l, shell_parse_ofile_name( l, NULL ));

  if ( lex_ok( l )) {
    if ( only_one_node )
      bed_io_print_node( fp, node );
    else {
      kernel_dfs( fp, node, bed_io_print_node );
      kernel_clear_marks();
    }

    if ( only_one_node )
      mustbe( l, T_RBRK );
  }
  close_file( fp );
}


/*===[ Count command ]===============================================*/

static void parse_count_command( Lex *l ) 
{
  bed_node node = shell_parse_node( l );

  if ( lex_ok( l )) {
    uint n = bed_node_count( node );
    if ( n != BED_UNDEFINED )
      fprintf( shell_out, "Number of nodes: %d\n", n );
    else
      lex_error( l, "Could not count the number of nodes" );
  }
}


/*===[ Dot command ]===============================================*/


/* Syntax: dot [<node>] [> <filename>] */

static void parse_dot_command( Lex *l )
{
  bed_node_list *nodes = shell_parse_node_list( l );
  FILE *fp = open_file( l, shell_parse_ofile_name( l, "bed.dot" ));

  if ( lex_ok( l ))
    bed_io_graph( fp, nodes );

  if ( nodes ) il_free( nodes );
  
  close_file( fp );
}


/* Syntax: cdot <node1> <node2> <node3> [> <filename>] */

static void parse_cdot_command( Lex *l )
{
  bed_node n1, n2, n3;
  FILE *fp;

  n1 = shell_parse_node( l );
  n2 = shell_parse_node( l );
  n3 = shell_parse_node( l );

  fp = open_file( l, shell_parse_ofile_name( l, "bed.dot" ));

  if ( lex_ok( l ))
    bed_io_color_graph( fp, n1, n2, n3 );

  close_file( fp );
}


/*===[ Dimacs command ]===============================================*/


/* Syntax: dimacs [<node>] [> <filename>] */

static void parse_dimacs_command( Lex *l )
{
  bed_node node = shell_parse_node( l );
  FILE *fp = open_file( l, shell_parse_ofile_name( l, "bed.dimacs" ));

  if ( lex_ok( l ))
    bed_io_dimacs( fp, node );

  close_file( fp );
}


/*===[ View command ]==================================================*/

static void parse_view_command( Lex *l )
{
  char buf[1024];
  FILE *fp;
  int pd = (int) getpid();
  bed_node_list *nodes = shell_parse_node_list( l );

  if ( !lex_ok( l )) {
    if ( nodes ) il_free( nodes );
    return;
  }

  view_number++;

  sprintf( buf, "/tmp/%d_%d.dot", pd, view_number );
  fp = open_file( l, buf );

  if ( lex_ok( l ) ) {
    bed_io_graph( fp, nodes );
    close_file( fp );

    sprintf( buf, "(dot -Tps /tmp/%d_%d.dot > /tmp/%d_%d.ps; ghostview /tmp/%d_%d.ps; \
		rm -f /tmp/%d_%d.{dot,ps}) &",pd, view_number, pd, view_number, pd,
	     view_number, pd, view_number );

    if ( system( buf ) ) {
      fprintf( shell_err, "Error executing DOT or GHOSTVIEW.\n" );
      return;
    }
  } else
    close_file( fp );

  if ( nodes ) il_free( nodes );
}


/*===[ Support command ]===============================================*/

static void parse_support_command( Lex *l )
{
  bed_node node;
  bed_root root;
  if ( have( l, T_INTEGER ) ) {
    root = BED_UNDEFINED;
    node = get_int( l );
  } else {
    root = shell_parse_root( l );
    node = r2n_lookup( root );
  }

  if ( lex_ok( l ) ) {
    bed_var_list *sup = shell_support( node );
    int i;

    fprintf( shell_out, "support( %s ) = [ ", lex_quote( ( root != BED_UNDEFINED ) ? shell_root2name( root ) : bed_node2name( node ) ) );
   
    IL_ITER( sup, i ) {
      fputs( lex_quote( bed_var2name( il_elem( sup, i ) ) ), shell_out );
      if ( i < il_length( sup )) fputc( ' ', shell_out );
    }
    
    fputs( "]\n", shell_out );
    il_free( sup );
  }
}




/*===[ Up commands ]====================================================*/

static void parse_up_one_command( Lex *l )
{
  if ( lex_ok( l ) ) {
    int i, j;
    bed_var_list *vars = shell_parse_variable_list( l );
    bed_root_list *roots = shell_parse_root_list( l );

    if ( vars && roots && lex_ok( l ) ) {
      /* Now actually run upone */
      IL_ITER( vars, i ) {
	bed_var v = il_elem( vars, i );
	IL_ITER( roots, j ) {
	  bed_root root = il_elem( roots, j );
	  bed_node node = r2n_lookup( root );
	  bed_node new = bed_upone( v, node );
	  r2n_update( root, new );

	  fprintf( shell_out, "Up_one( %s, %s ) -> %d\n", lex_quote( bed_var2name( v ) ),
		   lex_quote( shell_root2name( root ) ), new );
	}
      }
    }
    
    if ( vars ) il_free( vars );
    if ( roots ) il_free( roots );    
  }
}


static void parse_verify_command( Lex *l )
{
  if ( lex_ok( l ) ) {
    bed_root_list *roots = shell_parse_root_list( l );

    if ( roots && lex_ok( l ) ) {
      int i;
      IL_ITER( roots, i ) {
	bed_root root = il_elem( roots, i );
	bed_node node = r2n_lookup( root );
	bed_node new = bed_upone_iter( node );
	r2n_update( root, new );
	
	fprintf( shell_out, "Verify( %s ) -> %d\n", lex_quote( shell_root2name( root ) ), new );
      }
    }

    if ( roots ) il_free( roots );
  }
}

static void parse_up_all_command( Lex *l )
{
  if ( lex_ok( l ) ) {
    bed_root_list *roots = shell_parse_root_list( l );

    if ( roots && lex_ok( l ) ) {
      int i;
      IL_ITER( roots, i ) {
	bed_root root = il_elem( roots, i );
	bed_node node = r2n_lookup( root );
	bed_node new = bed_upall( node );
	r2n_update( root, new );
	
	fprintf( shell_out, "Upall( %s ) -> %d\n", lex_quote( shell_root2name( root ) ), new );
      }
    }

    if ( roots ) il_free( roots );
  }
}


static void parse_up_some_command( Lex *l )
{
  if ( lex_ok( l ) ) {
    int i, j;
    bed_var_list *vars = shell_parse_variable_list( l );
    bed_root_list *roots = shell_parse_root_list( l );

    if ( vars && roots && lex_ok( l ) && il_length(vars) && il_length(roots) ) {
      /* Now actually run up_some */
      up_some_set_vector( vars );
      IL_ITER( roots, j ) {
	bed_root root = il_elem( roots, j );
	bed_node node = r2n_lookup( root );
	bed_node new = up_some( node );
	r2n_update( root, new );

	fprintf( shell_out, "Up_some( %s ) -> %d\n",
		 lex_quote( shell_root2name( root ) ), new );
      }
      up_some_free_vector();
    }
    
    if ( vars ) il_free( vars );
    if ( roots ) il_free( roots );    
  }
}



/* assert( <boolean-expr> ); 
 * <boolean-expr> ::= <node-list> [== | !=] [0|1]
 *
 * e.g., assert( x2 == 1 ); 
 * or	 assert( [x1 x2 x4] == 1 );
 * or	 assert( * == 0 );
 */

Boolean parse_bool_expr( Lex *l )
{
  Boolean res = true;
  Boolean eq = true;

  bed_node_list *nodes = shell_parse_node_list( l );
  
  if ( lex_ok( l ) ) {
    if ( have( l, T_NEQ ))
      eq = false;
    else
    (void) mustbe( l, T_EQU_EQU );

    if ( lex_ok( l )) {    
      mustbe( l, T_INTEGER );
      
      if ( lex_ok( l )) {
	bed_node val = ( get_int( l ) == 1 ? bed_one : bed_zero );
	int len = il_length( nodes );
	int i;

	for ( i = 0; res && (i < len); i++ )
	  res = (eq ? ( il_elem( nodes, i ) == val )
		 : ( il_elem( nodes, i ) != val ) );
      }
    }
  }
  if ( nodes ) il_free( nodes );
  return res;
}

static void parse_assert_command( Lex *l )
{
  mustbe( l, T_LPAR );
  if ( lex_ok( l )) {
    Boolean res = parse_bool_expr( l );
    if (lex_ok( l )) {
      mustbe( l, T_RPAR );
      if ( lex_ok( l ))
	if ( res == false ) {
	  if ( l->input_from_file ) {
	    fprintf( shell_err, "*** Assertion failed (file '%s', line %d).\n",
		     l->filename, get_lineno(l) );
	  } else
	    lex_error( l, "Assertion failed." );
	}
    }
  }
}


/*===[ Garbage collection command ]============================================*/

static void parse_gc_command( Lex *l )
{
  bed_gc( );
}


/*===[ Eval command ]====================================================*/

static void parse_eval_command( Lex *l )
{
  bed_node node = shell_parse_node( l );

  if ( lex_ok( l ) ) {
    bed_var_list *var_list = shell_parse_variable_list( l );

    if ( lex_ok( l ) )
      fprintf( shell_out, "Answer = %s\n", bed_evaluate( node, var_list ) ? "true" : "false" );

    if ( var_list )
      il_free( var_list );
  }
}


/*===[ GMC command ]===========================================*/


static char *eval_var_assign;
static bed_var_list *gmc_order;


/* Output the quasi path of length k in state_array.
 * p is the point where the path breaks.
 * If  delta  is true then only the variables which change are displayed.
 */
static void output_quasi_path( int k, bed_node *state_array, int p,
			       Boolean delta, bed_node G )
{
  int i;

  for ( i = 0; i <= k; i++ ) {
    bed_node n, prev;

    fprintf( shell_out, "State %d (%s):\n", i, ((i!=0) && delta ? "delta" : "full" ) );
    
    n = state_array[i];

    if ( !delta || (i == 0) )
      prev = bed_zero;
    else
      prev = state_array[i-1];

    assert( n != bed_zero );
    assert( n != BED_UNDEFINED );

    while ( n != bed_one ) {
      if ( LOW(n) != bed_zero ) {
	if ( (prev == bed_zero) || (LOW(prev) == bed_zero) ) {
	  fprintf( shell_out, "  %s = 0\n", bed_var2name(VAR(n)) );
	  if ( !IS_TERMINAL( prev ) )
	    prev = HIGH( prev );
	} else {
	  if ( !IS_TERMINAL( prev ) )
	    prev = LOW( prev );
	}
	n = LOW(n);

      } else {
	assert( HIGH(n) != bed_zero );
	if ( (prev == bed_zero) || (HIGH(prev) == bed_zero) ) {
	  fprintf( shell_out, "  %s = 1\n", bed_var2name(VAR(n)) );
	  if ( !IS_TERMINAL( prev ) )
	    prev = LOW( prev );
	} else {
	  if ( !IS_TERMINAL( prev ) )
	    prev = HIGH( prev );
	}
	n = HIGH(n);
      }
    }

    if ( i != k ) { /* Check for early stop */
      bed_node tmp;
      tmp = bed_apply( BED_IMP, state_array[i], G );
      if ( tmp == bed_one ) {
	fprintf( shell_out, "Early stop! (Actual path length is %d)\n", i );
	break;
      }
    }

    if ( (i != k) && (i == p) )
      fprintf( shell_out, "-=-=-=-=-\n" );

  }
  fprintf( shell_out, "\n" );
}



/* Pick a random state in u.
 * u is a BDD of unprimed (even) variables.
 */
static bed_node find_state( bed_node u )
{
  int i;
  bed_node res;
  bed_var_list *vars;

  assert( u != bed_zero );

  vars = il_new();

  IL_ITER( gmc_order, i ) {
    bed_var v1, v2;

    v1 = il_elem( gmc_order, i );
    if ( v1 % 2 )
      continue;

    v2 = VAR( u );

    if ( v1 != v2 ) {
      /* u does not depend on v1 so we can pick any value for v1. */
      il_append( vars, ( random() & 32 ) ? (v1+1) : -(v1+1) );

    } else {
      /* u depends on v1 */
      int next;

      if ( LOW(u) == bed_zero )
	next = 1;
      else if ( HIGH(u) == bed_zero )
	next = 0;
      else
	next = ( random() & 32 ) ? 1 : 0;

      if ( next == 0 ) {
	il_append( vars, -(v1+1) );	/* Add one to avoid zero (+0 = -0 = 0) */
	u = LOW(u);
      } else {
	il_append( vars, v1+1 );
	u = HIGH(u);
      }
    }
  }

  res = bed_ref( bed_one ); 

  for ( i = il_length(vars)-1; i >= 0; i-- ) {
    bed_node n;
    int v;

    v = il_elem( vars, i );

    assert( v != 0 );

    if ( v > 0 )
      n = bed_ref( bed_mk_var( v-1, bed_zero, res ) );
    else
      n = bed_ref( bed_mk_var( -v-1, res, bed_zero ) );

    bed_deref( res );
    res = n;
  }

  if ( vars )	il_free( vars );

  bed_deref( res );
  return res;
}


/* Return true if variable 'v' can be set to value 'value' without leading to any 'Ts'
 * being false.
 */
static Boolean assignment_okay( bed_var v, int value, bed_node_list *Ts )
{
  int i;

  IL_ITER( Ts, i ) {
    bed_node t;
    t = il_elem( Ts, i );
    if ( t == bed_zero )
      return false;
    else if ( ( t == bed_one ) || ( VAR( t ) != v ) )
      continue;
    if ( ( LOW(t) == bed_zero ) && ( value == 0 ) )
      return false;
    if ( ( HIGH(t) == bed_zero ) && ( value == 1 ) )
      return false;
  }

  return true;
}


/* Return a new list of nodes where variable 'v' is assigned value 'value'
 */
static bed_node_list* assign_value( bed_var v, int value, bed_node_list *Ts )
{
  int i;
  bed_node_list *res;

  res = il_new();
  assert( res );

  IL_ITER( Ts, i ) {
    bed_node n;

    n = il_elem( Ts, i );
    if ( VAR( n ) == v ) {
      if ( value == 0 )
	n = LOW(n);
      else
	n = HIGH(n);
    }

    il_append( res, n );
  }

  return res;
}



/* Return a variable assignment in var_assign which satisfies the Ts BDDs.
 * Initial call should have i=0 and  var_assign  should be initialized to 'x'.
 * Return true on success (variable assignment exists). 0 / 1 in  var_assign  indicates that
 * the corresponding variable is assigned false / true.
 * The BDD preferred is a preferred assignment to the variables (bed_one if no preferences).
 */
static Boolean pick_assignment( int i, bed_node_list *Ts, char *var_assign, bed_node preferred )
{
  int j, value;
  bed_var v;

  if ( i >= il_length( gmc_order ) )
    return true;

  v = il_elem( gmc_order, i );

  if ( IS_VARIABLE( preferred ) && ( VAR(preferred) == v ) ) {
    if ( LOW(preferred) != bed_zero ) {
      value = 0;
      preferred = LOW( preferred );
    } else {
      value = 1;
      preferred = HIGH( preferred );
    }      
  } else
    value = ( random() & 32 ) ? 1 : 0;

  if ( assignment_okay( v, value, Ts ) ) {
    Boolean res;
    bed_node_list *tmp;

    tmp = assign_value( v, value, Ts );
    res = pick_assignment( i+1, tmp, var_assign, preferred );
    il_free( tmp );

    if ( res ) {
      var_assign[v] = value;
      return true;
    }
  }

  value = 1-value;

  if ( assignment_okay( v, value, Ts ) ) {
    Boolean res;
    bed_node_list *tmp;

    tmp = assign_value( v, value, Ts );
    res = pick_assignment( i+1, tmp, var_assign, preferred );
    il_free( tmp );

    if ( res ) {
      var_assign[v] = value;
      return true;
    }
  }

  return false;
}



/* Pick a random transition in Ts which starts in u.
 * u is a BDD of unprimed (even) variables.
 * Returns BED_UNDEFINED on error.
 */
static bed_node find_transition( bed_node_list *Ts, bed_node u )
{
  int i, nov;
  bed res;
  bed_node_list *Tpos;
  char *var_assign;	/* 0 (false), 1 (true), 255 unassigned */

  assert( u != bed_zero );

  Tpos = il_copy( Ts );
  il_append( Tpos, u );

  nov = bed_get_info().number_of_variables;
  var_assign = MALLOC_ARRAY( nov, char );

  for ( i = 0; i < nov; i++ )		/* Mark all variables as unassigned */
    var_assign[i] = 255;

  if ( !pick_assignment( 0, Tpos, var_assign, bed_one ) ) {
#if 0
    fprintf( shell_err, "*** Warning: Transition relation is not total\n" );
#endif
    free( var_assign );
    if ( Tpos )		il_free( Tpos );
    return BED_UNDEFINED;
  }

  res = bed_ref( bed_one ); 

  for ( i = il_length(gmc_order)-1; i >= 0; i-- ) {
    bed_node n;
    bed_var v;

    v = il_elem( gmc_order, i );

    if ( (v % 2) == 0 )
      continue;

    if ( var_assign[v] == 1 )
      n = bed_ref( bed_mk_var( v-1, bed_zero, res ) );	/* v-1 to get unprimed variables */
    else {
      assert( var_assign[v] == 0 );
      n = bed_ref( bed_mk_var( v-1, res, bed_zero ) );
    }

    bed_deref( res );
    res = n;
  }

  free( var_assign );
  if ( Tpos )	il_free( Tpos );

  bed_deref( res );
  return res;
}


/* Create a random quasi-path from I to G of length k.
 * Return the position where the transition relation does not hold.
 */
static int quasi_path( bed_node I, bed_node G, bed_node_list *Ts, int k,
		       bed_node *state_array )
{
  int i;

  state_array[0] = bed_ref( find_state( I ) );
  state_array[k] = bed_ref( find_state( G ) );

  assert( state_array[0] != BED_UNDEFINED );
  assert( state_array[k] != BED_UNDEFINED );

  for ( i = 1; i < k; i++ ) {
    state_array[i] = bed_ref( find_transition( Ts, state_array[i-1] ) );
    if ( state_array[i] == BED_UNDEFINED ) {
      if ( i == 1 ) {
	bed_deref( state_array[0] );
	i--;
      } else {
	bed_deref( state_array[i-1] );
	i = i-2;
      }
    }
  }

  return k-1;
}


/* Swap primed and unprimed variables in the BED u
 */
static bed_node swap_variables( bed_node u )
{
  bed_node res, low, high;
  bed_var v;
  register Cache *p;

  if ( IS_TERMINAL( u ) )
    return u;

  p = cache_get( TAG_SWAP_VARS, u, 0, 0, 0 );
  if ( cache_match( p, TAG_SWAP_VARS, u, 0, 0, 0 ) )
    return p->r1;

  low = bed_ref( swap_variables( LOW( u ) ) );
  high = bed_ref( swap_variables( HIGH( u ) ) );

  v = VAR( u );

  if ( IS_VARIABLE( u ) ) {
    if ( (v%2) == 1 )
      v--;
    else
      v++;
  }

  res = bed_mk( v, OP(u), low, high );

  bed_deref( low );
  bed_deref( high );
  
  cache_insert( p, TAG_SWAP_VARS, u, 0, 0, 0, res, 0 );

  return res;
}


/* Create a new state p' such that T(p',q) and p and p' differ as little as possible.
 * Return BED_UNDEFINED if no such p' can be found.
 */
static bed_node flip_one_state1( bed_node p, bed_node q, bed_node_list *Ts )
{
  bed_node qp, res;
  bed_node_list *new_Ts;

  qp = bed_ref( swap_variables( q ) );

  new_Ts = il_copy( Ts );
  il_append( new_Ts, qp );

  if ( pick_assignment( 0, new_Ts, eval_var_assign, p ) ) {
    int i;

    res = bed_ref( bed_one ); 

    for ( i = il_length(gmc_order)-1; i >= 0; i-- ) {
      bed_node n;
      bed_var v;

      v = il_elem( gmc_order, i );

      if ( (v % 2) == 1 )
	continue;

      if ( eval_var_assign[v] == 1 )
	n = bed_ref( bed_mk_var( v, bed_zero, res ) );
      else {
	assert( eval_var_assign[v] == 0 );
	n = bed_ref( bed_mk_var( v, res, bed_zero ) );
      }
      
      bed_deref( res );
      res = n;
    }

    bed_deref( res );

  } else
    res = BED_UNDEFINED;

  if ( new_Ts ) il_free( new_Ts );

  bed_deref( qp );
  return res;
}


/* Create a new state q' such that T(p,q') and q and q' differ as little as possible.
 * Return BED_UNDEFINED if no such q' can be found.
 */
static bed_node flip_one_state2( bed_node p, bed_node q, bed_node_list *Ts )
{
  bed_node qp, res;
  bed_node_list *new_Ts;

  qp = bed_ref( swap_variables( q ) );

  new_Ts = il_copy( Ts );
  il_append( new_Ts, p );

  if ( pick_assignment( 0, new_Ts, eval_var_assign, qp ) ) {
    int i;

    res = bed_ref( bed_one ); 

    for ( i = il_length(gmc_order)-1; i >= 0; i-- ) {
      bed_node n;
      bed_var v;

      v = il_elem( gmc_order, i );

      if ( (v % 2) == 0 )
	continue;

      if ( eval_var_assign[v] == 1 )
	n = bed_ref( bed_mk_var( v-1, bed_zero, res ) );
      else {
	assert( eval_var_assign[v] == 0 );
	n = bed_ref( bed_mk_var( v-1, res, bed_zero ) );
      }
      
      bed_deref( res );
      res = n;
    }

    bed_deref( res );

  } else
    res = BED_UNDEFINED;

  if ( new_Ts ) il_free( new_Ts );

  bed_deref( qp );
  return res;
}


/* Evaluate a new state new_p over the old state old_p -- new_p may be
 * BED_UNDEFINED. Return -1 on error or an integer for how good new_p
 * is. Lower is better, 0 is best (= path found).
 * Part of the check is whether there is a transition from p to q in Ts.
 */
static int state_eval( bed_node new_p, bed_node old_p, bed_node p, bed_node q,
		       bed_node_list *Ts )
{
  int res, nov;
  bed_node qp;
  bed_node_list *new_Ts;

  if ( new_p == BED_UNDEFINED )
    return -1;

  assert( old_p != BED_UNDEFINED );
  assert( p != BED_UNDEFINED );
  assert( q != BED_UNDEFINED );

  new_Ts = il_copy( Ts );
  il_append( new_Ts, p );

  qp = bed_ref( swap_variables( q ) );
  il_append( new_Ts, qp );

  res = 0;

  if ( !pick_assignment( 0, new_Ts, eval_var_assign, bed_one ) ) {

    res++;

    while ( ( p != bed_one ) && ( q != bed_one ) ) {

      assert( !IS_TERMINAL( p ) );
      assert( !IS_TERMINAL( q ) );

      if ( LOW( p ) == bed_zero ) {
	p = HIGH( p );
	if ( LOW( q ) == bed_zero )
	  q = HIGH( q );
	else {
	  q = LOW( q );
	  res++;
	}
      } else {
	p = LOW( p );
	if ( HIGH( q ) == bed_zero )
	  q = LOW( q );
	else {
	  q = HIGH( q );
	  res++;
	}
      }
    }

  }


  bed_deref( qp );

  if ( new_Ts )	il_free( new_Ts );

  return res;
}



/* Flip states in state_array. Return TRUE if path was found. FALSE if we give up.
 * I : initial states (unprimed variables)
 * G : goal states (unprimed variables)
 * Ts : transition relations (unprimed to primed variables)
 * k : number of steps in the path
 * p : place where the path breaks
 * state_array : array of states in the quasi-path
 */
static Boolean flip_states( bed_node I, bed_node G, bed_node_list *Ts,
			    int k, int p, bed_node *state_array )
{
  Boolean res;
  int flips;
  bed_node Gp;

  flips = gmc_flips;
  res = false;

  Gp = bed_ref( swap_variables( G ) );	/* Gp = G but with primed variables */

  while ( !res && (flips-- > 0) ) {
    int se1, se2;
    bed_node f1, f2;
    bed_node prev, next;
    bed_node_list *new_Ts;

    new_Ts = il_copy( Ts );

    if ( p == 0 )
      il_append( new_Ts, I );
    
    il_append( new_Ts, Gp );

    if ( p != k-1 ) {
      /* Check for early termination */
      f2 = flip_one_state2( state_array[p], state_array[p+1], new_Ts );

      if ( f2 != BED_UNDEFINED ) {
	state_array[p+1] = bed_ref( f2 );
	il_free( new_Ts );
	res = true;
      } else
	il_remove( new_Ts, Gp );
    }

    if ( !res ) {
#if 0
      if ( p == k-1 )
	il_append( new_Ts, Gp );
#endif
      
      f1 = bed_ref( flip_one_state1( state_array[p], state_array[p+1], new_Ts ) );
      f2 = bed_ref( flip_one_state2( state_array[p], state_array[p+1], new_Ts ) );

      if ( new_Ts ) il_free( new_Ts );

      prev = ( p == 0 ) ? bed_one : state_array[p-1];
      next = ( p == k-1) ? bed_one : state_array[p+2];

      se1 = state_eval( f1, state_array[p], prev, f1, Ts );
      se2 = state_eval( f2, state_array[p+1], f2, next, Ts );

      if ( ( se1 == -1 ) && ( se2 == -1 ) ) {
	int i;

	fprintf( shell_out, "*** Warning: Reached a dead-end. Reshuffling the states.\n" );
	bed_deref( f1 );
	bed_deref( f2 );

	for ( i = 0; i <= k; i++ )
	  bed_deref( state_array[i] );
	p = quasi_path( I, G, Ts, k, state_array );
	
	continue;
      }

      if ( (se2 != -1) && ( ( se1 == -1 ) || ( se2 < se1 ) || ( (se2==se1) && (random() & 32) ))) {
	bed_deref( state_array[p+1] );
	bed_deref( f1 );
	assert( f2 != BED_UNDEFINED );
	state_array[p+1] = f2;
	p++;
	if ( se2 == 0 )
	  res = true;

      } else {
	bed_deref( state_array[p] );
	bed_deref( f2 );
	assert( f1 != BED_UNDEFINED );
	state_array[p] = f1;
	p--;
	if ( se1 == 0 )
	  res = true;
      }
    }
  }

  bed_deref( Gp );

  return res;
}


/* Greedy Model Checking with
 * I : Initial states
 * G : Goal states
 * Ts : list of transition relations (conjunctive partitioning)
 * k : expected length of counterexample ( >=1 )
 * ALL BEDs *must* be BDDs with the same variable ordering.
 */
static void gmc( bed_node I, bed_node G, bed_node_list *Ts, int k )
{
  Boolean done;
  int i, tries;
  bed_node *state_array;

  if ( ( k < 1 ) || !( Ts && (il_length(Ts)>0) ) || ( I == bed_zero ) || ( G == bed_zero ) )
    return;

  state_array = MALLOC_ARRAY( k+1, bed_node );

  eval_var_assign = MALLOC_ARRAY( bed_get_info().number_of_variables, char );

  gmc_order = bed_get_ordering();

  done = false;
  tries = gmc_tries;

  while ( (!done) && (tries != 0) ) {
    int p;

    tries--;

    p = quasi_path( I, G, Ts, k, state_array );

    done = flip_states( I, G, Ts, k, p, state_array );

    if ( (!done) && (tries != 0) )
      for ( i = 0; i <= k; i++ )
	bed_deref( state_array[i] );
  }

  if ( done ) {
    fprintf( shell_out, "Found a path of length %d:\n\n", k );
    output_quasi_path( k, state_array, -1, gmc_delta, G );
    fprintf( shell_out, "\n" );

  } else {
    fprintf( shell_out, "Sorry, but I could not find a path of length %d\n", k );
  }

  for ( i = 0; i <= k; i++ )
    bed_deref( state_array[i] );

  if ( gmc_order)	il_free( gmc_order );
  free( state_array );
  free( eval_var_assign );
}


/* Syntax : gmc I G [T1 T2 ... Tn] k
 * I and G are expressed in unprimed variables.
 * T1..n are over unprimed and primed variables.
 * Variable ordering *must* be interleaved: x1 x1' x2 x2' ... xn xn'
 */
static void parse_gmc_command( Lex *l )
{
  bed_node I, G;
  bed_node_list *Ts = NULL;

  if ( !lex_ok( l ) )
    return;

  I = shell_parse_node( l );
  if ( lex_ok( l ) )
    G = shell_parse_node( l );
  if ( lex_ok( l ) )
    Ts = shell_parse_node_list( l );

  if ( lex_ok( l ) && Ts && ( il_length( Ts ) > 0 ) ) {
    if ( have( l, T_INTEGER ) ) {
      int i;
      int k = get_int( l );

      if ( k <= 0 ) {
	lex_error( l, "Expected an integer >= 1" );
      } else {
	I = bed_ref( bed_upall( I ) );
	G = bed_ref( bed_upall( G ) );
	IL_ITER( Ts, i )
	  il_elem( Ts, i ) = bed_ref( bed_upall( il_elem( Ts, i ) ) );

	gmc( I, G, Ts, k );
	
	IL_ITER( Ts, i )
	  bed_deref( il_elem( Ts, i ) );
	bed_deref( G );
	bed_deref( I );
      }
    } else
      lex_error( l, "Expected an integer" );
  }

  if ( Ts ) il_free( Ts );
}





/*===[ Sat command ]===========================================*/

static char *satsolve_array = NULL;	/* E : Empty
					   L : low done
					   H : high done
					*/
static Timer sat_timer;
static int sat_old_ratio;

static void satsolve_output_ratio( int c )
{
  int i, n;
  double r;
  int res;

  r = 0.0;
  n = bed_get_info().number_of_variables;

  for ( i = 0; i <= c ; i++ )
    if ( satsolve_array[i] != 'E' )
      r += pow( (double) 2.0, (double) (n-i-1) );

  res = (int)( 100.0*r / pow( (double) 2.0, (double) n ) );

  fprintf( shell_out, "\r%d%% ", res );
  sat_old_ratio = res;
}


static bed_var find_var_depth( bed_node u, int depth )
{
  bed_var v;

  if ( IS_VARIABLE( u ) )
    return VAR( u );

  if ( IS_TERMINAL( u ) || ( depth <= 0 ) )
    return BED_UNDEFINED;

  v = find_var_depth( LOW( u ), depth-1 );
  if ( v != BED_UNDEFINED )
    return v;
  return find_var_depth( HIGH( u ), depth-1 );
}


static bed_var find_var( bed_node u, int level )
{
#if 0

#if 0
  int i = 1;
  bed_var v = BED_UNDEFINED;

  assert( !IS_TERMINAL( u ) );

  while ( v == BED_UNDEFINED )
    v = find_var_depth( u, i++ );

  return v;
#else
  bed_var_list *var_list = bed_get_ordering();
  bed_var v = il_elem( var_list, level );
  if ( var_list ) il_free( var_list );
  return v;
#endif

#else
  while ( !IS_VARIABLE( u ) ) {
    assert( !IS_TERMINAL( u ) );
    u = LOW( u );
  }
  assert( IS_VARIABLE( u ) );
  return VAR( u );
#endif
}


static bed_node satsolve( bed_node u, int c, bed_node lookfor )
{
  bed_var v;
  bed_node r, res, l, h;
  char tag;

  if ( IS_TERMINAL( u ) )
    return u;

  if ( (max_sat_depth != 0) && (c >= max_sat_depth) )
    return u;

  if ( ( max_sat_time > 0 ) && ( timer_get( sat_timer ) >= 1000 * max_sat_time ) ) {
    return u;
  }

  v = find_var( u, c );

  satsolve_array[c] = 'E';

  satsolve_output_ratio( c );

  bed_ref( u );

  r = bed_ref( bed_upone( v, u ) );

  if ( IS_TERMINAL( r ) ) {
    bed_deref( u );
    bed_deref( r );
    return r;
  }

  if ( ! ( IS_VARIABLE(r) && ( VAR(r) == v ) ) ) {
    res = satsolve( r, c+1, lookfor );
  } else {
    int lsize, hsize;

    l = LOW( r );
    h = HIGH( r );

    lsize = bed_node_count( l );
    hsize = bed_node_count( h );

    if ( hsize <= lsize ) {
      bed_node tmp;
      int tmp2;
      tmp = l;
      l = h;
      h = tmp;
      tag = 'H';
      tmp2 = hsize;
      hsize = lsize;
      lsize = tmp2;
    } else
      tag = 'L';

    if ( lsize < max_sat_size )
      res = (bed_upall( l ) == bed_one - lookfor) ? bed_one - lookfor : lookfor;
    else
      res = satsolve( l, c+1, lookfor );

    if( res != lookfor ) {
      satsolve_array[c] = tag;
      if ( hsize < max_sat_size )
	res = (bed_upall( h ) == bed_one - lookfor) ? bed_one - lookfor : lookfor;
      else
	res = satsolve( h, c+1, lookfor );
    }
  }

  bed_deref( u );
  bed_deref( r );

  return res;
}


static void parse_satsolve_command( Lex *l, bed_node lookfor )
{
  if ( lex_ok( l ) ) {
    unsigned char oldmode;
    bed_node res;
    bed_root_list *roots = shell_parse_root_list( l );

    if ( roots == NULL )
      return;

    satsolve_array = MALLOC_ARRAY( bed_get_info().number_of_variables, char );

    oldmode = bed_get_upone_mode();
    bed_set_upone_mode( BED_UPONE_MODE_STRICT );

    if ( lex_ok( l ) ) {
      int i;
      IL_ITER( roots, i ) {
	bed_root root = il_elem( roots, i );
	bed_node node = r2n_lookup( root );
	bed_node new;

	fprintf( shell_out, "Part of statespace proved:\n" );
	if ( ( max_sat_depth > 0 ) && ( max_sat_depth < bed_get_info().number_of_variables ) )
	  fprintf( shell_out, "(Number not correct due to limited depth)\n" );
	satsolve_array[0] = 'E';
	sat_old_ratio = -1;
	satsolve_output_ratio( 0 );

	if ( max_sat_size > 0 ) {
	  bed_var_list *ordering = shell_fanin( node );
	  bed_set_ordering( ordering );
	  il_free( ordering );
	}

	sat_timer = timer_start();
	new = satsolve( node, 0, lookfor );

	fprintf( shell_out, "\n" );

	if ( IS_TERMINAL( new ) ) {
	  r2n_update( root, new );
	  node = new;
	}

	fprintf( shell_out, "bed%ssat( %s ) -> %d\n", ( lookfor == bed_zero ? "un" : "" ), lex_quote( shell_root2name( root ) ), node );
      }
    }

    if ( roots ) il_free( roots );
    bed_set_upone_mode( oldmode );
    free( satsolve_array );
    satsolve_array = NULL;
  }
}


static int sat_number = 0;

/* whichsolver = 1 : Sato
 *               2 : Grasp
 *
 * Note: Sato and Grasp *must* be modified to return the result
 * (1 = sat, 0 = unsat) as an error code. Otherwise it will not work.
 *
 * The runtimes reported by BED may not include the Sato and Grasp
 * runtimes.
 */

static Boolean external_sat( int whichsolver, bed_node u )
{
  char buf[1024];
  FILE *fp;
  int pd = (int) getpid();
  int res = 2;

  if ( IS_TERMINAL( u ) )
    return u == bed_one;

  sat_number++;

  sprintf( buf, "/tmp/%d_%d.dimacs", pd, sat_number );

  fp = fopen( buf, "w" );
  if ( fp ) {
    bed_io_dimacs( fp, u );
    fclose( fp );

    if ( whichsolver == 1 )
      sprintf( buf, "sato -t /tmp/%d_%d.dimacs > /dev/null", pd, sat_number );
    else if ( whichsolver == 2 )
      sprintf( buf, "sat-grasp /tmp/%d_%d.dimacs > /dev/null", pd, sat_number );
    else
      assert( 0 );

    res = system( buf );
  }

  sprintf( buf, "rm -f /tmp/%d_%d.dimacs", pd, sat_number );
  system( buf );

  if ( ( res != 0 ) && ( res != 1 ) && ( res != 256 ) ) {
    /* 256 : Corresponds to 1 */
    fprintf( shell_out, "*** Error: SAT-solver returned invalid error code: %d\n", res );
  }

  return ( res != 0 );
}


static void parse_sat_unsat_command( Lex *l, bed_node lookfor )
{
  int whichsolver = 0;
  char solver[12];

  if ( lex_ok( l ) ) {
    bed_root_list *roots;

    if ( have_keyword( l, "sato" ) ) {
      sprintf( solver, "sato" );
      whichsolver = 1;
    } else if ( have_keyword( l, "grasp" ) ) {
      sprintf( solver, "grasp" );
      whichsolver = 2;
    } else
      lex_error( l, "Expected 'sato' or 'grasp'" );

    roots = shell_parse_root_list( l );

    if ( roots && lex_ok( l ) ) {
      int i;
      IL_ITER( roots, i ) {
	bed_root root = il_elem( roots, i );
	bed_node node = r2n_lookup( root );
	bed_node new;

	if ( lookfor == bed_zero )
	  node = bed_mk_not( node );

	new = external_sat( whichsolver, node ) ? bed_one : bed_zero;
	if ( lookfor == bed_zero )
	  new = bed_one - new;

	if ( IS_TERMINAL( new ) ) {
	  r2n_update( root, new );
	  node = new;
	}

	fprintf( shell_out, "%ssat %s( %s ) -> %d\n", ( lookfor == bed_zero ? "un" : "" ), solver, lex_quote( shell_root2name( root ) ), node );
      }
    }

    if ( roots ) il_free( roots );
  }
}


/*===[ anysat, anynonsat, satcount commands ]===========================================*/

static void parse_sat_command( Lex *l, bed_node look_for )
{
  int i;
  bed_var_list* res;
  bed_node u = shell_parse_node( l );

  if ( lex_err( l )) return;

  res = (look_for == bed_one ?
	 bed_any_sat( u ) :
	 bed_any_nonsat( u ) );

  if ( res == NULL ) {
    fprintf( shell_out, "No assignment found\n" );
    return;
  }

  fprintf( shell_out,"Variables assigned the value true:" );

  fprintf( shell_out, "[" );
  IL_ITER( res, i )
    fprintf( shell_out, "%s ", lex_quote( bed_var2name( il_elem( res, i ) ) ) );
  fprintf( shell_out, "]\n" );

  il_free( res );
}

static void parse_satcount_command( Lex *l )
{
  bed_node node = shell_parse_node( l );
  if ( lex_ok( l )) {
    double d = bed_sat_count( node );

    if ( d < 0.0 )
      fprintf( shell_out, "BED is not ordered or it contains operators. SatCount not possible.\n" );
    else
      fprintf( shell_out, "SatCount: %g\n", d );
  }
}


/*===[ Quantdown ]===========================================*/

void parse_quantdown_command( Lex *l )
{
  if ( lex_ok( l ) ) {
    int j;
    bed_root_list *roots;

    roots = shell_parse_root_list( l );

    if ( roots ) {
      IL_ITER( roots, j ) {
	bed_root root = il_elem( roots, j );
	bed_node node = bed_ref( shell_root2node( root ) );

	node = quantdown( node );

	shell_root_update( root, node );

	fprintf( shell_out, "quantdown %s -> %d\n", lex_quote(shell_root2name(root)),
		 node );
      }
      il_free( roots );

    }
  }
}


/*===[ order command ]======================================================*/

static void parse_order_command( Lex *l )
{
  if ( lookahead( l, T_EOF ) || lookahead( l, T_SEMI ) ) {
    int i;
    bed_var_list *var_list = bed_get_ordering();
    IL_ITER( var_list, i )
      fprintf( shell_out, "%s ", lex_quote( bed_var2name( il_elem( var_list, i ) ) ) );
    fprintf( shell_out, "\n" );
    il_free( var_list );

  } else {
    bed_var_list *var_list = shell_parse_variable_list( l );

    if ( lex_err( l )) return;

    bed_set_ordering( var_list );
    il_free( var_list );
  }
}


/*===[ reachable command ]==================================================*/

static void parse_reachable_command( Lex *l )
{
  if ( lex_ok( l ) ) {
    bed_node u = shell_parse_node( l );
    bed_node_list *nodes;

    if ( ! lex_ok( l ) )
      return;

    nodes = shell_parse_node_list( l );

    if ( lex_ok( l ) ) {
      int i;
      Boolean res = false;

      IL_ITER( nodes, i ) {
	if ( bed_is_reachable( u, il_elem( nodes, i ) ) ) {
	  res = true;
	  break;
	}
      }

      fprintf( shell_out, "%s\n", res ? "Reachable" : "Not reachable" );
    }
    if ( nodes != NULL ) il_free( nodes );
  }
}


/*===[ Environment command ]==================================================*/

static void parse_set_command( Lex *l )
{
  if ( have_keyword( l, "support" )) {
    if ( have_keyword( l, "left" ) )
      bed_support_low_first = true;
    else {
      mustbe_keyword( l, "right" );
      bed_support_low_first = false;
    }

  } else if ( ( have_keyword( l, "reduce" )) || ( have_keyword( l, "reductions" )) ) {
    if ( have_keyword( l, "on" )) {
      bed_do_reductions = true;
    } else if ( have_keyword( l, "off" )) {
      bed_do_reductions = false;
    } else {
      fprintf( shell_out, "%s\n", bed_do_reductions ? "on" : "off" );
    }

  } else if ( have_keyword( l, "dot_margin" )) {
    if ( have( l, T_REAL ) ) 
      bed_io_dot_margin = get_real( l );
    else  if ( have( l, T_INTEGER ) )
      bed_io_dot_margin = (float) get_int( l );
    else
      fprintf( shell_out, "dot_margin: %3.1f\n", bed_io_dot_margin );

  } else if ( have_keyword( l, "dot_ranksep" )) {
    if ( have( l, T_REAL ) ) 
      bed_io_dot_ranksep = get_real( l );
    else if ( have( l, T_INTEGER ) )
      bed_io_dot_ranksep = (float) get_int( l );
    else
      fprintf( shell_out, "dot_ranksep: %3.1f\n", bed_io_dot_ranksep );

  } else if ( have_keyword( l, "dot_nodesep" )) {
    if ( have( l, T_REAL ) ) 
      bed_io_dot_nodesep = get_real( l );
    else if ( have( l, T_INTEGER ) )
      bed_io_dot_nodesep = (float) get_int( l );
    else
      fprintf( shell_out, "dot_nodesep: %3.1f\n", bed_io_dot_nodesep );

  } else if ( have_keyword( l, "dot_fontsize" )) {
    if ( have( l, T_INTEGER ) ) 
      bed_io_dot_fontsize = get_int( l );
    else 
      fprintf( shell_out, "dot_fontsize: %d\n", bed_io_dot_fontsize );

  } else if ( have_keyword( l, "dot_ratio" )) {
    if ( have_keyword( l, "auto" ) )
      bed_io_dot_ratio = "auto";
    else if ( have_keyword( l, "compress" ))
      bed_io_dot_ratio = "compress";
    else if ( have_keyword( l, "fill" ))
      bed_io_dot_ratio = "fill";
    else if ( have( l, T_REAL )) {
      bed_io_dot_ratio  = MALLOC_ARRAY( 5, char );
      sprintf( bed_io_dot_ratio, "%3.1f", get_real( l ) );
    } else if ( have( l, T_INTEGER )) {
      bed_io_dot_ratio  = MALLOC_ARRAY( 4, char );
      sprintf( bed_io_dot_ratio, "%3d", get_int( l ) );
    } else
      fprintf( shell_out, "dot_ratio: %s\n", bed_io_dot_ratio );

  } else if ( have_keyword( l, "dot_zero" )) {
    if ( have_keyword( l, "on" )) {
      bed_io_dot_draw_to_zero = true;
    } else if ( have_keyword( l, "off" )) {
      bed_io_dot_draw_to_zero = false;
    } else {
      fprintf( shell_out, "%s\n", bed_io_dot_draw_to_zero ? "on" : "off" );
    }

  } else if ( have_keyword( l, "dot_numbers" )) {
    if ( have_keyword( l, "on" )) {
      bed_io_dot_print_node_numbers = true;
    } else if ( have_keyword( l, "off" )) {
      bed_io_dot_print_node_numbers = false;
    } else {
      fprintf( shell_out, "%s\n", bed_io_dot_print_node_numbers ? "on" : "off" );
    }

  } else if ( have_keyword( l, "displaytime" )) {
    display_time = ( have( l, T_INTEGER ) ? get_int( l ) : 1 );

  } else if ( have_keyword( l, "sort" ) || have_keyword( l, "sort_roots" ) ) {
    if ( have_keyword( l, "on" )) {
      bed_sort_roots = true;
    } else if ( have_keyword( l, "off" )) {
      bed_sort_roots = false;
    } else {
      fprintf( shell_out, "%s\n", bed_sort_roots ? "on" : "off" );
    }

  } else if ( have_keyword( l, "sat_max_size" ) ) {
    if ( have( l, T_INTEGER ) )
      max_sat_size = get_int( l );
    else
      fprintf( shell_out, "%d\n", max_sat_size );

  } else if ( have_keyword( l, "sat_depth" ) ) {
    if ( have( l, T_INTEGER ) )
      max_sat_depth = get_int( l );
    else
      fprintf( shell_out, "%d\n", max_sat_depth );

  } else if ( have_keyword( l, "sat_time" ) ) {
    if ( have( l, T_INTEGER ) )
      max_sat_time = get_int( l );
    else
      fprintf( shell_out, "%d\n", max_sat_time );

  } else if ( have_keyword( l, "gmc_tries" ) ) {
    if ( have( l, T_INTEGER ) )
      gmc_tries = get_int( l );
    else
      fprintf( shell_out, "%d\n", gmc_tries );

  } else if ( have_keyword( l, "gmc_flips" ) ) {
    if ( have( l, T_INTEGER ) )
      gmc_flips = get_int( l );
    else
      fprintf( shell_out, "%d\n", gmc_flips );

  } else if ( have_keyword( l, "gmc_delta" )) {
    if ( have_keyword( l, "on" )) {
      gmc_delta = true;
    } else if ( have_keyword( l, "off" )) {
      gmc_delta = false;
    } else {
      fprintf( shell_out, "%s\n", gmc_delta ? "on" : "off" );
    }

  } else if ( have_keyword( l, "order" ) || have_keyword( l, "ordering" ) ) {
    parse_order_command( l );

  } else if ( have_keyword( l, "bedsize" ) ) {
    long size;
    mustbe( l, T_INTEGER );
    size = get_int( l ) * 1024 * 1024;
    if ( size <= 0 )
      lex_error( l, "Must be a positive integer." );
    else if ( !kernel_resize_bed( size / sizeof( BED ) ) )
      lex_error( l, "Could not resize bed. Try using the 'clear' command first." );

  } else if ( have_keyword( l, "cachesize" ) ) {
    long size;
    mustbe( l, T_INTEGER );
    size = get_int( l ) * 1024 * 1024;
    if ( size <= 0 )
      lex_error( l, "Must be a positive integer." );
    else
      kernel_resize_caches( size / sizeof( Cache ) );

  } else if ( lookahead( l, T_EOF ) || lookahead( l, T_SEMI ) ) {
    fprintf( shell_out, "Current settings:\n" );
    fprintf( shell_out, "support         : %s\n", bed_support_low_first ? "left" : "right" );
    fprintf( shell_out, "reductions      : %s\n", bed_do_reductions ? "on" : "off" );
    fprintf( shell_out, "dot_zero        : %s\n", bed_io_dot_draw_to_zero ? "on" : "off" );
    fprintf( shell_out, "dot_numbers     : %s\n", bed_io_dot_print_node_numbers ? "on" : "off" );
    fprintf( shell_out, "dot_ranksep     : %3.1f\n", bed_io_dot_ranksep );
    fprintf( shell_out, "dot_nodesep     : %3.1f\n", bed_io_dot_nodesep );
    fprintf( shell_out, "dot_margin      : %3.1f\n", bed_io_dot_margin );
    fprintf( shell_out, "dot_fontsize    : %3d\n", bed_io_dot_fontsize );
    fprintf( shell_out, "dot_ratio       : %s\n", bed_io_dot_ratio );
    fprintf( shell_out, "sort_roots      : %s\n", bed_sort_roots ? "on" : "off" );
    fprintf( shell_out, "gmc_tries       : %d\n", gmc_tries );
    fprintf( shell_out, "gmc_flips       : %d\n", gmc_flips );
    fprintf( shell_out, "gmc_delta       : %s\n", gmc_delta ? "on" : "off" );
    fprintf( shell_out, "sat_max_size    : %d\n", max_sat_size );
    fprintf( shell_out, "sat_depth       : %d\n", max_sat_depth );
    fprintf( shell_out, "sat_time        : %d sec\n", max_sat_time );
    fprintf( shell_out, "displaytime     : %d sec\n", display_time );
    fprintf( shell_out, "bedsize         : %.2f MB\n", (float) bed_get_info().number_of_nodes * sizeof( BED ) / ( 1024.0 * 1024.0 ) );
    fprintf( shell_out, "cachesize       : %.2f MB\n", (float) ( cache_size()*sizeof( Cache ) ) / ( ( 1024.0 * 1024.0 ) ) );
  } else {
    (void) get_token( l );
    lex_error( l, "Unknown option '%s'\n", get_name( l ) );
  }
}

static void parse_unset_command( Lex *l )
{
  if ( have_keyword( l, "displaytime" )) {
    display_time = 10000000;	/* = Infinite */
  }
}

/*===[ Let command (introduce new roots) ]===============================*/

static bed_node parse_expr_primary( Lex *l );	/* Prototype */
bed_node shell_parse_expr( Lex *l );			/* Prototype */


static bed_node bed_mk_exists_chain( bed_var_list *vars, bed_node u )
{
  int i;
  bed_node tmp;
  bed_ref( u );

  for ( i = il_length( vars ) - 1; i >= 0; i-- ) {
    tmp = bed_mk_exists( il_elem( vars, i ), u );
    bed_deref( u );
    u = tmp;
  }
  bed_deref( u );
  return u;
}

static bed_node bed_mk_forall_chain( bed_var_list *vars, bed_node u )
{
  int i;
  bed_node tmp;
  bed_ref( u );

  for ( i = il_length( vars ) - 1; i >= 0; i-- ) {
    tmp = bed_mk_forall( il_elem( vars, i ), u );
    bed_deref( u );
    u = tmp;
  }
  bed_deref( u );
  return u;
}


static bed_node parse_reach_function( Lex *l )
{ 
  bed_node I, T, R;
  bed_info info;

  mustbe( l, T_LPAR );
  I = bed_ref( parse_expr_primary( l ) );
  mustbe( l, T_COMMA );
  T = bed_ref( parse_expr_primary( l ) );
  mustbe( l, T_RPAR );
  if (lex_err( l )) return BED_UNDEFINED;
  
  info = bed_get_info();

  if ( info.number_of_variables % 2 != 0) {
    lex_error( l, "Odd number of variables" );
    return BED_UNDEFINED;
  }
     
  R = bed_reach_forward( I, T );

  bed_deref( I );
  bed_deref( T );
 
  return R;
}

static bed_node parse_exists_function( Lex *l )
{
  bed_node u;
  bed_var_list *vars;
  bed_node res;

  vars = shell_parse_variable_list( l );
  mustbe( l, '.' );
  u = bed_ref( parse_expr_primary( l ) );

  if (lex_err( l )) {
    if ( vars ) il_free( vars );
    return BED_UNDEFINED;
  }

  res = bed_mk_exists_chain( vars, u );

  il_free( vars );

  bed_deref( u );

  return res;
}

static bed_node parse_forall_function( Lex *l )
{
  bed_node u;
  bed_var_list *vars;
  bed_node res;

  vars = shell_parse_variable_list( l );
  mustbe( l, '.' );
  u = bed_ref( parse_expr_primary( l ) );

  if (lex_err( l )) {
    if ( vars ) il_free( vars );
    return BED_UNDEFINED;
  }

  res = bed_mk_forall_chain( vars, u );

  il_free( vars );

  bed_deref( u );

  return res;
}

static bed_node parse_esub_function( Lex *l )
{ 
  bed_node res, u = bed_ref( parse_expr_primary( l ) );

  if (lex_err( l )) return BED_UNDEFINED;

  res = bed_mk_esub( u );

  bed_deref( u );

  return res;
}

static bed_node parse_expr_name( Lex *l )
{
  if ( lex_ok( l ) ) {

    if ( have( l, T_NAME ) || have( l, T_STRING ) ) {
      bed_root root;
      bed_var var;

      root = lookup_root( get_name( l ) );
      if ( root != BED_UNDEFINED )
	return r2n_lookup( root );

      var = lookup_var( get_name( l ) );

      if ( var != BED_UNDEFINED )
	return bed_mk_var( var, bed_zero, bed_one );

      lex_error( l, "No symbol named '%s'", get_name( l ));
    } else {
      mustbe( l, T_INTEGER );
      return get_int( l );
    }
  }
  return BED_UNDEFINED;
}

static bed_node parse_expr_primary( Lex *l )
{
  bed_node u = BED_UNDEFINED;

  if ( have( l, T_LPAR )) {
    u = shell_parse_expr( l );
    mustbe( l, T_RPAR );
    if ( lex_err( l )) return BED_UNDEFINED;

  } else if ( have( l, (Token) '!' ) || have_keyword( l, "not" ) ||
	      have( l, (Token) '~' )) {
    bed_node low = bed_ref( parse_expr_primary( l ) );
    u = ( lex_err( l ) ? BED_UNDEFINED : bed_mk_not( low ) );
    bed_deref( low );

  } else if ( have_keyword( l, "reach" )) {
    u = parse_reach_function( l );

  } else if ( have_keyword( l, "exists" )) {
    u = parse_exists_function( l );

  } else if ( have_keyword( l, "forall" )) {
    u = parse_forall_function( l );

  } else if ( have_keyword( l, "esub" )) {
    u = parse_esub_function( l );

  } else if ( have_keyword( l, "true" )) {
    u = bed_one;

  } else if ( have_keyword( l, "false" )) {
    u = bed_zero;

  } else if ( have( l, T_INTEGER ) ) {
    u = get_int( l );

  } else 
    u = parse_expr_name( l );

  bed_ref( u );

  while ( lex_ok( l ) && have( l, T_LBRK ) ) {    /* Substitution */
    do {
      bed_node v, w;
      bed_var var = shell_parse_variable( l );
      mustbe( l, T_COLON_EQU );
      v = bed_ref( shell_parse_expr( l ) );
      w = bed_ref( ( lex_err( l ) ? BED_UNDEFINED : bed_mk_subst( var, u, v ) ) );
      bed_deref( u );
      bed_deref( v );
      u = w;
    } while ( lex_ok( l ) && !have( l, T_RBRK ) );
  }

  bed_deref( u );

  return u;
}

static bed_node parse_expr_ite( Lex *l )	/* ite:   <expr> <var> <expr> */
{
  bed_node u = bed_ref( parse_expr_primary( l ) );

  if ( have( l, (Token) '<' )) {
    bed_var x = shell_parse_variable( l );
    bed_node v, w;
    mustbe( l, (Token) '>' );
    if ( lex_err( l )) {
      bed_deref( u );
      return BED_UNDEFINED;
    }

    v = bed_ref( parse_expr_primary( l ) );
    if ( lex_err( l )) {
      bed_deref( u );
      bed_deref( v );
      return BED_UNDEFINED;
    }
    w = bed_ref( bed_mk_var( x, u, v ) );
    bed_deref( v );
    bed_deref( u );
    u = w;
  }

  bed_deref( u );
  return u;
}


static bed_node parse_expr_nand( Lex *l )
{
  bed_node u = bed_ref( parse_expr_ite( l ) );

  while ( have_keyword( l, "nand" )) {
    bed_node w, v = bed_ref( parse_expr_ite( l ) );
    if ( lex_err( l )) {
      bed_deref( u );
      bed_deref( v );
      return BED_UNDEFINED;
    }
    w = bed_ref( bed_mk_op( NAND, u, v ) );
    bed_deref( u );
    bed_deref( v );
    u = w;
  }

  bed_deref( u );
  return u;
}

static bed_node parse_expr_conj( Lex *l )
{
  bed_node u = bed_ref( parse_expr_nand( l ) );

  while ( have( l, (Token) '&' ) || have_keyword( l, "and" )) {
    bed_node w, v = bed_ref( parse_expr_nand( l ) );
    if ( lex_err( l )) {
      bed_deref( u );
      bed_deref( v );
      return BED_UNDEFINED;
    }
    w = bed_ref( bed_mk_op( AND, u, v ) );
    bed_deref( u );
    bed_deref( v );
    u = w;
  }

  bed_deref( u );
  return u;
}

static bed_node parse_expr_nor( Lex *l )
{
  bed_node u = bed_ref( parse_expr_conj( l ) );

  while ( have_keyword( l, "nor" )) {
    bed_node w, v = bed_ref( parse_expr_conj( l ) );
    if ( lex_err( l )) {
      bed_deref( u );
      bed_deref( v );
      return BED_UNDEFINED;
    }
    w = bed_ref( bed_mk_op( NOR, u, v ) );
    bed_deref( u );
    bed_deref( v );
    u = w;
  }

  bed_deref( u );
  return u;
}

static bed_node parse_expr_disj( Lex *l )
{
  bed_node u = bed_ref( parse_expr_nor( l ) );

  while ( have( l, (Token) '|' ) || have_keyword( l, "or" )) {
    bed_node w, v = bed_ref( parse_expr_nor( l ) );
    if ( lex_err( l )) {
      bed_deref( u );
      bed_deref( v );
      return BED_UNDEFINED;
    }
    w = bed_ref( bed_mk_op( OR, u, v ) );
    bed_deref( u );
    bed_deref( v );
    u = w;
  }

  bed_deref( u );
  return u;
}


static bed_node parse_expr_nlimp( Lex *l )
{
  bed_node u = bed_ref( parse_expr_disj( l ) );

  while ( have_keyword( l, "nlimp" )) {
    bed_node w, v = bed_ref( parse_expr_disj( l ) );
    if ( lex_err( l )) {
      bed_deref( u );
      bed_deref( v );
      return BED_UNDEFINED;
    }
    w = bed_ref( bed_mk_op( NLIMP, u, v ) );
    bed_deref( u );
    bed_deref( v );
    u = w;
  }

  bed_deref( u );
  return u;
}

static bed_node parse_expr_limp( Lex *l )
{
  bed_node u = bed_ref( parse_expr_nlimp( l ) );

  while ( have( l, T_LANG_EQU ) || have_keyword( l, "limp" )) {
    bed_node w, v = bed_ref( parse_expr_nlimp( l ) );
    if ( lex_err( l )) {
      bed_deref( u );
      bed_deref( v );
      return BED_UNDEFINED;
    }
    w = bed_ref( bed_mk_op( LIMP, u, v ) );
    bed_deref( u );
    bed_deref( v );
    u = w;
  }

  bed_deref( u );
  return u;
}

static bed_node parse_expr_nimp( Lex *l )
{
  bed_node u = bed_ref( parse_expr_limp( l ) );

  while ( have_keyword( l, "nimp" )) {
    bed_node w, v = bed_ref( parse_expr_limp( l ) );
    if ( lex_err( l )) {
      bed_deref( u );
      bed_deref( v );
      return BED_UNDEFINED;
    }
    w = bed_ref( bed_mk_op( NIMP, u, v ) );
    bed_deref( u );
    bed_deref( v );
    u = w;
  }

  bed_deref( u );
  return u;
}

static bed_node parse_expr_imp( Lex *l )
{
  bed_node u = bed_ref( parse_expr_nimp( l ) );

  while ( have( l, T_IMPLIES ) || have_keyword( l, "imp" )) {
    bed_node w, v = bed_ref( parse_expr_nimp( l ) );
    if ( lex_err( l )) {
      bed_deref( u );
      bed_deref( v );
      return BED_UNDEFINED;
    }
    w = bed_ref( bed_mk_op( IMP, u, v ) );
    bed_deref( u );
    bed_deref( v );
    u = w;
  }

  bed_deref( u );
  return u;
}


static bed_node parse_expr_xor( Lex *l )
{
  bed_node u = bed_ref( parse_expr_imp( l ) );

  while ( have( l, T_BANG_EQU ) || have_keyword( l, "xor" )) {
    bed_node w, v = bed_ref( parse_expr_imp( l ) );
    if ( lex_err( l )) {
      bed_deref( u );
      bed_deref( v );
      return BED_UNDEFINED;
    }
    w = bed_ref( bed_mk_op( XOR, u, v ) );
    bed_deref( u );
    bed_deref( v );
    u = w;
  }

  bed_deref( u );
  return u;
}


bed_node shell_parse_expr( Lex *l )
{
  bed_node u = bed_ref( parse_expr_xor( l ) );

  while  ( have( l, T_EQU ) || have( l, T_LANG_EQU_RANG ) || have_keyword( l, "biimp" )) {
    bed_node w, v = bed_ref( parse_expr_xor( l ) );
    if ( lex_err( l )) {
      bed_deref( u );
      bed_deref( v );
      return BED_UNDEFINED;
    }
    w = bed_ref( bed_mk_op( BIIMP, u, v ) );
    bed_deref( u );
    bed_deref( v );
    u = w;
  }

  bed_deref( u );
  return u;
}


static void parse_let_command( Lex *l )
{
  if ( lex_ok( l ) ) {
    mustbe( l, T_NAME );

    if ( lex_ok( l ) ) {
      bed_root root;
      bed_var var;
      char name[1024];
      strcpy( name, get_name( l ) );
      root = lookup_root( name );
      var = lookup_var( name );

      if ( have( l, T_EQU ) ) {
	if ( ! ( ( root == BED_UNDEFINED ) && ( var == BED_UNDEFINED ) ) )
	  lex_error( l, "Symbol '%s' already defined.", name );
	else {
	  bed_node u = shell_parse_expr( l );
	
	  if ( lex_ok( l ))
	    if ( lookahead( l, T_EOF ) || lookahead( l, T_SEMI ) )
	      shell_insert_root( name, u );
	}

      } else {
	mustbe( l, T_COLON_EQU );
	if ( ! ( var == BED_UNDEFINED ) )
	  lex_error( l, "Symbol '%s' already defined as a variable.", name );
	else {
	  bed_node u = shell_parse_expr( l );
	  
	  if ( lex_ok( l ))
	    if ( lookahead( l, T_EOF ) || lookahead( l, T_SEMI ) ) {
	      if ( root == BED_UNDEFINED )
		shell_insert_root( name, u );
	      else
		shell_root_update( root, u );
	    }
	}
      }
    }
  }
}

static void parse_unlet_command( Lex *l )
{
  while( lex_ok( l ) && ( have(l, T_NAME ) || have( l, T_STRING ) ) ) {
    if ( lookup_root( get_name( l ) ) != BED_UNDEFINED )
      remove_root( get_name( l ) );
    else
      lex_error( l, "Unknown root '%s'", get_name( l ) ); 
  }
}

static void parse_addvar_command( Lex *l )
{
  while ( lex_ok( l ) && !lookahead( l, T_EOF ) && !lookahead( l, T_SEMI)) {
    if (!have( l, T_NAME ))
      mustbe( l, T_STRING );
  
    if ( lex_ok( l ) ) {
      if ( ( lookup_var( get_name( l ) ) != BED_UNDEFINED ) ||
	   ( lookup_root( get_name( l ) ) != BED_UNDEFINED ) )
	lex_error( l, "Symbol '%s' already defined.", get_name( l ));
      else {
	shell_insert_var( get_name( l ), bed_new_variables( 1 ) );
      }
    }
  }
}


/*===[ Simplify command ]==================================================*/

static void parse_simplify_command( Lex *l )
{
  if ( lex_ok( l ) ) {
    bed_root_list *roots;
    roots = shell_parse_root_list( l );

    if ( roots ) {
      int j;
      bed_node constraint = shell_parse_node( l );
      if ( lex_ok( l ) ) {
	IL_ITER( roots, j ) {
	  bed_root root = il_elem( roots, j );
	  bed_node node = bed_ref( shell_root2node( root ) );
	  
	  node = simplify( node, constraint );
	  shell_root_update( root, node );

	  fprintf( shell_out, "simplify %s with %d -> %d\n", lex_quote( shell_root2name( root ) ), constraint, node );
	}
      }
      il_free( roots );
    }
  }
}


/*===[ Shell commands ]==================================================*/

static void parse_shell_command( Lex *l )
{
  if ( l->input_from_file ) {
    lex_error( l, "Shell-escape ('!') can only be used in interactive mode" );
  } else {
    int exit_no = system( l->ptr );
 
    if ( exit_no )
      lex_warning( l, "exit status = %d\n", exit_no );
    
    get_line( l );
    get_token( l );
  }
}

static void parse_ls_command( Lex *l )
{
  int exit_no;
  char buf1[MAX_STRING];
  char buf2[MAX_STRING];

  (void) parse_up_to_separators( l, buf1, ";" );

  expand_meta_chars( l, buf1, buf2 );
  sprintf( buf1, "/bin/ls -FC %s", buf2 );

  if ( lex_ok( l ))
    if ((exit_no = system( buf1 )))
      lex_error( l, "'%s' failed with exit no. %d", buf1, exit_no );
}

static void parse_pwd_command()
{
  char buf[MAX_STRING];
  getcwd( buf, MAX_STRING );

  fprintf( shell_out, "%s\n", buf );
}

static void parse_cd_command( Lex *l )
{
  char *path = parse_full_path( l );

  if ( lex_ok(l) ) {
    if ( strlen( path ) == 0 ) 	/* 'cd;' case */
      path = getenv( "HOME" );	
    if ( strlen( path )==0 || chdir( path ))
      lex_error( l, "Could not change directory to '%s'", path );
  } 
}


/*===[ Echo command ]====================================================*/

static void parse_echo_command( Lex *l )
{
  while ( ( have( l, T_NAME ) || have( l, T_STRING ) ) & lex_ok(l) )
    fprintf( shell_out, "%s ", get_name( l ) );

  if (!lookahead(l, T_SEMI ))
    if (!lookahead( l, T_EOF ) )
      lex_error( l, "Expected ';' or EOF." );
  if ( lex_ok(l) )
    fprintf( shell_out, "\n" );
}

/*===[ Depth command ]====================================================*/

static void parse_depth_command( Lex *l )
{
  if ( lex_ok( l ) ) {
    bed_root_list *roots = shell_parse_root_list( l );

    if ( roots && lex_ok( l ) ) {
      int i;
      IL_ITER( roots, i ) {
	bed_root root = il_elem( roots, i );
	bed_node node = r2n_lookup( root );
	uint res = depth( node );
	
	fprintf( shell_out, "Depth( %s ) : %d\n", lex_quote( shell_root2name( root ) ), res );
      }
    }

    if ( roots ) il_free( roots );
  }
}

/*===[ Foreach command ]====================================================*/

static void parse_foreach_command( Lex *l )
{
  char buf[256];
  char name[64];
  char filename[128];
  bed_root_list* root_list;
  int i;
  Lex *ll;
  FILE *fp;
  int pd = (int) getpid();

  if ( !have(l, T_NAME) ) {
    lex_error( l, "Expected a name." );
    return;
  }

  strncpy( name, get_name( l ), 64 );
  name[63] = '\0';

  if ( have_keyword( l, "in" ) )
    root_list = shell_parse_root_list( l );
  else
    root_list = root_list_sort( ht_2_il( RootNameTable ) );

  if ( root_list == NULL )
    return;

  if ( !have_keyword(l, "do") ) {
    lex_error( l, "Expected 'do'." );
    il_free( root_list );
    return;
  }

  if ( !have(l, T_STRING ) ) {
    lex_error( l, "Expected string." );
    il_free( root_list );
    return;
  }

  sprintf( filename, "/tmp/%d.bed", pd );
  fp = open_file( ll, filename );

  IL_ITER( root_list, i ) {
    bed_root root = il_elem( root_list, i );

    fprintf( fp, "#undef %s\n", name );
    fprintf( fp, "#define %s %s\n", name, lex_quote( shell_root2name( root ) ) );
    fprintf( fp, "%s;\n", get_name(l) );
  }

  close_file( fp );

  il_free( root_list );

  if ( lex_ok( l ) ) {
    ll = lex_open_from_file( filename, LEX_FLAGS );
    ll->errstream = shell_err;

    parse_command( ll );
    lex_close( ll );

    sprintf( buf, "rm -f %s", filename );
    system( buf );
  }
}


/*===[ Parser ]=========================================================*/

static int parse_command( Lex *l )
{
  FILE *err = l->errstream;
  (void) signal( SIGINT, signal_handler );	/* Ctrl-C causes 'signal_handler' to be called */

  if ( setjmp( env )) {
    /* return from control-c -- print warning */
    fprintf( err, "\n*** Command aborted ***\n" );
    kernel_clear_marks();
    return false;
  }
  
  while (! lookahead( l, T_EOF ) && lex_ok( l )) {
    Timer t = timer_start();
    
    /* Remember what command we are about to execute -- this is used in the help 
     * in case of syntax errors 
     */

    char command[128];  
    if ( lookahead( l, T_NAME ))
      strncpy( command, l->current_name, 127 );
    else 
      command[0] = EOL;

    /* Now parse the command */

    if ( have_keyword( l, "exit" ) ||
         have_keyword( l, "quit" ))
      return true;              /* Done -- return to shell if in a script  */

    if ( have_keyword( l, "halt" )) {
      halt_flag = true;		/* Done -- always exit. */
      return true;
    }
      
    else if ( have_keyword( l, "up_one" ) ||
	      have_keyword( l, "upone" ))
      parse_up_one_command( l );

    else if ( have_keyword( l, "verify" ))
      parse_verify_command( l );

    else if ( have_keyword( l, "assert" ))
      parse_assert_command( l );

    else if ( have_keyword( l, "up_all" ) ||
	      have_keyword( l, "upall" ))
      parse_up_all_command( l );

    else if ( have_keyword( l, "up_some" ) ||
	      have_keyword( l, "upsome" ))
      parse_up_some_command( l );

    else if ( have_keyword( l, "help" ) ||
	      have_keyword( l, "man" ))
      parse_help_command( l );

    else if ( have_keyword( l, "clear" ))
      parse_clear_command( l );

    else if ( lookahead_keyword( l, "writeorder" ))
     parse_writeorder_command( l );

    else if ( lookahead_keyword( l, "source" ))
     parse_source_command( l );

    else if ( lookahead_keyword( l, "read" ))
      parse_read_command( l );

    else if ( have_keyword( l, "write" ))
      parse_write_command( l );

    else if ( have_keyword( l, "dump" ))
      parse_dump_command( l );

    else if ( have_keyword( l, "count" ))
      parse_count_command( l );

    else if ( have_keyword( l, "dumpnode" ) ||
	      have_keyword( l, "print" ))
      parse_dumpnode_command( l );

    else if ( have_keyword( l, "check" )) 
      kernel_check( shell_out );

    else if ( have_keyword( l, "support" ))
      parse_support_command( l );
    
    else if ( have_keyword( l, "dot" ))
      parse_dot_command( l );

    else if ( have_keyword( l, "cdot" ))
      parse_cdot_command( l );

    else if ( have_keyword( l, "dimacs" ))
      parse_dimacs_command( l );

    else if ( have_keyword( l, "view" ))
      parse_view_command( l );

    else if ( have_keyword( l, "addvar" ) ||
	     have_keyword( l, "addinput" ) ||
	      have_keyword( l, "var" ))
      parse_addvar_command( l );

    else if ( have_keyword( l, "inputs" ) ||
	      have_keyword( l, "vars" ))
      parse_vars_command( l );

    else if ( have_keyword( l, "outputs" ) ||
	      have_keyword( l, "lets" ) ||
	      have_keyword( l, "roots" ))
      parse_roots_command( l );

    else if ( have_keyword( l, "stat" ))
      parse_stat_command( l );

    else if ( have_keyword( l, "gmc" ))
      parse_gmc_command( l );

    else if ( have_keyword( l, "bedsat" ) )
      parse_satsolve_command( l, bed_one );

    else if ( have_keyword( l, "bedunsat" ) )
      parse_satsolve_command( l, bed_zero );

    else if ( have_keyword( l, "sat" ))
      parse_sat_unsat_command( l, bed_one );

    else if ( have_keyword( l, "unsat" ))
      parse_sat_unsat_command( l, bed_zero );

    else if ( have_keyword( l, "anysat" ))
      parse_sat_command( l, ONE );

    else if ( have_keyword( l, "anynonsat" ))
      parse_sat_command( l, ZERO );

    else if ( have_keyword( l, "satcount" ))
      parse_satcount_command( l );

    else if ( have_keyword( l, "simplify" ))
      parse_simplify_command( l );

    else if ( have_keyword( l, "quantdown" ))
      parse_quantdown_command( l );

    else if ( have_keyword( l, "reachable" ))
      parse_reachable_command( l );

    else if ( have_keyword( l, "order" ))
      parse_order_command( l );

    else if ( have_keyword( l, "gc" ))
      parse_gc_command( l );

    else if ( lookahead_keyword( l, "cd" ))
      parse_cd_command( l );

    else if ( have_keyword( l, "pwd" ))
      parse_pwd_command();

    else if ( lookahead_keyword( l, "ls" ))
      parse_ls_command( l );

    else if ( have_keyword( l, "eval" ))
      parse_eval_command( l );

    else if ( have_keyword( l, "pause" )) {
      fprintf( shell_out, "Type <Return> to continue... " );
      (void) getc( stdin );
    
    }  else if ( have_keyword( l, "set" ))
      parse_set_command( l );

    else if ( have_keyword( l, "unset" ))
      parse_unset_command( l );

    else if ( have_keyword( l, "let" ))
      parse_let_command( l );

    else if ( have_keyword( l, "unlet" ))
      parse_unlet_command( l );

    else if ( have_keyword( l, "echo" ))
      parse_echo_command( l );

    else if ( have_keyword( l, "foreach" ))
      parse_foreach_command( l );

    else if ( have_keyword( l, "depth" ))
      parse_depth_command( l );

    else if ( lookahead( l, (Token) '!' ))
      parse_shell_command( l );

    else if ( have( l, T_NAME )) {
      HashTableElement *p = ht_lookup( Commands, get_name( l ) );
      if ( p != NULL ) {
	void (*fct)(Lex *);
	fct = HT_PTR( p );
	fct( l );
      } else
	lex_error( l, "Unknown command: '%s'", get_name( l ));
    }

    /* Done parsing command -- make sure we are done */

    switch ( lex_err( l )) {
    case LEX_OK: {	/* No errors encountered */
      long cmd_time = timer_get( t );
      if ( cmd_time > display_time * 1000 )
	/* Only the runtime of commands taking longer than display_time secs are displayed */
	timer_stop( t, shell_out, "Command execution time" );

      if ( !have( l, T_EOF ))	/* All commands must end with either EOF or semicolon. */
	mustbe( l, T_SEMI );
      break;
    }
    
    case LEX_ERR_SYNTAX:		/* A syntax error */
      if ( strlen( command ))		
	help_syntax( command, shell_out );
      break;

    default:
      break;
    }
  }

  (void) signal(SIGINT, SIG_IGN);

  return false;
}

static int parse( char *command )
{
  int ret_val;
  
  Lex *l = lex_open_from_string( command, LEX_FLAGS );
  l->errstream = shell_err;

  ret_val = parse_command( l );
  lex_close( l );

  return ret_val;
}

/*===[ Start the shell ]================================================*/

void shell( char *BED_filename, char *command_filename )
{
  init_shell( BED_filename, command_filename );
 
  /* read a command until done */
  {
    char *p;
    Boolean done = false;

    while ( !halt_flag && !done && ( p = getline_( "bed> " )) && *p ) {
      gl_histadd( p );
      done = parse( p );
    }
  }
 
  end_shell();
}
