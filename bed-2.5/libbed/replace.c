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

#include "replace.h"
#include "bed.h"
#include "kernel.h"
#include "op.h"
#include "tables.h"		/* Reduction tables */


/* Local variables */


#ifdef COLLECT_STATS
static uint red_term_child = 0;
static uint red_ID_children = 0;
static uint red_2 = 0;
static uint red_3_2 = 0;
static uint red_3_3 = 0;
static uint red_sym = 0;
static uint red_neg_parent = 0;
static uint red_neg_child = 0;
#endif


static Op mini_replacenode( uint var, Op op, uint l, uint h, uint *v_, uint *l_, uint *h_ );
static Op table_replacenode( uint var, Op op, uint l, uint h, uint *v_, uint *l_, uint *h_ );
static Op table_replace_lookup( Op op, uint l, uint h, uint *v_, uint *l_, uint *h_ );



inline Op replacenode( uint var, Op op, uint l, uint h, uint *v_, uint *l_, uint *h_ )
{
  return bed_do_reductions ?
    table_replacenode( var, op, l, h, v_, l_, h_ ) :
    mini_replacenode( var, op, l, h, v_, l_, h_ );
}


static inline uint two_ops_to_number( Op op1, Op op2 )
{
  return (op1-K0)*16+(op2-K0);
}

static inline uint three_ops_to_number( Op op1, Op op2, Op op3 )
{
  return ( (op1-K0)*16+(op2-K0) ) * 16 + (op3-K0);
}

static inline Boolean is_simple_operator( Op op )
{
  return ( op >= K0 ) && ( op <= K1 );
}


/*
 * BDD Replacenode
 *
 */

Op bdd_replacenode( Op op, uint l, uint h, uint *l_, uint *h_ )
{
  switch ( op ) {
  case AND:	
    if ( l == h ) {
      *l_ = l;      	return PI1;
    } else if ( (l == ZERO) || (h == ZERO) ) {
      *l_ = ZERO; 	return PI1;
    } else if ( l == ONE ) {
      *l_ = h;		return PI1;
    } else if ( h == ONE ) {
      *l_ = l;		return PI1;
    } 
    break;

  case NAND:
    if ( l == h ) {
      return bdd_replacenode( NPI1, l, l, l_, h_ );
    } else if ( (l == ZERO) || (h == ZERO) ) {
      *l_ = ONE;	return PI1;
    } else if ( l == ONE ) {
      return bdd_replacenode( NPI1, h, h, l_, h_ );
    } else if ( h == ONE ) {
      return bdd_replacenode( NPI1, l, l, l_, h_ );
    } 
    break;

  case OR:
    if ( l == h ) {
      *l_ = l;		return PI1;
    } else if ( (l == ONE) || (h == ONE) ) {
      *l_ = ONE;	return PI1;
    } else if ( l == ZERO ) {
      *l_ = h;		return PI1;
    } else if ( h == ZERO ) {
      *l_ = l;		return PI1;
    } 
    break;
  
  case NOR:
    if ( l == h ) {
      return bdd_replacenode( NPI1, l, l, l_, h_ );
    } else if ( (l == ONE) || (h == ONE) ) {
      *l_ = ZERO;	return PI1;
    } else if ( l == ZERO ) {
      return bdd_replacenode( NPI1, h, h, l_, h_ );
    } else if ( h == ZERO ) {
      return bdd_replacenode( NPI1, l, l, l_, h_ );
    }
    break;
    
  case BIIMP:
    if ( l == h ) {
      *l_ = ONE;	return PI1;
    } else if ( l == ONE ) {
      *l_ = h;		return PI1;
    } else if ( h == ONE ) {
      *l_ = l;		return PI1;
    } else if ( l == ZERO ) {
      return bdd_replacenode( NPI1, h, h, l_, h_ );
    } else if ( h == ZERO ) {
      return bdd_replacenode( NPI1, l, l, l_, h_ );
    } 
    break;
    
  case XOR:	
    if ( l == h ) {
      *l_ = ZERO;	return PI1;
    } else if ( l == ZERO ) {
      *l_ = h;		return PI1;
    } else if ( h == ZERO ) {
      *l_ = l;		return PI1;
    } else if ( l == ONE ) {
      return bdd_replacenode( NPI1, h, h, l_, h_ );
    } else if ( h == ONE ) {
      return bdd_replacenode( NPI1, l, l, l_, h_ );
    } 
    break;

  case NPI1:		/* negation */
    if ( l == ZERO ) {
      *l_ = ONE;	return PI1;
    } else if ( l == ONE ) {
      *l_ = ZERO;	return PI1;
    } else {

      switch ( OP( l )) {
      case NPI1: 	*l_ = LOW( l ); 		 	   return PI1;
      case AND:	  	return bdd_replacenode( NAND,  LOW( l ), HIGH( l ), l_, h_ );
      case NAND:	return bdd_replacenode( AND,   LOW( l ), HIGH( l ), l_, h_ );
      case OR:	  	return bdd_replacenode( NOR,   LOW( l ), HIGH( l ), l_, h_ );
      case NOR:	  	return bdd_replacenode( OR,    LOW( l ), HIGH( l ), l_, h_ );
      case BIIMP:	return bdd_replacenode( XOR,   LOW( l ), HIGH( l ), l_, h_ );
      case XOR:	  	return bdd_replacenode( BIIMP, LOW( l ), HIGH( l ), l_, h_ );
      default:
	break;
      }
      *l_ = *h_ = l; 
      return op;
    }
    
  case PI1:		/* indirection */
  case NOP:
    break;

    /* (N)IMP & (N)LIMP added for use in make_table() */
  case IMP:
    if ( l == ONE ) {
      *l_ = h;         return PI1;
    } else if ( (l == ZERO) || (h == ONE) ) {
      *l_ = ONE;       return PI1;
    } else if ( h == ZERO ) {
      return bdd_replacenode( NPI1, l, l, l_, h_ );      /* negation */
    } else if ( l == h ) {
      *l_ = ONE;       return PI1;
    }
    break;

  case NIMP:
    if ( h == ZERO ) {
      *l_ = l;         return PI1;
    } else if ( (l == ZERO) || (h == ONE) ) {
      *l_ = ZERO;      return PI1;
    } else if ( l == ONE ) {
      return bdd_replacenode( NPI1, h, h, l_, h_ );      /* negation */
    } else if ( l == h ) {
      *l_ = ZERO;      return PI1;
    }
    break;

  case LIMP:
    if (( h == ZERO ) || ( l == ONE )) {
      *l_ = ONE;       return PI1;
    } else if ( l == ZERO ) {
      return bdd_replacenode( NPI1, h, h, l_, h_ );      /* negation */
    } else if ( h == ONE ) {
      *l_ = l;         return PI1;
    } else if ( l == h ) {
      *l_ = ONE;       return PI1;
    }
    break;

  case NLIMP:
    if (( h == ZERO ) || ( l == ONE )) {
      *l_ = ZERO;      return PI1;
    } else if ( h == ONE ) {
      return bdd_replacenode( NPI1, l, l, l_, h_ );      /* negation */
    } else if ( l == ZERO ) {
      *l_ = h;         return PI1;
    } else if ( l == h ) {
      *l_ = ZERO;      return PI1;
    }
    break;

  case EXIST:
  case FORALL:
  case SUBST:
  case ESUB:
  default:
    fprintf( stderr, "Internal Error: Illegal operator: %d\n", (int) op );
    abort();
  }

  if ( op_is_symmetric( op ) && (l > h) ) {
    *l_ = h;      *h_ = l;
  } else {
    *l_ = l;      *h_ = h;
  }

  return op;
}




