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
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "cb.h"

/* Memory allocator for the character strings... */

static void extend( CharBlock *cb )
{
  CharBlockFreeList *new_block = MALLOC( CharBlockFreeList );
  /* fprintf( stderr, "File %s, line %d: extend: MALLOC_ARRAY( %d ) = %d bytes\n", __FILE__, __LINE__, CB_BLOCK_SIZE, CB_BLOCK_SIZE*sizeof(char)); */
  
  new_block->head = MALLOC_ARRAY( CB_BLOCK_SIZE, char );
  new_block->link = cb->freelist;
  cb->freelist= new_block;
  cb->n_used = 0;
}

CharBlock *cb_new()
{
  CharBlock *cb = MALLOC( CharBlock );
  cb->freelist = NULL;
  cb->n_used = 0;
  return cb;
}


void cb_clear( CharBlock *cb )
{
  while ( cb->freelist ) {
    register CharBlockFreeList *next = cb->freelist->link;
    free( cb->freelist->head );
    free( cb->freelist );
    cb->freelist = next;
  }
  /* post-condition: cb->freelist == NULL */
}

void cb_free( CharBlock *cb )
{
  cb_clear( cb );
  free( cb );
}

char *cb_alloc( CharBlock *cb, int n )	
{
  char *p;

  assert( n < CB_BLOCK_SIZE );

  if ( (cb->freelist == NULL) || 
       (cb->n_used + n > CB_BLOCK_SIZE ))
    extend( cb );

  p = cb->freelist->head + cb->n_used;
  cb->n_used += n;

  return p;
}

char *cb_copy( CharBlock *cb, char *str )
{
  char *p = cb_alloc( cb, strlen( str ) + 1 );
  strcpy( p, str );
  return p;
}
