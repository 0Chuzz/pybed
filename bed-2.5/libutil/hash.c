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

#include "hash.h"
#include <stdio.h>
#include <assert.h>


/* Memory allocator for HashTableElements */
static HashTableElement *hte_free_list = NULL;



static int T[] =
{  1, 87, 49, 12,176,178,102,166,121,193,  6, 84,249,230, 44,163,
  14,197,213,181,161, 85,218, 80, 64,239, 24,226,236,142, 38,200,
 110,177,104,103,141,253,255, 50, 77,101, 81, 18, 45, 96, 31,222,
  25,107,190, 70, 86,237,240, 34, 72,242, 20,214,244,227,149,235,
  97,234, 57, 22, 60,250, 82,175,208,  5,127,199,111, 62,135,248,
 174,169,211, 58, 66,154,106,195,245,171, 17,187,182,179,  0,243,
 132, 56,148, 75,128,133,158,100,130,126, 91, 13,153,246,216,219,
 119, 68,223, 78, 83, 88,201, 99,122, 11, 92, 32,136,114, 52, 10,
 138, 30, 48,183,156, 35, 61, 26,143, 74,251, 94,129,162, 63,152,
 170,  7,115,167,241,206,  3,150, 55, 59,151,220, 90, 53, 23,131,
 125,173, 15,238, 79, 95, 89, 16,105,137,225,224,217,160, 37,123,
 118, 73,  2,157, 46,116,  9,145,134,228,207,212,202,215, 69,229,
  27,188, 67,124,168,252, 42,  4, 29,108, 21,247, 19,205, 39,203,
 233, 40,186,147,198,192,155, 33,164,191, 98,204,165,180,117, 76,
 140, 36,210,172, 41, 54,159,  8,185,232,113,196,231, 47,146,120,
  51, 65, 28,144,254,221, 93,189,194,139,112, 43, 71,109,184,209
};


unsigned int hash( const unsigned char *k, int size ) 
{
  register unsigned int sum=0;

   /*
    * 8, 16, 24, or 32 bit hashing function--- from CACM June 1990, p.679
    */

   if ( *k ) {
      const char *p;
      unsigned char c;
      if ( size <= (1<<8)) {
	 for( p=k; (c= (unsigned char) *p++); ) sum = T[ sum ^ c];
      } else if ( size <= (1<<16)) {
	 unsigned int sum1;
	 sum = T[ *k];
	 sum1 = T[ 0xff & ( 1+ *k)];
	 for( p=k+1; (c=*p++); ) {
	    sum = T[ sum ^ c];
	    sum1 = T[ sum1 ^ c];
	 }
	 sum |= sum1 << 8;
      } else if ( size <= (1<<24)) {
	 unsigned int sum1, sum2;
	 sum = T[ *k];
	 sum1 = T[ 0xff & ( 1+ *k)];
	 sum2 = T[ 0xff & ( 2+ *k)];
	 for( p=k+1; (c=*p++); ) {
	    sum = T[ sum ^ c];
	    sum1 = T[ sum1 ^ c];
	    sum2 = T[ sum2 ^ c];
	 }
	 sum |= (sum1 << 8) | (sum2 << 16);
      } else {
	 unsigned int sum1, sum2, sum3;
	 sum = T[ *k];
	 sum1 = T[ 0xff & ( 1+ *k)];
	 sum2 = T[ 0xff & ( 2+ *k)];
	 sum3 = T[ 0xff & ( 3+ *k)];
	 for( p=k+1; (c=*p++); ) {
	    sum = T[ sum ^ c];
	    sum1 = T[ sum1 ^ c];
	    sum2 = T[ sum2 ^ c];
	    sum3 = T[ sum3 ^ c];
	 }
	 sum |= (sum1 << 8) | (sum2 << 16) | (sum3 << 24);
      }
   }

  return sum & (size-1);
}

unsigned int ht_2power( unsigned int size )
{
  unsigned int n = 1;

  while ( n < size )
    n <<= 1;
  return n;	/* Postcondition: n >= size && \exists k \in N: n = 2^k */
}

HashTable *ht_new( int s )
{
  HashTable *ht = MALLOC( HashTable );

  ht->size = ht_2power( s );
  /* fprintf( stderr, "File %s, line %d: ht_new( %d ) = %d bytes\n", __FILE__, __LINE__, ht->size, ht->size*sizeof(HashTableElementPtr)); */

  ht->elems = 0;
  ht->hash_table = MALLOC_ARRAY( ht->size, HashTableElementPtr );
  bzero( (char *) ht->hash_table, ht->size * sizeof( HashTableElementPtr ) );

  ht->cb = cb_new();

  return ht;
}

void ht_free( HashTable *ht )
{
  ht_clear( ht );

  free( ht->hash_table );
  cb_free( ht->cb );
  free( ht );

}


