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

#ifndef _darray_h
#define _darray_h
 
#include "Malloc.h"
#include "bool.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct dArray {
  unsigned int	n_alloc;	/* Number of allocated elements */
  int*		arr;		/* The elements */
} dArray;

dArray*	da_new( unsigned int n );	/* n is the number of initially allocated elements */
dArray*	da_copy( dArray *a );		/* copy dArray a */
void	da_free( dArray *a );

void	da_set_elem( dArray *a, unsigned int n, int v );
int	da_get_elem( dArray *a, unsigned int n );

#ifdef __cplusplus
}
#endif

#endif
