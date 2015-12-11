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


#ifndef _cache_h_
#define _cache_h_

#include "bool.h"


/* Tags 0 through 127 are reserved for internal use.
 * Tags 128 through 255 are free for user purposes.
 */

#define TAG_FREE		0
#define TAG_UPONE_ORDER		1	/* Must match BED_UPONE_MODE_ORDER */
#define TAG_UPONE_STRICT	2	/* Must match BED_UPONE_MODE_STRICT */
#define TAG_UPALL		3
#define TAG_RESTRICT		4
#define TAG_SIMPLIFY		5
#define TAG_QUANTDOWN		6
#define TAG_UPSOME		7


typedef struct Cache {
  unsigned char	tag;

  unsigned int	v1;
  unsigned int	v2;
  unsigned int	v3;
  unsigned int	v4;

  unsigned int	r1;
  unsigned int	r2;
} Cache;

#ifdef __cplusplus
extern "C" {
#endif

void		cache_init( long size );
void		cache_free();
void		cache_clear();

long		cache_size();

void		cache_insert( Cache *p, unsigned char tag,
			      unsigned int v1, unsigned int v2,
			      unsigned int v3, unsigned int v4,
			      unsigned int r1, unsigned int r2 );

Cache*		cache_get( unsigned char tag,
			   unsigned int v1, unsigned int v2,
			   unsigned int v3, unsigned int v4 );

Boolean		cache_match( Cache *p, unsigned char tag,
			     unsigned int v1, unsigned int v2,
			     unsigned int v3, unsigned int v4 );

#ifdef __cplusplus
}
#endif

#endif
