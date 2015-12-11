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

#include <time.h>
#include <math.h>

#ifdef PI2
#undef PI2
#endif

#include "bed.h"
#include "kernel.h"
#include "upall.h"
#include "upone.h"
#include "upsome.h"
#include "ref.h"
#include "malloc.h"
#include "bool.h"
#include "sat.h"
#include "op.h"
#include "restrict.h"
#include "simplify.h"
#include "cache.h"
#include "quant.h"
#include "upsome.h"


/* 
 * ====[ Global variables ]====================================================
 */

const bed_node		bed_zero		= ZERO;
const bed_node		bed_one			= ONE;

#define			bed_true		bed_one
#define			bed_false		bed_zero

Boolean			bed_do_reductions	= true;

static char*		default_variable_to_name( unsigned int );	/* Prototype */
static char*		default_node_to_name( unsigned int );		/* Prototype */
char*			(*bed_var2name)(bed_var)	= default_variable_to_name;
char*			(*bed_node2name)(bed_node)	= default_node_to_name;


/* 
 * ====[ Local variables ]====================================================
 */

static unsigned int	node_count_number	= 0;
static iList*		support_list		= NULL;

static bed_node		target_node;
static Boolean		result;

static Boolean		is_running		= false;


/* 
 * ====[ Initialization, clearing, and freeing of BEDs ]=======================
 */

/*
NAME	{* bed\_init *}
SHORT	{* Initializes the BED package *}
PROTO	{* void bed_init( unsigned long n, unsigned long c ) *}
DESCR	{* Initializes the BED package. The parameter $n$ specifies the
	   number of bytes to allocate for vertices while $c$ specifies
	   the number of bytes to allocate for the cache. *}
RETURN	{* *}
ALSO	{* bed\_done, bed\_clear, bed\_is\_running *}
*/

void bed_init( unsigned long n, unsigned long c )
{
  if ( is_running )
    return;

  kernel_init( n / sizeof( BED ), c / sizeof( Cache ) );

  if ( Hashtbl_init( &ref_count_table ) < 0 ) {
    fprintf( stderr, "BED: Error, not enough memory!\n" );
    exit( 1 );
  }

  bed_level2var = MALLOC( bed_var );
  bed_var2level = MALLOC( unsigned int );
  bed_level2var[0] = 0;
  bed_var2level[0] = 0;

  srandom( time( NULL ) );

  is_running = true;
}


/*
NAME	{* bed\_clear *}
SHORT	{* Clears any existing BED in memory *}
PROTO	{* void bed_clear() *}
DESCR	{* Clears any existing BED in memory and empties the cache. *}
RETURN	{* *}
ALSO	{* bed\_init, bed\_done, bed\_clear\_cache *}
*/

void bed_clear()
{
  if ( ! is_running )
    return;

  if ( kernel_vars != 0 )
    kernel_clear();

  Hashtbl_done( &ref_count_table );
  if ( Hashtbl_init( &ref_count_table ) < 0 ) {
    fprintf( stderr, "BED: Error, not enough memory!\n" );
    exit( 1 );
  }

  if ( bed_var2level != NULL )
    free( bed_var2level );
  bed_var2level = MALLOC( unsigned int );
  bed_var2level[0] = 0;

  if ( bed_level2var != NULL )
    free( bed_level2var );
  bed_level2var = MALLOC( bed_var );
  bed_level2var[0] = 0;
}


/*
NAME	{* bed\_clear\_cache *}
SHORT	{* Clears the internal cache *}
PROTO	{* void bed_clear_cache() *}
DESCR	{* Clears the internal cache. *}
RETURN	{* *}
ALSO	{* bed\_clear *}
*/

void bed_clear_cache()
{
  if ( ! is_running )
    return;

  kernel_clear_caches();

}



/*
NAME	{* bed\_done *}
SHORT	{* Terminates the use of the BED package *}
PROTO	{* void bed_done() *}
DESCR	{* Terminates the use of the BED package by freeing memory. *}
RETURN	{* *}
ALSO	{* bed\_init, bed\_clear, bed\_is\_running *}
*/

void bed_done()
{
  if ( ! is_running )
    return;

  kernel_done();

  Hashtbl_done( &ref_count_table );

  if ( bed_var2level != NULL )
    free( bed_var2level );

  if ( bed_level2var != NULL )
    free( bed_level2var );

  is_running = false;
}


/*
NAME	{* bed\_is\_running *}
SHORT	{* Check if the BED package is running *}
PROTO	{* Boolean bed_is_running() *}
DESCR	{* Returns true if the BED package is running. The BED package
	   is running after the function bed\_init has been called and
	   until the function bed\_done has been called. *}
RETURN	{* Boolean *}
ALSO	{* bed\_init, bed\_done *}
*/

Boolean bed_is_running()
{
  return is_running;
}


