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


#include <stdio.h>

#include "bedfsm.h"
#include "bed.h"

#include "kernel.h"		/* to get "ref_stack" */


/* =================================================== */


/* EXIST-CACHE */

typedef struct Exist_Cache {
  uint n;
  uint m;
  uint res1;
  uint res2;
} Exist_Cache;

static Exist_Cache *exist_cache;
static uint c_size;

static void exist_cache_clear()
{
  memset( (char *) exist_cache, 0, c_size * sizeof( Exist_Cache ) );
}

static void exist_cache_init( uint n )
{
  exist_cache = (Exist_Cache *) malloc( n * sizeof( Exist_Cache ) );

  c_size = n;

  exist_cache_clear();
}

static void exist_cache_free()
{
  free( exist_cache );
}

static uint exist_cache_size()
{
  return c_size;
}


#define c_pair( i, j )	( ( (((i)+(j)) * ((i)+(j)+1)) >> 1 ) + (i) )
#define c_hash(d0,d1)	( c_pair((d0),(d1)) % c_size )


static inline void exist_cache_insert( Exist_Cache *p, uint n, uint m, uint res1, uint res2 )
{
  p->n = n;
  p->m = m;
  p->res1 = res1;
  p->res2 = res2;
}

static inline Exist_Cache* exist_cache_get( uint n, uint m )
{
  return exist_cache + c_hash( n, m );
}



/* =================================================== */


static void exist_rec( bed_node b, bed_var i, bed_node *co_pos, bed_node *co_neg )
{
  Exist_Cache *p;
  bed_op op;
  bed_var var;

  if ( IS_TERMINAL( b ) ) {
    *co_pos = b;
    *co_neg = b;
    return;
  }

  p = exist_cache_get( i, b );
  if ( ( p->n == i ) && ( p->m == b ) ) {
    *co_pos = p->res1;
    *co_neg = p->res2;
    return;
  }

  op = OP( b );
  var = VAR( b );

  if ( ( op == BED_NOP ) && ( var == i ) ) {
    *co_pos = HIGH( b );
    *co_neg = LOW( b );
  } else {
    bed_node lpos, lneg, hpos, hneg;

    exist_rec( LOW( b ), i, &lpos, &lneg );
    is_push( ref_stack, lpos );
    is_push( ref_stack, lneg );

    exist_rec( HIGH( b ), i, &hpos, &hneg );
    is_push( ref_stack, hpos );
    is_push( ref_stack, hneg );

    *co_pos = is_push( ref_stack, mk( var, op, lpos, hpos ) );
    *co_neg = mk( var, op, lneg, hneg );

    is_popm( ref_stack, 5 );
  }

  exist_cache_insert( p, i, b, *co_pos, *co_neg );

  return;
}

#if 1

bed_node exist_set( bed_node b, bed_var_list *vars )
{
  int i;

  bed_ref( b );

  IL_ITER( vars, i ) {
    bed_node tmp;

    tmp = bed_ref( bed_mk_exists( il_elem( vars, i ), b ) );
    bed_deref( b );
    b = tmp;
  }

  IL_ITER( vars, i ) {
    bed_node tmp;

    tmp = bed_ref( bed_upone( il_elem( vars, i ), b ) );
    bed_deref( b );
    b = tmp;
  }

  bed_deref( b );
  return b;
}

#else

static int exist_ID = 0;

static bed_node exist_set_rec( bed_node b, int *varmap, int len )
{
  Exist_Cache *p;
  bed_op op;
  bed_var var;
  bed_node res = 0;
  bed_node low, high;

  if ( IS_TERMINAL( b ) )
    return b;

  p = exist_cache_get( exist_ID, b );
  if ( ( p->n == exist_ID ) && ( p->m == b ) )
    return p->res1;

  low = exist_set_rec( LOW(b), varmap, len );
  high = exist_set_rec( HIGH(b), varmap, len );

  op = OP( b );
  var = VAR( b );

  if ( ( op == BED_NOP ) && ( var < len ) && ( varmap[var] != -1 ) )
    res = mk( varmap[var], op, low, high );
  else
    res = mk( var, op, low, high );

  exist_cache_insert( p, exist_ID, b, res, 0 );

  return res;
}

