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

#ifndef _ilist_h
#define _ilist_h
 
#include "Malloc.h"
#include "bool.h"

typedef struct iList {
  unsigned int	n_alloc;	/* Number of allocated elements */
  union {
    unsigned int	len;		/* Length of array */
    struct iList	*next;		/* used by memory allocator */
  } info;
  int*		arr;		/* The elements */
} iList;

void	il_set_default_list_length( unsigned int n );

iList*	il_new();
iList*	il_copy( iList *a );		/* copy iList a */
void	il_free( iList *a );

void	il_append( iList *l, int e );
void	il_remove( iList *l, int e );	/* removes first occurrence of e */
iList*	il_concat( iList *l1, iList *l2 );
void	il_clear( iList *l );
iList*	il_reverse( iList *l1 );
Boolean	il_has( iList *l, int x );
Boolean il_equal( iList *l1, iList *l2 );

void	il_sort( iList *l );
int	il_find( iList *l, int x );

#define il_elem(a, n)	((a)->arr[(n)])
#define il_length(a)	((a)->info.len)
#define il_empty(a)	((a)->info.len == 0)
#define il_clear(a)	((a)->info.len = 0)

#define IL_ITER( l, i )	for ( (i) = 0; (i) < il_length( l ); (i)++ )

#endif
