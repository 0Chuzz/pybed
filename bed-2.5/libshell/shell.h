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

#ifndef shell_h_
#define shell_h_


#include "bed.h"

#include "bool.h"
#include "lex.h"



typedef bed_node	bed_root;
typedef bed_node_list	bed_root_list;


extern FILE*		shell_out;
extern FILE*		shell_err;



/* Shell init and finish  */

void		shell_init();
void		shell( char *BED_filename, char *command_filename );


/* Clear BED */

void		shell_clear_bed();


/* Register new commands */

void		shell_register_command( char *command_name, void (*fct)( Lex *l ) );


/* Add variables and roots */

void		shell_insert_var( char* name, bed_var var );
bed_root	shell_insert_root( char* name, bed_node node );


/* Parse functions */

bed_var		shell_parse_variable( Lex *l );
bed_var_list*	shell_parse_variable_list( Lex *l );

bed_root	shell_parse_root( Lex *l );
bed_root_list*	shell_parse_root_list( Lex *l );

bed_node	shell_parse_node( Lex *l );
bed_node_list*	shell_parse_node_list( Lex *l );

bed_node	shell_parse_expr( Lex *l );

char*		shell_parse_ofile_name( Lex *l, char *default_filename );
char*		shell_parse_ifile_name( Lex *l );


/* Misc. */

bed_node	shell_root2node( bed_root root );
char*		shell_root2name( bed_root root );
void		shell_root_update( bed_root root, bed_node node );

#define		shell_var2name( var )	bed_var2name( var )

#endif
