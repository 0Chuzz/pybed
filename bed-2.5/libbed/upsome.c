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


#include "upsome.h"
#include "bed.h"
#include "kernel.h"
#include "istack.h"
#include "Malloc.h"
#include "cache.h"


static char* up_vector = NULL;
static int up_vector_size = 0;	/* Size in bytes */

static unsigned int up_some_cache_id = 0;



/* Expand the vector to include _size_ bits.
 */
void up_some_expand_vector( int size )
{
  int i;
  int new_size = (size+7)/8;
  char *new_vector = MALLOC_ARRAY( new_size, char );

  /* Vector already long enough */
  if ( new_size == up_vector_size )
    return;

  assert( new_size > up_vector_size );

  if ( up_vector )
    memcpy( new_vector, up_vector, up_vector_size );

  for ( i = up_vector_size; i < new_size; i++ )
    new_vector[i] = 0;

  memset( new_vector+up_vector_size, 0, (new_size - up_vector_size)*sizeof(char) );

  up_some_free_vector();
  up_vector = new_vector;
  up_vector_size = new_size;
}

void up_some_free_vector()
{
  if ( up_vector )
    free( up_vector );
  up_vector = NULL;
  up_vector_size = 0;
}



/* Functions for setting, clearing and testing bits
 */

static void set_var( bed_var var )
{
  register n = var / 8;
  assert( up_vector && ( up_vector_size*8 >= var ) );
  up_vector[ n ] = up_vector[ n ] | ( 1 << (var % 8) );
}

static void clr_var( bed_var var )
{
  register n = var / 8;
  assert( up_vector && ( up_vector_size*8 >= var ) );
  up_vector[ n ] = up_vector[ n ] & ~( 1 << (var % 8) );
}

static Boolean tst_var( bed_var var )
{
  assert( up_vector && ( up_vector_size*8 >= var ) );
  return up_vector[ var / 8 ] & ( 1 << (var % 8) );
}




/* Set new up_some vector to include the variables in _vars_
 */
void up_some_set_vector( iList *vars )
{
  int i;

  assert( up_vector );

  memset( up_vector, 0, up_vector_size*sizeof(char) );
  
  IL_ITER( vars, i )
    set_var( il_elem( vars, i ) );

  if ( 0 == ++up_some_cache_id )
    cache_clear();
}



static inline uint up_some_makenode( bed_var var, uint l, uint h )
{
  if ( ( var == VAR(l) ) && ( IS_VARIABLE( l ) ) )
    l = LOW(l);
  if ( ( var == VAR(h) ) && ( IS_VARIABLE( h ) ) )
    h = HIGH(h);

  return makenode( var, NOP, l, h );
}


