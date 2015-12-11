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

SRC		= main.c
HDR		= main.h
OBJ		= $(addprefix obj/, $(subst .c,.o,$(SRC)))

TARGET		= ../bin/bed

INCLUDE		= -I../libshell -I../libbed -I../libutil
LIBS		= -L../lib/ -lshell -lbed -lutil -lm

CFLAGS		= $(CDEBUG) $(INCLUDE) $(DEFS) $(OPTIMIZE)
CPPFLAGS	= $(INCLUDE) 
LDFLAGS		= $(LIBS) $(INCLUDE)

# -----[ Standard Rules for Binaries ]------------------------------

obj/%.o : %.c	;	@echo Compiling $(notdir $<)
		@$(CC) -c $(CFLAGS) $(INCLUDE) $< -o $@

.PHONY:		all clean depend 

all:		$(TARGET) 

$(TARGET):	$(OBJ) obj/version.o ../lib/libshell.a ../lib/libbed.a ../lib/libutil.a
		@echo Building $(TARGET)...
		@$(CC) -c $(CFLAGS) $(INCLUDE) version.c -o obj/version.o
		@$(CC) $(CFLAGS) $(OBJ) obj/version.o $(LDFLAGS) -o $(TARGET)
		@chmod og+rx $(TARGET)
		@echo "Binary $(PWD)/$(TARGET) has been successfully built."

clean:
		@echo Removing object files
		@rm -f $(OBJ)

depend:		
		@if [ ! -d obj ]; then mkdir obj; fi
		@$(CC) -MM $(CPPFLAGS) $(SRC) > obj/dependencies

-include obj/dependencies
