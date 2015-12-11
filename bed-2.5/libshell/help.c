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

#include <stdio.h>
#include <strings.h>

#include "help.h"

typedef struct HelpInfo {
 char*	command_name;
 char*	args_syntax;
 char*	short_desc;
 char*	long_desc;
} HelpInfo;


#define ADDINPUT_DESC "Adds the variables x1 x2 ... xn to the already declared variables."

#define DOT_DESC      "Outputs the BEDs rooted at r to the file filename.dot in the \
		       DOT format. The default name is bed.dot. DOT is an excellent \
		       graph-drawing program from AT&T which can be obtained from the web at \
		       http://www.research.att.com/sw/tools/graphviz/."

#define VIEW_DESC     "Using the DOT and the GHOSTVIEW programs, this command \
		       produces a graphical picture of the BED rooted at r."

#define GC_DESC	      "Garbage collection of unreachable nodes. This can also be done \
			automatically whenever bed is close to running out of \
			BED nodes; see \"set auto_gc\"."

#define LET_DESC       "Declares root r to be the BED defined by the Boolean expression \
			<expr> which has the syntax: \
			\n<expr> ::= ID | ( <expr> ) | \
		        <expr> <binop> <expr> | <expr>  '<' <var> '>' <expr> | not <expr> \
			| reach( <expr>, <expr> ) | exists ID . <expr> | forall ID . <expr> \
			| <expr> [ <var> := <expr> ] \
			\n<binop> \
			::= and | or | = | => | <= | xor | nor | nand | nimp | nlimp \
			\nThe operators are left associative and bind as you would expect. \
			The expression \"<expr1> '<' <var> '>' <expr2>\" denotes the \
			if-then-else operator where <expr1> denotes the low-child and \
			<expr2> denotes the high-child. \
			\nThe expression reach( <expr1>, \
			<expr2> ) denotes the reachable state space where <expr1> is the \
			set of initial states, and <expr2> is the transition relation. \
			The variables in the BED are assumed to be state variables in the \
			order: x1 x1p x2 x2p ... xn xnp. The p's denote primed (next state) \
			variables. \
			\nThe expression <expr1> [ <var> := <expr2> ] denotes the expression \
			<expr1> in which all occurences of the variable <var> have been \
			replaced with the expression <expr2>. \
			\nThe '=' version of the let command expects r to be previously \
			undefined, while the ':=' version forces an overwrite of any \
			previously defined root with the name r."

#define UNLET_DESC	"Undeclares one or more roots."

#define READ_DESC	"Reads a file containing a description of a Boolean expression. \
			 Any previously defined Boolean expressions are discarded."

#define WRITE_DESC	"Writes the root r to a file. It can later be read using the \
			 read command. Use * to write all roots."

#define PRINT_DESC 	"Prints the node r (first case) or prints r and all the nodes \
			 reachable from r (second case)."

#define UPALL_DESC	"Turns the BED at root r or the BEDs at roots r1 r2 ... rn into \
			 reduced ordered BDDs by lifting all the variables up above the \
			 operators and thereby eliminating the operators. The variable \
			 ordering used can be set by the order command."

#define UPONE_DESC	"Lifts the variable x ( x1 x2 ... xn ) up to root r ( r1 r2 ... rn ). \
			 A variable x is either lifted up until it reaches a node \
			 containing a variable which is before x in the ordering."

#define VERIFY_DESC	"Turns the BED at root r or the BEDs at roots r1 r2 ... rn into \
			 reduced ordered BDDs by lifting all the variables up above the \
			 operators using upones and thereby eliminating the operators. \
			 The variable ordering used can be set by the order command."

#define BEDSAT_DESC	"Returns 1 is the root is satisfiable. Returns 0 is the root is not \
			 satisfiable. Returns the original values of the root if no \
			 conclusion could be reached."

#define BEDUNSAT_DESC	"Returns 0 is the root is falsifiable (negation of root is satisfiable). \
			 Returns 1 is the root is not falsifiable (root is a tautology). \
			 Returns the original values of the root if no conclusion could be reached."

