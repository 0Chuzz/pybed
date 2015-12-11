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

#ifndef lex_h_
#define lex_h_

#include <stdio.h>
#include "bool.h"

#define MAX_STRING 		8192

typedef enum Token {
   T_NAME, 			/* [a-zA-Z_][a-zA-Z0-9_]* */
   T_STRING, 			/* ".*" */
   T_INTEGER, 			/* [0-9]+ */
   T_REAL, 			/* [0-9]*\.[0-9]* */
   T_EOF, 
   T_BAD, 
   T_BAR_BAR, 			/* || */
   T_LOR = T_BAR_BAR,		/* || */
   T_AND_AND, 			/* && */
   T_LAND = T_AND_AND,		/* && */
   T_IMPLIES, 			/* => */
   T_STAR_LBRK, 		/* *[ */
   T_LBRK_RBRK, 		/* [] */
   T_DOT_DOT, 			/* .. */
   T_DASH_RANG,			/* -> */
   T_LANG_EQU_RANG,		/* <=> */
   T_LANG_EQU, 			/* <= */
   T_LE = T_LANG_EQU,		/* <= */
   T_RANG_EQU, 			/* >= */
   T_GE = T_RANG_EQU, 		/* >= */
   T_BANG_EQU, 			/* != */
   T_NEQ = T_BANG_EQU, 		/* != */
   T_COLON_EQU, 		/* := */
   T_LANG_LANG,			/* <> */
   T_RANG_RANG,			/* >> */
   T_COLON_COLON,		/* :: */
   T_EQU_EQU,			/* == */
   T_BAR='|',
   T_EQU='=',
   T_POUND='#',
   T_COLON=':',
   T_TILDA='~',
   T_SEMI=';',
   T_COMMA=',',
   T_DOT='.',
   T_LPAR='(',
   T_RPAR=')',
   T_LBRK='[',
   T_RBRK=']',
   T_LBRC='{',
   T_RBRC='}',
   T_LANG='<',
   T_LT = T_LANG,
   T_RANG='>',
   T_GT = T_RANG,
   T_PLUS='+',
   T_MINUS='-',
   T_STAR='*',
   T_MUL=T_STAR,
   T_SLASH='/',
   T_DIV=T_SLASH, 
   T_QUEST='?'
} Token;

#define LEX_FLAGS_EXIT_ON_ERROR 	0x1	/* Exit program on an error */
#define LEX_FLAGS_DEBUG 		0x2	/* Print debug information */
#define LEX_FLAGS_LONG_PUNCT 		0x4	/* Combine punctuation characters */
#define LEX_FLAGS_RADIX_CONSTANTS 	0x8	/* Allow hex and octal numbers */
#define LEX_FLAGS_REALS 		0x10	/* Allow real numbers */

/* Error codes */
#define LEX_OK			0
#define LEX_ERR_UNKNOWN		1
#define LEX_ERR_OPEN_FILE	2
#define LEX_ERR_LINE_TOO_LONG	3
#define LEX_ERR_CLOSE_FILE	4
#define LEX_ERR_SYNTAX		5

typedef struct  {
  /* for file input */
  FILE 		*infile;
  FILE		*errstream;
  char 		filename[MAX_STRING];

  /* for string input */
  char		*buf;
  unsigned	buf_len;
  char	 	*ptr;

  int		err_no;
  int  		flags:20;
  Boolean	input_from_file:1;

  char 		current_name[MAX_STRING];
  enum Token 	current_token;
  int   	current_int; 
  double	current_real;
  int   	current_line;

  enum Token 	last_token;
  int   	last_int; 
  double	last_real;
  char  	last_name[MAX_STRING];
  int		last_line;
} Lex;

#define current_char( l ) 	(*(l)->ptr)
#define lex_err( l )		( (l)->err_no )
#define lex_ok( l)		( lex_err(l) == LEX_OK )

#define EOL			'\0'

#ifndef equal
#define equal( s1, s2 )	( 0 == strcmp( s1, s2 ))
#endif

/*
 *  External interface to lexer. 
 */

/*  Initialization */

extern Lex*	lex_open_from_string( char *text, int flags );
extern Lex*	lex_open_from_file( char *filename, int flags );
extern int	lex_close( Lex *l );

extern void 	lex_syntax_error( /* Lex *l, const char *s, char *a1, char *a2, char *a3, char *a4 */ );
extern void 	lex_error( /* Lex *l, const char *s, char *a1, char *a2, char *a3, char *a4 */);
extern void 	lex_warning( /* Lex *l, const char *s, char *a1, char *a2, char *a3, char *a4 */ );

extern char* 	lex_quote( char *s );
extern char*	lex_token_to_string( Token t );
extern char*	lex_parse_filename( Lex *l );

extern int 	get_lineno( Lex *l );
extern void	get_line( Lex *l );
extern char* 	get_name( Lex *l );
extern double 	get_real( Lex *l );
extern int 	get_int( Lex *l );

extern Boolean 	lookahead( Lex *l,  enum Token t);
extern Boolean 	lookahead_keyword( Lex *l,  char *s);

extern Boolean 	have( Lex *l,  enum Token t);
extern Boolean 	have_keyword( Lex *l,  char *s);

extern int 	mustbe( Lex *l,  enum Token t);
extern int 	mustbe_keyword( Lex *l,  char *s);

/* If you want to parse the input yourself: */

void 		next_char( Lex *l );
void 		skip_white_spaces( Lex *l );
Token		get_token( register Lex *l );
#endif
