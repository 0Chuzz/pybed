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

#include "lex.h"
#include "Malloc.h"

#include <ctype.h>
#include <string.h>
#include <values.h>
#include <assert.h>
#include <unistd.h>

#ifdef __STDC__
#include <stdlib.h>
#endif


static char *cpp_paths[] =
{
  "/usr/lib/cpp",
  "/lib/cpp",
  "/usr/ccs/lib/cpp",
  "/bin/cpp",
  "/usr/bin/cpp",
#ifdef CPP_PATH
  CPP_PATH,
#endif
  NULL
};

inline int get_lineno( Lex *l ) {
  return l->last_line;
}

inline char* get_name( Lex *l )
{
  return l->last_name;
}

inline int get_int( Lex *l )
{
  return l->last_int;
}

inline double get_real( Lex *l )
{
  return l->last_real;
}

char* lex_quote( char *s )
{
  char *p=s;
  static char line[2+MAX_STRING];

  if ( isalpha( *p) || *p == '_') {
    p++;
    while( *p) {
      if ( isalnum( *p) || *p == '_') {
	p++;
      } else {
	break;
      }
    }
  }

  if ( *p || *s == EOL ) {
    strcpy( line, "'");
    strcat( line, s);
    strcat( line, "'");
    return line;
  } else {
    return s;
  }
}

char *lex_token_to_string( Token t)
{
  switch(t) {
  case T_NAME:    	return "<NAME>";
  case T_STRING:    	return "<STRING>";
  case T_INTEGER: 	return "<INTEGER>";
  case T_REAL:		return "<REAL>";
  case T_EOF:     	return "<EOF>";
  case T_AND_AND: 	return "'&&'";
  case T_BAR_BAR: 	return "'||'";
  case T_IMPLIES:	return "'=>'";
  case T_STAR_LBRK: 	return "'*['";
  case T_LBRK_RBRK: 	return "'[]'";
  case T_DOT_DOT:   	return "'..'";
  case T_DASH_RANG: 	return "'->'";
  case T_LANG_EQU: 	return "'<='";
  case T_RANG_EQU:  	return "'>='";
  case T_BANG_EQU:  	return "'!='";
  case T_COLON_EQU:	return "':='";
  case T_LANG_LANG: 	return "'<<'";
  case T_RANG_RANG: 	return "'>>'";
  case T_COLON_COLON: 	return "'::'";
  case T_EQU_EQU:	return "'=='";

    /* These are unnecessary ! */
  case T_EQU:		return "'='";
  case T_BAR: 		return "'|'";
  case T_SEMI:  	return "';'";
  case T_COMMA: 	return "','";
  case T_DOT:  		return "'.'";
  case T_LPAR:  	return "'('";
  case T_RPAR: 		return "')'";
  case T_LBRK: 		return "'['";
  case T_RBRK:  	return "']'";
  case T_LBRC:  	return "'{'";
  case T_RBRC:  	return "'}'";
  case T_LANG: 		return "'<'";
  case T_RANG: 		return "'>'";
  case T_PLUS: 		return "'+'";
  case T_MINUS:  	return "'-'";
  case T_STAR: 		return "'*'";
  case T_SLASH: 	return "'/'";
  case T_POUND: 	return "'#'";
  case T_COLON: 	return "':'";
  case T_TILDA:		return "'~'";

  case T_BAD:
  default:
    if ( ispunct( (char) t)) {
      static char r[4];
      (void) strcpy( r, "'x'");
      r[1] = (char) t;
      return r;
    } else {
      return "bad";
    }
  }
}


/*==[ Error reporting ]=======================================================*/

static void _error( l, errtype, s, a1, a2, a3, a4 )
Lex *l;
char *errtype, *s, *a1, *a2, *a3, *a4;
{
  fprintf( l->errstream, "*** %s", errtype );

  if ( l->input_from_file ) {
    if ( l->last_line != l->current_line && l->last_line )
      fprintf( l->errstream, " (File '%s', between lines %d and %d)",
	       l->filename, l->last_line, l->current_line );
    else
      fprintf( l->errstream, " (File '%s', Line %d)", l->filename, l->last_line );
  }

  if ( s ) {
    fprintf( l->errstream, ": " );
    fprintf( l->errstream, s, a1, a2, a3, a4 );
    fprintf( l->errstream, "\n" );
  }
}