#define EVAL_DESC	"Returns the value of root r when the variables x1 x2 ... xn are \
			 assigned true. The variables not listed are set to be false."


#define ANYSAT_DESC	"Returns a satisfying assignment for a Boolean function represented \
			 by r. The assignment is given as a list of variables which should \
                         be set to true (all variables not mentioned should be set to false). \
                         This only works if the BED is transformed into an ROBDD first."

#define ANYNONSAT_DESC	"Returns a falsifying assignment for a Boolean function represented \
			 by r. The assignment is given as a list of variables which should \
                         be set to true (all variables not mentioned should be set to false). \
                         This only works if the BED is transformed into an ROBDD first."

#define SATCOUNT_DESC	"Returns the number of satisfying assignments for a Boolean function \
			represented by r. This only works if the BED is transformed into \
			a ROBDD first."

#define EXIT_DESC	"In interactive mode this commands exits the program. In script mode \
			 the script is terminated and the program goes into interactive mode."

#define FINDORDER_DESC	"Returns the ordering of the variables of a root r. The BED at r \
			 must be without operator vertices and it must be ordered."

#define SET_DESC	"Sets the <option> to <value>. There are the follwing options: \
			\"support\", \"reductions\", \"dot_zero\", \"dot_numbers\", \
			\"dot_ranksep\", \"dot_nodesep\", \"dot_margin\", \"dot_fontsize\", \
			\"dot_ratio\", \"sort_roots\", \
			\"gmc_tries\", \"gmc_flips\", \"gmc_delta\", \
			\"sat_max_size\", \"sat_depth\", \"sat_time\", \
			\"display_time\", \"bedsize\", and \"cachesize\". \
			\nsupport is used to control whether the support should be \
			calculated by a \"left\" or a \"right\" depth-first traversal \
			of the BED. Default is \"left\". \
			\nreductions is used to to turn the reduction rules \"on\" or \
			\"off\". Default is \"on\". \
			\ndot_zero is used to turn the drawing of the edges going to the \
			terminal ZERO \"on\" or \"off\". Default is \"on\". \
			\ndot_numbers is used to turn the drawing of the node numbers \
			\"on\" or \"off\". Default is \"on\". \
			\ndot_ranksep, dot_nodesep, dot_margin, dot_fontsize, dot_ration \
			are options to the \"dot\" program. \
			\nsort_roots is used to turn alphabetical sorting of the roots (outputs) \
			\"on\" or \"off\". Default is \"on\". \
			\ngmc_tries and gmc_flips are used to control greedy model checking. \
			Default options are 50 tries of 100 flips each. \
			\ngmc_delta controls how the output states in greedy model checking \
			is displayed. Options are \"on\" for only displaying the differences \
			between the previous state (default) and \"off\" for displaying full \
			information. \
			\nsat_max_size sets a node threshold for \"bedsat\" under which upall \
			is used to determine satisfiability. Default is 0 (never use upall). \
			\nsat_depth sets a maximum depth (number of variables to split on) \
			for \"bedsat\". Upon reaching this limit, \"bedsat\" backtracks. \
			This leads to an incomplete decision procedure. Default is 0 \
			(no max depth -- in which case \"bedsat\" is complete). \
			\nsat_time sets a limit in seconds (default 0 -- no limit) for how \
			much time \"bedsat\" may use per output. \
			\ndisplaytime is used to control the printout of CPU time for the \
			commands. If a command takes longer than <displaytime> CPU \
			seconds, the CPU time is printed. Default is 10 second. \
			\nbedsize is the amount of memory in MB to be used for the the bed \
			data structure. \
			\ncachesize is the amount of memory in MB to be used for internal \
			caches."


