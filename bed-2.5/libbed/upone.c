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


#include "upone.h"
#include "upall.h"
#include "bed.h"
#include "kernel.h"
#include "istack.h"
#include "Malloc.h"
#include "cache.h"


/* Local variables */

static iList*	support_list;

/* Determines how upone works.
 *
 * TAG_UPONE_ORDER: Upone pulls variables up until they fit the ordering.
 * TAG_UPONE_STRICT: Upone pulls variables up to the root.
 *
 * Use set_upone_mode() to change its value.
 */
static unsigned char upone_tag	= TAG_UPONE_ORDER;




/* ===[ Without ]================================================================= */


uint without( uint a, uint b )
{
  uint r;
  if ( a == ZERO )
    r = ZERO;
  else if ( b == ONE )
    r = ZERO;
  else if ( a == b )
    r = ZERO;
  else if ( b == ZERO )
    return a;
  else if ( a == ONE ) {
    uint bb = is_push( ref_stack, without( ONE, LOW( b ) ) );
    r = makenode( VAR(b), NOP, bb, ZERO );
    is_popm( ref_stack, 1 );
  } else if ( VAR( a ) == VAR( b ) ) {
    uint g0 = is_push( ref_stack, without( LOW( a ), LOW( b ) ) );
    uint g1 = is_push( ref_stack, makenode( 0, OR, LOW( b ), HIGH( b ) ) );
    uint g2 = is_push( ref_stack, without( HIGH( a ), g1 ) );
    r = makenode( VAR( a ), NOP, g0, g2 );
    is_popm( ref_stack, 3 );
  } else if ( VARS_IN_ORDER( VAR( a ), VAR( b ) ) ) {
    uint w0 = is_push( ref_stack, without( LOW( a ), b ) );
    uint w1 = is_push( ref_stack, without( HIGH( a ), b ) );
    r = makenode( VAR( a ), NOP, w0, w1 );
    is_popm( ref_stack, 2 );
  } else /* ( VARS_IN_ORDER( VAR( b ), VAR( a ) ) ) */ {
    uint w = is_push( ref_stack, without( a, LOW( b ) ) );
    r = makenode( VAR( b ), NOP, w, ZERO );
    is_popm( ref_stack, 1 );
  }

  return r;
}




/* ===[ Up_one ]================================================================== */


void set_upone_mode( unsigned char tag )
{
  upone_tag = tag;
}

unsigned char get_upone_mode()
{
  return upone_tag;
}



static inline uint makenode_upone( uint var, uint l, uint h )
{
  if ( ( var == VAR(l) ) && ( IS_VARIABLE( l ) ) )
    l = LOW(l);
  if ( ( var == VAR(h) ) && ( IS_VARIABLE( h ) ) )
    h = HIGH(h);

  return makenode( var, NOP, l, h );
}

static void upone_parts( uint x, uint u, uint *res_l, uint *res_h )
{
  uint low_low, low_high;
  uint high_low, high_high;
  uint var, op;

  register Cache *p = cache_get( upone_tag, x, u, 0, 0 );
  if ( cache_match( p, upone_tag, x, u, 0, 0 ) ) {
    *res_l = p->r1;
    *res_h = p->r2;
    return;
  }

  assert( ! IS_GARBAGE( u ) );

  if ( IS_TERMINAL( u ) ) {
    *res_l = u;
    *res_h = u;
    return;
  }

  upone_parts( x, LOW( u ), &low_low, &low_high );
  is_push( ref_stack, low_low );
  is_push( ref_stack, low_high );

  upone_parts( x, HIGH( u ), &high_low, &high_high );
  is_push( ref_stack, high_low );
  is_push( ref_stack, high_high );

  var = VAR( u );
  op = OP( u );

  if ( ( op == NOP ) && ( var == x ) ) {
    *res_l = low_low;
    *res_h = high_high;

  } else if ( ( op == NOP ) && VARS_IN_ORDER( var, x ) && ( upone_tag == TAG_UPONE_ORDER ) ) {
    uint l, h;
    l = is_push( ref_stack, makenode_upone( x, low_low, low_high ) );
    h = is_push( ref_stack, makenode_upone( x, high_low, high_high ) );
    *res_l = makenode_upone( var, l, h );
    *res_h = *res_l;

    is_popm( ref_stack, 2 );

#ifndef PURE_BED
  } else if ( ( op == EXIST ) && ( var == x ) ) {
    *res_l = *res_h = makenode( 0, OR, low_low, low_high );

  } else if ( ( op == FORALL ) && ( var == x ) ) {
    *res_l = *res_h = makenode( 0, AND, low_low, low_high );

  } else if ( ( op == SUBST ) && ( var == x ) ) {
    uint h, noth, andl, andh;
    h = is_push( ref_stack, makenode_upone( x, high_low, high_high ) );
    noth = is_push( ref_stack, makenode( 0, NPI1, h, h ) );
    andl = is_push( ref_stack, makenode( 0, AND, low_low, noth ) );
    andh = is_push( ref_stack, makenode( 0, AND, low_high, h ) );
    *res_l = *res_h = makenode( 0, OR, andl, andh );

    is_popm( ref_stack, 4 );

  } else if ( op == ESUB ) {
    uint l, h;
    l = is_push( ref_stack, makenode( 0, ESUB, low_low, low_low ) );
    h = is_push( ref_stack, makenode( 0, ESUB, low_high, low_high ) );

    if ( x % 2 == 0 ) 	/* x even */
      *res_l = *res_h = makenode( 0, OR, l, h );
    else 		/* x odd */
      *res_l = *res_h = makenode_upone( x-1, l, h );

    is_popm( ref_stack, 2 );

#endif

  } else {
    *res_l = is_push( ref_stack, makenode( var, op, low_low, high_low ) );
    *res_h = makenode( var, op, low_high, high_high );
    is_popm( ref_stack, 1 );
  }

  is_popm( ref_stack, 4 );

  cache_insert( p, upone_tag, x, u, 0, 0, *res_l, *res_h );
}

uint up_one( uint x, uint u )
{
  uint res, l, h;
  upone_parts( x, u, &l, &h );
  is_push( ref_stack, l );
  is_push( ref_stack, h );
  res = makenode_upone( x, l, h );
  is_popm( ref_stack, 2 );
  return res;
}


static void support( FILE *fp, bed_node node )
{
  if ( IS_VARIABLE( node )) {
    uint level = VAR( node );
    
    if ( ! il_has( support_list, level ) )
      il_append( support_list, level );
  }
}

iList* upone_support( bed_node node )
{
  support_list = il_new();
  kernel_dfs( stdout, node, support );
  kernel_clear_marks();
  return support_list;
}


uint up_one_iter( FILE *fp, uint u )
{
  uint level, l, h;
  iList *sup = upone_support( u );

  for ( level = 0; ( level < kernel_vars ) && !IS_TERMINAL( u ); level++ ) {
    bed_var x = bed_level2var[ level ];
    if ( il_has( sup, x  ) && !IS_TERMINAL( u ) ) {
      is_push( ref_stack, u );
      upone_parts( x, u, &l, &h );
      is_push( ref_stack, l );
      is_push( ref_stack, h );
      u = makenode_upone( x, l, h );
      is_popm( ref_stack, 3 );

      if ( fp != NULL )
	fprintf( stdout, "\tupone( %s ) -> %d\n", bed_var2name( x ), u );
    }
  }

  il_free( sup );
  return u;
}
