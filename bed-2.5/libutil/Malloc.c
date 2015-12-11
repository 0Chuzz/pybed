/***********************************************************************
 *    Copyright 1991                                                   *
 *    Department of Computer Science                                   *
 *    California Institute of Technology, Pasadena, CA 91125 USA       *
 *    All rights reserved                                              *
 ***********************************************************************/

#include <stdlib.h>
#include "Malloc.h"
#include <stdio.h>
 
char* Malloc( unsigned s )
{
  char* p = malloc(s);

  if ( !p) {
    perror( "Malloc");
    exit( 1 );
  }
  return p;
}
 
char* Calloc( unsigned n, unsigned s)
{
  char* p = calloc( n, s);
  if ( !p) {
    perror( "Calloc");
    exit( 1 );
  }
  return p;
}
 
char* Realloc( char *old, unsigned s)
{
  char* p = realloc( old, s);
  if ( !p) {
    perror( "Realloc");
    exit( 1 );
  }
  return p;
}

