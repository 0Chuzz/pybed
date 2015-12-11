/***********************************************************************
 *    Copyright 1991                                                   *
 *    Department of Computer Science                                   *
 *    California Institute of Technology, Pasadena, CA 91125 USA       *
 *    All rights reserved                                              *
 ***********************************************************************/

 
#ifndef _Malloc_h
#define _Malloc_h
 
#include <strings.h>
#include <malloc.h>
 
#ifdef DMALLOC
#include "dmalloc.h"

#undef CALLOC
#undef MALLOC
#undef MALLOC_ARRAY
#endif

#define STR_DUP( t, s) do { \
                          (t) = Malloc ( (unsigned) 1 + strlen( (s))); \
                          (void) strcpy( (t), (s)); \
                       } while ( 0)


#define CALLOC(n,type)		(type*) Calloc(n,sizeof(type))
#define MALLOC(type) 		(type*) Malloc(sizeof(type))
#define MALLOC_ARRAY(n,type) 	(type*) Malloc((n)*sizeof(type))
 
char* Malloc( unsigned );
char* Calloc( unsigned , unsigned );
char* Realloc( char *, unsigned );
 
 
#endif
