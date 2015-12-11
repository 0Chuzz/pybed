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


#ifndef tables_h
#define tables_h

#include "op.h"
#include "kernel.h"

struct one_terminal_reduction {
  Op l0;
  Op l1;
  Op h0;
  Op h1;
};

struct three_nodes_reduction {
  int is_left	: 1;
  Op op1	: BED_OP_BITS;
  Op op2	: BED_OP_BITS;
};

extern Op symmetric_operator_array[];
extern struct one_terminal_reduction one_terminal_reduction_array[];
extern Op identical_children_reduction_array[];
extern Op negation_child_reduction_array[];
extern Op negation_parent_reduction_array[];
extern Op two_nodes_left_reduction_array[];
extern struct three_nodes_reduction three_nodes_reduction_array[];
extern Op three_nodes_two_grandchildren_reduction_array[];

#endif
