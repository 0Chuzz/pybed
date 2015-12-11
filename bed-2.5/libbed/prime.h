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

#ifndef prime_h_
#define prime_h_

#include <stdio.h>
#include "bool.h"

unsigned int 	prime_ge( unsigned int x, unsigned s );
Boolean 	is_prime( unsigned int x, unsigned s );


#endif
