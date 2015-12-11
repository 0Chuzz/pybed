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

#ifndef sat_h_
#define sat_h_


#include "math.h"

#ifdef PI2
#undef PI2
#endif

#include "bed.h"


double		sat_count( bed_node node );
bed_var_list*	any_sat( bed_node node );
bed_var_list*	any_nonsat( bed_node node );

#endif
