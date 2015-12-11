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


#include "upall.h"
#include "bed.h"
#include "kernel.h"
#include "istack.h"
#include "Malloc.h"
#include "cache.h"



/* ===[ Up_all ]=================================================================== */


static inline uint makenode_upall( uint var, uint l, uint h )
{
  if ( var == VAR(l) )
    l = LOW(l);
  if ( var == VAR(h) )
    h = HIGH(h);

  return makenode( var, NOP, l, h );
}

uint upall_parts( uint var, Op op, uint l, uint h, Boolean is_bdd )
{
  uint r;
  register uint vl, vh;
  uint ol, oh;
  register Cache *p;

#ifdef COLLECT_STATS
  number_upall_parts++;
#endif

  p = cache_get( TAG_UPALL, var, op, l, h );
  if ( cache_match( p, TAG_UPALL, var, op, l, h ) )
    return p->r1;

  ol = l; oh = h;

  if ( ! is_bdd ) {
    if ( !IS_TERMINAL( l ) )
      l = upall_parts( VAR(l), OP(l), LOW(l), HIGH(l), false );
    is_push( ref_stack, l );

    if ( !IS_TERMINAL( h ) )
      h = upall_parts( VAR(h), OP(h), LOW(h), HIGH(h), false );
    is_push( ref_stack, h );
  }

  vl = VAR(l);
  vh = VAR(h);

  if ( IS_TERMINAL( l ) && IS_TERMINAL( h ) )
    r = makenode( var, op, l, h );

  else if ( ( op == NOP ) && VARS_IN_ORDER( var, vl ) && VARS_IN_ORDER( var, vh ) ) {
    r = makenode_upall( var, l, h );

#ifndef PURE_BED
  } else if ( op == EXIST ) {
    if ( IS_TERMINAL( l ) )
      r = l;
    else if ( var == vl )
      r = upall_parts( 0, OR, LOW( l ), HIGH( l ), true );
    else {
      bed_node tmp1 = is_push( ref_stack, upall_parts( var, EXIST, LOW(l), LOW(l), true ));
      bed_node tmp2 = is_push( ref_stack, upall_parts( var, EXIST, HIGH(l), HIGH(l), true ));
      r = upall_parts( vl, NOP, tmp1, tmp2, true );

      is_popm( ref_stack, 2 );
    }

  } else if ( op == FORALL ) {
    if ( IS_TERMINAL( l ) )
      r = l;
    else if ( var == vl )
      r = upall_parts( 0, AND, LOW( l ), HIGH( l ), true );
    else {
      bed_node tmp1 = is_push( ref_stack, upall_parts( var, FORALL, LOW(l), LOW(l), true ));
      bed_node tmp2 = is_push( ref_stack, upall_parts( var, FORALL, HIGH(l), HIGH(l), true ));
      r = upall_parts( vl, NOP, tmp1, tmp2, true );

      is_popm( ref_stack, 2 );
    }

  } else if ( op == SUBST ) {
    if ( var == vl ) {
      uint andl, andh, noth, or;
      noth = is_push( ref_stack, makenode( 0, NPI1, h, h ) );
      andl = is_push( ref_stack, makenode( 0, AND, LOW( l ), noth ) );
      andh = is_push( ref_stack, makenode( 0, AND, HIGH( l ), h ) );
      or = is_push( ref_stack, makenode( 0, OR, andl, andh ) );
      r = upall_parts( VAR( or ), OP( or ), LOW( or ), HIGH( or ), false );

      is_popm( ref_stack, 4 );

    } else if ( VARS_IN_ORDER(  var, vl ) ) {
      r = l;

    } else if ( VARS_IN_ORDER( vl, vh ) ) {
      bed_node tmp1 = is_push( ref_stack, upall_parts( var, SUBST, LOW(l), h, true ) );
      bed_node tmp2 = is_push( ref_stack, upall_parts( var, SUBST, HIGH(l), h, true ) );

      r = upall_parts( vl, NOP, tmp1, tmp2, true );

      is_popm( ref_stack, 2 );

    } else {
      bed_node h1 = is_push( ref_stack, upall_parts( vl, SUBST, h, ZERO, true ) );
      bed_node h2 = is_push( ref_stack, upall_parts( vl, SUBST, h, ONE, true ) );
      bed_node tmp1 = is_push( ref_stack, upall_parts( var, SUBST, LOW(l), h1, true ) );
      bed_node tmp2 = is_push( ref_stack, upall_parts( var, SUBST, HIGH(l), h2, true ) );

      r = upall_parts( vl, NOP, tmp1, tmp2, true );

      is_popm( ref_stack, 4 );

    }

  } else if ( op == ESUB ) {
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

    }
#endif

  } else if ( vl == vh ) {
    bed_node tmp1 = is_push( ref_stack, upall_parts( var, op, LOW(l), LOW(h), true ) );
    bed_node tmp2 = is_push( ref_stack, upall_parts( var, op, HIGH(l), HIGH(h), true ) );
    r = makenode_upall( vl, tmp1, tmp2 );

    is_popm( ref_stack, 2 );
    
  } else if ( VARS_IN_ORDER( vl, vh ) ) {
    bed_node tmp1 = is_push( ref_stack, upall_parts( var, op, LOW(l), h, true ) );
    bed_node tmp2;

    tmp2 = is_push( ref_stack, upall_parts( var, op, HIGH(l), h, true ) );
    r = makenode_upall( vl, tmp1, tmp2 );

    is_popm( ref_stack, 2 );

  } else /* if ( vl > vh ) */ {
    bed_node tmp1 = is_push( ref_stack, upall_parts( var, op, l, LOW(h), true ) );
    bed_node tmp2;

    tmp2 = is_push( ref_stack, upall_parts( var, op, l, HIGH(h), true ) );
    r = makenode_upall( vh, tmp1, tmp2 );

    is_popm( ref_stack, 2 );

  }

  if ( ! is_bdd )
    is_popm( ref_stack, 2 );

  cache_insert( p, TAG_UPALL, var, op, ol, oh, r, 0 );
  return r;
}

uint up_all( uint u )
{
  uint v;
  if ( IS_TERMINAL( u ) )
    v = u;
  else
    v = upall_parts( VAR( u ), OP( u ), LOW( u ), HIGH( u ), false );

  return v;
}

