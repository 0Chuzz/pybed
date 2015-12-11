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

#ifndef kernel_h_
#define kernel_h_
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>		/* Defines uint */

#include "bed.h"
#include "op.h"
#include "istack.h"
#include "ref.h"


/* Define COLLECT_STATS to include statistical info on the reduction rules */

#ifdef COLLECT_STATS
#define COUNT_REDUCTIONS( x ) {x;}
extern uint	number_addnodes;
extern uint	number_makenodes;
extern uint	number_makenodes_terminal;
extern uint	number_upall_parts;
#else
#define COUNT_REDUCTIONS( x )
#endif


/* BED defines */

#define BED_OP_BITS		5		/* Allows for 32 operators 	*/
#define BED_VAR_BITS		16		/* 65k variables		*/
#define BED_EXMARK_BITS         1               /* One mark bit for GC          */

#define BED_MARK_BITS		(32 - BED_OP_BITS - BED_VAR_BITS - BED_EXMARK_BITS )
#define BED_LAST_MARK		((1 << (BED_MARK_BITS))-1)

#define BED_VARS		(1 << (BED_VAR_BITS))	/* Number of vars	*/
#define BED_MAX_VAR		(BED_VARS-2)	/* Number of last var, the last is reserved for the terminals 		*/

/* A BED vertex */
typedef struct {
  uint		var: 	BED_VAR_BITS;	 /* variable index			*/
  Op		op:	BED_OP_BITS;	 /* operator 				*/
  uint          exmark: BED_EXMARK_BITS; /* extra mark bit                      */
  uint 		mark:	BED_MARK_BITS;	 /* mark number				*/
  uint		low;			 /* low child 				*/
  uint		high;			 /* high child 				*/
  uint		H;			 /* Hash Table entry			*/
  uint		next; 	                 /* Collision resolution in hash table	*/
} BED;

#define VAR( u )		( bed_array[u].var )
#define OP( u )			( bed_array[u].op )
#define MARK( u )		( bed_array[u].mark )
#define LOW( u )		( bed_array[u].low )
#define HIGH( u )		( bed_array[u].high )

#define H( u )			( bed_array[u].H )
#define NEXT( u )		( bed_array[u].next )
#define EXMARK( u )             ( bed_array[u].exmark )

#define SET_MARK( u )		( MARK( u ) = kernel_mark_id )
#define TST_MARK( u )		( MARK( u ) == kernel_mark_id )
#define CLR_MARK( u )		( MARK( u ) = 0	)

#define SET_EXMARK( u )		( EXMARK( u ) = 1 )
#define TST_EXMARK( u )		( EXMARK( u ) == 1 )
#define CLR_EXMARK( u )		( EXMARK( u ) = 0 )

#define KEY_PAIR( v, op )	( ((v) << BED_OP_BITS) + ((int) (op)))
#define KEY( u )		( KEY_PAIR( VAR( u ), OP( u ) ))

#define IS_DEFINED( u )		( (u) != BED_UNDEFINED )
#define IS_UNDEFINED( u )	( (u) == BED_UNDEFINED )

#define IS_VALID_NODE( u )	( ((u) >= 0) && ((u) < kernel_nodes) )

#define ZERO			0	/* Zero terminal vertex id 	*/
#define ONE			1	/* One terminal vertex id	*/

#define IS_TERMINAL( u )	( (u) <= 1 )
#define IS_VARIABLE( u )	( !IS_TERMINAL( u ) && (OP( u ) == NOP) )
#define IS_OPERATOR( u )	( !IS_TERMINAL( u ) && (OP( u ) != NOP ))
#define IS_BOOL_OPERATOR( u )	( IS_OPERATOR( u ) && ( OP( u ) <= K1 ) )
#define IS_GARBAGE( u )         ( OP( u ) == GARBAGE )

#define TO_BOOLEAN( u )		( (u) == ZERO ? false : true )

#define	VARS_IN_ORDER( v1, v2 )	( bed_var2level[v1] <= bed_var2level[v2] )


/* Global variables */

extern BED*	bed_array;		/* The one global BED data structure 	*/
extern uint	kernel_mark_id;
extern uint	kernel_nodes;		/* Number of vertices in the BED 	*/
extern uint	kernel_vars;		/* Number of variables in the BED 	*/
extern uint	kernel_number_of_gc;	/* Number of garbage collections	*/

extern FILE*	kernel_err;		/* Output stream for the kernel		*/

extern Hashtbl	ref_count_table;	/* Reference counting on roots		*/
extern iStack*	ref_stack;		/* Internal reference counting		*/

extern unsigned int*	bed_var2level;	/* Map variables to levels		*/
extern bed_var*		bed_level2var;	/* Map levels to variables		*/


/* Initialization, clearing, freeing of the kernel */

void		kernel_init( unsigned long n, unsigned long c );
void		kernel_clear();
void		kernel_done();
Boolean		kernel_resize_bed( long newsize );
void		kernel_resize_caches( long newsize );

void		kernel_clear_caches();
void		kernel_clear_marks();


/* Functions to make nodes */

uint		mk( uint var, Op op, uint low, uint high );

#define		makenode( var, op, low, high )	mk( var, op, low, high )
#define		mk_operator( op, low, high )	mk( 0, op, low, high )
#define		mk_variable( var_id, low, high)	mk( var_id, NOP, low, high )

		/* Don't use 'addnode' unless you are 100% sure of what you
		 * are doing -- and even then: use 'mk' instead!
		 */
uint		addnode( uint var, Op op, uint low, uint high );


/* Garbage collection */

void            kernel_gc();


/* Set ordering */

void		kernel_set_ordering( bed_var *old_level2var );


/* Depth-first search */

void		kernel_dfs( FILE *fp, bed_node node, void (*fnc)( FILE *, bed_node ) );


/* Marking */

int		kernel_reserve_marks( int n );
#define		kernel_set_mark( node, mark )	MARK( node ) = (mark)
#define		kernel_get_mark( node )		MARK( node )
void		kernel_clear_marks();


/* Kernel information */

bed_info	kernel_get_info();

void		kernel_reduction_stat();	/* For debugging the kernel	*/
void		kernel_hash_stat();		/* Ditto			*/
Boolean		kernel_check();			/* Ditto			*/


#endif