/* Building and manipulating BEDs */

/*
NAME	{* bed\_new\_variables *}
SHORT	{* Declares new variables *}
PROTO	{* bed_var bed_new_variables( unsigned int number ) *}
DESCR	{* Declares $number$ new Boolean variables. The variables are
	   identified by $number$ successive numbers starting from the return value. *}
RETURN	{* bed\_var *}
ALSO	{* *}
*/

bed_var bed_new_variables( unsigned int number )
{
  unsigned int i;
  bed_var first = kernel_vars;

  if ( ! is_running )
    return BED_UNDEFINED;

  bed_var2level = (uint*) Realloc( (char*) bed_var2level,
				   ( kernel_vars + number + 1 ) * sizeof( unsigned int ) );
  bed_level2var = (bed_var*) Realloc( (char*) bed_level2var,
				      ( kernel_vars + number + 1 ) * sizeof( unsigned int ) );
  kernel_vars += number;

  for ( i = first; i <= kernel_vars; i++ ) {
    bed_var2level[ i ] = i;
    bed_level2var[ i ] = i;
  }

  up_some_expand_vector( kernel_vars );

  /* Maintain BED array invariant */
  VAR(ZERO)	= kernel_vars;
  VAR(ONE)	= kernel_vars;

  return first;
}


/*
NAME	{* bed\_mk *}
SHORT	{* Creates a BED vertex *}
PROTO	{* bed_node bed_mk( bed_var var, bed_op op, bed_node low, bed_node high ) *}
DESCR	{* Creates a BED vertex with variable $var$, operator $op$, low child
	   $low$, and high child $high$. Special care should be taken to avoid building
	   BEDs which are not free. *}
RETURN	{* bed\_node *}
ALSO	{* Other bed\_mk functions *}
*/

bed_node bed_mk( bed_var var, bed_op op, bed_node low, bed_node high )
{
  if ( ! is_running )
    return BED_UNDEFINED;
  return mk( var, op, low, high );
}

/*
NAME	{* bed\_mk\_var *}
SHORT	{* Creates a BED variable vertex *}
PROTO	{* bed_node bed_mk_var( bed_var var, bed_node low, bed_node high ) *}
DESCR	{* Creates a vertex for the Boolean function \emph{if var then high else low}.
	   Special care should be taken to avoid building BEDs which are not free. *}
RETURN	{* bed\_node *}
ALSO	{* Other bed\_mk functions *}
*/

/*
NAME	{* bed\_mk\_op *}
SHORT	{* Creates a BED operator vertex *}
PROTO	{* bed_node bed_mk_op( bed_op op, bed_node low, bed_node high ) *}
DESCR	{* Creates a vertex for the Boolean function $low\ op\ high$. *}
RETURN	{* bed\_node *}
ALSO	{* Other bed\_mk functions *}
*/

/*
NAME	{* bed\_mk\_not *}
SHORT	{* Creates a BED negation vertex *}
PROTO	{* bed_node bed_mk_not( bed_node node ) *}
DESCR	{* Creates a vertex for the Boolean function $not\ node$. *}
RETURN	{* bed\_node *}
ALSO	{* Other bed\_mk functions *}
*/

/*
NAME	{* bed\_mk\_exists *}
SHORT	{* Creates a BED existential quantification vertex *}
PROTO	{* bed_node bed_mk_exist( bed_var var, bed_node node ) *}
DESCR	{* Creates a vertex for the Boolean function $\exists\ var\ :\ node$. *}
RETURN	{* bed\_node *}
ALSO	{* Other bed\_mk functions *}
*/

/*
NAME	{* bed\_mk\_forall *}
SHORT	{* Universal quantification of a BED variable *}
PROTO	{* bed_node bed_mk_forall( bed_var var, bed_node node ) *}
DESCR	{* Creates a BED for the Boolean function $\forall\ var\ :\ node$. *}
RETURN	{* bed\_node *}
ALSO	{* Other bed\_mk functions *}
*/

/*
NAME	{* bed\_mk\_subst *}
SHORT	{* Creates a BED substitution vertex *}
PROTO	{* bed_node bed_mk_subst( bed_var var, bed_node in_node, bed_node with_node ) *}
DESCR	{* Creates a vertex for the Boolean function $in\_node[var:=with\_node]$.*}
RETURN	{* bed\_node *}
ALSO	{* Other bed\_mk functions *}
*/

/*
NAME	{* bed\_mk\_esub *}
SHORT	{* Creates a BED esub vertex *}
PROTO	{* bed_node bed_mk_esub( bed_node node ) *}
DESCR	{* Creates a vertex for the Boolean function existentially quantifying all
	   variables with an even number and substitute all odd variables
	   with variables having a number which is one less. This is useful in
	   fixed-point computations. *}
RETURN	{* bed\_node *}
ALSO	{* Other bed\_mk functions *}
*/



