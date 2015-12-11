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

#ifndef help_h_
#define help_h_

#include <stdio.h>

void help( char *command, FILE *fp );			/* Prints help for command 	*/
void help_syntax( char *command, FILE *fp );		/* Prints the syntax of command */
void help_general( FILE *fp );				/* Prints list of commands	*/

int complete( char *buf, int *loc );
#endif
