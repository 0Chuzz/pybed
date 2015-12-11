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


#include "restrict.h"
#include "cache.h"
#include "kernel.h"


/* ===[ Restrict ]================================================================== */

bed_node restrict_( bed_node u, bed_var x, Boolean val ) 
{
  register Cache *p = cache_get( TAG_RESTRICT, u, x, val, 0 );
  register bed_node l, h, v;

  assert( ! IS_GARBAGE( u ) );

  if ( cache_match( p, TAG_RESTRICT, u, x, val, 0 ) )
    return p->r1;

  if ( IS_TERMINAL( u ) )
    return u;

  l = is_push( ref_stack, restrict_( LOW( u ), x, val ) );
  h = is_push( ref_stack, restrict_( HIGH( u ), x, val ) );

  if ( IS_VARIABLE( u ) && (VAR( u ) == x) ) {
    v = val ? h : l;

  } else {
    v = mk( VAR( u ), OP( u ), l, h );
  }

  is_popm( ref_stack, 2 );

  cache_insert( p, TAG_RESTRICT, u, x, val, 0, v, 0 );

  return v;
}
