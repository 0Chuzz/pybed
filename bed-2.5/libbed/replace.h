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


#ifndef replace_h
#define replace_h

#include "kernel.h"


Op	replacenode( uint var, Op op, uint l, uint h, uint *v_, uint *l_, uint *h_ );
Op 	bdd_replacenode( Op op, uint l, uint h, uint *l_, uint *h_ );

void	reduction_stat( FILE *fp );

void	set_base_set( int set );
int	get_base_set();

#endif
