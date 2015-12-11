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

#include <assert.h>
#include <stdio.h>
#include <math.h>

#ifdef PI2
#undef PI2
#endif

#include "kernel.h"
#include "bed.h"
#include "timer.h"

#include "restrict.h"
#include "replace.h"
#include "upall.h"
#include "upone.h"
#include "cache.h"

#include "istack.h"


#ifndef BED_DEFAULT_SIZE
#define BED_DEFAULT_SIZE		200000		/* Approx. 4 MB */
#endif

#ifndef BED_CACHE_DEFAULT_SIZE
#define BED_CACHE_DEFAULT_SIZE		 20000		/* Approx. 0.50 MB */
#endif


/* Global variables */

BED*		bed_array		= NULL;		/* The BED graph */

uint 		kernel_mark_id;
uint		kernel_nodes;
uint		kernel_vars;
uint		kernel_number_of_gc	= 0;		/* Number of garbage collections */

FILE*		kernel_err;

Hashtbl		ref_count_table;			/* Reference counting on roots */
iStack*		ref_stack;				/* Internal reference counting */

unsigned int*	bed_var2level;				/* Map variables to levels */
bed_var*	bed_level2var;				/* Map levels to variables */



#ifdef COLLECT_STATS
uint		number_addnodes			= 0;
uint		number_makenodes		= 0;
uint		number_makenodes_terminal	= 0;
uint		number_upall_parts		= 0;
#endif


/* Invariant for the BED array:
  VAR(ZERO)		= kernel_vars;
  VAR(ONE)		= kernel_vars;
  LOW(ZERO)		= ZERO;
  HIGH(ZERO)		= ZERO;
  LOW(ONE)		= ONE;
  HIGH(ONE)		= ONE;
*/


/* Local variables */

static uint	bed_alloc_size;
static uint     max_nodes_in_use;

static uint     free_list;
static uint     n_free_list;

static Timer	gc_time;

/* 
 * ====[ Initialization, clearing, and freeing of the kernel ]=======================
 */

void kernel_init( unsigned long n, unsigned long c )
{
  assert( sizeof( BED ) <= 20 );

  kernel_err		= stderr;

  if ( n == 0 ) n	= BED_DEFAULT_SIZE;
  if ( c == 0 ) c	= BED_CACHE_DEFAULT_SIZE;
  
  bed_alloc_size	= n;
  bed_array		= MALLOC_ARRAY( bed_alloc_size, BED );

  cache_init( c ); 

  ref_stack = is_new();

  kernel_clear();
}

static void initialize_hash_table_and_free_list()
{
  register int i;

  for ( i=2; i < bed_alloc_size; i++ ) {
    LOW( i )		= i+1;
    OP( i )		= GARBAGE;
    MARK( i )		= 0;
    EXMARK( i )		= 0;
    H( i )		= BED_UNDEFINED;
    NEXT( i )		= BED_UNDEFINED;
  }

  LOW( bed_alloc_size - 1 )	= BED_UNDEFINED;
  free_list		= 2;
  n_free_list		= bed_alloc_size-2;
  max_nodes_in_use	= 2;

  H( 0 )		= BED_UNDEFINED;
  H( 1 )		= BED_UNDEFINED;
  NEXT( 0 )		= BED_UNDEFINED;
  NEXT( 1 )		= BED_UNDEFINED;
}

void kernel_clear()
{
  kernel_nodes		= 2;
  kernel_vars		= 0;
  kernel_mark_id	= 1;
  kernel_number_of_gc	= 0;
  gc_time = 0;

  /* Initialize 0 */
  bed_array[0].var		= kernel_vars;
  bed_array[0].op		= NOP;
  bed_array[0].low		= ZERO;
  bed_array[0].high		= ZERO;
  bed_array[0].mark		= 0;

  /* Initialize 1 */
  bed_array[1].var		= kernel_vars;
  bed_array[1].op		= NOP;
  bed_array[1].low		= ONE;
  bed_array[1].high		= ONE;
  bed_array[1].mark		= 0;

  SET_EXMARK( ZERO );
  SET_EXMARK( ONE );

  initialize_hash_table_and_free_list();

  is_free( ref_stack );
  ref_stack = is_new();

  up_some_free_vector();

  kernel_clear_caches();
}

void kernel_done()
{
  cache_free();
  is_free( ref_stack );
  up_some_free_vector();
  free( bed_array );
}

void kernel_clear_caches()
{
  cache_clear();
}


