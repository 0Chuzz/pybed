#!/usr/bin/env python2
import sys
import bed
print dir(bed)
print bed.mk_op(bed.Op.BED_AND, bed.mk_var(bed.Var()), bed.mk_var(bed.Var()))