bed_node exist_set( bed_node b, bed_var_list *vars )
{
  int i;
  int len = il_length( vars );
  int new_vars = bed_new_variables( len );
  int *varmap = MALLOC_ARRAY( 2*len, int );

  for ( i = 0; i < 2*len; i++ )
    varmap[i] = -1;

  IL_ITER( vars, i )
    varmap[ il_elem( vars, i ) ] = new_vars + i;

  exist_ID++;
  if ( exist_ID == 0 ) {
    exist_cache_clear();
    exist_ID++;
  }

  b = exist_set_rec( b, varmap, 2*len );

  bed_ref( b );

  IL_ITER( vars, i ) {
    bed_node tmp1, tmp2, tmp3;

    tmp1 = is_push( ref_stack, bed_mk_subst( il_elem( vars, i ), b, ZERO ) );
    tmp2 = is_push( ref_stack, bed_mk_subst( il_elem( vars, i ), b, ONE ) );

    tmp3 = bed_ref( mk( 0, BED_OR, tmp1, tmp2 ) );

    bed_deref( b );
    is_popm( ref_stack, 2 );

    b = tmp3;
  }

  bed_deref( b );
  free( varmap );
  return b;
}

#endif


bed_node exist_var( bed_node b, bed_var var )
{
  bed_node co_pos, co_neg;

  is_push( ref_stack, b );

  exist_rec( b, var, &co_pos, &co_neg );

  is_push( ref_stack, co_pos );
  is_push( ref_stack, co_neg );

  b = mk( 0, BED_OR, co_pos, co_neg );

  is_popm( ref_stack, 3 );

  return b;
}




/* =================================================== */


static bed_node subst_odd_with_even( bed_node b )
{
  Exist_Cache *p;
  bed_op op;
  bed_var var;
  bed_node res, low, high;

  if ( IS_TERMINAL( b ) )
    return b;

  p = exist_cache_get( -1, b );
  if ( ( p->n == -1 ) && ( p->m == b ) )
    return p->res1;

  op = OP( b );
  var = VAR( b );

  low = is_push( ref_stack, subst_odd_with_even( LOW( b ) ) );
  high = is_push( ref_stack, subst_odd_with_even( HIGH( b ) ) );
  
  if ( ( op == BED_NOP ) && ( (var % 2) == 1 ) )
    var--;

  res = bed_mk( var, op, low, high );

  is_popm( ref_stack, 2 );

  exist_cache_insert( p, -1, b, res, 0 );

  return res;
}



/* =================================================== */

void view( bed_node b )
{
  static int view_number = 0;
  char buf[1024];
  FILE *fp;
  int pd = (int) getpid();
  bed_node_list *nodes;

  nodes = il_new();
  il_append( nodes, b );

  view_number++;

  sprintf( buf, "/tmp/%d_%d.dot", pd, view_number );
  fp = fopen( buf, "w" );

  bed_io_graph( fp, nodes );
  il_free( nodes );
  fclose( fp );

  sprintf( buf, "(dot -Tps /tmp/%d_%d.dot > /tmp/%d_%d.ps; ghostview /tmp/%d_%d.ps; \
                 rm -f /tmp/%d_%d.{dot,ps}) &",pd, view_number, pd, view_number, pd,
	   view_number, pd, view_number );

  if ( system( buf ) )
    fprintf( stderr, "Error executing DOT or GHOSTVIEW\n" );

  return;
}

/* =================================================== */


static bed_var_list *support_list;

static void even_support( FILE *fp, bed_node node )
{
  if ( IS_VARIABLE( node )) {
    bed_var var = VAR( node );
    
    if ( (( var % 2 ) == 0) && ! il_has( support_list, var ) )
      il_append( support_list, var );
  }
}


#if 0

#if 1

/* New version -- with partitioned transition relation */

static bed_node upall_disj( bed_node b )
{
  if ( IS_OPERATOR( b ) && ( OP(b) == BED_OR ) ) {
    bed_node l = is_push( ref_stack, upall_disj( LOW(b) ) );
    bed_node h = is_push( ref_stack, upall_disj( HIGH(b) ) );
    bed_node res = bed_mk_op( BED_OR, l, h );
    is_popm( ref_stack, 2 );
    return res;
  };
  return bed_upall( b );
}

static bed_node esub_conj( bed_node R, bed_node T )
{
  if ( IS_OPERATOR( T ) && ( OP(T) == BED_OR ) ) {
    bed_node l = is_push( ref_stack, esub_conj( R, LOW(T) ) );
    bed_node h = is_push( ref_stack, esub_conj( R, HIGH(T) ) );
    bed_node res = bed_mk_op( BED_OR, l, h );
    is_popm( ref_stack, 2 );
    return res;
  } else {
    bed_node tmp, res;
    tmp = is_push( ref_stack, bed_mk_op( BED_AND, R, T ) );
    res = bed_mk_esub( tmp );
    is_popm( ref_stack, 1 );
    return res;
  }
}