void lex_error( l, s, a1, a2, a3, a4 )
Lex *l;
char *s, *a1, *a2, *a3, *a4;
{
  _error( l, "Error", s, a1, a2, a3, a4 );
  l->err_no = LEX_ERR_UNKNOWN;

  if ( l->flags & LEX_FLAGS_EXIT_ON_ERROR)
    exit( 1 );
}

void lex_warning( l, s, a1, a2, a3, a4 )
Lex *l;
char *s, *a1, *a2, *a3, *a4;
{
  _error( l, "Warning", s, a1, a2, a3, a4 );
}

void lex_syntax_error( l, s, a1, a2, a3, a4 )
Lex *l;
char *s, *a1, *a2, *a3, *a4;
{
  _error( l, "Syntax Error", s, a1, a2, a3, a4 );
  l->err_no = LEX_ERR_SYNTAX;

  if ( l->flags & LEX_FLAGS_EXIT_ON_ERROR)
    exit( 1 );
}



void skip_white_spaces( Lex *l )
{
  while ( isspace( *l->ptr )) {
    if ( *l->ptr == '\n' )
      get_line( l );
    else
      l->ptr++;
  }

  /* Post-condition: l->ptr == NULL || !isspace( *l->ptr ) */
}


static void parse_int( Lex *l, int *n )
{
  for( *n = 0; isdigit( *l->ptr ); l->ptr++ )
    (*n) = (*n)*10 + (*l->ptr - '0');
}

static void parse_cpp( Lex *l )
{
  assert( *l->ptr == '#' );

  l->ptr++;	/* Skip '#' */
  skip_white_spaces( l );

  /*
   * Get the line_no
   */

  parse_int( l, &l->current_line );
  l->current_line--;

  /*
   * Get the filename
   */

  skip_white_spaces( l );

  {
    char *q = l->filename;
    l->ptr++;	/* Skip first '"' */

    while ( *l->ptr != '"' && !isspace(*l->ptr) )
      *q++ = *l->ptr++;

    *q = EOL;
  }

  /*
   * Skip to next line
   */

  get_line( l );
}

void get_line( Lex *l )
{
  if ( l->input_from_file ) {

    if ( (l->ptr = fgets( l->buf, l->buf_len, l->infile ))) {

      while ( strlen( l->buf ) == l->buf_len-1 ) {
	/* Line was reached to the end of buffer */

	char *new_buf = MALLOC_ARRAY( 2*l->buf_len, char );

	strcpy( new_buf, l->buf );

	free( l->buf );

	l->ptr = new_buf;
	l->buf = new_buf;

	(void) fgets( l->buf + l->buf_len - 1, l->buf_len + 1, l->infile );

	l->buf_len *= 2;
      }

      l->current_line++;

      if ( *l->ptr == '#' )
	parse_cpp( l );
    } else {
      l->buf[0] = EOL;		/* Indicates EOF */
      l->ptr = l->buf;
    }
  } else {
    l->current_line++;

    while ( (*l->ptr != EOL) && ( *l->ptr != '\n' ))	/* find next '\n' or EOL */
      l->ptr++;
    if ( *l->ptr == '\n' )
      l->ptr++;
  }
}

inline void next_char( Lex *l )
{
  if ( *l->ptr != EOL )
    l->ptr++;
}

static char *find_cpp( Lex *l )
{
  char **cpp;

  for ( cpp = cpp_paths; *cpp; cpp++ ) {
    if ( access( *cpp, X_OK ) == 0 )
      return *cpp;
  }

  fprintf( l->errstream, "*** Warning: Cannot find C-preprocessor (cpp). Tried: " );

  for ( cpp = cpp_paths; *cpp; cpp++ )
    fprintf( l->errstream, "%s, ", *cpp );

  fprintf( l->errstream, "\n" );
  return NULL;
}

