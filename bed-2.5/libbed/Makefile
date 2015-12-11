# 
#  Copyright (c) 1996 - 2000 Technical University of Denmark
#  Copyright (c) 1999 - 2000 IT University in Copenhagen
#
# by Poul Frederick Williams, Henrik Hulgaard, Henrik Reif Andersen
# IT University of Copenhagen
# Glentevej 67
# DK-2400 Copenhagen NV, Denmark
# 
# e-mail: {pfw,henrik,hra}@it-c.dk

SRC		= prime.c tables.c upone.c bed.c op.c sat.c bedfsm.c \
			replace.c upall.c kernel.c ref.c bedio.c restrict.c \
			simplify.c cache.c quant.c upsome.c

CPPSRC		= bedcpp.cpp

HDR		= prime.h tables.h upone.h bed.h op.h sat.h bedfsm.h \
			replace.h upall.h kernel.h ref.h bedio.h restrict.h \
			simplify.h cache.h quant.h upsome.h

OBJ		= $(addprefix obj/, $(subst .c,.o,$(SRC))) \
		  $(addprefix obj/, $(subst .cpp,.o,$(CPPSRC)))

LIBDIR		= ../lib
TARGET		= $(LIBDIR)/libbed.a
INCLUDE		= -I../libutil 

CFLAGS		= -fPIC $(CDEBUG) $(INCLUDE) $(DEFS) $(OPTIMIZE) 
CPPFLAGS	= $(INCLUDE) -ansi

obj/%.o : %.c	;	@echo Compiling $(notdir $<)
		@$(CC) -c $(CFLAGS) $(INCLUDE) $< -o $@

obj/%.o : %.cpp	;	@echo Compiling $(notdir $<)
		@$(CPP) -c $(CFLAGS) $(INCLUDE) $< -o $@

# -----[ Standard Rules for Binaries ]------------------------------

.PHONY:		all clean depend

all:		$(TARGET) 

$(TARGET):	$(OBJ) obj/version.o ../lib/libutil.a
		@echo Building $(TARGET) ...
		@$(CC) -c $(CFLAGS) $(INCLUDE) version.c -o obj/version.o
		@rm -f $(TARGET)
		@ar rv $(TARGET) $(OBJ) obj/version.o
		@$(RANLIB) $(TARGET)

clean:
		@echo Removing object files 
		@rm -f $(OBJ) $(TARGET)

depend:		
		@if [ ! -d obj ]; then mkdir obj; fi
		@$(CC) -MM $(CPPFLAGS) $(SRC) > obj/dependencies
		@$(CPP) -MM $(CPPFLAGS) $(CPPSRC) >> obj/dependencies

-include obj/dependencies
