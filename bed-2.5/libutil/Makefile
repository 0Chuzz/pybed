# 
#  Copyright (c) 1996 - 2000 Technical University of Denmark
#  Copyright (c) 1999 - 2000 IT University of Copenhagen
#
# by Poul Frederick Williams, Henrik Hulgaard, Henrik Reif Andersen
# IT University of Copenhagen
# Glentevej 67
# DK-2400 Copenhagen NV, Denmark
# 
# e-mail: {pfw,henrik,hra}@it-c.dk

SRC		= Malloc.c darray.c getruntime.c ilist.c list.c \
		  cb.c getline.c hash.c lex.c timer.c istack.c

HDR		= Malloc.h darray.h hash.h list.h bool.h getline.h \
		  ilist.h timer.h cb.h getruntime.h lex.h istack.h

OBJ		= $(addprefix obj/, $(subst .c,.o,$(SRC)))

LIBDIR		= ../lib
TARGET		= $(LIBDIR)/libutil.a
INCLUDE		= -I.

CFLAGS		= -fPIC $(CDEBUG) $(INCLUDE) $(DEFS) $(OPTIMIZE)
CPPFLAGS	= $(INCLUDE) 

obj/%.o : %.c	;	@echo Compiling $(notdir $<)
		@$(CC) -c $(CFLAGS) $(INCLUDE) $< -o $@

# -----[ Standard Rules for Binaries ]------------------------------

.PHONY:		all clean depend

all:		$(TARGET) 

$(TARGET):	$(OBJ) 
		@echo Building $(TARGET) ...
		@rm -f $(TARGET)
		@ar rv $(TARGET) $(OBJ)
		@$(RANLIB) $(TARGET)

clean:
		@echo Removing object files 
		@rm -f $(OBJ) $(TARGET)

depend:		
		@if [ ! -d obj ]; then mkdir obj; fi
		@$(CC) -MM $(CPPFLAGS) $(SRC) > obj/dependencies

-include obj/dependencies