/*
 * TABLE Replacenode
 *
 */

#ifndef PURE_BED
Op replace_subst_exist( uint var, Op op, uint l, uint h, uint *v_, uint *l_, uint *h_ )
{
  /* The BED is assumed to be FREE */

  if ( op == EXIST ) {
    if ( IS_VARIABLE( l ) && (VAR( l ) == var) )
      return replacenode( 0, OR, LOW( l ), HIGH( l ), v_, l_, h_ );
 
    else if ( IS_TERMINAL( l ) ) 
      return replacenode( 0, PI1, l, l, v_, l_, h_ ); 

    else if ( IS_VARIABLE( l ) ) {
      uint r1 = is_push( ref_stack, mk( var, EXIST, LOW(l), LOW(l) ) );
      uint r2 = is_push( ref_stack, mk( var, EXIST, HIGH(l), HIGH(l) ) );
      uint res = replacenode( VAR( l ), NOP, r1, r2, v_, l_, h_ );
      is_popm( ref_stack, 2 );
      return res;

    } else if ( OP( l ) == NPI1 ) {
      uint r = is_push( ref_stack, mk( var, FORALL, LOW(l), LOW(l) ) );
      uint res = replacenode( 0, NPI1, r, r, v_, l_, h_ );
      is_popm( ref_stack, 1 );
      return res;

    } else if ( OP( l ) == OR ) {
      uint r1 = is_push( ref_stack, mk( var, EXIST, LOW(l), LOW(l) ) );
      uint r2 = is_push( ref_stack, mk( var, EXIST, HIGH(l), HIGH(l) ) );
      uint res = replacenode( 0, OR, r1, r2, v_, l_, h_ );
      is_popm( ref_stack, 2 );
      return res;

    } else if ( OP( l ) == IMP ) {
      uint r1 = is_push( ref_stack, mk( var, FORALL, LOW(l), LOW(l) ) );
      uint r2 = is_push( ref_stack, mk( var, EXIST, HIGH(l), HIGH(l) ) );
      uint res = replacenode( 0, IMP, r1, r2, v_, l_, h_ );
      is_popm( ref_stack, 2 );
      return res;

    } else if ( OP( l ) == LIMP ) {
      uint r1 = is_push( ref_stack, mk( var, EXIST, LOW(l), LOW(l) ) );
      uint r2 = is_push( ref_stack, mk( var, FORALL, HIGH(l), HIGH(l) ) );
      uint res = replacenode( 0, LIMP, r1, r2, v_, l_, h_ );
      is_popm( ref_stack, 2 );
      return res;

    } else if ( OP( l ) == NAND ) {
      uint r1 = is_push( ref_stack, mk( var, FORALL, LOW(l), LOW(l) ) );
      uint r2 = is_push( ref_stack, mk( var, FORALL, HIGH(l), HIGH(l) ) );
      uint res = replacenode( 0, NAND, r1, r2, v_, l_, h_ );
      is_popm( ref_stack, 2 );
      return res;

    }


  } else if ( op == FORALL ) {
    if ( IS_VARIABLE( l ) && (VAR( l ) == var) )
      return replacenode( 0, AND, LOW( l ), HIGH( l ), v_, l_, h_ );
 
    else if ( IS_TERMINAL( l ) ) 
      return replacenode( 0, PI1, l, l, v_, l_, h_ ); 

    else if ( OP( l ) == NPI1 ) {
      uint r = is_push( ref_stack, mk( var, EXIST, LOW(l), LOW(l) ) );
      uint res = replacenode( 0, NPI1, r, r, v_, l_, h_ );
      is_popm( ref_stack, 1 );
      return res;

    } else if ( OP( l ) == AND ) {
      uint r1 = is_push( ref_stack, mk( var, FORALL, LOW(l), LOW(l) ) );
      uint r2 = is_push( ref_stack, mk( var, FORALL, HIGH(l), HIGH(l) ) );
      uint res = replacenode( 0, AND, r1, r2, v_, l_, h_ );
      is_popm( ref_stack, 2 );
      return res;

    } else if ( OP( l ) == NIMP ) {
      uint r1 = is_push( ref_stack, mk( var, FORALL, LOW(l), LOW(l) ) );
      uint r2 = is_push( ref_stack, mk( var, EXIST, HIGH(l), HIGH(l) ) );
      uint res = replacenode( 0, NIMP, r1, r2, v_, l_, h_ );
      is_popm( ref_stack, 2 );
      return res;

    } else if ( OP( l ) == NLIMP ) {
      uint r1 = is_push( ref_stack, mk( var, EXIST, LOW(l), LOW(l) ) );
      uint r2 = is_push( ref_stack, mk( var, FORALL, HIGH(l), HIGH(l) ) );
      uint res = replacenode( 0, NLIMP, r1, r2, v_, l_, h_ );
      is_popm( ref_stack, 2 );
      return res;

    } else if ( OP( l ) == NOR ) {
      uint r1 = is_push( ref_stack, mk( var, EXIST, LOW(l), LOW(l) ) );
      uint r2 = is_push( ref_stack, mk( var, EXIST, HIGH(l), HIGH(l) ) );
      uint res = replacenode( 0, NOR, r1, r2, v_, l_, h_ );
      is_popm( ref_stack, 2 );
      return res;

    }

  } else if ( op == SUBST ) {
    if ( IS_TERMINAL( l ) )
      return replacenode( 0, PI1, l, l, v_, l_, h_ );
      
    else if ( IS_VARIABLE( l ) && ( VAR( l ) == var )) {
      uint r3 = is_push( ref_stack, mk_operator( NPI1, h, h ) );
      uint r2 = is_push( ref_stack, mk_operator( AND, h, HIGH( l ) ) );
      uint r1 = is_push( ref_stack, mk_operator( AND, LOW( l ), r3 ) );
      uint res = replacenode( 0, OR, r1, r2, v_, l_, h_ );
      is_popm( ref_stack, 3 );
      return res;
    }

  } else if ( op == ESUB ) {
    if ( IS_TERMINAL( l ) )
      return replacenode( 0, PI1, l, l, v_, l_, h_ );

  } else {
    /* op must be either SUBST or EXIST or FORALL or ESUB */
    assert( 0 );
  }

  *l_ = l;    *h_ = h;
  return op;
}
#endif



