RM=rm
EXE=bst.exe
CC=gcc
CXX=g++
CFLAGS=-O2 -g -Wall -std=c99
#CXXFLAGS=
#LIBS=
#LDFLAGS=
OBJECTS=bst.o stack.o queue.o

$(EXE): $(OBJECTS)
	$(CC) -o $(EXE) $(OBJECTS) $(CFLAGS)

.PHONY: clean
clean: 
	-$(RM) $(EXE) $(OBJECTS)