static int open_infile( Lex *l, char *filename )
{
  char buf[80];
  char *cpp_program = find_cpp( l );

  l->infile = NULL;
  l->input_from_file = true;

  strcpy( l->filename, filename ? filename : "<stdin>" );

  if ( cpp_program == NULL ) {

    l->infile = (filename ? fopen( filename, "r" ) : stdin );

  } else if ( filename == NULL ) {			/* use stdin */
    sprintf( buf, "%s -undef ", cpp_program );
    l->infile = popen( buf, "r");

  } else if ( access( filename, R_OK ) == 0) {		/* Check file can be opened. */
    sprintf( buf, "%s -undef %s", cpp_program, filename );
    l->infile = popen( buf, "r" );			/* Open file through cpp. */
  }

  if ( l->infile == NULL) {
    lex_error( l, "Cannot open file '%s'", l->filename );
    l->err_no = LEX_ERR_OPEN_FILE;			/* Cannot open file */
  }

  return l->err_no;
}

static Lex *lex_new( int flags )
{
  Lex *l = MALLOC( Lex );

  l->infile 		= NULL;
  l->errstream 		= stderr;
  l->filename[0]	= EOL;
  l->ptr 		= NULL;
  l->err_no		= LEX_OK;
  l->buf_len		= 1024;
  l->buf		= MALLOC_ARRAY( l->buf_len, char );

  l->flags 		= flags;
  l->input_from_file 	= false;

  l->current_line 	= 0;
  l->current_int 	= 0;
  l->current_real	= 0.0;
  l->current_name[0] 	= EOL;
  l->current_token 	= T_BAD;

  return l;
}

Lex *lex_open_from_file( char* filename, int flags)
{
  Lex *l = lex_new( flags );

  open_infile( l, filename );

  if ( lex_ok( l )) {
    get_line( l );
    (void) get_token( l );
  }
  return l;
}

Lex *lex_open_from_string(char *text, int flags )
{
  Lex *l = lex_new( flags );

  strcpy( l->filename, "--string--" );

  l->ptr = text;
  (void) get_token( l );
  return l;
}

int lex_close( Lex *l)
{
  int err;

  if ( l->infile && (l->infile != stdin )) {	/* don't close stdin ! */
    /* Scan to EOF! */

    while ( !have( l, T_EOF ))
      get_token( l );

    if ( pclose( l->infile )) {
      lex_error( l, "Could not close input pipe\n" );
      l->err_no = LEX_ERR_CLOSE_FILE;
    }
  }

  err= l->err_no;
  free( l->buf );
  free( l );
  return err;
}


