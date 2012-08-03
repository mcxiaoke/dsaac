RM=rm
EXE=avl.exe
CC=gcc
CXX=g++
CFLAGS=-O2 -g -Wall -std=c99
#CXXFLAGS=
#LIBS=
#LDFLAGS=
OBJECTS=avl.o main.o

$(EXE): $(OBJECTS)
	$(CC) -o $(EXE) $(OBJECTS) $(CFLAGS)

.PHONY: clean
clean: 
	-$(RM) $(EXE) $(OBJECTS)