static const HelpInfo help_procs[] = {
  { "upall",	"r | [r1 r2 ... rn]",
			"Transforms a BED into an ROBDD", UPALL_DESC },
  { "upone", 	"x r | [x1 x2 ... xn] [r1 r2 ... rn]",
			"Lifts one or more variables up to one or more roots.", UPONE_DESC },
  { "verify", 	"r | [r1 r2 ... rn]",
			"Uses upone repeatedly to transform a BED into an ROBDD.", VERIFY_DESC },

  { "", "", "", NULL },
  { "bedsat",	"r | [r1 r2 ... rn]",	"Determines satisfiability of the roots.", BEDSAT_DESC },
  { "bedunsat",	"r | [r1 r2 ... rn]",	"Determines falsifiability of the roots.", BEDUNSAT_DESC },
  { "", "", "", NULL },

  { "anysat",	"r",	"Determines a satisfying assignment.", ANYSAT_DESC },
  { "anynonsat","r",	"Determines a falsifying assignment.", ANYNONSAT_DESC },
  { "satcount", "r",	"Determines the number of satisfying assignments.", SATCOUNT_DESC },
  { "eval",     "r [x1 x2 ... xn]",
			"Evaluates a Boolean function.", EVAL_DESC },
  { "count",	"r",	"Returns the number of nodes visited on a depth-first traversal.", NULL },
  { "", "", "", NULL },

  { "var",	"x1 x2 ... xn",
			"Adds variables.", ADDINPUT_DESC },
  { "let",	"r = <expr> | r := <expr>",
			"Adds a root for a Boolean expression.", LET_DESC },
  { "unlet",	"r1 r2 r3",
			"Undeclares one or more roots.", UNLET_DESC },
  { "", "", "", NULL },

  { "set",	"<option> <value>",
			"Sets an option.", SET_DESC },
  { "", "", "", NULL },

  { "dot",	"r > filename.dot",
			"Outputs a BED in the DOT format.", DOT_DESC },
  { "view",	"r | [r1 r2 ... rn]",
			"Shows a graphical representation of a BED.", VIEW_DESC },
  /*
  { "dump",	"[<node id>[-<node id>]]",
			"Dump the BED between specified nodes or the entire BED.", NULL },
			*/

  /*
  { "dumpnode",	"'[' <node> ']' | <node>", "Dump just <node> (first case) or recursively dump nodes below <node> (second case).", NULL },
  */
  { "print",	"[ r ] | r",
			"Prints a node and all the nodes reachable from it.", PRINT_DESC },
  { "", "", "", NULL },

  { "read",	"<filename>",		"Reads BED from file.", READ_DESC },
  { "write",	"r > <filename>",	"Writes a BED root to file.", WRITE_DESC },
  { "source",	"<filename>", 		"Reads and executes a script of commands.", NULL },
  { "", "", "", NULL },

  { "vars", 	"",			"Shows the declared variables in order.", NULL },
  /*
  { "inputs", 	"",			"Alias for 'vars'.", NULL },
  */
  { "lets", 	"[r1 r2 ... rn]",	"Prints the roots of a BED.", NULL },
  /*
  { "outputs", 	"[<root>][ - [<root>]]", "Alias for 'lets'.", NULL },
  */
  { "stat", 	"bed | hash | cache | roots",
			"Prints statistical information.", NULL },
  { "support",	"r",
			"Prints the support for a BED.", NULL},
  { "order",	"[x y z]",		"Sets the variable ordering used in upall and verify.", NULL },
  { "writeorder",	"<filename>",	"Outputs the current variable ordering to a file.", NULL },
  { "", "", "", NULL },

  /*
  { "debug", 	"",			"Turn on debugging information.", NULL },
  { "nodebug", 	"",			"Turn off debugging information.", NULL },
  { "check",	"",			"Run miscellaneous consistency checks on the BED.", NULL },
  { "test",	"reductions",		"Tests the reduction rules for soundness.", NULL },
  { "", "", "", NULL },
  */

  { "clear", 	"",			"Clears any existing BED in memory.", NULL },
  { "exit", 	"",			"Exits the BED program.", EXIT_DESC },
  /*
  { "quit", 	"",			"Exit BED program.", EXIT_DESC },
  { "halt", 	"",			"Quits the program both in interactive mode and in script mode.", NULL },
  */
  { "", "", "", NULL },

  { "foreach",	"root do \"<commands>\" | root in [r1 r2 ... rn] do \"<commands>\"",
		"Repeat commands with \"root\" substituted order for each root.", NULL },
  { "", "", "", NULL },

  { "cd",	"<directory>", 		"Changes working directory.", NULL },
  { "ls",	"", 			"Lists contents of the working directory.", NULL },
  { "pwd",	"", 			"Prints current directory.", NULL },
  { "!",	"<command line>",	"Sends <command line> to a sub-shell (sh).", NULL },

  { "", "", "", NULL },
  { "echo",	"<text>",		"Echos text to the screen.", NULL },

  { "pause",	"",			"Pauses the execution of a script until a keypress.", NULL },

  /*
  { "help", 	"[<command>]",		"Provides help information on <command>.", NULL },
  */
  { NULL,	"", 			"No help available", NULL }
};


