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

#include "istack.h"

static unsigned int is_default_stack_length = 64;

void is_set_default_stack_length( unsigned int n )
{
  assert( n > 0 );
  is_default_stack_length = n;
}

iStack* is_new() 
{
  iStack *a = MALLOC( iStack );

  a->arr = MALLOC_ARRAY( is_default_stack_length, int );
  a->top = a->arr;
  a->arr_end = a->arr + is_default_stack_length;
  
  return a;
}


/*
inline int is_push( iStack *s, int e )
{
  return ( ( ( s->top == s->arr_end ) ? *is_expand( s ) : *(s->top++) ) = e);
}
*/

/*
inline int is_pop( iStack *s )
{
  assert( ! is_empty( s ) );

  return *(--s->top);
}
*/

/*
inline int is_popm( iStack *s, int n )
{
  assert( is_length( s ) >= n );

  return *(s->top -= n);
}
*/
