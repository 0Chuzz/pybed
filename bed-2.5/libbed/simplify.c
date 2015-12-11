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

#include "bed.h"
#include "kernel.h"
#include "upone.h"
#include "cache.h"

#include "lex.h"
#include "Malloc.h"


/*
 * ===[ Simplify ]=========================================================
 */

/*
 * f' = simplify( f, c )
 *
 * post: c => (f = f')      or equivalently     (f & c) = (f' & c)
 */


static bed_node simplify_rec( bed_node b, bed_node c, bed_var_list* vars, int n )
{
  bed_node res;
  bed_var v;
  Cache *p;

  bed_node b_tmp, c_tmp;
  bed_node b_low, b_high, c_low, c_high;

  if ( c == bed_false )
    return c;
  if ( IS_TERMINAL( b ) || IS_TERMINAL( c ) )
    return b;

  assert( n < il_length( vars ) );

  v = il_elem( vars, n );
  n++;
  p = cache_get( TAG_SIMPLIFY, b, c, v, 0 );
  if ( cache_match( p, TAG_SIMPLIFY, b, c, v, 0 ) )
    return p->r1;

  b_tmp = bed_ref( bed_upone( v, b ) );
  if ( IS_VARIABLE( b_tmp ) && ( VAR( b_tmp ) == v ) ) {
    b_low = LOW( b_tmp );
    b_high = HIGH( b_tmp );
  } else {
    b_low = b_tmp;
    b_high = b_tmp;
  }

  c_tmp = bed_ref( bed_upone( v, c ) );
  if ( IS_VARIABLE( c_tmp ) && ( VAR( c_tmp ) == v ) ) {
    c_low = LOW( c_tmp );
    c_high = HIGH( c_tmp );
  } else {
    c_low = c_tmp;
    c_high = c_tmp;
  }

  if ( c_low == c_high ) {
    /* res = (!v & b_low/c) | (v & b_high/c) */

    bed_node bc0 = bed_ref( simplify_rec( b_low, c, vars, n ) );
    bed_node bc1 = bed_ref( simplify_rec( b_high, c, vars, n ) );
    bed_node var = bed_ref( bed_mk_var( v, bed_false, bed_true ) );
    bed_node low = bed_ref( bed_mk_op( BED_LIMP, var, bc0 ) );
    bed_node high = bed_ref( bed_mk_op( BED_NAND, var, bc1 ) );

    res = bed_mk_op( BED_NAND, low, high );

    bed_deref( low );
    bed_deref( high );
    bed_deref( var );
    bed_deref( bc0 );
    bed_deref( bc1 );
  } else if ( b_low == b_high ) {
    /* res = b/(c_low | c_high) */

    bed_node con = bed_ref( bed_mk_op( BED_OR, c_low, c_high ) );
    res = simplify_rec( b, con, vars, n );
    bed_deref( con );
  } else if ( c_low == bed_false )
    res = simplify_rec( b_high, c_high, vars, n );
  else if ( c_high == bed_false )
    res = simplify_rec( b_low, c_low, vars, n );
  else {
    /* res = (!v & b_low/c_low) | (v & b_high/c_high) */

    bed_node bc0 = bed_ref( simplify_rec( b_low, c_low, vars, n ) );
    bed_node bc1 = bed_ref( simplify_rec( b_high, c_high, vars, n ) );
    bed_node var = bed_ref( bed_mk_var( v, bed_false, bed_true ) );
    bed_node low = bed_ref( bed_mk_op( BED_LIMP, var, bc0 ) );
    bed_node high = bed_ref( bed_mk_op( BED_NAND, var, bc1 ) );

    res = bed_mk_op( BED_NAND, low, high );

    bed_deref( low );
    bed_deref( high );
    bed_deref( var );
    bed_deref( bc0 );
    bed_deref( bc1 );
  }

  bed_deref( b_tmp );
  bed_deref( c_tmp );

  cache_insert( p, TAG_SIMPLIFY, b, c, v, 0, res, 0 );
  return res;
}


bed_node simplify( bed_node b, bed_node c )
{
  bed_node res;
  bed_var_list* vars;

  unsigned char old_mode = get_upone_mode();
  set_upone_mode( TAG_UPONE_STRICT );

#if 0
  {
    int i;
    bed_var_list *vars2;
    vars2 = bed_support( c );

    vars = il_new();
    for ( i = 0; i < kernel_nodes; i++ )
      if ( il_has( vars2, i ) )
	il_append( vars, i );
    
    il_free( vars2 );
  }
#else
  vars = bed_support( c );
#endif

  res = simplify_rec( b, c, vars, 0 );

  if ( vars )
    il_free( vars );

  set_upone_mode( old_mode );

  if ( bed_node_count( res ) < bed_node_count( b ) )
    return res;
  else
    return b;
}
