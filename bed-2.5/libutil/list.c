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

#include <stdio.h>

#include "list.h"

static lList *ls_free_list = NULL;
static ListElem *le_free_list = NULL;

#define LS_BLOCK_SIZE 	64	/* Number of list headers in a block */
#define LE_BLOCK_SIZE 	128	/* Number of list elements in a block */



ListElem *le_new()
{
  ListElem *le;

  if ( le_free_list == NULL ) {
    int i;

    le_free_list = MALLOC_ARRAY( LE_BLOCK_SIZE, ListElem );

    for ( i = 0; i <  LE_BLOCK_SIZE; i++ )
      le_free_list[i].next = ( i == LE_BLOCK_SIZE - 1 ? NULL : le_free_list+(i+1) );
  }

  le = le_free_list;
  le_free_list = le->next;

  return le;
}

int ls_new_cnt = 0;
int ls_free_cnt = 0;

lList* ls_new() 
{
  lList *l;

  ls_new_cnt++;
  if ( ls_free_list == NULL ) {
    int i;

    ls_free_list = MALLOC_ARRAY( LS_BLOCK_SIZE, lList );

    for ( i = 0; i <  LS_BLOCK_SIZE; i++ )
      ls_free_list[i].head = (ListElem *) ( i == LS_BLOCK_SIZE - 1 ? NULL : ls_free_list+(i+1) );
  }

  l = ls_free_list;
  ls_free_list = (lList *) l->head;

  INIT_LIST( l->head, l->tail );
  l->len = 0;

  return l;
}

void le_free( ListElem *le )
{
  le->next = le_free_list;
  le_free_list = le;
}

void ls_clear( lList *l )
{
  while ( l->head ) {
    register ListElem *n = l->head->next;
    le_free( l->head );
    l->head = n;
  } 
  INIT_LIST( l->head, l->tail );
  l->len = 0;
}

void ls_free( lList *l )
{
  ls_free_cnt++;

  ls_clear( l );  
  l->head = (ListElem *) ls_free_list;
  ls_free_list = l;
}

void ls_append( lList *l, void *e )
{
  ListElem *le = le_new();
  le->elem = e;
  l->len++;

  ADD_TO_LIST( l->tail, le, next );
}

void ls_prepend( lList *l, void *e )
{
  if ( ls_empty( l ))  {
    ls_append( l, e );
  } else {
    ListElem *le = le_new();

    l->len++;
    le->elem = e;
    le->next = l->head;
    l->head = le;
  }
}

void ls_insert_after( lList *l, ListElem *le, void *e )
{
  ListElem *le2 = le_new();
  le2->elem = e;
  le2->next = le->next;

  le->next = le2;

  l->len++;
}

void ls_concat( lList *l1, lList *l2 )
{
  l1->len += l2->len;
  l2->len = 0;

  CONCAT_LISTS( l1->tail, l2->head, l2->tail );
}

void* ls_remove_front( lList *l )
{
  ListElem *le = l->head;
  void *e = le->elem;

  l->head = le->next;

  if ( l->head == NULL )
    INIT_LIST( l->head, l->tail );

  le_free( le );
  l->len--;
  return e;
}
