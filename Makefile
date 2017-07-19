# Makefile template for CS 270

# List of files
C_SRCS		= expox.c expoxch.c
C_OBJS		= expox.o expoxch.o

OBJS		= ${C_OBJS} 


# Compiler and loader commands and flags
CC		= c99
CC_FLAGS	= -g -Wall -c 
LD_FLAGS	= -g -Wall 

all:	expox	expoxch

expox:
	$(CC) $(CCFLAGS) expox.c -o expox -lm
	
expoxch:
	$(CC) $(CCFLAGS) expoxch.c -o expoxch -lm

# Clean up the directory
clean:
	rm -f *.o *~ expox	expoxch 

# Package the directory
package:
	@echo "Packaging up project directory ..."
