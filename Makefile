# Makefile for guess_animal program

CFLAGS= -std=c99 
SRC=animal-main.c animal.c
OBJ=animal-main.o animal.o
guess_animal: ${OBJ} 

# New target

depend: makedepend -Y ${SRC} &> /dev/null 

clean: rm -f ${OBJ} guess_animal Makefile.bak 

install: guess_animal cp guess_animal ~/bin

animal-main.o: animal.h
animal.o: animal.h