static Op base_set_array1[] = {
 NOP,   /* Dummy row */
 K0,    /* K0 */
 PI1,   /* PI1 */
 PI2,   /* PI2 */
 OR,    /* NOR */
 LIMP,  /* NLIMP */
 NPI1,  /* NPI1 */
 IMP,   /* NIMP */
 NPI2,  /* NPI2 */
 BIIMP, /* XOR */
 NAND,  /* NAND */
 NAND,  /* AND */
 BIIMP, /* BIIMP */
 IMP,   /* IMP */
 LIMP,  /* LIMP */
 OR,    /* OR */
 K1,    /* K1 */
 0      /* Dummy row */
};

static Op base_set_array2[] = {
 NOP,   /* Dummy row */
 K0,    /* K0 */
 PI1,   /* PI1 */
 PI2,   /* PI2 */
 NOR,   /* NOR */
 NLIMP, /* NLIMP */
 NPI1,  /* NPI1 */
 NIMP,  /* NIMP */
 NPI2,  /* NPI2 */
 XOR,   /* XOR */
 AND,   /* NAND */
 AND,   /* AND */
 XOR,   /* BIIMP */
 NIMP,  /* IMP */
 NLIMP, /* LIMP */
 NOR,   /* OR */
 K1,    /* K1 */
 0      /* Dummy row */
};

static Op *base_set_array = base_set_array1;


int get_base_set()
{
  if ( base_set_array == base_set_array1 )
    return 1;
  if ( base_set_array == base_set_array2 )
    return 2;
  fprintf( stderr, "Unknown base_set in use... exiting...\n" );
  exit( 1 );
}

/* Set the use of base set to 1 or 2 */
void set_base_set( int set )
{
  if ( set == 1 )
    base_set_array = base_set_array1;
  else if ( set == 2 )
    base_set_array = base_set_array2;
  else {
    fprintf( stderr, "set_base_set: unknown base set %d. Nothing changed.\n", set );
  }    
}

static Op align_to_base_set( Op op, uint l, uint h, uint *l_, uint *h_ )
{
  register int op_;
  Boolean pop_some = 2;

  *l_ = l; *h_ = h; op_ = op;

#if 0
  /* Uncomment to use all operators */
  return op_;
#endif


  if ( ( op_arity( op ) != 2 ) && ( op != NPI1 ) )
    return op_;

  is_push( ref_stack, l );
  is_push( ref_stack, h );

  if ( IS_BOOL_OPERATOR( l ) ) {
    register int opl = base_set_array[ OP( l ) ];
    if ( opl != OP( l ) ) {
      *l_ = addnode( 0, opl, LOW( l ), HIGH( l ) );
      op_ = negation_child_reduction_array[ op_ ];
      is_push( ref_stack, *l_ );
      pop_some++;
    }
  }

  if ( IS_BOOL_OPERATOR( h ) ) {
    register int oph = base_set_array[ OP( h ) ];
    if ( oph != OP( h ) ) {
      *h_ = addnode( 0, oph, LOW( h ), HIGH( h ) );
      op_ = symmetric_operator_array[ negation_child_reduction_array[ symmetric_operator_array[ op_ ] ] ];
      is_push( ref_stack, *h_ );
      pop_some++;
    }
  }

  if ( ( op != op_ ) || ( l != *l_ ) || ( h != *h_ ) ) {
    uint var = 0;
    op_ = table_replacenode( 0, op_, *l_, *h_, &var, l_, h_ );
  }

  is_popm( ref_stack, pop_some );

  return op_;
}


Op table_replacenode( uint var, Op op, uint l, uint h, uint *v_, uint *l_, uint *h_ )
{
  *v_ = var;
  *l_ = l;
  *h_ = h;

  if ( op == NOP ) {	/* A variable vertex */
    if ( l == h )
      return PI1;
    else
      return op;
  }

  if ( IS_TERMINAL( l ) && IS_TERMINAL( h ) ) {
    *l_ = op_eval( op, l, h );
    return PI1;
  }

  switch ( op ) {
  case PI1:
    return PI1;

  case PI2:
    *l_ = h;
    return PI1;

  case K0:
    *l_ = ZERO;
    return PI1;

  case K1:
    *l_ = ONE;
    return PI1;

#ifndef PURE_BED
  case SUBST:
  case EXIST:
  case FORALL:
  case ESUB:
    return replace_subst_exist(var, op, l, h, v_, l_, h_ );
#endif

  default:
    {
      Op op_;
      assert ( is_simple_operator( op ));

      op_ = table_replace_lookup( op, l, h, v_, l_, h_ );

#if 0
      if ( (op_!=op) || ( *l_!=l) || (*h_!=h) ) {
	fprintf( stderr, "Reducing ( %s, %d, %d ) to ( %s, %d, %d )\n",
		 op2string( op ), l, h, op2string( op_ ), *l_, *h_ );
      }
#endif
     
      if ( op_ == NPI1 )
	*h_ = *l_;
      else if ( op_ == NPI2 )
	*l_ = *h_, op_ = NPI1;

      is_push( ref_stack, *l_ );
      is_push( ref_stack, *h_ );

      op_ = align_to_base_set( op_, *l_, *h_, l_, h_ );

      is_popm( ref_stack, 2 );

      return op_;
    }
  }
}


/* Returns  true   if  u = !v */
/* Returns  false  if  u = v  OR if unable to decide */
static inline Boolean are_complements( uint u, uint v )
{
  if ( IS_BOOL_OPERATOR( u ) && IS_BOOL_OPERATOR( v ) ) {
    return ( ( ( OP( u ) == negation_parent_reduction_array[ OP( v ) ] ) &&
	   ( LOW( u ) == LOW( v ) ) && ( HIGH( u ) == HIGH( v ) ) ) || 
	 ( ( OP( u ) == symmetric_operator_array[ negation_parent_reduction_array[ OP( v ) ] ] ) &&
	   ( LOW( u ) == HIGH( v ) ) && ( HIGH( u ) == LOW( v ) ) ) );
  } else
    return false;
}


