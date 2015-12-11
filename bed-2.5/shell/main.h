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

#ifndef main_h_
#define main_h_

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

#ifdef DONT_HAVE_INLINE
#define inline
#endif

#define equal( s1, s2 )	( 0 == strcmp( s1, s2 ))

#endif
