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

#ifndef op_h_
#define op_h_

#include "bool.h"
#include "bed.h"

/* The possible operators */
typedef enum { 
  NOP	= BED_NOP,		/* No operator */
  VAR	= BED_VAR,		/* Variable ( same as NOP ) */
  ITE	= BED_ITE,		/* If-Then-Else ( same as NOP */
  K0  	= BED_K0, 		/* Constant 0 (should not appear)	*/
  PI1   = BED_PI1,		/* left-child */
  PI2   = BED_PI2,		/* right-child */
  NOR 	= BED_NOR,
  NLIMP	= BED_NLIMP, 		/* Not left-imply */
  NPI1 	= BED_NPI1, 		/* Not left-child */
  NIMP 	= BED_NIMP, 		/* Not imply */
  NPI2 	= BED_NPI2, 		/* Not right-child (should not appear) */
  XOR 	= BED_XOR,
  NAND  = BED_NAND,
  AND   = BED_AND,
  BIIMP = BED_BIIMP,		/* Logical equality */
  IMP   = BED_IMP,		/* Imply */
  LIMP  = BED_LIMP,		/* left-imply */
  OR    = BED_OR,		
  K1    = BED_K1,		/* Constant 1 (should not appear) */
  EXIST = BED_EXISTS,		/* Existential quantifier */
  FORALL= BED_FORALL,		/* Universal quantifier */
  SUBST = BED_SUBST,		/* Substitution */
  ESUB	= BED_ESUB,		/* Experimental exists-&-subst of all variables */
  GARBAGE,			/* Node is marked as garbage and on the free_list */
} Op;

extern char* operator_names[];

char*	op2string( Op op );
Op 		string2op( char *name );
Boolean		is_operator( char *name );
Boolean 	op_is_symmetric( Op op );
unsigned	op_arity( Op op );

Boolean		op_eval( Op op, Boolean a, Boolean b );
#endif