Token get_token( register Lex *l )
{
  Token result = T_BAD;

  l->last_int  	= l->current_int;
  l->last_real	= l->current_real;
  (void) strcpy( l->last_name, l->current_name);
  l->last_token = l->current_token;
  l->last_line 	= l->current_line;

  skip_white_spaces( l );

  if ( current_char( l ) == EOL ) {
    /* T_EOF */
    result = T_EOF;

  } else if ( isalpha( current_char( l )) || current_char( l ) == '_' ) {
    /* T_NAME */
    char *p;
    for( p=l->current_name; isalnum(current_char( l )) || (current_char( l ) == '_');  next_char( l ))
      *p++ = current_char( l );
    *p = EOL;
    result = T_NAME;

  } else if ( (current_char( l ) == '"') ||
	      (current_char( l ) == '\'')) {
    /* T_STRING or T_NAME */
    char c = current_char( l );
    char *p = l->current_name;

    next_char( l );

    while ( current_char( l ) != c ) {
      if ((current_char( l ) == EOL) || ((p - l->current_name) >= MAX_STRING)) break;

      if ( current_char( l ) == '\n' )
	get_line( l );
      else
	*p++ = current_char( l );

      next_char( l );
    }
    *p = EOL;
    next_char( l );

    result = ( c== '"' ? T_STRING : T_NAME );

  } else if ( isdigit( current_char( l )) ||
	      ((current_char( l ) == '.') && (l->flags & LEX_FLAGS_REALS) )) {

    /* A number of some kind... */
    if ( l->flags & LEX_FLAGS_REALS) {
      int digits=0;
      for( l->current_int=0; isdigit( current_char( l )); next_char( l ) ) {
	l->current_int = l->current_int*10 + (current_char(l) - '0');
	digits++;
      }

      if ( current_char( l ) == '.') {
	int frac, count;
	next_char( l );

	for( frac=0,count=1; isdigit( current_char( l ));  next_char( l )) {
	  frac = frac*10 + (current_char( l ) - '0');
	  count = count*10;
	}

	if (digits || count != 1) {
	  l->current_real = ((double) l->current_int) + ((double) frac) / ((double) count);
	  result = T_REAL;
	} else {

	  if ( (l->flags & LEX_FLAGS_LONG_PUNCT) && ( current_char( l ) == '.' )) {
	    result = T_DOT_DOT;
	    next_char( l );
	  } else {
	    result = (Token) '.';
	  }
	}

      } else {	/* No period -- just an int */
	result = T_INTEGER;
      }

    } else {		/* not l->flags & LEX_FLAGS_REALS */

      /* T_INTEGER */
      int radix = 10;

      if ( l->flags & LEX_FLAGS_RADIX_CONSTANTS) {
	if ( current_char( l ) == '0') {
	  next_char( l );
	  if ( current_char( l ) == 'x' || current_char( l ) == 'X') {
	    radix = 16;
	    next_char( l );
	  } else if ( current_char( l ) == 'o' || current_char( l ) == 'O') {
	      radix = 8;
	      next_char( l );
	    } else if ( current_char( l ) == 'b' || current_char( l ) == 'B') {
	      radix = 2;
	      next_char( l );
	    }
	  }
	}

	for( l->current_int=0;
	     isdigit( current_char( l )) || (radix==16 && isxdigit( current_char( l )));
	     next_char( l ) ) {
	  if ( isdigit( current_char( l )))
	    l->current_int = l->current_int*radix + current_char( l ) - '0';
	  else {
	    if ( isupper( current_char( l )))
	      current_char( l ) = tolower( current_char( l ));

	    l->current_int = l->current_int*radix + current_char( l ) - 'a' + 10;
	  }
	}
	result = T_INTEGER;
      }

  } else if ( ispunct( current_char( l ))) {		/* Punctuation ... 	*/
    if ( l->flags & (LEX_FLAGS_LONG_PUNCT)) {

      if ( '|' == current_char( l )) {
	next_char( l );
	if ( '|' == current_char( l )) {
	  result = T_BAR_BAR;
	  next_char( l );
	} else {
	  result = (Token) '|';
	}

      } else if ( '&' == current_char( l )) {
	next_char( l );
	if ( '&' == current_char( l )) {
	  result = T_AND_AND;
	  next_char( l );
	} else {
	  result = (Token) '&';
	}

      } else if ( '=' == current_char( l )) {
	next_char( l );

	if ( '>' == current_char( l )) {
	  result = T_IMPLIES;
	  next_char( l );
	} else if ( '=' == current_char( l ) ) {
	  result = T_EQU_EQU;
	  next_char( l );
	} else {
	  result = (Token) '=';
	}

      } else if ( '*' == current_char( l )) {
	next_char( l );
	if ( '[' == current_char( l )) {
	  result = T_STAR_LBRK;
	  next_char( l );
	} else {
	  result = (Token) '*';
	}

      } else if ( '.' == current_char( l )) {
	next_char( l );
	if ( '.' == current_char( l )) {
	  result = T_DOT_DOT;
	  next_char( l );
	} else {
	  result = (Token) '.';
	}

      } else if ( '[' == current_char( l )) {
	next_char( l );
	if ( ']' == current_char( l )) {
	  result = T_LBRK_RBRK;
	  next_char( l );
	} else {
	  result = (Token) '[';
	}

      } else if ( '-' == current_char( l )) {
	next_char( l );
	if ( '>' == current_char( l )) {
	  result = T_DASH_RANG;
	  next_char( l );
	} else {
	  result = (Token) '-';
	}

      } else if ( '<' == current_char( l )) {
	next_char( l );
	if ( '=' == current_char( l )) {
	  next_char( l );
	  if ( '>' == current_char( l )) {
	    result = T_LANG_EQU_RANG;
	    next_char( l );
	  } else
	    result = T_LANG_EQU;
	} else if ( '<' == current_char( l )) {
	  result = T_LANG_LANG;
	  next_char( l );
	} else {
	  result = (Token) '<';
	}

      } else if ( '>' == current_char( l )) {
	next_char( l );
	if ( '=' == current_char( l )) {
	  result = T_RANG_EQU;
	  next_char( l );
	} else if ( '>' == current_char( l )) {
	  result = T_RANG_RANG;
	  next_char( l );
	} else {
	  result = (Token) '>';
	}

      } else if ( '!' == current_char( l )) {
	next_char( l );
	if ( '=' == current_char( l )) {
	  result = T_BANG_EQU;
	  next_char( l );
	} else {
	  result = (Token) '!';
	}

      } else if ( ':' == current_char( l )) {
	next_char( l );
	if ( '=' == current_char( l )) {
	  result = T_COLON_EQU;
	  next_char( l );
	} else if ( ':' == current_char( l )) {
	  result = T_COLON_COLON;
	  next_char( l );
	} else {
	  result = (Token) ':';
	}

      } else {
	result = (Token) current_char( l );
	next_char( l );
      }
    } else {
      result = (Token) current_char( l );
      next_char( l );
    }
  } else {
    (void) fprintf(stderr,"Lexical error: unknown char '%c' at line %d\n",
		   current_char( l ), l->current_line);
    result = T_BAD;
    next_char( l );
  }

  if ( l->flags & LEX_FLAGS_DEBUG) {
    (void) fprintf( stderr, "%d: %s", l->current_line, lex_token_to_string(result));

    switch (result) {
    case T_STRING:	fprintf( stderr, " \"%s\"", l->current_name );	break;
    case T_NAME:	fprintf( stderr, " `%s`", l->current_name );	break;
    case T_INTEGER:	fprintf( stderr, " (%d)", l->current_int );	break;
    case T_REAL:	fprintf( stderr, " %f", l->current_real );	break;
    default:		break;
    }
    (void) fprintf( stderr, "\n");
  }

  return l->current_token=result;
}

