#!/usr/bin/env python2
import sys
import bed
from os import tempnam
a = tempnam()
b = bed.mk_op(bed.Op.BED_AND, bed.mk_var(bed.Var()), bed.mk_var(bed.Var()))
b.write_graph(a)
with open(a) as f:
    print f.read()

c = bed.read_file(a)
print a,b,c
print b == c, cmp(b,c)