/*
NAME	{* bed\_upall *}
SHORT	{* Transforms a BED to a BDD *}
PROTO	{* bed_node bed_upall( bed_node node ) *}
DESCR	{* Transforms a BED to a BDD by removing all operator vertices.
	   The transformation closely resembles the standard BDD apply algorithm
	   for building BDDs. The variable ordering of the resulting BDD is the
	   global variables ordering set by bed\_set\_ordering.*}
RETURN	{* bed\_node *}
ALSO	{* bed\_upone, bed\_upone\_iter, bed\_upsome, bed\_set\_ordering *}
*/

bed_node bed_upall( bed_node node )
{
  if ( ! is_running )
    return BED_UNDEFINED;
  return up_all( node );
}

/*
NAME	{* bed\_upone *}
SHORT	{* Lifts one variable up *}
PROTO	{* bed_node bed_upone( bed_var var, bed_node node ) *}
DESCR	{* Lifts the variable $var$ up. How far the variable is lifted depends
	   on the current mode. In BED\_UPONE\_MODE\_ORDER mode, upone lifts
	   $var$ to either vertex $node$ or to just below a variable
	   vertex with a variable which comes before $var$ in the global ordering.
	   In BED\_UPONE\_MODE\_STRICT mode, upone lifts $var$ to vertex $node$. *}
RETURN	{* bed\_node which is the root of a BED *}
ALSO	{* bed\_upall, bed\_upone\_iter, bed\_upsome, bed\_set\_ordering,
	   bed\_get\_upone\_mode, bed\_set\_upone\_mode *}
*/

bed_node bed_upone( bed_var var, bed_node node )
{
  if ( ! is_running )
    return BED_UNDEFINED;
  return up_one( var, node );
}

/*
NAME	{* bed\_upone\_iter *}
SHORT	{* Transforms a BED to a BDD *}
PROTO	{* bed_node bed_upone_iter( bed_node node ) *}
DESCR	{* Transforms a BED to a BDD by lifting all variables up above the
	   operators vertices. The variables are lifted up in the order set by
	   bed\_set\_ordering. *}
RETURN	{* bed\_node which is the root of a BDD *}
ALSO	{* bed\_upone, bed\_upall, bed\_upsome, bed\_set\_ordering *}
*/

bed_node bed_upone_iter( bed_node node )
{
  if ( ! is_running )
    return BED_UNDEFINED;
  return up_one_iter( stdout, node );
}

/*
NAME	{* bed\_upsome *}
SHORT	{* Lifts a set of variables up *}
PROTO	{* bed_node bed_upsome( bed_var_list *vars, bed_node node ) *}
DESCR	{* Lifts the variables $vars$ up to vertex $node$. Uses the global
	   ordering, however, variables in $vars$ are always lifted above
	   variables outside $vars$. *}
RETURN	{* bed\_node which is the root of a BED *}
ALSO	{* bed\_upall, bed\_upone\_iter, bed\_set\_ordering *}
*/

bed_node bed_upsome( bed_var_list *vars, bed_node node )
{
  if ( ! is_running )
    return BED_UNDEFINED;
  up_some_set_vector( vars );
  return up_some( node );
}


/*
NAME	{* bed\_restrict *}
SHORT	{* Restricts a variable to a Boolean value *}
PROTO	{* bed_node bed_restrict( bed_node u, bed_var var, Boolean val ) *}
DESCR	{* The standard BDD restrict. This function returns a BED in which
	   all occurences of $var$ are replaced with either $low(var)$ or $high(var)$
	   depending on whether $val$ is \textbf{false} or \textbf{true}. *}
RETURN	{* bed\_node which is the root of a BED *}
ALSO	{*  *}
*/

bed_node bed_restrict( bed_node u, bed_var var, Boolean val ) 
{
  if ( ! is_running )
    return BED_UNDEFINED;
  return restrict_( u, var, val );
}


/*
NAME	{* bed\_simplify *}
SHORT	{* Simplifies a formula under a condition *}
PROTO	{* bed_node bed_simplify( bed_node u, bed_node c ) *}
DESCR	{* The simplify function from Coudert, Berthet, and Madre (1989).
	   The BED $u$ is simplified to a BED $u'$ such that
	   $f^c \rightarrow (f^u = f^{u'})$, where $f^v$ is the formula
	   represented by BED $v$. *}
RETURN	{* bed\_node which is the root of a BED *}
ALSO	{*  *}
*/

bed_node bed_simplify( bed_node u, bed_node c )
{
  if ( ! is_running )
    return BED_UNDEFINED;
  return simplify( u, c );
}


/*
NAME	{* bed\_quantdown *}
SHORT	{* Pushes quantifiers down into a formula *}
PROTO	{* bed_node bed_quantdown( bed_node u ) *}
DESCR	{* Pushes quantifiers down into a formula. This works best if
	   the reduction rules are turned on. *}
RETURN	{* bed\_node which is the root of a BED *}
ALSO	{*  *}
*/