bed_node bed_reach_forward( bed_node I, bed_node T )
{
  bed_node C, by;
  bed_node tmp;
  bed_node bx;

  /* Make sure I is a BDD, and that T is a disjunction of BDDs */
  I = bed_upall(I); is_push( ref_stack, I );
  T = upall_disj(T); is_push( ref_stack, T );

  bx = bed_false;
  
  do {
    is_push( ref_stack, bx );

    by = bx;
    C = is_push( ref_stack, esub_conj( bx, T ) );
    tmp = is_push( ref_stack, bed_mk_op( BED_OR, I, C ) );
    bx = bed_upall( tmp );

    is_popm( ref_stack, 3 );

#ifdef REACH_TICKS
    fputc( '.', stdout ); fflush(stdout);
#endif
  } while( bx != by );

#ifdef REACH_TICKS
  fputc( '\n', stdout );
#endif
  is_popm( ref_stack, 2 ); /* I and T */

  return bx;
}


#else

/* New version -- using Staalmarck */

bed_node bed_reach_forward( bed_node I, bed_node T )
{
  bed_node C, by;
  bed_node tmp1, tmp2;
  bed_node bx;

  Boolean done;

  int i;
  bed_var_list *even;

#if 1
  even = il_new();
  for ( i = 0; i < bed_get_info().number_of_variables; i+=2 )
    il_append( even, i );
#else
  support_list = il_new();
  kernel_dfs( stdout, T, even_support );
  kernel_clear_marks();
  even = support_list;
#endif

  exist_cache_init( 10240 );

#if 1
  upstep_cache_init( 51200 );
  //  bed_external_gc = upstep_cache_clear;
#endif

  bed_external_gc = exist_cache_clear;

  bx = I;

  i = 1;
  
  do {
    is_push( ref_stack, bx );

    by = bx;
    tmp1 = bed_mk_op( BED_AND, T, bx );
    is_push( ref_stack, tmp1 );

    tmp2 = exist_set( tmp1, even );
    is_push( ref_stack, tmp2 );

    C = subst_odd_with_even( tmp2 );
    is_push( ref_stack, C );

    bx = bed_mk_op( BED_OR, I, C );
    is_push( ref_stack, bx );

#if 0
    tmp1 = minimize( 1, bx );
    is_popm( ref_stack, 1 );
    is_push( ref_stack, tmp1 );
    bx = tmp1;
#endif

#if 1
    tmp1 = quantdown( bx );
    is_popm( ref_stack, 1 );
    is_push( ref_stack, tmp1 );
    bx = tmp1;
#endif

#ifdef REACH_TICKS
    fputc( '*', stdout ); fflush(stdout);
#endif

    if ( (i++ % 24) == 0 ) {
        tmp1 = bed_mk_op( BED_IMP, bx, by );

#if 0
	tmp2 = random_simulate( tmp1, 128 );
	if ( tmp2 ==  ONE )
	  tmp2 = staalmarck( tmp1 );
#else
	tmp2 = staalmarck( tmp1 );
#endif
	done = ( tmp2 == ONE); // bx == by
    } else {
#if 0
      bed_node over, under;
      approx( bx, 35, &over, &under );
      is_popm( ref_stack, 1 );
      is_push( ref_stack, under );
      bx = under;
#endif
      done = false;
    }

    is_popm( ref_stack, 5 );
  } while( !done );

#ifdef REACH_TICKS
  fputc( '\n', stdout );
#endif

  bed_external_gc = NULL;
  exist_cache_free();
  il_free( even );

#if 1
  bed_external_gc = NULL;
  upstep_cache_free();
#endif

  return bx;
}

#endif

#else

/* Old version */

bed_node bed_reach_forward( bed_node I, bed_node T )
{
  bed_node bx, by, C, tmp;

  /* The code below assumes I and T are BDDs, so we first ensure
     that they are. */

  I = bed_upall(I); is_push( ref_stack, I );
  T = bed_upall(T); is_push( ref_stack, T );

  bx = I;
  
  do {
    is_push( ref_stack, bx );

    by = bx;
    tmp = bed_apply( BED_AND, T, bx );
    is_push( ref_stack, tmp );

    C = bed_apply( BED_ESUB, tmp, tmp );
    is_push( ref_stack, C );

    bx = bed_apply( BED_OR, I, C );

    is_popm( ref_stack, 3 );
#ifdef REACH_TICKS
    fputc( '.', stdout ); fflush(stdout);
#endif
  } while( bx != by );

#ifdef REACH_TICKS
  fputc( '\n', stdout );
#endif
  is_popm( ref_stack, 2 ); /* I and T */

  return bx;
}

#endif
