/***********************************************************************
 *    Copyright 1991                                                   *
 *    Department of Computer Science                                   *
 *    California Institute of Technology, Pasadena, CA 91125 USA       *
 *    All rights reserved                                              *
 ***********************************************************************/
 
#ifndef _list_h
#define _list_h
 
#include "Malloc.h"
#include "bool.h"

#ifdef __cplusplus
extern "C" {
#endif

#define INIT_LIST( h, t) do { h=0; t=&h; } while( 0)

#define ADD_TO_LIST( t, e, n) do { *t=e; e->n=0; t=&e->n; } while( 0)
#define CONCAT_LISTS( t1, h2, t2) if ( h2 ) { *t1 = h2; t1 = t2; INIT_LIST( h2, t2); }    


typedef struct ListElem {
  void 			*elem;
  struct ListElem	*next;
} ListElem;

typedef struct lList {
  ListElem 		*head, **tail;
  int			len;
} lList;

lList*	ls_new();
void	ls_free( lList *l );

void	ls_append( lList *l, void *e );
void	ls_prepend( lList *l, void *e );
void	ls_concat( lList *l1, lList *l2 );
void*	ls_remove_front( lList *l );
void	ls_insert_after( lList *l, ListElem *le, void *e );
void	ls_clear( lList *l );

#define ls_length( l )	((l)->len)
#define ls_size( l )	(ls_length( l ))
#define ls_empty( l )	(ls_length(l) == 0)

#ifdef __cplusplus
}
#endif
   
#endif