/* Reductions to "(a opl b) op (c oph d)" */
static inline Boolean three_nodes( Op op, Op opl, Op oph, uint a, uint b, uint c, uint d,
				   uint *op_, uint *v_, uint *l_, uint *h_ )
{
  register uint n;

  if ( a != d )
    return false;

  if ( are_complements( b, c ) ) {
    n = three_ops_to_number( op, opl, symmetric_operator_array[ negation_child_reduction_array[ oph ] ] );
    *op_ = table_replacenode( 0, three_nodes_two_grandchildren_reduction_array[ n ],
			      a, b, v_, l_, h_ );
    return true;
  }

  n = three_ops_to_number( op, opl, oph );

  if ( three_nodes_reduction_array[ n ].op1 == NOP )
    return false;

  if ( three_nodes_reduction_array[ n ].is_left ) {
    *op_ = table_replacenode( 0, three_nodes_reduction_array[ n ].op1,
	      is_push( ref_stack, makenode( 0, three_nodes_reduction_array[ n ].op2, a, b ) ), c, v_, l_, h_ );
    is_popm( ref_stack, 1 );
  } else {
    *op_ = table_replacenode( 0, three_nodes_reduction_array[ n ].op1, a,
	      is_push( ref_stack, makenode( 0, three_nodes_reduction_array[ n ].op2, b, c ) ), v_, l_, h_ );
    is_popm( ref_stack, 1 );
  }
  return true;
}

/* Reductions to "(a opl b) op (c oph d)" */
static inline Boolean three_nodes_to_three_nodes( Op op, Op opl, Op oph,
    uint a, uint b, uint c, uint d, uint *op_, uint *v_, uint *l_, uint *h_ )
{
  register uint n;

  if ( a != d )
    return false;

  n = three_ops_to_number( op, opl, oph );

  if ( three_nodes_reduction_array[ n ].op1 == NOP ) {
    bed_node low, high;
    bed_op op2 = three_nodes_reduction_array[ n ].op2;
    if ( op2 == NOP )
      return false;

    low = is_push( ref_stack, makenode( 0, opl, a, b ) );
    high = is_push( ref_stack, makenode( 0, oph, c, d ) );

    if ( high < low ) {
      COUNT_REDUCTIONS( red_sym++ );
      *h_ = low;
      *l_ = high;
      *op_ = symmetric_operator_array[ op2 ];
    } else {
      *h_ = high;
      *l_ = low;
      *op_ = op2;
    }
    *v_ = 0;

    is_popm( ref_stack, 2 );
    return true;
  }
  return false;
}


static uint build_triple( Op op, Op opl, Op oph, uint ll, uint hl, uint lh, uint hh )
{
  uint l = is_push( ref_stack, mk( 0, opl, ll, hl ) );
  uint h = is_push( ref_stack, mk( 0, oph, lh, hh ) );
  uint res = mk( 0, op, l, h );
  is_popm( ref_stack, 2 );
  return res;
}


