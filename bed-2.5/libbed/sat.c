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


#include "math.h"

#ifdef PI2
#undef PI2
#endif

#include "sat.h"
#include "bed.h"
#include "kernel.h"
#include "ilist.h"




static double satcount( uint u, double *memo )
{
  uint l, h;

  if ( memo[u] >= 0.0 )
    return memo[u];

  if ( IS_TERMINAL( u ))
    return ( u == ZERO ) ? 0.0 : 1.0;

  l = bed_var2level[ VAR( LOW( u ) ) ];
  h = bed_var2level[ VAR( HIGH( u ) ) ];

  memo[u] = ( pow( (double) 2.0, (double) ( l - bed_var2level[VAR( u )] - 1 )))
    * satcount( LOW( u ), memo )
    + ( pow( (double) 2.0, (double) ( h - bed_var2level[VAR( u )] - 1 )))
    * satcount( HIGH( u ), memo );

  return memo[u];
} 

/* Count the number of satisfying assignment for 'node' */
/* 'node' *must* be a BDD */
double sat_count( bed_node node )
{
  double *memo = MALLOC_ARRAY( kernel_nodes, double );
  uint i;
  double res;

  /* Mark nodes as not visited */
  for ( i = 0; i < kernel_nodes; i++ )
    memo[i] = -1.0;

  res = ( pow( (double) 2.0, (double) bed_var2level[VAR( node )] )) * satcount( node, memo );

  free( memo );

  return res;
}



static bed_var_list* internal_any_sat( bed_node node, bed_node look_for )
{
  bed_var_list* result = il_new();

  do {
   if ( IS_VARIABLE( node )) {
      uint l = LOW( node );
      uint h = HIGH( node );

      if ( l == look_for ) {
	node = l;
      } else if ( h == look_for ) {
	il_append( result, bed_get_var( node ) );
	node = h;
      } else if ( !IS_TERMINAL( l )) {
	node = l;
      } else if ( !IS_TERMINAL( h )) {
	il_append( result, bed_get_var( node ) );
	node = h;
      } else {
	il_free( result );
	return NULL;
      }
    } else if ( IS_OPERATOR( node )) {
      il_free( result );
      return NULL;
    }
  } while ( !IS_TERMINAL( node ) );

  if ( node == look_for )
    return result;
  else {
    il_free( result );
    return NULL;
  }
}

bed_var_list* any_sat( bed_node node )
{
  return internal_any_sat( node, bed_one );
}

bed_var_list* any_nonsat( bed_node node )
{
  return internal_any_sat( node, bed_zero );
}