bed_node bed_quantdown( bed_node u )
{
  if ( ! is_running )
    return BED_UNDEFINED;
  return quantdown( u );
}


/*
NAME	{* bed\_apply *}
SHORT	{* Connects two BDDs with a Boolean connective *}
PROTO	{* bed_node bed_apply( bed_op op, bed_node low, bed_node high ) *}
DESCR	{* The standard BDD apply. This function assumes that both $low$
	   and $high$ are BDDs. The result is a BDD. The ordering used is
	   the global ordering set by bed\_set\_ordering. *}
RETURN	{* bed\_node which is the root of a BDD *}
ALSO	{* bed\_upall, bed\_upone\_iter, bed\_set\_ordering *}
*/

bed_node bed_apply( bed_op op, bed_node low, bed_node high )
{
  if ( ! is_running )
    return BED_UNDEFINED;
  return upall_parts( 0, op, low, high, true );
}

/* 
 * ====[ Reference counting ]===================================================
 */

/*
NAME	{* bed\_ref *}
SHORT	{* Reference count a vertex *}
PROTO	{* bed_node bed_ref( bed_node node ) *}
DESCR	{* Mark the vertex $node$ and all vertices reachable from it so that they
	   will not be garbage collected. Use bed\_deref to unmark a vertex. All
	   functions expect their input to be marked and return unmarked vertices.
	   It is possible to call bed\_ref multiple times for a vertex, in which
	   case bed\_deref should be called the same number of times. *}
RETURN	{* The input vertex $node$ *}
ALSO	{* bed\_deref *}
*/

bed_node bed_ref( bed_node node )
{
  if ( !is_running || IS_UNDEFINED( node ) )
    return BED_UNDEFINED;

  Hashtbl_addref( &ref_count_table, node );
  return node;
}

/*
NAME	{* bed\_deref *}
SHORT	{* Dereference count a vertex *}
PROTO	{* void bed_deref( bed_node node ) *}
DESCR	{* Unmark the vertex $node$ which has previously been marked by bed\_ref. *}
RETURN	{* *}
ALSO	{* bed\_ref *}
*/

void bed_deref( bed_node node )
{
  if ( !is_running || IS_UNDEFINED( node ) )
    return;
  Hashtbl_delref( &ref_count_table, node );
}


/* 
 * ====[ Ordering ]==============================================================
 */

/*
NAME	{* bed\_set\_ordering *}
SHORT	{* Sets the variable ordering *}
PROTO	{* void bed_set_ordering( bed_var_list *var_list ) *}
DESCR	{* Sets the variable ordering to the order in which the variables occur
	   in $var\_list$. Variables which are not mentioned are placed last in
	   the ordering. The default ordering is the ordering in which the
	   variables have been declared. *}
RETURN	{* *}
ALSO	{* bed\_get\_ordering *}
*/

void bed_set_ordering( bed_var_list *var_list )
{
  unsigned int i;
  unsigned int* old_level2var;
  iList* order;
  Boolean *mark;

  if ( ! is_running )
    return;

  if ( kernel_vars == 0 )
    return;

  if ( il_length( var_list ) == 0 )
    return;

  mark = MALLOC_ARRAY( kernel_vars, Boolean );
  for ( i = 0; i < kernel_vars; i++ )
    mark[ i ] = false;
    
  for ( i = 0; i < il_length( var_list ); i++ )
    mark[ il_elem( var_list, i ) ] = true;

  order = il_copy( var_list );
  old_level2var = MALLOC_ARRAY( kernel_vars, bed_var );
  
  memcpy( old_level2var, bed_level2var, kernel_vars * sizeof( bed_var ) );

  for ( i = 0; i < kernel_vars; i++ )
    if ( ! mark[ bed_level2var[ i ] ] ) {
      mark[ bed_level2var[ i ] ] = true;
      il_append( order, bed_level2var[ i ] );
    }

  free( mark );
#if 0
    if ( ! il_has( order, bed_level2var[ i ] ) )
      il_append( order, bed_level2var[ i ] );
#endif

  for ( i = 0; i < kernel_vars; i++ ) {
    bed_var var = il_elem( order, i );
    bed_var2level[ var ] = i;
    bed_level2var[ i ] = var;
  }
 
  il_free( order );

  /*  kernel_set_ordering( old_level2var ); */
  kernel_clear_caches();

  free( old_level2var );
}

/*
NAME	{* bed\_get\_ordering *}
SHORT	{* Returns the current variable ordering *}
PROTO	{* bed_var_list* bed_get_ordering() *}
DESCR	{* Returns the current variable ordering. *}
RETURN	{* bed\_var\_list* *}
ALSO	{* bed\_set\_ordering *}
*/