/* Changes the size of the BED to  newsize  entries */
/* Returns true if possible */
Boolean kernel_resize_bed( long newsize )
{
  BED *newbed;

  if ( ( newsize < bed_alloc_size ) && ( kernel_vars != 0 ) )
    return false;

  if ( newsize == bed_alloc_size )
    return true;

  newbed = (BED*) realloc( (void*) bed_array, newsize*sizeof( BED ) );

  if ( newbed == NULL ) {
    fprintf( stderr, "Not enough memory.\n" );
    return false;
  }

  bed_array = newbed;

  if ( newsize > bed_alloc_size ) {
    register int i;
    for ( i=bed_alloc_size; i < newsize; i++ ) {
      LOW( i )		= i+1;
      OP( i )		= GARBAGE;
      MARK( i )		= 0;
      EXMARK( i )	= 0;
      H( i )		= BED_UNDEFINED;
      NEXT( i )		= BED_UNDEFINED;
    }

    LOW( newsize - 1 )	= free_list;
    free_list		= bed_alloc_size;

    n_free_list		+= newsize - bed_alloc_size;
    bed_alloc_size	= newsize;
    
  } else {
    bed_alloc_size	= newsize;
    initialize_hash_table_and_free_list();
  }

  return true;
}


void kernel_resize_caches( long newsize )
{
  cache_free();
  cache_init( newsize );
}


/* 
 * ====[ Marking ]===============================================================
 */

int kernel_reserve_marks( int n )
{
  int i, old_marks;
  while ( kernel_mark_id > BED_LAST_MARK-n) 
    kernel_clear_marks();

  old_marks = kernel_mark_id;

  for ( i = 0; i < n; i++ )
    kernel_clear_marks();

  return old_marks;
}

void kernel_clear_marks()
{
  kernel_mark_id++;

  if ( kernel_mark_id > BED_LAST_MARK ) {
    register BED *b = bed_array, *b_end = bed_array+kernel_nodes;

    while ( b < b_end )
      (b++)->mark = 0;

    kernel_mark_id = 1;
  }
}


/* 
 * ====[ Hash functions ]===============================================
 */

#if 0
inline static unsigned long pair( unsigned int i, unsigned long j )
{
  register ij = i+j;
  return ((( ij ) * (ij + 1)) >> 1) + i;
}
#else

#define pair( i, j )	( ( (((i)+(j)) * ((i)+(j)+1)) >> 1 ) + (i) )

#endif

#if 0
inline static unsigned int hash3( unsigned int d1, unsigned int d2, unsigned int d3 )
{
  return ( pair( d1, pair( d2, d3 )) % 1088619811 ) % bed_alloc_size;
}
#else

#define hash3(d1, d2, d3)  (( pair( (d1), pair( (d2), (d3) )) % 1088619811 ) % bed_alloc_size)

#endif

inline static uint kernel_hash_node( uint u )
{
  return hash3( KEY( u ), LOW( u ), HIGH( u ) );
}

static void initialize_hash_table( )
{
  register BED *b	= bed_array;
  register BED *b_end	= b + bed_alloc_size;

  for ( ; b < b_end; b++ ) {
    b->H		= BED_UNDEFINED;
    b->next		= BED_UNDEFINED;
  }
}

inline static void H_insert( uint u )
{
  register uint bucket	= kernel_hash_node( u );

  NEXT( u )		= H( bucket );
  H( bucket )		= u;
}

inline static void H_insert_at_bucket( uint u, uint bucket )
{
  NEXT( u )		= H( bucket );
  H( bucket )		= u;
}

inline static void H_remove( uint u )
{
  register uint bucket	= kernel_hash_node( u );

  register uint h	= H( bucket );

  if ( h == u ) {
    H( bucket )	= NEXT( u );
  } else {

    while ( IS_DEFINED( h )) {
      register BED *b = bed_array + h;
    
      if ( u == b->next ) {
	b->next	= NEXT( u );
	return;
      }
      h	= b->next;
    }
    fprintf( kernel_err, "*** Fatal error: Did not find node %d in Hash Table!\n", u );
    assert( 0 ); 
  }  
}

inline static void rehash()
{
  uint i;

  initialize_hash_table();

  /* Rehash H */
  for ( i = 0; i < kernel_nodes; i++ )
    if ( OP( i ) != GARBAGE )
      H_insert( i );
}


/* 
 * ====[ Functions to make nodes ]=========================================
 */

