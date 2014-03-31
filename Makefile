# Makefile for animal_guess program

CFLAGS= -std=c99 
SRC=animal-main.c animal.c
OBJ=animal-main.o animal.o
animal_guess: ${OBJ} 

# New target

depend: makedepend -Y ${SRC} &> /dev/null 

clean: rm -f ${OBJ} animal_guess Makefile.bak 

install: animal_guess cp animal_guess ~/bin

animal-main.o: animal.h
animal.o: animal.h

