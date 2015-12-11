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


#ifndef bedio_h_
#define bedio_h_


#ifdef __cplusplus
#define CPLUSPLUS
#endif

#ifdef CPLUSPLUS
extern "C" {
#endif


#include <stdio.h>

#include "bed.h"


typedef struct bed_io_root_entry {
  char				*name;
  bed_node			root;
  struct bed_io_root_entry*	next;
} bed_io_root_entry;

typedef struct bed_io_var_entry {
  char				*name;
  bed_var			var;
  struct bed_io_var_entry*	next;
} bed_io_var_entry;

typedef struct {
  bed_io_var_entry*		vars;
  bed_io_root_entry*		roots;
} bed_io_read_info;




extern Boolean		bed_io_dot_draw_to_zero;
extern Boolean		bed_io_dot_print_node_numbers;

extern float		bed_io_dot_ranksep;
extern float		bed_io_dot_nodesep;
extern int		bed_io_dot_fontsize;
extern float		bed_io_dot_margin;
extern char*		bed_io_dot_ratio;


void			bed_io_write( FILE *fp, bed_io_root_entry* nodes );

bed_io_read_info*	bed_io_read( char *filename );
void			bed_io_read_done( bed_io_read_info *info );

void			bed_io_graph( FILE *fp, bed_node_list *nodes );
void			bed_io_color_graph( FILE *fp, bed_node u, bed_node red, bed_node blue );
void			bed_io_print_node( FILE *fp, bed_node node );

void			bed_io_view( bed_node node );

void			bed_io_dimacs( FILE *fp, bed_node node );


#ifdef CPLUSPLUS
}
#endif

#endif
