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


#ifndef _hash_h
#define _hash_h

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "Malloc.h"
#include "bool.h"
#include "cb.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct HashTableElement_ {
  char 		*key;
  union {
    int		val;
    void	*ptr;
  } info;
  struct HashTableElement_ 
  		*next;
} HashTableElement, *HashTableElementPtr;

#define		HT_KEY( h )	((h)->key)
#define		HT_VALUE( h )	((h)->info.val)
#define		HT_PTR( h )	((h)->info.ptr)

#define 	HT_HTE_BLOCK_SIZE 	1024

typedef struct {
  int           	size;
  int           	elems;
  HashTableElement	**hash_table;
  CharBlock		*cb;
} HashTable;

HashTable*		ht_new( int size );
void			ht_free( HashTable *ht );

HashTableElement*	ht_lookup( HashTable *ht, char *key );
HashTableElement*	ht_insert_int( HashTable *ht, char *key, int value );
HashTableElement*	ht_insert_ptr( HashTable *ht, char *key, void *ptr );
HashTableElement*	ht_remove( HashTable *ht, char *key );
void			ht_clear( HashTable *ht );

void			ht_print_statistics( HashTable *ht, FILE *fp );

unsigned int 		hash( const unsigned char *key, int );
unsigned int		ht_2power( unsigned int n );

#ifdef __cplusplus
}
#endif

#endif