int mustbe( Lex *l, Token t)
{
  char buf[60];

  if (lex_ok(l) && !have( l, t) ) {
    strcpy( buf, lex_token_to_string( l->current_token ));

    lex_syntax_error( l, "Token: Actual=%s, Expected=%s",
		      buf, lex_token_to_string( t ));
  }

  return l->err_no;
}

Boolean have( Lex *l, Token t)
{
  if ( l->current_token == t) {
    (void) get_token( l);
    return 1;
  } else {
    return 0;
  }
}

Boolean lookahead( Lex *l, Token t )
{
  return ( l->current_token == t);
}

int mustbe_keyword( Lex *l, char *s )
{
  mustbe( l, T_NAME );

  if ( lex_ok(l) && !equal( l->last_name, s)) {
    lex_syntax_error( l, "Actual token=%s, Expected keyword '%s'",
		      lex_token_to_string( l->current_token ), s );
  }
  return l->err_no;
}

Boolean have_keyword( Lex *l, char* s )
{
  if ( (l->current_token == T_NAME ) &&
       (0 == strcmp( l->current_name, s)) ) {
    (void) get_token( l );
    return true;
  } else {
    return false;
  }
}

Boolean lookahead_keyword( Lex *l, char* s )
{
  return ( (l->current_token == T_NAME) && equal( l->current_name, s) );
}
