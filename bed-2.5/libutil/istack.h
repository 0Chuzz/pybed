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

#ifndef _istack_h
#define _istack_h
 
#include "Malloc.h"
#include "bool.h"

typedef struct iStack {
  int*		top;		/* Top of stack */
  int*		arr;		/* The elements */
  int*		arr_end;	/* End of stack */
} iStack;

void		is_set_default_stack_length( unsigned int n );

iStack*		is_new();

inline int* is_expand( iStack *a )
{
  register int new_size = 2 * ( a->arr_end - a->arr );
  register int top = a->top - a->arr;

  a->arr = (int *) Realloc( (char *) a->arr, new_size * sizeof( int ));
  a->arr_end = a->arr + new_size;
  a->top = a->arr + top;
  return a->top++;
}

inline void is_free( iStack *a )
{
  free( a->arr );
  free( a );
}

inline int  is_push(iStack *s, int e) {
  if ((s)->top == (s)->arr_end)
	 *is_expand(s) = e;
  else
	 *((s)->top++) = (e);
	return e;
}
#define is_popm(s,n) ( (s)->top -= (n) )
#define is_pop(s) ( *(--(s)->top) )

#define		is_elem(a, n)	((a)->arr[(n)])
#define		is_length(a)	((a)->top - (a)->arr)
#define		is_empty(a)	((a)->top == (a)->arr)
#define		is_clear(a)	((a)->top = (a)->arr)

#define		IS_ITER( s, i )	for ( (i) = 0; (i) < ((s)->top) - ((s)->arr); (i)++ )

#endif