uint up_parts( bed_var var, bed_op op, uint l, uint h, Boolean second_time )
{
  uint r;
  register bed_var vl, vh;
  uint ol, oh;
  register Cache *p;
  Boolean vis, lis, his;

  p = cache_get( TAG_UPSOME, var, op, l, h );
  if ( cache_match( p, TAG_UPSOME, var, op, l, h ) && ( up_some_cache_id == p->r2 ) )
    return p->r1;

  ol = l; oh = h;

  if ( ! second_time ) {
    if ( !IS_TERMINAL( l ) )
      l = up_parts( VAR(l), OP(l), LOW(l), HIGH(l), false );
    is_push( ref_stack, l );

    if ( !IS_TERMINAL( h ) )
      h = up_parts( VAR(h), OP(h), LOW(h), HIGH(h), false );
    is_push( ref_stack, h );
  }

  vl = VAR(l);
  vh = VAR(h);

  vis = ( op == NOP ) && tst_var( var );   /* var in set */
  lis = IS_VARIABLE( l ) && tst_var( vl ); /* low in set */
  his = IS_VARIABLE( h ) && tst_var( vh ); /* high in set */

  if ( IS_TERMINAL( l ) && IS_TERMINAL( h ) )
    r = makenode( var, op, l, h );

#ifndef PURE_BED
  else if ( op == EXIST ) {
    if ( IS_TERMINAL( l ) )
      r = l;
    else if ( IS_VARIABLE( l ) && ( var == vl ) )
      r = up_parts( 0, OR, LOW( l ), HIGH( l ), true );
    else if ( tst_var(var) && !lis )
      r = l;
    else if ( !tst_var(var) && !lis )
      r = makenode( var, op, l, h );
    else /* lis */ {
      bed_node tmp1 = is_push( ref_stack, up_parts( var, EXIST, LOW(l), LOW(l), true ));
      bed_node tmp2 = is_push( ref_stack, up_parts( var, EXIST, HIGH(l), HIGH(l), true ));
      r = up_parts( vl, NOP, tmp1, tmp2, true );

      is_popm( ref_stack, 2 );
    }

  } else if ( op == FORALL ) {
    if ( IS_TERMINAL( l ) )
      r = l;
    else if ( IS_VARIABLE( l ) && ( var == vl ) )
      r = up_parts( 0, AND, LOW( l ), HIGH( l ), true );
    else if ( tst_var(var) && !lis )
      r = l;
    else if ( !tst_var(var) && !lis )
      r = makenode( var, op, l, h );
    else /* lis */ {
      bed_node tmp1 = is_push( ref_stack, up_parts( var, FORALL, LOW(l), LOW(l), true ));
      bed_node tmp2 = is_push( ref_stack, up_parts( var, FORALL, HIGH(l), HIGH(l), true ));
      r = up_parts( vl, NOP, tmp1, tmp2, true );

      is_popm( ref_stack, 2 );
    }

  } else if ( op == SUBST ) {

    assert( 0 );	/* XXX: SUBST not ready yet */
#if 0
    if ( var == vl ) {
      uint andl, andh, noth, or;
      noth = is_push( ref_stack, makenode( 0, NPI1, h, h ) );
      andl = is_push( ref_stack, makenode( 0, AND, LOW( l ), noth ) );
      andh = is_push( ref_stack, makenode( 0, AND, HIGH( l ), h ) );
      or = is_push( ref_stack, makenode( 0, OR, andl, andh ) );
      r = up_parts( VAR( or ), OP( or ), LOW( or ), HIGH( or ), false );

      is_popm( ref_stack, 4 );

    } else if ( VARS_IN_ORDER(  var, vl ) ) {
      r = l;

    } else if ( VARS_IN_ORDER( vl, vh ) ) {
      bed_node tmp1 = is_push( ref_stack, up_parts( var, SUBST, LOW(l), h, true ) );
      bed_node tmp2 = is_push( ref_stack, up_parts( var, SUBST, HIGH(l), h, true ) );

      r = up_parts( vl, NOP, tmp1, tmp2, true );

      is_popm( ref_stack, 2 );

    } else {
      bed_node h1 = is_push( ref_stack, up_parts( vl, SUBST, h, ZERO, true ) );
      bed_node h2 = is_push( ref_stack, up_parts( vl, SUBST, h, ONE, true ) );
      bed_node tmp1 = is_push( ref_stack, up_parts( var, SUBST, LOW(l), h1, true ) );
      bed_node tmp2 = is_push( ref_stack, up_parts( var, SUBST, HIGH(l), h2, true ) );

      r = up_parts( vl, NOP, tmp1, tmp2, true );

      is_popm( ref_stack, 4 );

    }
#endif

  } else if ( op == ESUB ) {

    assert( 0 );	/* XXX: ESUB not ready yet */
#if 0
    if ( IS_TERMINAL( l ) )
      r = l;
    else if ( vl % 2 == 0 ) {  /* VAR(l) even */
      bed_node tmp1 = is_push( ref_stack, upall_parts( 0, ESUB, LOW(l), LOW(l), true ) );
      bed_node tmp2 = is_push( ref_stack, upall_parts( 0, ESUB, HIGH(l), HIGH(l), true ) );
      r = upall_parts( 0, OR, tmp1, tmp2, true );

      is_popm( ref_stack, 2 );

    } else { /* VAR(l) odd */
      bed_node tmp1 = is_push( ref_stack, upall_parts( 0, ESUB, LOW(l), LOW(l), true ) );
      bed_node tmp2 = is_push( ref_stack, upall_parts( 0, ESUB, HIGH(l), HIGH(l), true ) );
      r = makenode_upall( vl-1, tmp1, tmp2 );

      is_popm( ref_stack, 2 );
#endif

    }
#endif

  else if ( lis && ( !vis || VARS_IN_ORDER( vl, var ) ) ) {

    if ( his && ( vl == vh ) ) {			/* Pull vl (=vh) up */
      bed tmp1 = is_push(ref_stack,up_parts( var, op, LOW(l), LOW(h), true));
      bed tmp2 = is_push(ref_stack,up_parts( var, op, HIGH(l), HIGH(h), true));
      r = up_some_makenode( vl, tmp1, tmp2 );

      assert( !IS_TERMINAL( l ) );
      assert( !IS_TERMINAL( h ) );

      is_popm( ref_stack, 2 );
    } else if ( his && VARS_IN_ORDER( vh, vl ) ) {	/* Pull vh up */
      bed tmp1 = is_push( ref_stack, up_parts( var, op, l, LOW(h), true ) );
      bed tmp2 = is_push( ref_stack, up_parts( var, op, l, HIGH(h), true ) );
      r = up_some_makenode( vh, tmp1, tmp2 );

      assert( !IS_TERMINAL( h ) );

      is_popm( ref_stack, 2 );
    } else {						/* Pull vl up */
      bed tmp1 = is_push( ref_stack, up_parts( var, op, LOW(l), h, true ) );
      bed tmp2 = is_push( ref_stack, up_parts( var, op, HIGH(l), h, true ) );
      r = up_some_makenode( vl, tmp1, tmp2 );

      assert( !IS_TERMINAL( l ) );

      is_popm( ref_stack, 2 );
    }

  } else if ( his && ( !vis || VARS_IN_ORDER( vh, var ) ) ) { /* Pull vh up */
    bed tmp1 = is_push( ref_stack, up_parts( var, op, l, LOW(h), true ) );
    bed tmp2 = is_push( ref_stack, up_parts( var, op, l, HIGH(h), true ) );
    r = up_some_makenode( vh, tmp1, tmp2 );

    assert( !IS_TERMINAL( h ) );
    
    is_popm( ref_stack, 2 );
  } else {						/* Pull nothing up */
    r = makenode( var, op, l, h );
  }

  if ( ! second_time )
    is_popm( ref_stack, 2 );

  cache_insert( p, TAG_UPSOME, var, op, ol, oh, r, up_some_cache_id );
  return r;
}



/* Pull all variables in the up_vector up in _u_.
 * The up_vector must be defined using up_some_set_vector().
 */
uint up_some( uint u )
{
  assert( up_vector );

  if ( IS_TERMINAL( u ) )
    return u;

  return up_parts( VAR(u), OP(u), LOW(u), HIGH(u), false );
}
