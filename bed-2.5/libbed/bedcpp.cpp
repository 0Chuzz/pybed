/* 
 * C++ interface
 *
 * Copyright (c) 1999 Poul Frederick Williams
 *
 * Department of Information Technology
 * Technical university of Denmark
 * DK-2800 Lyngby, Denmark
 * 
 * e-mail: pfw@it.dtu.dk
 */


#include "bed.h"

const bed bed_one_pp = bed_mk_true();
const bed bed_zero_pp = bed_mk_false();

const bed BED_UNDEFINED = bed_mk_undefined();


bed bed::operator=(const bed &r)
{
  if (root != r.root) {
    bed_deref(root);
    root = r.root;
    bed_ref(root);
  }
  return *this;
}


bed bed::operator=(bed_node r)
{
  if (root != r) {
    bed_deref(root);
    root = r;
    bed_ref(root);
  }
  return *this;
}


/* Construct bed from integer.
 * Warning: Use only if 'r' is a valid bed_node.
 */
bed bed_from_int( bed_node r )
{
  bed res;
  bed_deref( res.root );
  res.root = r;
  bed_ref( res.root );
  return res;
}
