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


#include <string.h>

#include "bedio.h"
#include "bed.h"
#include "kernel.h"
#include "lex.h"
#include "op.h"

#include "cb.h"
#include "hash.h"
#include "Malloc.h"


/* Global variables */

Boolean		bed_io_dot_draw_to_zero		= true;
Boolean		bed_io_dot_print_node_numbers	= true;

float		bed_io_dot_ranksep		= 0.4;
float		bed_io_dot_nodesep		= 0.1;
int		bed_io_dot_fontsize		= 10;
float		bed_io_dot_margin		= 0.4;
char*		bed_io_dot_ratio		= "auto";


/* Local variables */

static int	view_number			= 0;


/*
 * ====[ Graph (dot) ]=====================================================
 */

static void dot_start( FILE *fp )
{
  fprintf( fp, "digraph BED {\n" );
  fprintf( fp, "  page = \"8.25,11.0\";\n" );
  fprintf( fp, "  size = \"%3.2f,%3.2f\";\n", 8.25 - bed_io_dot_margin,
	   11.0 - bed_io_dot_margin );
  fprintf( fp, "  ranksep = %3.1f;\n", bed_io_dot_ranksep );
  fprintf( fp, "  nodesep = %3.1f;\n", bed_io_dot_nodesep );
  fprintf( fp, "  fontsize = %d;\n", bed_io_dot_fontsize );
  fprintf( fp, "  margin = %3.1f;\n", bed_io_dot_margin );
  fprintf( fp, "  ratio = %s; /* Alternatives: auto, compress, fill */\n", bed_io_dot_ratio );
}

static void dot_end( FILE *fp )
{
  fprintf( fp, "}\n" );
}

static void dot_node( FILE *fp, bed_node u )
{
  if ( bed_io_dot_print_node_numbers )
    fprintf( fp, "   %d [label = \"%s: ", u, bed_node2name( u ) );
  else
    fprintf( fp, "   %d [label = \"", u );

  if ( IS_VARIABLE( u ))
    fprintf( fp, "%s", bed_var2name( VAR( u ) ) );
  else {
    if ( OP( u ) == EXIST ) {
      fprintf( fp, "? %s", bed_var2name( VAR( u ) ) );
    } else if ( OP( u ) == FORALL ) {
      fprintf( fp, "! %s", bed_var2name( VAR( u ) ) );
    } else if ( OP( u ) == SUBST ) {
      fprintf( fp, "%s :=", bed_var2name( VAR( u ) ) );
    } else
      fprintf( fp, "%s", op2string( OP( u )));
  }
 
  fprintf( fp, "\" ];\n" );

  if ( bed_io_dot_draw_to_zero || ( LOW( u ) != ZERO ) )
    fprintf( fp, "   %d -> %d [style=dotted];\n", u, LOW( u ));
  if ( bed_io_dot_draw_to_zero || ( HIGH( u ) != ZERO ) )
    fprintf( fp, "   %d -> %d;\n", u, HIGH( u ));
}

void bed_io_graph( FILE *fp, bed_node_list *nodes )
{
  int i;
  Boolean seen_ZERO = false, seen_ONE = false;

  dot_start( fp );

  for ( i = 0; i < il_length( nodes ); i++ ) {
    bed_node s = il_elem( nodes, i );
    if ( s == ZERO )
      seen_ZERO = true;
    else if ( s == ONE )
      seen_ONE = true;
    else
      seen_ZERO = true, seen_ONE = true;
  }

  if ( seen_ZERO & bed_io_dot_draw_to_zero )
    fprintf( fp, "  0 [shape=box];\n" );
  if ( seen_ONE )
    fprintf( fp, "  1 [shape=box];\n" );

  for ( i = 0; i < il_length( nodes ); i++ ) {
    bed_node s = il_elem( nodes, i );
    kernel_dfs( fp, s, dot_node );
  }
  kernel_clear_marks();

  dot_end( fp );
}


static dfs_red( FILE *fp, bed_node u, int mark )
{
  if ( ( kernel_get_mark(u) == mark ) || IS_TERMINAL( u ) )
    return;

  kernel_set_mark( u, mark );

  dfs_red( fp, LOW( u ), mark );
  dfs_red( fp, HIGH( u ), mark );
}


