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


#include "cache.h"
#include "prime.h"
#include "Malloc.h"


/* Macros */

#define c_pair( i, j )	( ( (((i)+(j)) * ((i)+(j)+1)) >> 1 ) + (i) )
#define c_hash(d0, d1, d2, d3, d4)  (( c_pair( (d0), c_pair( (d1), c_pair( (d2), c_pair( (d3), (d4) ))))) % c_size)


/* Local variables */

static Cache	*cache;
static long	c_size;


/* Functions */

void cache_init( long size )
{
  c_size = prime_ge( size, 10 );
  cache = MALLOC_ARRAY( c_size, Cache );
  cache_clear();
}

void cache_free()
{
  free( cache );
}

void cache_clear()
{
  memset( (char *) cache, 0, c_size * sizeof( Cache ) );
}

long cache_size()
{
  return c_size;
}


void cache_insert( Cache *p, unsigned char tag,
		   unsigned int v1, unsigned int v2,
		   unsigned int v3, unsigned int v4,
		   unsigned int r1, unsigned int r2 )
{
  p->tag = tag;
  p->v1 = v1;
  p->v2 = v2;
  p->v3 = v3;
  p->v4 = v4;
  p->r1 = r1;
  p->r2 = r2;
}

Cache* cache_get( unsigned char tag,
		  unsigned int v1, unsigned int v2,
		  unsigned int v3, unsigned int v4 )
{
  return cache + c_hash( tag, v1, v2, v3, v4 );
}

Boolean cache_match( Cache *p, unsigned char tag,
		     unsigned int v1, unsigned int v2,
		     unsigned int v3, unsigned int v4 )
{
  return (p->tag == tag) && (p->v1 == v1) && (p->v2 == v2) &&
    (p->v3 == v3) && (p->v4 == v4);
}
