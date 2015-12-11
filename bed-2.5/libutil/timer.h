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


#ifndef _TIMER_H
#define _TIMER_H

#include <stdio.h>
#include "getruntime.h"

typedef unsigned long Timer;

Timer 		timer_start();
unsigned long 	timer_get( Timer t );
void		timer_stop( Timer t, FILE *fp, char *message );

#endif