static dfs_blue( FILE *fp, bed_node u, int mark )
{
  int thismark = kernel_get_mark( u );
  if ( ( thismark == mark+1 ) ||
       ( thismark == mark+2 ) || IS_TERMINAL( u ) )
    return;

  if ( thismark == mark )
    kernel_set_mark( u, mark+2 );
  else
    kernel_set_mark( u, mark+1 );

  dfs_blue( fp, LOW( u ), mark );
  dfs_blue( fp, HIGH( u ), mark );
}


static dfs_purple( FILE *fp, bed_node u, int mark )
{
  int thismark = kernel_get_mark( u );
  if ( ( thismark == mark+3 ) || IS_TERMINAL( u ) )
    return;

  fprintf( fp, "   %d [label=\"\", style=filled, ", u );

  if ( thismark == mark )
    fprintf( fp, "color=red" );
  else if ( thismark == mark+1 )
    fprintf( fp, "color=blue" );
  else if ( thismark == mark+2 )
    fprintf( fp, "color=purple" );
  else
    fprintf( fp, "color=black" );

  fprintf( fp, "];\n" );

  if ( bed_io_dot_draw_to_zero || ( LOW( u ) != ZERO ) )
    fprintf( fp, "   %d -> %d [style=dotted];\n", u, LOW( u ));
  if ( bed_io_dot_draw_to_zero || ( HIGH( u ) != ZERO ) )
    fprintf( fp, "   %d -> %d;\n", u, HIGH( u ));


  kernel_set_mark( u, mark+3 );

  dfs_purple( fp, LOW( u ), mark );
  dfs_purple( fp, HIGH( u ), mark );
}


void bed_io_color_graph( FILE *fp, bed_node u, bed_node red, bed_node blue )
{
  int i;
  int colormark;

  dot_start( fp );

  /* Reserve marks for the colors:
     +0 : red, +1 : blue, +2 : purple, +3 : clear
  */
  colormark = kernel_reserve_marks( 4 );

  if ( bed_io_dot_draw_to_zero )
    fprintf( fp, "  0 [label=\"\", style=filled, shape=box, color=purple];\n" );
  fprintf( fp, "  1 [label=\"\", style=filled, shape=box, color=purple];\n" );

  dfs_red( fp, red, colormark );
  dfs_blue( fp, blue, colormark );
  dfs_purple( fp, u, colormark );

  kernel_clear_marks();

  dot_end( fp );
}


/*
 * ====[ Print node ]==================================================
 */

void bed_io_print_node( FILE *fp, bed_node node )
{
  char var[256];
  char op[16];
  char low[256];
  char high[256];

  if ( ( node == bed_true ) || ( node == bed_false ) ) {
    fprintf( fp, "%s: %s\n", bed_node2name( node ), (node==bed_true)?"1":"0" );
    return;
  }

  strcpy( var, bed_var2name( VAR( node ) ) );
  strcpy( op, bed_op2name( OP( node ) ) );

  if ( ( LOW( node ) == bed_true ) || LOW( node ) == bed_false )
    sprintf( low, "%d", LOW( node ) );
  else
    strcpy( low, bed_node2name( LOW( node ) ) );

  if ( ( HIGH( node ) == bed_true ) || HIGH( node ) == bed_false )
    sprintf( high, "%d", HIGH( node ) );
  else
    strcpy( high, bed_node2name( HIGH( node ) ) );

  if ( IS_VARIABLE( node ))
    fprintf( fp, "%s: %s -> %s, %s\n", bed_node2name( node ), var, high, low ); 

  else if ( OP( node ) == SUBST )
    fprintf( fp, "%s: %s [%s:=%s]\n", bed_node2name( node ), low, var, high );

  else if ( OP( node ) == EXIST )
    fprintf( fp, "%s: ? %s . %s\n", bed_node2name( node ), var, low );

  else if ( OP( node ) == FORALL )
    fprintf( fp, "%s: ! %s . %s\n", bed_node2name( node ), var, low );

  else if ( op_arity( OP( node )) == 1 )
    fprintf( fp, "%s: %s %s\n", bed_node2name( node ), op, low );

  else
    fprintf( fp, "%s: %s %s %s\n", bed_node2name( node ), low, op, high );
}


