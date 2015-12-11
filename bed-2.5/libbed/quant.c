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


#include "quant.h"
#include "cache.h"
#include "kernel.h"


/* quantdown
 *
 */


static Boolean find_free_var_rec( bed_node node, bed_var var )
{
  Boolean res;

  if ( TST_MARK( node ) )
    return false;

  if ( IS_TERMINAL( node ) )
    return false;

  if ( IS_VARIABLE( node ) && ( VAR(node) == var ) ) {
    res = true;
  } else if ( ( ( OP(node) == BED_EXISTS ) || ( OP(node) == BED_FORALL ) ) &&
	      ( VAR(node) == var ) ) {
    res = false;
  } else {
    res = find_free_var_rec( LOW(node), var ) || find_free_var_rec( HIGH(node), var );
  }

  SET_MARK( node );
  return res;
}

static Boolean find_free_var( bed_node node, bed_var var )
{
  Boolean res = find_free_var_rec( node, var );
  kernel_clear_marks();
  return res;
}


static Boolean quant_high_change[] = {
  0, // NOP
  0, // K0
  0, // PI1
  0, // PI2
  1, // NOR
  0, // NLIMP
  1, // NPI1
  1, // NIMP
  1, // NPI2
  0, // XOR
  1, // NAND
  0, // AND
  0, // BIIMP
  0, // IMP
  1, // LIMP
  0, // OR
  0  // K1
};

static Boolean quant_low_change[] = {
  0, // NOP
  0, // K0
  0, // PI1
  0, // PI2
  1, // NOR
  1, // NLIMP
  1, // NPI1
  0, // NIMP
  1, // NPI2
  0, // XOR
  1, // NAND
  0, // AND
  0, // BIIMP
  1, // IMP
  0, // LIMP
  0, // OR
  0  // K1
};


bed_node quantdown( bed_node node )
{
  bed_node res;
  bed_node low, high;

  register Cache *p = cache_get( TAG_QUANTDOWN, node, 0, 0, 0 );
  if ( cache_match( p, TAG_QUANTDOWN, node, 0, 0, 0 ) )
    return p->r1;

  if ( IS_TERMINAL( node ) )
    return node;

  low = is_push( ref_stack, quantdown( LOW( node ) ) );
  high = is_push( ref_stack, quantdown( HIGH( node ) ) );

  if ( ( OP( node ) == BED_EXISTS ) || ( OP( node ) == BED_FORALL ) ) {
#if 1
    if ( OP( low ) == OP( node ) ) {
      bed_node tmp;
      tmp = is_push( ref_stack,
		     bed_mk( VAR(node), OP(node), LOW( low ), LOW( low ) ) );
      tmp = is_push( ref_stack, quantdown( tmp ) );
      res = bed_mk( VAR(low), OP(low), tmp, tmp );
      is_popm( ref_stack, 2 );

    } else
#endif
      if ( ( OP( low ) == BED_EXISTS ) || ( OP( low ) == BED_FORALL ) )
      res = bed_mk( VAR(node), OP(node), low, high );
    else if ( ( IS_OPERATOR( low ) && ( OP(low) != BIIMP ) &&
		( OP(low) != XOR ) ) ||
	      ( IS_VARIABLE( low ) && ( OP( node ) == BED_FORALL ) &&
		VAR( node ) != VAR( low ) ) ) {
      /* Is either low(low) or high(low) independent of var(node) ? */
      Boolean l = find_free_var( LOW(low), VAR(node) );
      Boolean h = find_free_var( HIGH(low), VAR(node) );

      if ( !l && !h ) {
	res = low;
      } else if ( l && !h ) {
	bed_node tmp;
	Op op = OP( node );
	if ( quant_low_change[ OP(low) ] )
	  op = ( op == BED_EXISTS ? BED_FORALL : BED_EXISTS );

	tmp = is_push( ref_stack, bed_mk( VAR(node), op, LOW(low), LOW(low) ) );
	res = is_push( ref_stack, bed_mk( VAR(low), OP(low), tmp, HIGH(low) ) );
	res = quantdown( res );
	is_popm( ref_stack, 2 );
	
      } else if ( !l && h ) {
	bed_node tmp;
	Op op = OP( node );
	if ( quant_high_change[ OP(low) ] )
	  op = ( op == BED_EXISTS ? BED_FORALL : BED_EXISTS );

	tmp = is_push( ref_stack, bed_mk( VAR(node), op, HIGH(low), HIGH(low) ) );
	res = is_push( ref_stack, bed_mk( VAR(low), OP(low), LOW(low), tmp ) );
	res = quantdown( res );
	is_popm( ref_stack, 2 );
	
      } else {
	res = bed_mk( VAR(node), OP(node), low, high );
      }

    } else
      res = bed_mk( VAR(node), OP(node), low, high );

  } else {
    res = bed_mk( VAR(node), OP(node), low, high );
  }

  is_popm( ref_stack, 2 );

  cache_insert( p, TAG_QUANTDOWN, node, 0, 0, 0, res, 0 );

  return res;
}

