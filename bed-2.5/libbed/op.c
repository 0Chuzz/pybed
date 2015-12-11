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

#include "op.h"
#include "kernel.h"

#ifndef equal
#define equal( s1, s2 )	( 0 == strcmp( s1, s2 ))
#endif

typedef struct OpInfo {
  Op		id;
  char*		name;
  Boolean	is_symmetric: 1;
  int		arity;
  Boolean	ok_in_bed_file:1;
} OpInfo;

static OpInfo operators[] = {
  {	NOP, 	"ite", 		false,	0,	false },
  {	K0,	"false",	false,	0,	false },
  {	PI1,	"buff",		false,	1,	true },
  {	PI2,	"pi2",		false,	1,	false },
  {	NOR, 	"nor",		true,	2,	true },
  {	NLIMP,	"nlimp",	false,	2,	true },
  {	NPI1, 	"not",		false,	1,	true },
  {	NIMP,	"nimp",		false,	2,	true },
  {	NPI2,	"npi2",		false,	1,	false },
  {	XOR,	"xor",		true,	2,	true },
  {	NAND,	"nand",		true,	2,	true },
  {	AND,	"and",		true,	2,	true },
  {	BIIMP,	"biimp",	true,	2,	true },
  {	IMP,	"imp",		false,	2,	true },
  {	LIMP,	"limp",		false,	2,	true },
  {	OR,	"or",		true,	2,	true },
  {	K1,	"true",		false,	0,	false },
  {	EXIST,	"?",		false,	3,	true },
  {	FORALL,	"!",		false,	3,	true },
  {	SUBST,	":=",		false,	3,	true },
  {	ESUB,	"ESUB",		false,	0,	false },
  {	GARBAGE, "<garbage>",	false,	0,	false },
  {	NOP,	"",		false,	0,	false }	/* Dummy row */
};

char *op2string( Op op )
{
  /* This relies on the fact that the order in which the operators are listed 
   * in the array 'operators' is exactly the same as the order the operators
   * are defined in the 'typedef enum { ... } Op;' definition. 
   */
  return operators[op].name;
}

static int op_index( char *name )
{
  switch ( name[0] ) {
  case 'E':	if (equal(name,"ESUB"))	return (int) ESUB;	break;
  case 'N':	if (equal(name,"NOP"))	return (int) NOP;	break;
  case 'V':	if (equal(name,"VAR"))	return (int) VAR;	break;
  case 'a':	if (equal(name,"and"))	return (int) AND;	break;
  case 'b':	if (equal(name,"buff"))	return (int) PI1;	else 
    		if (equal(name,"biimp"))return (int) BIIMP;	break;
  case 'i':	if (equal(name,"imp"))	return (int) IMP;	else
    		if (equal(name,"ite"))	return (int) ITE;	break;
  case 'l':	if (equal(name,"limp"))	return (int) LIMP;	break;
  case 'n':	
    switch( name[1] ) {
    case 'a':	if (equal(name,"nand"))	return (int) NAND;	break;
    case 'i':	if (equal(name,"nimp"))	return (int) NIMP;	break;
    case 'l':	if (equal(name,"nlimp"))return (int) NLIMP;	break;
    case 'o':	if (equal(name,"nor"))	return (int) NOR;	else
      	        if (equal(name,"not"))	return (int) NPI1;	break;
    case 'p':	if (equal(name,"npi2"))	return (int) NPI2;	break;
    default:	break;
    }
    break;

  case 'o':	if (equal(name,"or"))	return (int) OR;	break;
  case 'p':	if (equal(name,"pi2"))	return (int) PI2;	break;
  case 'x':	if (equal(name,"xor"))	return (int) XOR;	break;

  case '?':     if (equal(name,"?"))	return (int) EXIST;	break;

  case '!':	if (equal(name,"!"))	return (int) FORALL;	break;
  case ':':	if (equal(name,":="))	return (int) SUBST;	break;
  default:
    break;
  }
  return -1;	/* Indicates we didn't find it */
}

Boolean is_operator( char *name )
{
  return ( op_index( name ) >= 0 );
}

Op string2op( char *name ) 
{
  /* Nothing applied */
  int idx = op_index( name );

  if ( idx >= 0 )
    return (Op) idx;
  
  return GARBAGE;
}

Boolean op_is_symmetric( Op op )
{
  return operators[op].is_symmetric;
}


unsigned op_arity( Op op )
{
  return operators[op].arity;
}

Boolean op_eval( Op op, Boolean a, Boolean b )
{
  assert( IS_TERMINAL( a ));
  assert( IS_TERMINAL( b ));

  switch ( op ) {
  case K0: 	return false;
  case NOR: 	return (!(a || b ));
  case PI1:	return (a);
  case PI2:	return (b);
  case NLIMP: 	return (b && !a);
  case NPI1: 	return (!a);
  case NIMP:	return (a && !b);
  case NPI2:	return (!b);
  case XOR:	return (a ^ b);
  case NAND:	return (!(a && b));
  case AND:	return (a && b);
  case BIIMP:	return (a == b);
  case IMP:	return (!a || b);
  case LIMP:	return (!b || a);
  case OR: 	return (a || b);
  case K1: 	return true;
  case EXIST:	return (a || b);
  case FORALL:	return (a && b);
  case SUBST:	return (a);
  case ESUB:	return (a);
  case NOP:
  default:
    fprintf( stderr, "*** Internal error: Unknown or illegal operator '%d'\n", (int) op );
    abort();    
  }
}


/* Used when creating the reduction tables */
char* operator_names[] = {
  	"NOP"	,
  	"K0"	,
  	"PI1"	,
  	"PI2"	,
  	"NOR"	,
  	"NLIMP"	,
  	"NPI1"	,
  	"NIMP"	,
  	"NPI2"	,
  	"XOR"	,
  	"NAND"	,
  	"AND"	,
  	"BIIMP"	,
  	"IMP"	,
  	"LIMP"	,
  	"OR"	,
  	"K1"	
};