bed_var_list* bed_get_ordering()
{
  int i;
  bed_var_list *order;
  if ( ! is_running )
    return NULL;

  order = il_new();

  for ( i=0; i < kernel_vars; i++ )
    il_append( order, bed_level2var[ i ] );
  
  return order;
}


/* 
 * ====[ Garbage collection ]============================================================
 */

/*
NAME	{* bed\_gc *}
SHORT	{* Garbage collection *}
PROTO	{* void bed_gc() *}
DESCR	{* Performs a garbage collection. All vertices which are not marked by
	   bed\_ref and cannot be reached from a marked vertex are garbage collected.
	   Garbage collection happens automatically when the BED package runs out of
	   memory. *}
RETURN	{* *}
ALSO	{* bed\_external\_gc *}
*/

void bed_gc()
{
  if ( ! is_running )
    return;
  kernel_gc();
}

/*
NAME	{* bed\_external\_gc *}
SHORT	{* Function called by the garbage collector *}
PROTO	{* void (*bed_external_gc)() *}
DESCR	{* The function pointed to by bed\_external\_gc is called
	   by the garbage collecter before any garbage collection is done.
	   Default is NULL meaning no function is called. *}
RETURN	{* *}
ALSO	{* bed\_gc, bed\_external\_gc\_post *}
*/

void (*bed_external_gc)() = NULL;			/* Function which is called */
							/* before garbage collection */

/*
NAME	{* bed\_external\_gc\_post *}
SHORT	{* Function called by the garbage collector *}
PROTO	{* void (*bed_external_gc_post)() *}
DESCR	{* The function pointed to by bed\_external\_gc is called
	   by the garbage collecter after the garbage collection has been done.
	   Default is NULL meaning no function is called. *}
RETURN	{* *}
ALSO	{* bed\_gc, bed\_external\_gc *}
*/

void (*bed_external_gc_post)() = NULL;			/* Function which is called */
							/* after garbage collection */


/* 
 * ====[ Examining BEDs ]==============================================================
 */


static void bed_dfs( FILE *fp, bed_node node, void (*fnc)( FILE *, bed_node ) )
{
  kernel_dfs( fp, node, fnc );
  kernel_clear_marks();
}

static void is_reachable( FILE *fp, bed_node node )
{
  if ( node == target_node )
    result = true;
}

/*
NAME	{* bed\_is\_reachable *}
SHORT	{* Reachability of a vertex from another vertex *}
PROTO	{* Boolean bed_is_reachable( bed_node node, bed_node from_node ) *}
DESCR	{* Returns true if vertex $node$ is reachable from vertex $from\_node$. *}
RETURN	{* Boolean *}
ALSO	{* *}
*/

Boolean bed_is_reachable( bed_node node, bed_node from_node )
{
  if ( ! is_running )
    return false;

  target_node = node;
  result = false;

  if ( ( node == bed_zero ) && ( from_node != bed_one ) )
    return true;

  if ( ( node == bed_one ) && ( from_node != bed_zero ) )
    return true;

  bed_dfs( stdout, from_node, is_reachable );

  return result;
}

static void is_bdd( FILE *fp, bed_node node )
{
  if ( ! IS_VARIABLE( node ) )
    result = false;
}

/*
NAME	{* bed\_is\_bdd *}
SHORT	{* Tests whether a BED is a BDD *}
PROTO	{* Boolean bed_is_bdd( bed_node node ) *}
DESCR	{* Returns true if the BED at vetex $node$ is a BDD. *}
RETURN	{* Boolean *}
ALSO	{* *}
*/

Boolean bed_is_bdd( bed_node node )
{
  if ( ! is_running )
    return false;

  result = true;

  bed_dfs( stdout, node, is_bdd );

  return result;
}

/*
NAME	{* bed\_sat\_count *}
SHORT	{* Counts satisfying assignments *}
PROTO	{* double bed_sat_count( bed_node node ) *}
DESCR	{* Returns the number of satisfying assignments of the Boolean function
	   represented by vertex $node$. $node$ must be a BDD. *}
RETURN	{* double. A negative number indicates an error. *}
ALSO	{* *}
*/

double bed_sat_count( bed_node node )
{
  if ( ! is_running )
    return -5.0;

  if ( bed_is_bdd( node ) )
    return sat_count( node );
  else
    return -1.0;
}


/*
NAME	{* bed\_any\_sat *}
SHORT	{* Returns a satisfying assignment *}
PROTO	{* bed_var_list* bed_any_sat( bed_node node ) *}
DESCR	{* Returns a satisfying assignment for the BED rooted at $node$. The result
	   is a list of variables which are assigned the value true. *}
RETURN	{* bed\_var\_list* *}
ALSO	{* bed\_any\_nonsat *}
*/

