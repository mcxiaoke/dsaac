RM=rm
EXE=list.exe
CC=gcc
CXX=g++
CFLAGS=-O2 -g -Wall
CXXFLAGS=
LIBS=
LDFLAGS=
OBJECTS=list.o

$(EXE): $(OBJECTS)
	$(CC) -o $(EXE) $(OBJECTS) $(CFLAGS)
#list.o: list.h

.PHONY: clean
clean: 
	-$(RM) $(EXE) $(OBJECTS)