uint addnode( uint var, Op op, uint low, uint high )
{
  register uint u;

  uint key		= KEY_PAIR( var, op );
  uint bucket		= hash3( key, low, high );
  register uint h	= H( bucket );

#if COLLECT_STATS
  number_addnodes++;
#endif

  while ( IS_DEFINED( h )) {
    register BED *b = bed_array + h;

    if ( ( b->var == var ) &&
         ( b->op  == op ) &&
	 ( b->low == low ) &&
	 ( b->high == high ))
      return h;		/* Post-condition: (var,op,low,high) == b->(var,op,low,high) */
    
    h = b->next;
  }

  assert( (op != K0) && (op != K1) );	/* Replacenode() never returns K0 or K1 */
  assert( low < bed_alloc_size );	/* Basic boundary check */
  assert( high < bed_alloc_size );	/* Basic boundary check */
  assert( (op != NPI1) || low == high );/* All negation operators must have low == high */
  assert( op != PI1 );			/* Indirection nodes make no sense */
					/* No operators with terminal children */
  assert( (op == NOP) || (op >= K1) || ( !IS_TERMINAL( low ) && !IS_TERMINAL( high )));
  assert( var <= BED_MAX_VAR );		/* Do we have enough variables ? */
  assert( var < kernel_vars );          /* Legal variable value? */
  assert( op != GARBAGE );		/* No garbage */

  if ( n_free_list > 0 ) {
    u = free_list;

    assert( u < bed_alloc_size );	/* Free_list corrupt? */
    assert( IS_DEFINED( u ) );
    assert( IS_GARBAGE( u ) );

    free_list = LOW( u );
    n_free_list--;
    if ( u >= kernel_nodes )
      kernel_nodes = u+1;
  } else {

    kernel_gc();

    if ( n_free_list > 0 )
      return addnode( var, op, low, high );

    fprintf( kernel_err, "Sorry, out of BED nodes (%u nodes = %3.1f MB was allocated)\n",
	     bed_alloc_size,
	     (unsigned) ((float) (sizeof(BED) * bed_alloc_size))/((float) (1024*1024)) );
    fprintf( kernel_err, "Try allocating more memory.\n" );
    fprintf( kernel_err, "Exiting...\n" );
    exit ( 1 );
  }

  {
    register BED *b = bed_array + u;

    b->var 	= var;
    b->op	= op;
    b->mark	= 0;
    b->low 	= low;
    b->high 	= high;
    b->exmark	= 0;
  }

  H_insert_at_bucket( u, bucket );

  if ( max_nodes_in_use < bed_alloc_size - n_free_list )
    max_nodes_in_use = bed_alloc_size - n_free_list;

  return u;
}

uint mk( uint var, Op op, uint low, uint high )
{
  register uint u;

#if COLLECT_STATS
  number_makenodes++;
  if ( IS_TERMINAL( low ) && IS_TERMINAL( high ) )
    number_makenodes_terminal++;
#endif

  is_push( ref_stack, low );
  is_push( ref_stack, high );

  if ( op == NOP ) {		/* Variable vertex */
    if ( low == high )
      u = low;
    else
      u = addnode( var, op, low, high );
  } else {			/* Operator vertex */
    uint v_, l_, h_;

    Op op_ = replacenode( var, op, low, high, &v_, &l_, &h_ );

    if ( op_ == PI1 )		/* indirection */
      u = l_;
    else if ( op_ == PI2 )	/* indirection */
      u = h_;
    else {
      is_push( ref_stack, l_ );
      is_push( ref_stack, h_ );
      u = addnode( v_, op_, l_, h_ );
      is_popm( ref_stack, 2 );
    }
  }

  assert( OP( u ) != PI1 );
  assert( !IS_GARBAGE( u ));

  is_popm( ref_stack, 2 );

  return u;
}


/* 
 * ====[ Garbage collection ]==============================================
 */

static uint gc_mark_rec( uint u )
{
  assert( IS_VALID_NODE( u ) );
  assert( ! IS_GARBAGE( u ) );

  if ( TST_EXMARK( u ) ) return 0;

  SET_EXMARK( u );

  return gc_mark_rec( LOW( u ) ) + gc_mark_rec( HIGH( u ) ) + 1;
}

static uint gc_mark( uint u )
{
  assert( IS_VALID_NODE( u ) );
  assert( TST_EXMARK( ZERO ) && TST_EXMARK( ONE ) );
  return gc_mark_rec( u );
}

static int exmarkscleared() 
{
  uint u;
  for (u = 2; u < kernel_nodes; u++) if (TST_EXMARK( u )) return 0;
  return 1;
}

static uint update_free_list_stack()
{
  uint u, n=0;

  for ( u=2; u < kernel_nodes; u++ )
    if ( ! (TST_EXMARK( u ) || IS_GARBAGE( u ) ) ) {
      H_remove( u );
      OP( u )	= GARBAGE;
      LOW( u )	= free_list;
      free_list	= u;
      n++;
      n_free_list++;
    } else CLR_EXMARK( u );
  return n;
}