/*
 * ====[ BED write ]=======================================================
 */


static void io_write_variables( FILE *fp )
{
  bed_var var;
  int n = bed_get_info().number_of_variables;
  fprintf( fp, "inputs\n" );

  for ( var = 0; var < n; var++ ) {
    fprintf( fp, "%s ", lex_quote( bed_var2name( var ) ) );
    if ( (var % 10) == 9 )
      fprintf( fp, "\n" );
  }

  fprintf( fp, "\n" );
}

static Boolean op_has_var( bed_op op )
{
  if ( ( op == BED_VAR ) || ( op == BED_EXISTS ) || ( op == BED_FORALL ) || ( op == BED_SUBST ) )
    return true;

  return false;
}

static void io_write_one_node( FILE *fp, bed_node node )
{
  bed_op op = bed_get_op( node );

  fprintf( fp, "%d\t", node );

  if ( op_has_var( op ) )
    fprintf( fp, "%s", lex_quote( bed_var2name( bed_get_var( node ) ) ) );
  else
    fprintf( fp, "-" );

  fprintf( fp, "\t%s\t%d\t%d\n",
	   bed_op2name( op ),
	   bed_get_low( node ),
	   bed_get_high( node ) );
}

static void io_write_assigns( FILE *fp, bed_io_root_entry* nodes )
{
  fprintf( fp, "assign\n" );

  while( nodes != NULL ) {
    kernel_dfs( fp, nodes->root, io_write_one_node );
    nodes = nodes->next;
  }

  kernel_clear_marks();
}

static void io_write_outputs( FILE *fp, bed_io_root_entry* nodes )
{
  fprintf( fp, "outputs\n" );

  while( nodes != NULL ) {
    fprintf( fp, "%s\t%d\n", lex_quote( nodes->name ), nodes->root );
    nodes = nodes->next;
  }
}

void bed_io_write( FILE *fp, bed_io_root_entry* nodes )
{
  fprintf( fp, "/* BED data file (%s) */\n\n", bed_version() );

  io_write_variables( fp );
  io_write_assigns( fp, nodes );
  io_write_outputs( fp, nodes );
}



/*
 * ====[ BED read ]=======================================================
 */

static HashTable* io_read_variables( Lex *l, bed_io_read_info *info )
{
  int i = 0;
  HashTable *ht = ht_new( 256 );

  bed_io_var_entry *last, *v;

  info->vars = last = NULL;

  mustbe_keyword( l, "inputs" );

  while ( ( lex_ok( l ) ) && !have_keyword( l, "assign" ) ) {
    if ( !have( l, T_NAME ) )
      mustbe( l, T_STRING );

    v = MALLOC( bed_io_var_entry );

    if ( i == 0 )
      info->vars = v;
    else
      last->next = v;

    v->name = strdup( get_name( l ) );
    v->var = i;
    v->next = NULL;
    last = v;

    ht_insert_int( ht, v->name, i++ );
  }

  if ( kernel_vars < i )
    bed_new_variables( i-kernel_vars );

  return ht;
}

