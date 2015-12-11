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

#ifndef upsome_h_
#define upsome_h_

#include "kernel.h"
#include "ilist.h"


void		up_some_set_vector( iList *vars );
uint            up_some( uint u );

void		up_some_expand_vector( int size );
void		up_some_free_vector();

#endif
