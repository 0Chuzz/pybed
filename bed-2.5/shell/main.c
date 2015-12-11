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

#include <assert.h>
#include <math.h>

#include "main.h"

#include "shell.h"
#include "version.h"

#include "bool.h"
#include "lex.h"
#include "timer.h"


static void usage()
{
  fprintf( stderr, "Usage: bed [-f <command file>] [-b <BED size in MB>] [-c <cache size in MB>] [<BED filename>]\n" );
  exit( 1 );
}

static inline unsigned long get_mem_size( char *size )
{
  return ((unsigned long) rint( atof( size ) * 1024.0 * 1024.0 ) );
}

int main( int argc, char *argv[] )
{
  Boolean 	bad 		= false;
  Timer 	t	 	= timer_start();

  char*		BED_filename 	= NULL;
  char*		command_filename= NULL;

  unsigned long the_bed_size	= 0;
  unsigned long	the_cache_size	= 0;

  /* Parse arguments */
  while( (--argc > 0) && ((**++argv)=='-') && !bad ) {
 
    if ( equal( *argv, "-h") || equal( *argv, "-?") || equal( *argv, "-help")) {
      bad = true;
    } else if ( equal( *argv, "-f" )) { 
      if ( --argc) command_filename = *++argv; else bad = true;

    } else if ( equal( *argv, "-b" ) ) {
      if ( --argc) the_bed_size =  get_mem_size( *++argv );
      else bad = true;

    } else if ( equal( *argv, "-c" )) { 
      if ( --argc) the_cache_size = get_mem_size( *++argv );
      else bad = true;

    } else {
      fprintf( stderr, "*** Error: Unknown option '%s'\n", *argv );
      bad = true;
    }
  }
  
  if ( bad )
    usage();

  if ( argc == 1 )
    BED_filename = *argv;
  else if ( argc > 1 )
    fprintf( stderr, "*** Warning: Arguments after '%s' are ignored\n", *argv );

  bed_init( the_bed_size, the_cache_size );
  
  fprintf( stdout, "BED Tool -- %s\n\n", bed_shell_version() );

  shell_init();

  /*
  shell_register_command( "<name1>", function1 );	--- void function1( Lex *l )
  shell_register_command( "<name2>", function2 );	--- void function2( Lex *l )
  */

  shell( BED_filename, command_filename );

  bed_done();

  timer_stop( t, stdout, "Total run-time" );

  return 0;
}