static HashTable* io_read_assigns( Lex *l, HashTable *ht_vars )
{
  bed_var var = 0;
  bed_op op;
  bed_node node, low, high;

  HashTable *ht = ht_new( 256 );

  HashTableElement *p;

  ht_insert_int( ht, "0", 0 );
  ht_insert_int( ht, "1", 1 );

  while ( ( lex_ok( l ) ) && !have_keyword( l, "outputs" ) ) {
    /* Node ID */
    mustbe( l, T_INTEGER );
    if ( ! lex_ok( l ) )
      return ht;
    node = get_int( l );

    /* Variable */
    if ( have( l, T_MINUS ) )
      var = 0;
    else {
      if ( have( l, T_NAME ) || have( l, T_STRING ) ) {
	if ( ! lex_ok( l ) )
	  return ht;

	p = ht_lookup( ht_vars, get_name( l ) );
	if ( p == NULL ) {
	  lex_error( l, "Unknown variable '%s'", get_name( l ) );
	  return ht;
	} else
	  var = HT_VALUE( p );
      } else {
	mustbe( l, T_INTEGER );

	if ( ! lex_ok( l ) )
	  return ht;

	var = get_int( l );
      }
    }

    /* Operator */ 
    if ( have( l, T_COLON ) ) {
      mustbe( l, T_EQU );
      op = BED_SUBST;
    } else if ( have( l, T_QUEST ) ) {
      op = BED_EXISTS;
    } else if ( have( l, '!' ) ) {
      op = BED_FORALL;
    } else {
      if ( !have( l, T_NAME ) )
	mustbe( l, T_STRING );
      if ( ! lex_ok( l ) )
	return ht;
      op = string2op( get_name( l ) );
      if ( op == GARBAGE ) {
	lex_error( l, "Unknown operator '%s'", get_name( l ) );
	return ht;
      }
    }
   
    /* Low */
    mustbe( l, T_INTEGER );
    if ( ! lex_ok( l ) )
      return ht;
    low = get_int( l );
       
    /* High */
    mustbe( l, T_INTEGER );
    if ( ! lex_ok( l ) )
      return ht;
    high = get_int( l );

    if ( lex_ok( l ) ) {
      char name[256];
      char name_low[256];
      char name_high[256];
      sprintf( name, "%d", node );
      sprintf( name_low, "%d", low );
      sprintf( name_high, "%d", high );

      p = ht_lookup( ht, name_low );
      if ( p == NULL )
	lex_error( l, "Unknown node '%d'", low );
      else
	low = HT_VALUE( p );

      p = ht_lookup( ht, name_high );
      if ( p == NULL ) {
	lex_error( l, "Unknown node '%d'", high );
	return ht;
      } else
	high = HT_VALUE( p );

      ht_insert_int( ht, name, bed_mk( var, op, low, high ) );
    }
  }

  return ht;
}

static void io_read_outputs( Lex *l, HashTable *ht_nodes, bed_io_read_info *info )
{
  unsigned int i = 0;
  bed_io_root_entry *first = NULL, *last = NULL;

  while ( lex_ok( l ) && ! have( l, T_EOF ) ) {
    bed_io_root_entry *r;
    char name[256];

    if ( !have( l, T_NAME ) )
      mustbe( l, T_STRING );

    r = MALLOC( bed_io_root_entry );

    if ( first == NULL )
      first = r;
    else
      last->next = r;

    last = r;
    r->next = NULL;
    r->name = strdup( get_name( l ) );

    mustbe( l, T_INTEGER );

    sprintf( name, "%d", get_int( l ) );
    r->root = HT_VALUE( ht_lookup( ht_nodes, name ) );

    i++;
  }

  info->roots = first;
}

bed_io_read_info* bed_io_read( char *filename )
{
  unsigned int ngc;
  HashTable *ht_vars, *ht_nodes;
  bed_io_read_info* info = MALLOC( bed_io_read_info );

  Lex *l = lex_open_from_file( filename, 0 );

  /*  bed_clear(); */

  ngc = bed_get_info().number_of_gc;

  ht_vars = io_read_variables( l, info );
  ht_nodes = io_read_assigns( l, ht_vars );
  io_read_outputs( l, ht_nodes, info );

  if ( !lex_ok( l ) || ( ngc != bed_get_info().number_of_gc ) ) {
    /*    bed_clear(); */
    bed_io_read_done( info );
    info = NULL;
  }

  ht_free( ht_vars );
  ht_free( ht_nodes );
  lex_close( l );

  return info;
}

void bed_io_read_done( bed_io_read_info *info )
{
  bed_io_var_entry *var;
  bed_io_root_entry *root;

  if ( info == NULL )
    return;

  var = info->vars;

  while ( var != NULL ) {
    bed_io_var_entry *v = var->next;
    if ( var->name != NULL )
      free( var->name );
    free( var );
    var = v;
  }

  root = info->roots;

  while ( root != NULL ) {
    bed_io_root_entry *r = root->next;
    if ( root->name != NULL )
      free( root->name );
    free( root );
    root = r;
  }

  free( info );
}



/*
 * ====[ BED view ]=======================================================
 */

/*
  This function requires 'dot' and 'ghostview'.
 */