bed_var_list* bed_any_sat( bed_node node )
{
  if ( ! is_running )
    return NULL;

  if ( bed_is_bdd( node ) )
    return any_sat( node );
  else
    return NULL;
}

/*
NAME	{* bed\_any\_nonsat *}
SHORT	{* Returns a non-satisfying assignment *}
PROTO	{* bed_var_list* bed_any_nonsat( bed_node node ) *}
DESCR	{* Returns a non-satisfying assignment for the BED rooted at $node$. The
	   result is a list of variables which are assigned the value true. *}
RETURN	{* bed\_var\_list* *}
ALSO	{* bed\_any\_sat *}
*/

bed_var_list* bed_any_nonsat( bed_node node )
{
  if ( ! is_running )
    return NULL;

  if ( bed_is_bdd( node ) )
    return any_nonsat( node );
  else
    return NULL;
}

static Boolean evaluate( bed_node node, bed_var_list *assignment, int mark )
{
  Boolean res;

  if ( kernel_get_mark( node ) == mark )
    return bed_zero;
  if ( kernel_get_mark( node ) == mark+1 )
    return bed_one;

  if ( IS_VARIABLE( node ) ) {
    bed_var var = bed_get_var( node );
    if ( il_has( assignment, var ) )
      res = evaluate( HIGH( node ), assignment, mark );
    else
      res = evaluate( LOW( node ), assignment, mark );

  } else {
    Boolean low, high;
    low = evaluate( LOW( node ), assignment, mark );
    high = evaluate( HIGH( node ), assignment, mark );

    res = op_eval( OP( node ), low, high );
  }

  if ( res )
    kernel_set_mark( node, mark+1 );
  else
    kernel_set_mark( node, mark );

  return res;
}

/*
NAME	{* bed\_evaluate *}
SHORT	{* Evaluates a truth assignment on a BED *}
PROTO	{* Boolean bed_evaluate( bed_node node, bed_var_list* assignment ) *}
DESCR	{* Returns true if the truth assignment $assignment$ evaluates to
	   true on the BED $node$. The assignment is a list of variables assigned
	   the value true. *}
RETURN	{* Boolean *}
ALSO	{* *}
*/

Boolean bed_evaluate( bed_node node, bed_var_list *assignment )
{
  Boolean res;
  int mark;

  if ( ! is_running )
    return false;

  mark = kernel_reserve_marks( 2 );	/* mark+0 : false ; mark+1 : true */

  kernel_set_mark( bed_zero, mark );
  kernel_set_mark( bed_one, mark+1 );

  res = evaluate( node, assignment, mark );

  kernel_clear_marks();
  return res;
}

static void node_count( FILE *fp, bed_node node )
{
  node_count_number++;
}

/*
NAME	{* bed\_node\_count *}
SHORT	{* Counts the number of vertices *}
PROTO	{* unsigned int bed_node_count( bed_node node ) *}
DESCR	{* Counts the number of vertices in the BED rooted at $node$. Terminal
	   vertices are not counted. *}
RETURN	{* unsigned int *}
ALSO	{* *}
*/

unsigned int bed_node_count( bed_node node )
{
  if ( ! is_running )
    return 0;

  node_count_number = 0;

  bed_dfs( stdout, node, node_count );
  kernel_clear_marks();

  return node_count_number;
}

static void support( FILE *fp, bed_node node )
{
  if ( IS_VARIABLE( node )) {
    /*    bed_var var = bed_level2var[ VAR( node ) ]; */
    bed_var var = VAR( node );
    
    if ( ! il_has( support_list, var ) )
      il_append( support_list, var );
  }
}

/*
NAME	{* bed\_support *}
SHORT	{* Returns the support of a BED *}
PROTO	{* bed_var_list* bed_support( bed_node node ) *}
DESCR	{* Returns the support of the BED $node$. The support is a list of all
	   the variables occurring in $node$ and the vertices reachable from it. *}
RETURN	{* bed\_var\_list* *}
ALSO	{* *}
*/

bed_var_list* bed_support( bed_node node )
{
  if ( ! is_running )
    return NULL;

  support_list = il_new();
  bed_dfs( stdout, node, support );
  return support_list;
}


/* 
 * ====[ Traversing BEDs ]==============================================================
 */

/*
NAME	{* bed\_get\_low *}
SHORT	{* Returns the low child *}
PROTO	{* bed_node bed_get_low( bed_node node ) *}
DESCR	{* Returns the low child of vertex $node$. *}
RETURN	{* bed\_node *}
ALSO	{* bed\_get\_high, bed\_get\_op, bed\_get\_var *}
*/

bed_node bed_get_low( bed_node node )
{
  if ( ! is_running )
    return BED_UNDEFINED;
  return LOW( node );
}

