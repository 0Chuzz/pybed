# 
#  Copyright (c) 1996 - 2000 Technical University of Denmark
#  Copyright (c) 1999 - 2000 IT University of Copenhagen
#
# by Poul Frederick Williams, Henrik Hulgaard, and Henrik Reif Andersen
# IT University of Copenhagen
# Glentevej 67
# DK-2400 Copenhagen NV, Denmark
# 
# e-mail: {pfw,henrik,hra}@it-c.dk

# ===[ User definable ]==================================================

LATEX		= latex
DVIPS		= dvips
PS2PDF		= ps2pdf

# ===[ Don't change anything below this line ]===========================

.PHONY:		all note manual

all:		note manual

note:
		( \
		cd bed-note; \
		$(LATEX) bed-note.tex; \
		$(LATEX) bed-note.tex; \
		$(DVIPS) -o bed-note.ps bed-note.dvi; \
		$(PS2PDF) bed-note.ps \
		)

manual:
		( \
		cd manual; \
		$(LATEX) bed-manual.tex; \
		$(LATEX) bed-manual.tex; \
		$(DVIPS) -o bed-manual.ps bed-manual.dvi; \
		$(PS2PDF) bed-manual.ps \
		)

