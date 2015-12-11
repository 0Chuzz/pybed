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

#ifndef _cb_h
#define _cb_h

#include "Malloc.h"

/* Our own memory allocator for the strings since otherwise
 * it may take a long time to especially deallocate memory.
 */


#ifdef __cplusplus
extern "C" {
#endif

#define CB_BLOCK_SIZE 	(20*1024)

typedef struct CharBlockFreeList {
  char 	*head;
  struct CharBlockFreeList *link;
} CharBlockFreeList;


typedef struct CharBlock {
  int			n_used;		/* number of character used in present block */
  CharBlockFreeList	*freelist;
} CharBlock;

CharBlock* 	cb_new();
void		cb_clear( CharBlock *cb );
void 		cb_free( CharBlock *cb );

char*		cb_alloc( CharBlock *cb, int n );
char*		cb_copy( CharBlock *cb, char *name );

#ifdef __cplusplus
}
#endif


#endif