/*
NAME	{* bed\_get\_high *}
SHORT	{* Returns the high child *}
PROTO	{* bed_node bed_get_high( bed_node node ) *}
DESCR	{* Returns the high child of vertex $node$. *}
RETURN	{* bed\_node *}
ALSO	{* bed\_get\_low, bed\_get\_op, bed\_get\_var *}
*/

bed_node bed_get_high( bed_node node )
{
  if ( ! is_running )
    return BED_UNDEFINED;
  return HIGH( node );
}

/*
NAME	{* bed\_get\_var *}
SHORT	{* Returns the variable*}
PROTO	{* bed_var bed_get_var( bed_node node ) *}
DESCR	{* Returns the variable of vertex $node$. *}
RETURN	{* bed\_var *}
ALSO	{* bed\_get\_low, bed\_get\_high, bed\_get\_op *}
*/

bed_var bed_get_var( bed_node node )
{
  if ( ! is_running )
    return BED_UNDEFINED;
  return VAR( node );
}

/*
NAME	{* bed\_get\_op *}
SHORT	{* Returns the operator *}
PROTO	{* bed_op bed_get_op( bed_node node ) *}
DESCR	{* Returns the operator of vertex $node$. *}
RETURN	{* bed\_op *}
ALSO	{* bed\_get\_low, bed\_get\_high, bed\_get\_var *}
*/

bed_op bed_get_op( bed_node node )
{
  if ( ! is_running )
    return BED_UNDEFINED;
  return OP( node );
}



/* 
 * ====[ Internal settings ]=========================================================
 */

/*
NAME	{* bed\_set\_upone\_mode *}
SHORT	{* Sets the upone mode *}
PROTO	{* void bed_set_upone_mode( unsigned char tag ) *}
DESCR	{* Sets the upone mode to BED\_UPONE\_MODE\_ORDER or
	   BED\_UPONE\_MODE\_STRICT. The former mode pulls variables up
	   until they reach their place in the ordering. The latter mode
	   pulls variables up to the root regardless of the current ordering.
	   Default is BED\_UPONE\_MODE\_ORDER. *}
RETURN	{* *}
ALSO	{* bed\_get\_upone\_mode, bed\_upone *}
*/

void bed_set_upone_mode( unsigned char tag )
{
  set_upone_mode( tag );
}


/*
NAME	{* bed\_get\_upone\_mode *}
SHORT	{* Returns the current upone mode *}
PROTO	{* unsigned char bed_get_upone_mode() *}
DESCR	{* Returns the current upone mode. It is either BED\_UPONE\_MODE\_ORDER or
	   BED\_UPONE\_MODE\_STRICT. The former mode pulls variables up
	   until they reach their place in the ordering. The latter mode
	   pulls variables up to the root regardless of the current ordering.*}
RETURN	{* *}
ALSO	{* bed\_set\_upone\_mode, bed\_upone *}
*/

unsigned char bed_get_upone_mode()
{
  return get_upone_mode();
}


/* 
 * ====[ Info about BEDs ]===========================================================
 */

/*
NAME	{* bed\_get\_info *}
SHORT	{* Return info about the BED*}
PROTO	{* bed_info bed_get_info() *}
DESCR	{* Returns info about the current state of the BED package. *}
RETURN	{* bed\_info *}
ALSO	{* *}
*/

bed_info bed_get_info()
{
  if ( ! is_running ) {
    bed_info dummy;
    return dummy;
  }
  return kernel_get_info();
}


/* 
 * ====[ Operator to name ]==========================================================
 */

/*
NAME	{* bed\_op2name *}
SHORT	{* Converts an operator to a string *}
PROTO	{* char* bed_op2name( bed_op op ) *}
DESCR	{* Returns a string which the name of the operator $op$. *}
RETURN	{* char* *}
ALSO	{* *}
*/

char* bed_op2name( bed_op op )
{
  return op2string( op );
}


/* 
 * ====[ Default var/node2name ]=====================================================
 */

static char* default_variable_to_name( unsigned int n )
{
  static char buf[20];

  sprintf( buf, "v_%d", n );
  return buf;
}

static char* default_node_to_name( unsigned int n )
{
  static char buf[20];

  sprintf( buf, "n_%d", n );
  return buf;
}




/* 
 * ====[ I/O commands ]==========================================================
 */

/*
NAME	{* bed\_io\_graph *}
SHORT	{* Outputs BEDs as graphs in the DOT format *}
PROTO	{* void bed_io_graph( FILE *fp, bed_node_list *nodes ) *}
DESCR	{* Outputs the BEDs in the list $nodes$ to the file $fp$ in the DOT format. *}
RETURN	{* *}
ALSO	{* bed\_io\_view *}
*/

/*
NAME	{* bed\_io\_print\_node *}
SHORT	{* Outputs a BED vertex as text *}
PROTO	{* void bed_io_print_node( FILE *fp, bed_node node ) *}
DESCR	{* Outputs the BED $node$ as text to the file $fp$. *}
RETURN	{* *}
ALSO	{* *}
*/

