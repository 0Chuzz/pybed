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

BED_SHELL	= shell
VERSION		= 2.5

# ===[ User definable ]==================================================

CC		= gcc
CPP		= g++ 

OPTIMIZE	= -O3 -finline-functions # -DNDEBUG
CDEBUG	 	= -g # -pg

#
# On 64-bit machines, add ``-DWORDSIZE=64'' to DEFS:
#
DEFS		= "-DCUR_DATE=\"`date`\"" -DPOSIX \
			-D__USE_FIXED_PROTOTYPES__ \
			-DREACH_TICKS \
			-DHAVE_GETRUSAGE \
			-DBED_DEFAULT_SIZE=200000 \
			-DBED_CACHE_DEFAULT_SIZE=20000

RANLIB		= ranlib

# ===[ Don't change anything below this line ]===========================

SHELL		= /bin/sh

SRC_DIRS	= libutil libbed libshell $(BED_SHELL)


export CC CPP OPTIMIZE CDEBUG DEFS RANLIB


.PHONY:		all clean distrib depend

all:		
		@for dir in $(SRC_DIRS); do \
			(cd $$dir; $(MAKE) all) ; \
		done

clean:
		@for dir in $(SRC_DIRS); do \
			(cd $$dir; $(MAKE) clean) ; \
		done

distrib:	clean
		if [ -d bed-$(VERSION) ]; then rm -rf ./bed-$(VERSION); fi
		mkdir ./bed-$(VERSION)
		cp ./README ./BED_LICENSE ./Makefile ./NEWS bed-$(VERSION)
		-for dir in $(SRC_DIRS) doc ; do \
			mkdir ./bed-$(VERSION)/$$dir; \
			cp $$dir/*.c $$dir/*.cpp $$dir/*.h $$dir/Makefile \
				$$dir/*.ps $$dir/*.pdf \
				./bed-$(VERSION)/$$dir; \
		done
		- mkdir ./bed-$(VERSION)/doc;
		- for dir in doc/manual doc/bed-note ; do \
			mkdir ./bed-$(VERSION)/$$dir; \
			cp $$dir/*.ps $$dir/*.pdf \
				./bed-$(VERSION)/$$dir; \
		done
		chmod -R u+rw ./bed-$(VERSION);
		tar cvf bed-$(VERSION).tar ./bed-$(VERSION);
		-gzip bed-$(VERSION).tar


depend:		
		@for dir in $(SRC_DIRS); do \
			(cd $$dir; $(MAKE) depend) ; \
		done
		@if [ ! -d lib ]; then mkdir lib; fi
		@if [ ! -d bin ]; then mkdir bin; fi