/* Insert ok nodes */
static uint update_free_list2_stack()
{
  uint u, n = 0;
  initialize_hash_table( );
  n_free_list = 0;
  free_list = BED_UNDEFINED;

  for ( u = bed_alloc_size-1; u >= 2; u-- )
    if( TST_EXMARK( u ) ) {
      H_insert( u );
      CLR_EXMARK( u );
    } else {
      if ( !IS_GARBAGE( u )) {
	n++;
	OP( u ) = GARBAGE;
      }
      LOW( u ) = free_list;
      free_list = u;
      n_free_list++;
    }
  return n;
}

void kernel_gc()
{
  uint i, n = 0;
  int *p;
  Timer	t;

  t = timer_start();

  /* Call user function */
  if ( bed_external_gc != NULL )
    bed_external_gc();

  fprintf( kernel_err, "GC [" );

  /* Mark nodes on the ref_count_table as "in use". */
  p = Hashtbl_first( &ref_count_table ); 
  while ( p ) {
    n += gc_mark( *p );
    p = Hashtbl_next( &ref_count_table );
  }

  /* Mark nodes on the internal ref stack */
  IS_ITER( ref_stack, i ) {
    n += gc_mark( is_elem( ref_stack, i ) );
  }

  fprintf( kernel_err, "%d unused of %d (%2.1f%%); ", bed_alloc_size-n-2, bed_alloc_size, ((float) (100*(bed_alloc_size-n-2)))/(float) bed_alloc_size);
  
  if ( n > 2 * ( bed_alloc_size - n_free_list ) / 3 ) {
    n = update_free_list_stack();          /* Remove garbage nodes */
  } else {
    n = update_free_list2_stack();         /* Insert ok nodes */
  }

  kernel_clear_caches();
  kernel_number_of_gc++;

  assert( exmarkscleared() );

  /* Call user function */
  if ( bed_external_gc_post != NULL )
    bed_external_gc_post();

  gc_time += timer_get( t );

  fprintf( kernel_err, "%ld.%03ld seconds]\n", gc_time / 1000, gc_time % 1000 );
}


/* 
 * ====[ Set ordering ]====================================================
 */

void kernel_set_ordering( bed_var *old_level2var )
{
  register uint i;

  for ( i = 0; i < bed_alloc_size; i++ ) {
    H( i ) = BED_UNDEFINED;
    NEXT( i ) = BED_UNDEFINED;
    if ( ! IS_BOOL_OPERATOR( i ) )
      VAR( i ) = bed_var2level[ old_level2var[ VAR( i ) ] ];
  }

  for ( i = 0; i < kernel_nodes; i++ ) {
    if ( !IS_GARBAGE( i ) )
      H_insert( i );
  }

  kernel_clear_caches();
}


/*
 * ====[ Depth-First Search ]==============================================
 */

void kernel_dfs( FILE *fp, bed_node node, void (*fnc)( FILE *, bed_node ) )
{
  if ( TST_MARK( node ) || IS_TERMINAL( node ) )
    return;

  SET_MARK( node );
 
  kernel_dfs( fp, LOW( node ), fnc);
  kernel_dfs( fp, HIGH( node ), fnc);

  fnc( fp, node ); 
}


/* 
 * ====[ Kernel information ]===============================================
 */

bed_info kernel_get_info()
{
  bed_info info;

  info.node_count		= bed_alloc_size - n_free_list;
  info.highest_node_count	= max_nodes_in_use;
  info.number_of_variables	= kernel_vars;
  info.number_of_nodes		= bed_alloc_size;
  info.number_of_gc		= kernel_number_of_gc;
  info.gc_time			= gc_time;

  return info;
}

void kernel_reduction_stat()
{
  reduction_stat( kernel_err );		/* Call a function in replace.c */
}

