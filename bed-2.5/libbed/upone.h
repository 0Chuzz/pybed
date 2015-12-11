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

#ifndef upone_h_
#define upone_h_

#include "kernel.h"
#include "stdio.h"

typedef struct Upone_Cache {  /* upone(x, u) -> "res_l <x> res_h" */
  uint x;
  uint u;
  uint res_l;
  uint res_h;
} Upone_Cache;

uint		up_one( uint x, uint u );
uint		up_one_iter( FILE *fp, uint u );

void		set_upone_mode( unsigned char tag );
unsigned char	get_upone_mode();

#endif