static Op table_replace_lookup( Op op, uint l, uint h, uint *v_, uint *l_, uint *h_ )
{
  register uint ll = LOW( l ), hh = HIGH( h ), hl = HIGH( l ), lh = LOW( h );
  register Op opl = OP( l ), oph = OP( h );

  /* Left child is a terminal */
  if ( l == ZERO ) {
    COUNT_REDUCTIONS( red_term_child++ );
    return table_replacenode( 0, one_terminal_reduction_array[ op ].l0, h, h, v_, l_, h_ );
  } else if ( l == ONE ) {
    COUNT_REDUCTIONS( red_term_child++ );
    return table_replacenode( 0, one_terminal_reduction_array[ op ].l1, h, h, v_, l_, h_ );
  }
  
  /* Right child is a terminal */
  if ( h == ZERO ) {
    COUNT_REDUCTIONS( red_term_child++ );
    return table_replacenode( 0, one_terminal_reduction_array[ op ].h0, l, l, v_, l_, h_ );
  } else if ( h == ONE ) {
    COUNT_REDUCTIONS( red_term_child++ );
    return table_replacenode( 0, one_terminal_reduction_array[ op ].h1, l, l, v_, l_, h_ );
  }

  /* Identical children */
  if ( l == h ) {
    op = identical_children_reduction_array[ op ];
    if ( op == NPI1 ) {
      if ( IS_BOOL_OPERATOR( l ) ) {
	COUNT_REDUCTIONS( red_neg_parent++ );
	return table_replacenode( 0, negation_parent_reduction_array[ opl ], ll, hl, v_, l_, h_ );
      }
    } else {
      COUNT_REDUCTIONS( red_ID_children++ );
      return table_replacenode( 0, op, l, l, v_, l_, h_ );
    }
  }

  /* 2-red. left */
  if ( IS_BOOL_OPERATOR( l ) ) {
    if ( opl == NPI1 ) {
      COUNT_REDUCTIONS( red_neg_child++ );
      return table_replacenode( 0, negation_child_reduction_array[ op ], ll, h, v_, l_, h_ );
    } else if ( ll == h ) {
      uint n = two_ops_to_number( op, opl );
      COUNT_REDUCTIONS( red_2++ );
      return table_replacenode( 0, two_nodes_left_reduction_array[ n ], h, hl, v_, l_, h_ );
    } else if ( hl == h ) {
      uint n = two_ops_to_number( op, symmetric_operator_array[ opl ] );
      COUNT_REDUCTIONS( red_2++ );
      return table_replacenode( 0, two_nodes_left_reduction_array[ n ], h, ll, v_, l_, h_ );
    }
  }
  
  /* 2-red. right */
  if ( IS_BOOL_OPERATOR( h ) ) {
    if ( oph == NPI1 ) {
      COUNT_REDUCTIONS( red_neg_child++ );
      return table_replacenode( 0, negation_child_reduction_array[ symmetric_operator_array[ op ] ], lh, l, v_, l_, h_ );
    } else if ( lh == l ) {
      uint n = two_ops_to_number( symmetric_operator_array[ op ], oph );
      COUNT_REDUCTIONS( red_2++ );
      return table_replacenode( 0, two_nodes_left_reduction_array[ n ], l, hh, v_, l_, h_ );
    } else if ( hh == l ) {
      uint n = two_ops_to_number( symmetric_operator_array[ op ], symmetric_operator_array[ oph ] );
      COUNT_REDUCTIONS( red_2++ );
      return table_replacenode( 0, two_nodes_left_reduction_array[ n ], l, lh, v_, l_, h_ );
    }
  }

  /* 3-red. */
  if ( IS_BOOL_OPERATOR( l ) && IS_BOOL_OPERATOR( h ) ) {
    uint op_;

    /* Only two different grandchildren */
    if ( ( ll == hh ) && ( hl == lh ) ) {
      uint n = three_ops_to_number( op, opl, symmetric_operator_array[ oph ] );
      COUNT_REDUCTIONS( red_3_2++ );
      return table_replacenode( 0, three_nodes_two_grandchildren_reduction_array[ n ],
				ll, hl, v_, l_, h_ );
    } else if ( ( hl == hh ) && ( ll == lh ) ) {
      uint n = three_ops_to_number( op, opl, oph );
      COUNT_REDUCTIONS( red_3_2++ );
      return table_replacenode( 0, three_nodes_two_grandchildren_reduction_array[ n ],
				ll, hl, v_, l_, h_ );
    }

    /* Three different grandchildren */
    if ( three_nodes( op, opl, oph, ll, hl, lh, hh, &op_, v_, l_, h_ ) ) {
      COUNT_REDUCTIONS( red_3_3++ );
      return op_;
    }
    if ( three_nodes( op, symmetric_operator_array[ opl ], oph, hl, ll, lh, hh,
		      &op_, v_, l_, h_ ) ) {
      COUNT_REDUCTIONS( red_3_3++ );
      return op_;
    }
    if ( three_nodes( op, opl, symmetric_operator_array[ oph ], ll, hl, hh, lh,
		      &op_, v_, l_, h_ ) ) {
      COUNT_REDUCTIONS( red_3_3++ );
      return op_;
    }
    if ( three_nodes( op, symmetric_operator_array[ opl ], symmetric_operator_array[ oph ],
		      hl, ll, hh, lh, &op_, v_, l_, h_ ) ) {
      COUNT_REDUCTIONS( red_3_3++ );
      return op_;
    }

#if 0
    /* Three different grandchildren -- three nodes*/
    if ( three_nodes_to_three_nodes( op, opl, oph, ll, hl, lh, hh, &op_, v_, l_, h_ ) ) {
      COUNT_REDUCTIONS( red_3_3++ );
      return op_;
    }
    if ( three_nodes_to_three_nodes( op, symmetric_operator_array[ opl ], oph, hl, ll, lh, hh, &op_, v_, l_, h_ ) ) {
      COUNT_REDUCTIONS( red_3_3++ );
      return op_;
    }
    if ( three_nodes_to_three_nodes( op, opl, symmetric_operator_array[ oph ], ll, hl, hh, lh, &op_, v_, l_, h_ ) ) {
      COUNT_REDUCTIONS( red_3_3++ );
      return op_;
    }
    if ( three_nodes_to_three_nodes( op, symmetric_operator_array[ opl ], symmetric_operator_array[ oph ], hl, ll, hh, lh, &op_, v_, l_, h_ ) ) {
      COUNT_REDUCTIONS( red_3_3++ );
      return op_;
    }
#endif

  }


  /* 3-cut reductions -- 3 operators */
  if ( IS_BOOL_OPERATOR( l ) && ( op_arity( opl ) == 2 ) ) {
    if ( IS_BOOL_OPERATOR( ll ) && ( ( h == LOW( ll ) ) || ( h == HIGH( ll ) ) ) ) {
      uint r0 = is_push( ref_stack, mk( 0, opl, ll, ZERO ) );
      uint t0 = is_push( ref_stack, mk( 0, op, r0, h ) );

      uint r1 = is_push( ref_stack, mk( 0, opl, ll, ONE ) );
      uint t1 = is_push( ref_stack, mk( 0, op, r1, h ) );

      uint a0 = is_push( ref_stack, mk( 0, NLIMP, hl, t0 ) );
      uint a1 = is_push( ref_stack, mk( 0, AND, hl, t1 ) );
      
      Op res;

      if ( IS_TERMINAL( t1 ) || IS_TERMINAL( t0 ) ) {
	res = table_replacenode( 0, OR, a0, a1, v_, l_, h_ );
	is_popm( ref_stack, 6 );
	return res;
      }

      is_popm( ref_stack, 6 );
    }

    if ( IS_BOOL_OPERATOR( hl ) && ( ( h == LOW( hl ) ) || ( h == HIGH( hl ) ) ) ) {
      uint r0 = is_push( ref_stack, mk( 0, opl, ZERO, hl ) );
      uint t0 = is_push( ref_stack, mk( 0, op, r0, h ) );

      uint r1 = is_push( ref_stack, mk( 0, opl, ONE, hl ) );
      uint t1 = is_push( ref_stack, mk( 0, op, r1, h ) );

      uint a0 = is_push( ref_stack, mk( 0, NLIMP, ll, t0 ) );
      uint a1 = is_push( ref_stack, mk( 0, AND, ll, t1 ) );
      
      Op res;

      if ( IS_TERMINAL( t1 ) || IS_TERMINAL( t0 ) ) {
	res = table_replacenode( 0, OR, a0, a1, v_, l_, h_ );
	is_popm( ref_stack, 6 );
	return res;
      }

      is_popm( ref_stack, 6 );
    }

  } else if ( IS_BOOL_OPERATOR( h ) && ( op_arity( opl ) == 2 ) ) {
    if ( IS_BOOL_OPERATOR( lh ) && ( ( l == LOW( lh ) ) || ( l == HIGH( lh ) ) ) ) {
      uint r0 = is_push( ref_stack, mk( 0, oph, lh, ZERO ) );
      uint t0 = is_push( ref_stack, mk( 0, op, l, r0 ) );

      uint r1 = is_push( ref_stack, mk( 0, oph, lh, ONE ) );
      uint t1 = is_push( ref_stack, mk( 0, op, l, r1 ) );

      uint a0 = is_push( ref_stack, mk( 0, NLIMP, hh, t0 ) );
      uint a1 = is_push( ref_stack, mk( 0, AND, hh, t1 ) );
      
      Op res;

      if ( IS_TERMINAL( t1 ) || IS_TERMINAL( t0 ) ) {
	res = table_replacenode( 0, OR, a0, a1, v_, l_, h_ );
	is_popm( ref_stack, 6 );
	return res;
      }

      is_popm( ref_stack, 6 );
    }

    if ( IS_BOOL_OPERATOR( hh ) && ( ( l == LOW( hh ) ) || ( l == HIGH( hh ) ) ) ) {
      uint r0 = is_push( ref_stack, mk( 0, oph, ZERO, hh ) );
      uint t0 = is_push( ref_stack, mk( 0, op, l, r0 ) );

      uint r1 = is_push( ref_stack, mk( 0, oph, ONE, hh ) );
      uint t1 = is_push( ref_stack, mk( 0, op, l, r1 ) );

      uint a0 = is_push( ref_stack, mk( 0, NLIMP, lh, t0 ) );
      uint a1 = is_push( ref_stack, mk( 0, AND, lh, t1 ) );
      
      Op res;

      if ( IS_TERMINAL( t1 ) || IS_TERMINAL( t0 ) ) {
	res = table_replacenode( 0, OR, a0, a1, v_, l_, h_ );
	is_popm( ref_stack, 6 );
	return res;
      }

      is_popm( ref_stack, 6 );
    }

  }

#define IS_ZERO( u )	( (u) == ZERO )

  /* 3-cut reductions -- 4 operators */
  if ( ( IS_BOOL_OPERATOR( l ) && ( op_arity( opl ) == 2 ) ) &&
       ( IS_BOOL_OPERATOR( h ) && ( op_arity( oph ) == 2 ) ) ) {
    register Op opll = OP( ll ), oplh = OP( lh );
    register Op ophl = OP( hl ), ophh = OP( hh );

    if ( IS_BOOL_OPERATOR( ll ) && ( op_arity( opll ) == 2 ) ) {
      /* Case: 1 */
      uint a = LOW( ll );
      uint b = HIGH( ll );
      if ( ( ( a == lh ) && ( b == hh ) ) ||
	   ( ( a == hh ) && ( b == lh ) ) ) {
	/* Split on hl */
	uint t0 = is_push( ref_stack, build_triple( op, opl, oph, ll, ZERO, lh, hh ) );
	uint t1 = is_push( ref_stack, build_triple( op, opl, oph, ll, ONE, lh, hh ) );
     
	if ( IS_ZERO( t1 ) || IS_ZERO( t0 ) ) {
	  uint a0 = is_push( ref_stack, mk( 0, NLIMP, hl, t0 ) );
	  uint a1 = is_push( ref_stack, mk( 0, AND, hl, t1 ) );
	  Op res = table_replacenode( 0, OR, a0, a1, v_, l_, h_ );
	  is_popm( ref_stack, 4 );
	  return res;
	} else
	  is_popm( ref_stack, 2 );

#if 0
      } else if ( ( ( a == lh ) && ( hl == hh ) ) ||
		  ( ( a == hh ) && ( hl == lh ) ) ) {
	/* Split on b */
	uint r0 = is_push( ref_stack, mk( 0, opll, a, ZERO ) );
	uint r1 = is_push( ref_stack, mk( 0, opll, a, ONE ) );

	uint t0 = is_push( ref_stack, build_triple( op, opl, oph, r0, hl, lh, hh ) );
	uint t1 = is_push( ref_stack, build_triple( op, opl, oph, r1, hl, lh, hh ) );
     
	if ( IS_ZERO( t1 ) || IS_ZERO( t0 ) ) {
	  uint a0 = is_push( ref_stack, mk( 0, NLIMP, b, t0 ) );
	  uint a1 = is_push( ref_stack, mk( 0, AND, b, t1 ) );
	  Op res = table_replacenode( 0, OR, a0, a1, v_, l_, h_ );
	  is_popm( ref_stack, 6 );
	  return res;
	} else
	  is_popm( ref_stack, 4 );

      } else if ( ( ( b == lh ) && ( hl == hh ) ) ||
		  ( ( b == hh ) && ( hl == lh ) ) ) {
	/* Split on a */
	uint r0 = is_push( ref_stack, mk( 0, opll, ZERO, b ) );
	uint r1 = is_push( ref_stack, mk( 0, opll, ONE, b ) );
	
	uint t0 = is_push( ref_stack, build_triple( op, opl, oph, r0, hl, lh, hh ) );
	uint t1 = is_push( ref_stack, build_triple( op, opl, oph, r1, hl, lh, hh ) );
	
	if ( IS_ZERO( t1 ) || IS_ZERO( t0 ) ) {
	  uint a0 = is_push( ref_stack, mk( 0, NLIMP, a, t0 ) );
	  uint a1 = is_push( ref_stack, mk( 0, AND, a, t1 ) );
	  Op res = table_replacenode( 0, OR, a0, a1, v_, l_, h_ );
	  is_popm( ref_stack, 6 );
	  return res;
	} else
	  is_popm( ref_stack, 4 );

#endif
      }
    }

    if ( IS_BOOL_OPERATOR( hl ) && ( op_arity( ophl ) == 2 ) ) {
      /* Case: 2 */
      uint a = LOW( hl );
      uint b = HIGH( hl );
      if ( ( ( a == lh ) && ( b == hh ) ) ||
	   ( ( a == hh ) && ( b == lh ) ) ) {
	/* Split on ll */
	uint t0 = is_push( ref_stack, build_triple( op, opl, oph, ZERO, hl, lh, hh ) );
	uint t1 = is_push( ref_stack, build_triple( op, opl, oph, ONE, hl, lh, hh ) );
     
	if ( IS_ZERO( t1 ) || IS_ZERO( t0 ) ) {
	  uint a0 = is_push( ref_stack, mk( 0, NLIMP, ll, t0 ) );
	  uint a1 = is_push( ref_stack, mk( 0, AND, ll, t1 ) );
	  Op res = table_replacenode( 0, OR, a0, a1, v_, l_, h_ );
	  is_popm( ref_stack, 4 );
	  return res;
	} else
	  is_popm( ref_stack, 2 );

#if 0
      } else if ( ( ( a == lh ) && ( ll == hh ) ) ||
		  ( ( a == hh ) && ( ll == lh ) ) ) {
	/* Split on b */
	uint r0 = is_push( ref_stack, mk( 0, ophl, a, ZERO ) );
	uint r1 = is_push( ref_stack, mk( 0, ophl, a, ONE ) );

	uint t0 = is_push( ref_stack, build_triple( op, opl, oph, ll, r0, lh, hh ) );
	uint t1 = is_push( ref_stack, build_triple( op, opl, oph, ll, r1, lh, hh ) );
     
	if ( IS_ZERO( t1 ) || IS_ZERO( t0 ) ) {
	  uint a0 = is_push( ref_stack, mk( 0, NLIMP, b, t0 ) );
	  uint a1 = is_push( ref_stack, mk( 0, AND, b, t1 ) );
	  Op res = table_replacenode( 0, OR, a0, a1, v_, l_, h_ );
	  is_popm( ref_stack, 6 );
	  return res;
	} else
	  is_popm( ref_stack, 4 );

      } else if ( ( ( b == lh ) && ( ll == hh ) ) ||
		  ( ( b == hh ) && ( ll == lh ) ) ) {
	/* Split on a */
	uint r0 = is_push( ref_stack, mk( 0, ophl, ZERO, b ) );
	uint r1 = is_push( ref_stack, mk( 0, ophl, ONE, b ) );
	
	uint t0 = is_push( ref_stack, build_triple( op, opl, oph, ll, r0, lh, hh ) );
	uint t1 = is_push( ref_stack, build_triple( op, opl, oph, ll, r1, lh, hh ) );
	
	if ( IS_ZERO( t1 ) || IS_ZERO( t0 ) ) {
	  uint a0 = is_push( ref_stack, mk( 0, NLIMP, a, t0 ) );
	  uint a1 = is_push( ref_stack, mk( 0, AND, a, t1 ) );
	  Op res = table_replacenode( 0, OR, a0, a1, v_, l_, h_ );
	  is_popm( ref_stack, 6 );
	  return res;
	} else
	  is_popm( ref_stack, 4 );

#endif
      }
    }

    if ( IS_BOOL_OPERATOR( lh ) && ( op_arity( oplh ) == 2 ) ) {
      /* Case: 3 */
      uint a = LOW( lh );
      uint b = HIGH( lh );
      if ( ( ( a == ll ) && ( b == hl ) ) ||
	   ( ( a == hl ) && ( b == ll ) ) ) {
	/* Split on hh */
	uint t0 = is_push( ref_stack, build_triple( op, opl, oph, ll, hl, lh, ZERO ) );
	uint t1 = is_push( ref_stack, build_triple( op, opl, oph, ll, hl, lh, ONE ) );
     
	if ( IS_ZERO( t1 ) || IS_ZERO( t0 ) ) {
	  uint a0 = is_push( ref_stack, mk( 0, NLIMP, hh, t0 ) );
	  uint a1 = is_push( ref_stack, mk( 0, AND, hh, t1 ) );
	  Op res = table_replacenode( 0, OR, a0, a1, v_, l_, h_ );
	  is_popm( ref_stack, 4 );
	  return res;
	} else
	  is_popm( ref_stack, 2 );

#if 0
      } else if ( ( ( a == ll ) && ( hh == hl ) ) ||
		  ( ( a == hl ) && ( hh == ll ) ) ) {
	/* Split on b */
	uint r0 = is_push( ref_stack, mk( 0, oplh, a, ZERO ) );
	uint r1 = is_push( ref_stack, mk( 0, oplh, a, ONE ) );

	uint t0 = is_push( ref_stack, build_triple( op, opl, oph, ll, hl, r0, hh ) );
	uint t1 = is_push( ref_stack, build_triple( op, opl, oph, ll, hl, r1, hh ) );
     
	if ( IS_ZERO( t1 ) || IS_ZERO( t0 ) ) {
	  uint a0 = is_push( ref_stack, mk( 0, NLIMP, b, t0 ) );
	  uint a1 = is_push( ref_stack, mk( 0, AND, b, t1 ) );
	  Op res = table_replacenode( 0, OR, a0, a1, v_, l_, h_ );
	  is_popm( ref_stack, 6 );
	  return res;
	} else
	  is_popm( ref_stack, 4 );

      } else if ( ( ( b == ll ) && ( hh == hl ) ) ||
		  ( ( b == hl ) && ( hh == ll ) ) ) {
	/* Split on a */
	uint r0 = is_push( ref_stack, mk( 0, oplh, ZERO, b ) );
	uint r1 = is_push( ref_stack, mk( 0, oplh, ONE, b ) );
	
	uint t0 = is_push( ref_stack, build_triple( op, opl, oph, ll, hl, r0, hh ) );
	uint t1 = is_push( ref_stack, build_triple( op, opl, oph, ll, hl, r1, hh ) );
	
	if ( IS_ZERO( t1 ) || IS_ZERO( t0 ) ) {
	  uint a0 = is_push( ref_stack, mk( 0, NLIMP, a, t0 ) );
	  uint a1 = is_push( ref_stack, mk( 0, AND, a, t1 ) );
	  Op res = table_replacenode( 0, OR, a0, a1, v_, l_, h_ );
	  is_popm( ref_stack, 6 );
	  return res;
	} else
	  is_popm( ref_stack, 4 );

#endif
      }
    }

    if ( IS_BOOL_OPERATOR( hh ) && ( op_arity( ophh ) == 2 ) ) {
      /* Case: 4 */
      uint a = LOW( hh );
      uint b = HIGH( hh );
      if ( ( ( a == ll ) && ( b == hl ) ) ||
	   ( ( a == hl ) && ( b == ll ) ) ) {
	/* Split on lh */
	uint t0 = is_push( ref_stack, build_triple( op, opl, oph, ll, hl, ZERO, hh ) );
	uint t1 = is_push( ref_stack, build_triple( op, opl, oph, ll, hl, ONE, hh ) );
     
	if ( IS_ZERO( t1 ) || IS_ZERO( t0 ) ) {
	  uint a0 = is_push( ref_stack, mk( 0, NLIMP, lh, t0 ) );
	  uint a1 = is_push( ref_stack, mk( 0, AND, lh, t1 ) );
	  Op res = table_replacenode( 0, OR, a0, a1, v_, l_, h_ );
	  is_popm( ref_stack, 4 );
	  return res;
	} else
	  is_popm( ref_stack, 2 );

#if 0
      } else if ( ( ( a == ll ) && ( lh == hl ) ) ||
		  ( ( a == hl ) && ( lh == ll ) ) ) {
	/* Split on b */
	uint r0 = is_push( ref_stack, mk( 0, ophh, a, ZERO ) );
	uint r1 = is_push( ref_stack, mk( 0, ophh, a, ONE ) );

	uint t0 = is_push( ref_stack, build_triple( op, opl, oph, ll, hl, lh, r0 ) );
	uint t1 = is_push( ref_stack, build_triple( op, opl, oph, ll, hl, lh, r1 ) );
     
	if ( IS_ZERO( t1 ) || IS_ZERO( t0 ) ) {
	  uint a0 = is_push( ref_stack, mk( 0, NLIMP, b, t0 ) );
	  uint a1 = is_push( ref_stack, mk( 0, AND, b, t1 ) );
	  Op res = table_replacenode( 0, OR, a0, a1, v_, l_, h_ );
	  is_popm( ref_stack, 6 );
	  return res;
	} else
	  is_popm( ref_stack, 4 );

      } else if ( ( ( b == ll ) && ( lh == hl ) ) ||
		  ( ( b == hl ) && ( lh == ll ) ) ) {
	/* Split on a */
	uint r0 = is_push( ref_stack, mk( 0, ophh, ZERO, b ) );
	uint r1 = is_push( ref_stack, mk( 0, ophh, ONE, b ) );
	
	uint t0 = is_push( ref_stack, build_triple( op, opl, oph, ll, hl, lh, r0 ) );
	uint t1 = is_push( ref_stack, build_triple( op, opl, oph, ll, hl, lh, r1 ) );
	
	if ( IS_ZERO( t1 ) || IS_ZERO( t0 ) ) {
	  uint a0 = is_push( ref_stack, mk( 0, NLIMP, a, t0 ) );
	  uint a1 = is_push( ref_stack, mk( 0, AND, a, t1 ) );
	  Op res = table_replacenode( 0, OR, a0, a1, v_, l_, h_ );
	  is_popm( ref_stack, 6 );
	  return res;
	} else
	  is_popm( ref_stack, 4 );

#endif
      }
    }

  }




  /* Symmetry reductions */
  *v_ = 0;
  if ( h < l ) {
    COUNT_REDUCTIONS( red_sym++ );
    *h_ = l;
    *l_ = h;
    return symmetric_operator_array[ op ];
  } else {
    *h_ = h;
    *l_ = l;
    return op;
  }
}