void kernel_hash_stat()
{
  uint N = 0, min = 0, max = 0, sum = 0, sum2 = 0;
  uint i;
  
  for( i=0; i < bed_alloc_size; i++) {
    uint l = 0, h = bed_array[i].H;

    while ( IS_DEFINED( h ))
      h = bed_array[h].next, l++;

    if ( N == 0 ) {
      max = l; min = l;
    } else {
      max = ( l > max ? l : max );
      min = ( l < min ? l : min );
    }

    sum += l;
    sum2 += l * l;

    N++;
  }

  if ( N < 2 ) 
    fprintf( kernel_err,
	     "BED Hash Statistics: # buckets = %u, min length = %u, max length = %u\n", 
	     bed_alloc_size, min, max );
  else {
    float mean = (float) sum / (float) N;
    float varx = (float) (N*sum2 - sum*sum) / (float) (N * (N-1));
    float std  = sqrt(varx);
    float cv   = mean > 0.0 ? std / mean : -1.0;

    fprintf( kernel_err, "BED Hash Statistics:\n" );
    fprintf( kernel_err, "# buckets:\t%u\n", bed_alloc_size );
    fprintf( kernel_err, "min length:\t%u\n", min );
    fprintf( kernel_err, "max length:\t%u\n", max );
    fprintf( kernel_err, "Average length:\t%4.2f (always between 0 and 1)\n", mean );
    fprintf( kernel_err, "Std. deviation:\t%4.2f\n", std );
    if ( mean > 0.0 )
      fprintf( kernel_err, "Coeff. Var:\t%4.2f%%\n", cv );
    else
      fprintf( kernel_err, "Coeff. Var:\tN/A\n");
  }
}

Boolean kernel_check()
{
  Boolean OK = true;
  uint u, v;
  BED *b;

  kernel_clear_marks();

  for ( u = 0, b = bed_array; u < kernel_nodes; u++, b++ ) {
   if ( !IS_GARBAGE( u )) {
      uint low = LOW( u );
      uint high = HIGH( u );

      if ( TST_MARK( u )) {
	fprintf( kernel_err, "*** Error: MARK( %d ) == 1 -- fixed.\n", u );
	CLR_MARK( u );
	OK = false;
      }
      
      if ( IS_TERMINAL( u ) && ( VAR( u ) != kernel_vars ) ) {
	fprintf( kernel_err, "*** Error: VAR( %d ) == %d != 0 -- fixed. \n", u, VAR( u ) );
	VAR( u ) = 0;
	OK = false;
      }

      if ( IS_TERMINAL( u ) && ( low != u ) ) {
	fprintf( kernel_err, "*** Error: LOW( %d ) == %d != %d -- fixed.\n", u, LOW( u ), u );
	LOW( u ) = u;
	OK = false;
      }

      if ( IS_TERMINAL( u ) && ( high != u ) ) {
	fprintf( kernel_err, "*** Error: HIGH( %d ) == %d != %d -- fixed.\n", u, high, u );
	HIGH( u ) = u;
	OK = false;
      }
     
      if ( low >= kernel_nodes ) {
	fprintf( kernel_err, "*** Error: LOW( %d ) == %d -- out of bounds (max is %d)\n", 
		u, low, kernel_nodes-1 );
	OK = false;
      }

      if ( high >= kernel_nodes ) {
	fprintf( kernel_err, "*** Error: HIGH( %d ) == %d -- out of bounds (max is %d)\n", 
		u, high, kernel_nodes-1 );
	OK = false;
      }

      if ( IS_GARBAGE( low )) {
	fprintf( kernel_err, "*** Error: LOW( %d ) == GARBAGE\n", u );
	OK = false;
      }

      if ( IS_GARBAGE( high )) {
	fprintf( kernel_err, "*** Error: HIGH( %d ) == GARBAGE\n", u );
	OK = false;
      }
    }
  }

  /* Check hash-table */
  for ( u = 0, b = bed_array; u < bed_alloc_size; u++, b++ ) {
    uint h = H( u );

    while ( IS_DEFINED( h ) ) {
      if ( h >= bed_alloc_size ) {
	fprintf( kernel_err, "*** Error: H( %d ) == %d -- out of bounds (max is %d)\n", 
		 u, h, bed_alloc_size-1 );
	OK = false;
      }
      if ( IS_GARBAGE( h )) {
	fprintf( kernel_err, "*** Error: H( %d ) == garbage\n", h ); 
	OK = false;
      }

      h = NEXT( h );
    }
  }

  /* Check free-list */
  {
    int n = 0;
    v = free_list;
    while ( v != BED_UNDEFINED ) {
      n++;
      SET_MARK( v );
      v = LOW( v );
    }

    if ( n != n_free_list ) {
      fprintf( kernel_err, "*** Error: Free_list is actually %d nodes long -- not %d\n", n, n_free_list );
      OK = false;
    }
  }

  for ( u = 0; u < kernel_nodes; u++ ) {
    if ( IS_GARBAGE( u )) {
      if ( !TST_MARK( u )) {
	fprintf( kernel_err, "*** Error: Garbage found in BED at node %d\n", u );
	OK = false;
      }
    } else {
      if ( TST_MARK( u )) {
	fprintf( kernel_err, "*** Error: Non-garbage found on free_list at node %d\n", u );
	OK = false;
      }
    }
  }
  kernel_clear_marks();

  return OK;
}