void bed_io_view( bed_node node )
{
  char buf[1024];
  FILE *fp;
  int pd = (int) getpid();

  view_number++;

  sprintf( buf, "/tmp/%d_%d.dot", pd, view_number );
  fp = fopen( buf, "w" );
  if ( fp ) {
    bed_node_list *nodes = il_new();
    il_append( nodes, node );

    bed_io_graph( fp, nodes );

    sprintf( buf, "(dot -Tps /tmp/%d_%d.dot > /tmp/%d_%d.ps;"
	     "ghostview /tmp/%d_%d.ps;"
	     "rm -f /tmp/%d_%d.{dot,ps}) &",
	     pd, view_number, pd, view_number, pd, view_number, pd, view_number );

    if ( system( buf ) )
      fprintf( stderr, "Error executing DOT or GHOSTVIEW.\n" );

    if ( nodes ) il_free( nodes );
  }
  
  fclose( fp );
}



/*
 * ====[ DIMACS ]=======================================================
 */

/* Outputs a bed in the DIMACS format. Extra variables are introduced
 * to avoid an exponential blowup. However, the resulting DIMACS file
 * is satisfiable iff the original formula is.
 */

#define dimacs_map_node( n )	io_dimacs_map_node(n)
#define dimacs_map_var( n )	((n)+1)

static int clause_count;
static int node_count;

static int *map_node_array;
static int *map_node_array2;
static int map_node_array_size;
static int map_node_next;

static void io_dimacs_map_node_insert( FILE *fp, bed_node n )
{
  /* Node n is NOT in the map array */

  int i, j;

  j = n % map_node_array_size;
  i = j;

  do {
    if ( map_node_array[i] == 0 ) {
      map_node_array[i] = map_node_next++;
      map_node_array2[i] = n;
      return;
    }

    i = ( i+1 ) % map_node_array_size;
  } while ( i != j );

  assert( 0 );	/* No free entries */
}

static int io_dimacs_map_node( bed_node n )
{
  int i, j;

  j = n % map_node_array_size;
  i = j;

  do {
    if ( ( map_node_array2[i] == n ) && ( map_node_array[i] != 0 ) )
      return map_node_array[i];
    else if ( map_node_array[i] == 0 ) {
      assert( 0 );	/* Node not found */
    }

    i = ( i+1 ) % map_node_array_size;
  } while ( i != j );

  assert( 0 );	/* Node not found */
  return 0;
}

static void io_dimacs_map_node_init( bed_node n )
{
  int i;

  map_node_array_size = 2*node_count;
  map_node_array = MALLOC_ARRAY( map_node_array_size, int );
  map_node_array2 = MALLOC_ARRAY( map_node_array_size, int );

  for ( i = 0; i < map_node_array_size; i++ )
    map_node_array[i] = 0;

  map_node_next = kernel_vars;

  kernel_dfs( NULL, n, io_dimacs_map_node_insert );
  kernel_clear_marks();
}

static void io_dimacs_map_node_done()
{
  free( map_node_array );
  free( map_node_array2 );
}



static void io_dimacs_clause( FILE *fp, int v1, int v2, int v3 )
{
  clause_count++;
  if ( fp == NULL )
    return;

  if ( v1 ) fprintf( fp, "%d ", v1 );
  if ( v2 ) fprintf( fp, "%d ", v2 );
  if ( v3 ) fprintf( fp, "%d ", v3 );
  fprintf( fp, "0\n" );
}