static HashTableElement *new_HashTableElement()
{
  HashTableElement *h;

  if ( hte_free_list == NULL ) {
    int i;

    /* fprintf( stderr, "File %s, line %d: new_HashTableElement: MALLOC_ARRAY( %d ) = %l bytes\n", __FILE__, __LINE__, HT_HTE_BLOCK_SIZE, HT_HTE_BLOCK_SIZE * sizeof( HashTableElement )); */

    hte_free_list = MALLOC_ARRAY( HT_HTE_BLOCK_SIZE, HashTableElement );
    for ( i = 0; i < HT_HTE_BLOCK_SIZE-1; i++ )
      hte_free_list[i].next = hte_free_list+(i+1);
    hte_free_list[HT_HTE_BLOCK_SIZE-1].next = NULL;
  }

  h = hte_free_list;
  hte_free_list = hte_free_list->next;
  return h;
}

static void free_HashTableElement( HashTableElement *h )
{
  h->next = hte_free_list;
  hte_free_list = h;
}

static HashTableElement *new_HashTableElement_int( HashTable *ht, char *key, int value, HashTableElement *next )
{
  HashTableElement *p = new_HashTableElement();

  p->key = cb_copy( ht->cb, key );
  p->info.val = value;
  p->next = next;

  return p;
}

static HashTableElement *new_HashTableElement_ptr( HashTable *ht, char *key, void *ptr, HashTableElement *next )
{
  HashTableElement *p = new_HashTableElement();

  p->key = cb_copy( ht->cb, key );

  p->info.ptr = ptr;
  p->next = next;

  return p;
}

static HashTableElement *lookup_internal( HashTable *ht, char *key, unsigned int bucket )
{  
  HashTableElement *p = ht->hash_table[ bucket ];

  for ( ; p; p = p->next )
    if ( 0 == strcmp( key, p->key ))
      return p;
  
  return NULL;
}

HashTableElement *ht_lookup( HashTable *ht, char *key ) 
{
  return lookup_internal( ht, key, hash( key, ht->size ) );
}

void ht_print_statistics( HashTable *ht, FILE *fp )
{
  int i;

  fprintf( fp, "Bucket counts (size %d):\n", ht->size );
  for( i=0; i < ht->size; i++) {
    HashTableElement *h = ht->hash_table[i];
    int num_in_bucket=0;

    while ( h )
      h=h->next, num_in_bucket++;

    fprintf( fp, "%d, ", num_in_bucket );
  }
  fprintf( fp, "\n" );  
}

static void expand_hash_table( HashTable *ht )
{
  HashTableElement **new_hash_table;
  int old_size = ht->size;
  int i;

  ht->size <<= 2;

  /* fprintf( stderr, "File %s, line %d: expand_hash_table: from size %d to size %d \n", __FILE__, __LINE__, old_size, ht->size  ); */

  new_hash_table = MALLOC_ARRAY( ht->size, HashTableElement* );
  bzero( (char *) new_hash_table, (ht->size) * sizeof( HashTableElement* ) );
  
  for( i=0; i< old_size; i++) {
    HashTableElement *h = ht->hash_table[i], *hnext;

    for( ; h; h=hnext) {
      int bucket;

      hnext = h->next;
      bucket = hash( h->key, ht->size );
      h->next = new_hash_table[ bucket ];
      new_hash_table[ bucket ] = h;
    }
  }

  free( ht->hash_table );
  ht->hash_table = new_hash_table;
}


static int insert_internal( HashTable *ht, char *key )
{
  int bucket;

  if ( ht->elems > ( ht->size << 2))
    expand_hash_table( ht );

  bucket = hash( key, ht->size );

  if ( lookup_internal( ht, key, bucket ))
    fprintf( stderr, "insert(): key = %s, key already inserted!\n", key ), abort();
  
  return bucket;
}


HashTableElement *ht_insert_int( HashTable *ht, char *key, int value )
{
  int bucket = insert_internal( ht, key );

  ht->elems++;
  ht->hash_table[ bucket ] = new_HashTableElement_int( ht, key, value, ht->hash_table[ bucket ]);
  return ht->hash_table[ bucket ];
}

HashTableElement *ht_insert_ptr( HashTable *ht, char *key, void *ptr )
{
  int bucket = insert_internal( ht, key );

  ht->elems++;
  ht->hash_table[ bucket ] = new_HashTableElement_ptr( ht, key, ptr, ht->hash_table[ bucket ]);
  return ht->hash_table[ bucket ];
}

HashTableElement *ht_remove( HashTable *ht, char *key )
{
  HashTableElement *p, *pnext, **prev;
  int bucket = hash( key, ht->size );

  prev = &(ht->hash_table[bucket]);

  for( p = *prev; p; p=pnext) {
    pnext = p->next;
    if ( 0 == strcmp( key, p->key )) {
      *prev = p->next;
      free_HashTableElement( p );
      ht->elems--;
      return *prev;
    } else {
      prev = &p->next;
    }
  }

  fprintf( stderr, "remove(): Key not found.\n" ), abort();
}


void ht_clear( HashTable *ht )	
{
  int size = ht->size;

  while ( size-- ) {
    while( ht->hash_table[ size ]) {
      HashTableElement* p = ht->hash_table[ size ];
      ht->hash_table[ size ] = ht->hash_table[size]->next;

      free_HashTableElement( p );
    }
  }

  cb_clear( ht->cb );
  ht->elems = 0;
}
