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

#include "ilist.h"


static iList *il_free_list = NULL;
#define IL_BLOCK_SIZE 	16	/* Number of list headers in a block */

static unsigned int il_default_list_length = 64;

void il_set_default_list_length( unsigned int n )
{
  assert( n > 0 );
  il_default_list_length = n;
}

int il_new_cnt = 0;
int il_free_cnt = 0;

iList* il_new() 
{
  iList *a;

  il_new_cnt++;
  if ( il_free_list == NULL ) {
    int i;

    il_free_list = MALLOC_ARRAY( IL_BLOCK_SIZE, iList );

    for ( i = 0; i <  IL_BLOCK_SIZE; i++ ) {
      il_free_list[i].n_alloc = il_default_list_length;
      il_free_list[i].arr = MALLOC_ARRAY( il_default_list_length, int );
      il_free_list[i].info.next = ( i == IL_BLOCK_SIZE - 1 ? NULL : il_free_list+(i+1) );
    }
  }

  a = il_free_list;

  il_free_list = a->info.next;
  il_length( a )	= 0;
  
  return a;
}

static void il_expand( iList *a, unsigned int n )
{
  int new_size;

  if ( a->n_alloc > n )
    return;

  new_size = 2*a->n_alloc > n ? 2*a->n_alloc : n;	/* = max( 2*n_alloc, n ) */

  a->arr = (int *)
    Realloc( (char *) a->arr, new_size * sizeof( int ));
  a->n_alloc = new_size;
}

iList* il_copy( iList *a ) 
{
  iList *b = il_new();

  if ( b->n_alloc < il_length( a ) )
    il_expand( b, a->n_alloc );

  bcopy( (char *) a->arr, (char *) b->arr, il_length(a) * sizeof( int ));
  il_length(b) = il_length( a );
  return b;
}

inline void il_free( iList *a )
{
  il_free_cnt++;
  a->info.next = il_free_list;
  il_free_list = a;
}

inline void il_append( iList *a, int e )
{
  if ( il_length(a) == a->n_alloc )
    il_expand( a, 2*a->n_alloc );

  a->arr[ il_length(a)++ ] = e;
}


iList *il_concat( iList *a, iList *b )
{
  iList *c = il_new();

  il_expand( c, il_length( a ) + il_length( b ));

  bcopy( (char *) a->arr, (char *) c->arr, il_length(a) * sizeof( int ));
  bcopy( (char *) b->arr, (char *) (c->arr+il_length(a)), il_length(b) * sizeof( int ));

  il_length(c) = il_length(a) + il_length(b);

  return c;
}

void il_remove( iList *l, int e )
{
  /* Find possition of e in l */
  int i;
  for ( i = 0; i < il_length(l); i++ )
    if ( l->arr[i] == e ) {	/* found it */
      int j;

      for ( j = i+1; j < il_length(l); j++ )
	l->arr[j-1] = l->arr[j];
      il_length(l)--;
      return;
    }
}


Boolean il_has( iList *l, int x )
{
  int i;
  IL_ITER( l, i )
    if ( il_elem( l, i ) == x )
      return true;
  return false;  
}

Boolean il_equal( iList *l1, iList *l2 ) 
{
  int i;

  IL_ITER( l1, i )
    if ( !il_has( l2, il_elem( l1, i )) )
      return false;


  IL_ITER( l2, i )
    if ( !il_has( l1, il_elem( l2, i )) )
      return false;

  return true;  
}

iList *il_reverse( iList *l1 )
{
  iList *l2 = il_new();

  int i;
  for ( i = il_length( l1 )-1; i >= 0; i-- )
    il_append( l2, il_elem( l1, i ));

  return l2;
}


/***[ QuickSort ]**************************************************/

static int Partition( int *arr, int p, int r )
{
  int x = arr[p];
  int i = p-1;
  int j = r+1;

  while ( 1 ) {
    do {
      j--;
    } while ( arr[j] > x );

    do {
      i++;
    } while ( arr[i] < x );

    if ( i < j ) {
      register int tmp = arr[i];
      arr[i] = arr[j];
      arr[j] = tmp;
    } else
      return j;      
  }
}

static void QuickSort( int *arr, int p, int r )
{
  if ( p < r ) {
    int q = Partition( arr, p, r );

    QuickSort( arr, p, q );
    QuickSort( arr, q+1, r );
  }
}

void il_sort( iList *l )
{
  QuickSort( l->arr, 0, il_length(l)-1 );
}

int il_find( iList *l, int x )
{
  /* Binary search to find element x */

  register int left = 0, right = il_length(l)-1;
  
  while ( left <= right ) {
    int middle = (left+right)/2;
    int val = l->arr[middle];

    if ( x == val )
      return middle;

    else if ( x < val )
      right = middle-1;

    else /* ( x > val ) */
      left = middle+1;
  }

  return -1;	/* Not found */
}
