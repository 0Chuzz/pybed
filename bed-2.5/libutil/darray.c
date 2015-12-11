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
#include <stddef.h>
#include <stdlib.h>

#include "darray.h"
#include "Malloc.h"

static dArray *da_free_list = NULL;
#define DA_BLOCK_SIZE 	64

dArray* da_new( unsigned int n ) 
{
  dArray *a;

  if ( da_free_list == NULL ) {
    int i;

    da_free_list = MALLOC_ARRAY( DA_BLOCK_SIZE, dArray );
    for ( i = 0; i <  DA_BLOCK_SIZE-1; i++ )
      da_free_list[i].arr = (int *) (da_free_list+(i+1));

    da_free_list[DA_BLOCK_SIZE-1].arr = NULL;
  }

  a = da_free_list;
  da_free_list = (dArray *) a->arr;

  a->n_alloc = n;
  a->arr = MALLOC_ARRAY( n, int );
  
  return a;
}

dArray* da_copy( dArray *a ) 
{
  dArray *b = da_new( a->n_alloc );
  int i;
  
  for ( i = 0; i < a->n_alloc; i++ )
    b->arr[i] = a->arr[i];

  return b;
}


void da_free( dArray *a )
{
  free( a->arr );

  a->arr = (int *) da_free_list;
  da_free_list = a;
}

static void da_expand( dArray *a, unsigned int n )
{
  unsigned int new_size;
  int *new_arr;

  if ( n < a->n_alloc )
    return;

  new_size = 2*a->n_alloc > n ? 2*a->n_alloc : n;	/* = max( 2*n_alloc, n ) */
  
  new_arr = (int *)
      Realloc( (char *) a->arr, new_size * sizeof( int ));
  
  if ( new_arr != a->arr ) {
/*
    bcopy( a->arr, new_arr, a->n_alloc * sizeof( int ));
    free( a->arr );
*/
    a->arr = new_arr;
  }
  a->n_alloc = new_size;
}

void da_set_elem( dArray *a, unsigned int n, int v )
{
  if ( n >= a->n_alloc )
    da_expand( a, n+1 );

  a->arr[n] = v;
}

int da_get_elem( dArray *a, unsigned int n )
{
  assert( (n >= 0) && (n < a->n_alloc));
  return a->arr[n];
}
