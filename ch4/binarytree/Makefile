RM=rm
EXE=binarytree.exe
CC=gcc
CXX=g++
CFLAGS=-O2 -g -Wall -std=c99
#CXXFLAGS=
#LIBS=
#LDFLAGS=
OBJECTS=binarytree.o

$(EXE): $(OBJECTS)
	$(CC) -o $(EXE) $(OBJECTS) $(CFLAGS)

.PHONY: clean
clean: 
	-$(RM) $(EXE) $(OBJECTS)