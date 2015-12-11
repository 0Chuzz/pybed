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

SRC		= shell.c help.c
HDR		= shell.h help.h

OBJ		= $(addprefix obj/, $(subst .c,.o,$(SRC)))

LIBDIR		= ../lib
TARGET		= $(LIBDIR)/libshell.a

# -----[ Compile Flags and Rules ]----------------------------------

INCLUDE		= -I../libbed -I../libutil
LIBS		= -L../lib -lbed -lutil -lm

CFLAGS		= $(CDEBUG) $(INCLUDE) $(DEFS) $(OPTIMIZE)
CPPFLAGS	= $(INCLUDE) 
LDFLAGS		= $(LIBS) $(INCLUDE)

obj/%.o : %.c	;	@echo Compiling $(notdir $<)
		@$(CC) -c $(CFLAGS) $(INCLUDE) $< -o $@

# -----[ Standard Rules for Binaries ]------------------------------

.PHONY:		all clean depend 

all:		$(TARGET) 

$(TARGET):	$(OBJ) obj/version.o ../lib/libbed.a ../lib/libutil.a
		@echo Building $(TARGET)... 
		@$(CC) -c $(CFLAGS) $(INCLUDE) version.c -o obj/version.o
		@rm -f $(TARGET)
		@ar rv $(TARGET) $(OBJ) obj/version.o
		@$(RANLIB) $(TARGET)

clean:
		@echo Removing object files 
		@rm -f $(OBJ)

depend:		
		@if [ ! -d obj ]; then mkdir obj; fi
		@$(CC) -MM $(CPPFLAGS) $(SRC)  > obj/dependencies

-include obj/dependencies