#define NULL_COMMAND 	-1

static inline int indent( FILE *fp, int margin )
{
  register int i;
  for ( i = 0; i < margin; i++ )
    putc( ' ', fp );
  return margin;
}

static inline int br( FILE *fp, int margin )
{
  putc( '\n', fp );
  return indent( fp, margin );
}

static void print_paragraph( char *p, FILE *fp, int width, int margin )
{
  int linelength = indent( fp, margin );

  while ( 1 ) {
    char *sp = index( p, ' ' );
    int word_len;

   if ( *p == '\n' ) {
     putc( '\n', fp );
      linelength = br( fp, margin );
      p++;
    }

    word_len = (sp ? sp - p : strlen( p ));

    if ( linelength + 1 + word_len > width ) {
      linelength = br( fp, margin );
    } else if ( linelength > margin ) {
      putc( ' ', fp );
      linelength++;
    }

    if ( sp == NULL ) {
      fputs( p, fp );
      putc( '\n', fp );
      return;
    }    

    /* Write word */
    while ( p != sp ) 
      putc( *p++, fp );
    while ( *p == ' ' || *p == '\t' ) p++;

    linelength += word_len;
  }
}

static int find_command( char *command )
{
  /* search through table ... */
  int i;

  for ( i = 0; help_procs[i].command_name; i++ )
    if ( 0 == strcmp( help_procs[i].command_name, command )) 
      return i;

  return NULL_COMMAND;	/* Could not find command in table */
}

void help_syntax( char *command, FILE *fp )
{
  int c = find_command( command );
  
  if ( c != NULL_COMMAND )
    fprintf( fp, "Syntax: %s %s\n", help_procs[c].command_name, help_procs[c].args_syntax );
}

void help_general( FILE *fp )
{
  int i;
 
  fprintf( fp, "\nList of commands:\n\n" );
 
  for ( i = 0; help_procs[i].command_name; i++ )
    if ( strlen( help_procs[i].command_name ))
      fprintf( fp, "%-10s %s\n", 
	       help_procs[i].command_name, 
	       help_procs[i].short_desc );
    else
      fprintf( fp, "\n" );

  fprintf( fp, "\nType 'help <command>' for more information on individual commands\n" ); 
}
 
void help( char *command, FILE *fp )
{
  /* search through table ... */
  int c = find_command( command );
  
  if ( c == NULL_COMMAND ) {
    fprintf( fp, "Nothing appropriate for command '%s'.\n", command );
  } else {
    fprintf( fp, "\n%s %s\n", 
	     help_procs[c].command_name, 
	     help_procs[c].args_syntax );
    if ( help_procs[c].long_desc )
      print_paragraph( help_procs[c].long_desc, fp, 76, 5 );
    else
      fprintf( fp, "     %s\n", help_procs[c].short_desc );
  }
}