/*
NAME	{* bed\_io\_write *}
SHORT	{* Writes BEDs to a file *}
PROTO	{* void bed_io_write( FILE *fp, bed_io_root_entry* nodes ) *}
DESCR	{* Writes BEDs in $nodes$ to the file $fp$ for later retrieval. *}
RETURN	{* *}
ALSO	{* bed\_io\_read *}
*/

/*
NAME	{* bed\_io\_read *}
SHORT	{* Retrieves BEDs from file *}
PROTO	{* bed_io_read_info* bed_io_read( char *filename ) *}
DESCR	{* Retrieves BEDs from the file named $filename$. The result is
           a pointer to a \texttt{bed\_io\_read\_info} structure. *}
RETURN	{* bed\_io\_read\_info* *}
ALSO	{* bed\_io\_read\_done, bed\_io\_write *}
*/

/*
NAME	{* bed\_io\_read\_done *}
SHORT	{* Cleans up after bed\_io\_read *}
PROTO	{* void bed_io_read_done( bed_io_read_info *info ) *}
DESCR	{* Cleans up the bed\_io\_read\_info structure after bed\_io\_read.
           All memory are deallocated. *}
RETURN	{* *}
ALSO	{* bed\_io\_read *}
*/

/*
NAME	{* bed\_io\_view *}
SHORT	{* Shows a graphical view of a BED *}
PROTO	{* void bed_io_view( bed_node node ) *}
DESCR	{* Shows a graphical view of the BED $node$. This command
           uses the DOT and GHOSTVIEW programs. *}
RETURN	{* *}
ALSO	{* bed\_io\_graph *}
*/

/*
NAME	{* bed\_io\_dimacs *}
SHORT	{* Outputs a BED in the DIMACS format *}
PROTO	{* void bed_io_dimacs( FILE *fp, bed_node node ) *}
DESCR	{* Outputs the BED $node$ to the file $fp$ in the DIMACS format. *}
RETURN	{* *}
ALSO	{* *}
*/



/* 
 * ====[ List commands ]==========================================================
 */


/*
NAME	{* il\_new *}
SHORT	{* Creates a new and empty integer list *}
PROTO	{* iList* il_new() *}
DESCR	{* Creates a new and empty interger list *}
RETURN	{* iList* *}
ALSO	{* il\_free *}
*/

/*
NAME	{* il\_free *}
SHORT	{* Frees an integer list *}
PROTO	{* void il_free( iList *a ) *}
DESCR	{* Frees the integer list $a$ *}
RETURN	{* *}
ALSO	{* il\_new *}
*/

/*
NAME	{* il\_copy *}
SHORT	{* Copies an integer list *}
PROTO	{* iList*  il_copy( iList *a ) *}
DESCR	{* Returns a copy of the integer list $a$ *}
RETURN	{* iList* *}
ALSO	{* *}
*/

/*
NAME	{* il\_append *}
SHORT	{* Appends an integer to an integer list *}
PROTO	{* void il_append( iList *l, int e ) *}
DESCR	{* Appends the integer $e$ to the list $l$. $e$ is appended at the
           end of the list. *}
RETURN	{* *}
ALSO	{* *}
*/

/*
NAME	{* il\_elem *}
SHORT	{* Gives access to an element in the list *}
PROTO	{* #define il_elem( a, n ) *}
DESCR	{* Gives access to element number $n$ in list $a$. Can be used
           on both left and right hand sides of '='. *}
RETURN	{* *}
ALSO	{* *}
*/

/*
NAME	{* il\_length *}
SHORT	{* Gives the length of a list *}
PROTO	{* unsigned int il_length( iList *l ) *}
DESCR	{* Returns the length of list $l$. *}
RETURN	{* unsigned int *}
ALSO	{* *}
*/

/*
NAME	{* il\_empty *}
SHORT	{* Check if a list is empty *}
PROTO	{* Boolean il_empty( iList *l ) *}
DESCR	{* Returns true if list $l$ is empty. *}
RETURN	{* Boolean *}
ALSO	{* *}
*/

/*
NAME	{* il\_clear *}
SHORT	{* Clears a list *}
PROTO	{* void il_clear( iList *l ) *}
DESCR	{* Clears list $l$. *}
RETURN	{* *}
ALSO	{* *}
*/

/*
NAME	{* il\_iter *}
SHORT	{* Iterates through all elements of a list *}
PROTO	{* #define IL_ITER( l, i ) *}
DESCR	{* Iterates through all elements of the list $l$. The integer $i$
           starts at 0 and ends at il\_length(l)-1. Use il\_elem(l,i) to
           access each element. *}
RETURN	{* *}
ALSO	{* *}
*/