void reduction_stat( FILE *fp )
{
#ifdef COLLECT_STATS
  fprintf( fp, "Reduction statistics\n" );
  fprintf( fp, "Terminal child         : %d\n", red_term_child );
  fprintf( fp, "ID children            : %d\n", red_ID_children );
  fprintf( fp, "2-red                  : %d\n", red_2 );
  fprintf( fp, "3-red 2 grand children : %d\n", red_3_2 );
  fprintf( fp, "3-red 3 grand children : %d\n", red_3_3 );
  fprintf( fp, "Symmetry               : %d\n", red_sym );
  fprintf( fp, "Negation of parent     : %d\n", red_neg_parent );
  fprintf( fp, "Negation of child      : %d\n", red_neg_child );
#else

  fprintf( fp, "No statistics collected. Compile with -DCOLLECT_STATS.\n" );
#endif
}


/*
 * Miminal replacenode()
 *
 */

/* Replacenode() using no simplifications */
static Op mini_replacenode( uint var, Op op, uint l, uint h, uint *v_, uint *l_, uint *h_ )
{
  *v_ = var;
  *l_ = l;
  *h_ = h;

  if ( IS_TERMINAL( l ) && IS_TERMINAL( h )) {
    if ( op != NOP ) {
      *l_ = op_eval( op, l, h );
      return PI1;
    }
    if ( l == h )
      return ( l == ZERO ) ? K0 : K1;
  }

  switch ( op ) {
  case NOP:		/* A variable vertex */
    if ( l == h )
      return PI1;
    else
      return op;

  case PI1:
    if ( IS_TERMINAL( l ) )
      return l == ONE ? K1 : K0;
    *l_ = LOW( l );
    *h_ = HIGH( l );
    *v_ = VAR( l );
    return OP( l );

  case PI2:
    if ( IS_TERMINAL( h ) )
      return h == ONE ? K1 : K0;
    *l_ = LOW( h );
    *h_ = HIGH( h );
    *v_ = VAR( h );
    return OP( h );

  case AND:	
    if ( l == h ) {
      *l_ = l;		return PI1;
    } else if ( (l == ZERO) || (h == ZERO) ) {
      *l_ = ZERO; 	return PI1;
    } else if ( l == ONE ) {
      *l_ = h;		return PI1;
    } else if ( h == ONE ) {
      *l_ = l;		return PI1;
    } 
    break;

  case NAND:
    if ( l == h ) {
      return mini_replacenode( var, NPI1, l, l, v_, l_, h_ );
    } else if ( (l == ZERO) || (h == ZERO) ) {
      *l_ = ONE;	return PI1;
    } else if ( l == ONE ) {
      return mini_replacenode( var, NPI1, h, h, v_, l_, h_ );
    } else if ( h == ONE ) {
      return mini_replacenode( var, NPI1, l, l, v_, l_, h_ );
    } 
    break;

  case OR:
    if ( l == h ) {
      *l_ = l;		return PI1;
    } else if ( (l == ONE) || (h == ONE) ) {
      *l_ = ONE;	return PI1;
    } else if ( l == ZERO ) {
      *l_ = h;		return PI1;
    } else if ( h == ZERO ) {
      *l_ = l;		return PI1;
    } 
    break;

  case NOR:
    if ( l == h ) {
      return mini_replacenode( var, NPI1, l, l, v_, l_, h_ );
    } else if ( (l == ONE) || (h == ONE) ) {
      *l_ = ZERO;	return PI1;
    } else if ( l == ZERO ) {
      return mini_replacenode( var, NPI1, h, h, v_, l_, h_ );
    } else if ( h == ZERO ) {
      return mini_replacenode( var, NPI1, l, l, v_, l_, h_ );
    }
    break;
    
  case BIIMP:
    if ( l == h ) {
      *l_ = ONE;	return PI1;
    } else if ( l == ONE ) {
      *l_ = h;		return PI1;
    } else if ( h == ONE ) {
      *l_ = l;		return PI1;
    } else if ( l == ZERO ) {
      return mini_replacenode( var, NPI1, h, h, v_, l_, h_ );
    } else if ( h == ZERO ) {
      return mini_replacenode( var, NPI1, l, l, v_, l_, h_ );
    } 
    break;

  case XOR:	
    if ( l == h ) {
      *l_ = ZERO;	return PI1;
    } else if ( l == ZERO ) {
      *l_ = h;		return PI1;
    } else if ( h == ZERO ) {
      *l_ = l;		return PI1;
    } else if ( l == ONE ) {
      return mini_replacenode( var, NPI1, h, h, v_, l_, h_ );
    } else if ( h == ONE ) {
      return mini_replacenode( var, NPI1, l, l, v_, l_, h_ );
    } 
    break;

  case NPI1:		/* negation */
    if ( l == ZERO ) {
      *l_ = ONE;	return PI1;
    } else if ( l == ONE ) {
      *l_ = ZERO;	return PI1;
    }
    break;

  case NPI2:		/* negation */
    if ( h == ZERO ) {
      *l_ = ONE;	return PI1;
    } else if ( h == ONE ) {
      *l_ = ZERO;	return PI1;
    }
    break;

#ifndef PURE_BED
  case EXIST:
  case FORALL:
  case SUBST:
  case ESUB:
    if ( IS_TERMINAL( l ) )
      return mini_replacenode( 0, PI1, l, l, v_, l_, h_ );
    break;
#endif

  case IMP:
    if ( l == ONE ) {
      *l_ = h;         return PI1;
    } else if ( (l == ZERO) || (h == ONE) ) {
      *l_ = ONE;       return PI1;
    } else if ( h == ZERO ) {
      return mini_replacenode( var, NPI1, l, l, v_, l_, h_ );      /* negation */
    } else if ( l == h ) {
      *l_ = ONE;       return PI1;
    }
    break;

  case NIMP:
    if ( h == ZERO ) {
      *l_ = l;         return PI1;
    } else if ( (l == ZERO) || (h == ONE) ) {
      *l_ = ZERO;      return PI1;
    } else if ( l == ONE ) {
      return mini_replacenode( var, NPI1, h, h, v_, l_, h_ );      /* negation */
    } else if ( l == h ) {
      *l_ = ZERO;      return PI1;
    }
    break;

  case LIMP:
    if (( h == ZERO ) || ( l == ONE )) {
      *l_ = ONE;       return PI1;
    } else if ( l == ZERO ) {
      return mini_replacenode( var, NPI1, h, h, v_, l_, h_ );      /* negation */
    } else if ( h == ONE ) {
      *l_ = l;         return PI1;
    } else if ( l == h ) {
      *l_ = ONE;       return PI1;
    }
    break;

  case NLIMP:
    if (( h == ZERO ) || ( l == ONE )) {
      *l_ = ZERO;      return PI1;
    } else if ( h == ONE ) {
      return mini_replacenode( var, NPI1, l, l, v_, l_, h_ );      /* negation */
    } else if ( l == ZERO ) {
      *l_ = h;         return PI1;
    } else if ( l == h ) {
      *l_ = ZERO;      return PI1;
    }
    break;

  case K0:
    *l_ =  *h_ = ZERO;      return PI1;
    break;

  case K1:
    *l_ = *h_ = ONE;        return PI1;
    break;

  default:
    fprintf( stderr, "Internal Error: Unknown operator: %d\n", (int) op );
    abort();
  }

  return op;
}