static void io_dimacs( FILE *fp, bed_node node )
{
  int u, l, h, v;

  assert( IS_VALID_NODE( node ) );
  assert( !IS_GARBAGE( node ) );
  assert( IS_VARIABLE( node ) || IS_BOOL_OPERATOR( node ) );

  u = dimacs_map_node( node );
  v = dimacs_map_var( VAR( node ) );

  if ( IS_VARIABLE( LOW( node ) ) && ( IS_TERMINAL( LOW( LOW( node ) ) ) )
       && ( IS_TERMINAL( HIGH( LOW( node ) ) ) ) ) {
    if ( LOW( LOW( node ) ) == ZERO )
      l = dimacs_map_var( VAR( LOW( node ) ) );
    else
      l = -dimacs_map_var( VAR( LOW( node ) ) );
  } else if ( !IS_TERMINAL( LOW( node ) ) )
    l = dimacs_map_node( LOW( node ) );
  else
    l = 0;


  if ( IS_VARIABLE( HIGH( node ) ) && ( IS_TERMINAL( LOW( HIGH( node ) ) ) )
       && ( IS_TERMINAL( HIGH( HIGH( node ) ) ) ) ) {
    if ( LOW( HIGH( node ) ) == ZERO )
      h = dimacs_map_var( VAR( HIGH( node ) ) );
    else
      h = -dimacs_map_var( VAR( HIGH( node ) ) );
  } else if ( !IS_TERMINAL( HIGH( node ) ) )
    h = dimacs_map_node( HIGH( node ) );
  else
    h = 0;


  switch( OP( node ) ) {
  case BED_NOP:
    if ( ! ( ( IS_TERMINAL( LOW( node ) ) && IS_TERMINAL( HIGH( node ) ) ) ) ) {
      io_dimacs_clause( fp, -u, v, l );
      io_dimacs_clause( fp, -u, -v, h );
      io_dimacs_clause( fp, -u, l, h );
      io_dimacs_clause( fp, u, -v, -h );
      io_dimacs_clause( fp, u, v, -l );
    }
    break;
  case BED_AND:
    io_dimacs_clause( fp, -u, l, 0 );
    io_dimacs_clause( fp, -u, h, 0 );
    io_dimacs_clause( fp, u, -l, -h );
    break;
  case BED_NAND:
    io_dimacs_clause( fp, u, l, 0 );
    io_dimacs_clause( fp, u, h, 0 );
    io_dimacs_clause( fp, -u, -l, -h );
    break;
  case BED_OR:
    io_dimacs_clause( fp, -u, l, h );
    io_dimacs_clause( fp, u, -l, 0 );
    io_dimacs_clause( fp, u, -h, 0 );
    break;
  case BED_NOR:
    io_dimacs_clause( fp, u, l, h );
    io_dimacs_clause( fp, -u, -l, 0 );
    io_dimacs_clause( fp, -u, -h, 0 );
    break;
  case BED_BIIMP:
    io_dimacs_clause( fp, -u, -l, h );
    io_dimacs_clause( fp, -u, l, -h );
    io_dimacs_clause( fp, u, l, h );
    io_dimacs_clause( fp, u, -l, -h );
    break;
  case BED_XOR:
    io_dimacs_clause( fp, u, -l, h );
    io_dimacs_clause( fp, u, l, -h );
    io_dimacs_clause( fp, -u, l, h );
    io_dimacs_clause( fp, -u, -l, -h );
    break;
  case BED_IMP:
    io_dimacs_clause( fp, -u, -l, h );
    io_dimacs_clause( fp, u, l, 0 );
    io_dimacs_clause( fp, u, -h, 0 );
    break;
  case BED_NIMP:
    io_dimacs_clause( fp, u, -l, h );
    io_dimacs_clause( fp, -u, l, 0 );
    io_dimacs_clause( fp, -u, -h, 0 );
    break;
  case BED_LIMP:
    io_dimacs_clause( fp, -u, l, -h );
    io_dimacs_clause( fp, u, -l, 0 );
    io_dimacs_clause( fp, u, h, 0 );
    break;
  case BED_NLIMP:
    io_dimacs_clause( fp, u, l, -h );
    io_dimacs_clause( fp, -u, -l, 0 );
    io_dimacs_clause( fp, -u, h, 0 );
    break;
  case BED_NPI1:
    io_dimacs_clause( fp, u, l, 0 );
    io_dimacs_clause( fp, -u, -l, 0 );
    break;
  default:
    fprintf( stderr, "Error writing dimacs file\n" );
    assert( 0 );
  }
}

void bed_io_dimacs( FILE *fp, bed_node node )
{
  bed_var_list *sup;

  /* Count number of clauses & number of nodes */
  clause_count = 0;
  node_count = bed_node_count( node );

  io_dimacs_map_node_init( node );

  kernel_dfs( NULL, node, io_dimacs );
  kernel_clear_marks();

  sup = bed_support( node );

  fprintf( fp, "p cnf %d %d\n", map_node_next, clause_count+1 );

  il_free( sup );

  /* Output clauses */
  kernel_dfs( fp, node, io_dimacs );
  kernel_clear_marks();

  /* The top vertex must be true */
  fprintf( fp, "%d 0\n", dimacs_map_node( node ) );

  io_dimacs_map_node_done();
}
