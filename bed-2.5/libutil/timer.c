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

#include "timer.h"
#include <stdio.h>

Timer timer_start()
{
  return (Timer) get_run_time();
}

unsigned long timer_get( Timer t )
{
  return get_run_time() - t;
}

void timer_stop( Timer t, FILE *fp, char *msg )
{
  long end_time = timer_get( t );		/* Time in milliseconds  */
  fprintf( fp, "%s: %ld.%03ld seconds\n", msg, end_time / 1000, end_time % 1000 );
}

