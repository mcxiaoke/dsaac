RM=rm
EXE=dlist.exe
CC=gcc
CXX=g++
CFLAGS=-O2 -g
CXXFLAGS=
LIBS=
LDFLAGS=
OBJECTS=dlist.o

$(EXE): $(OBJECTS)
	$(CC) -o $(EXE) $(OBJECTS) $(CFLAGS)
#list.o: list.h
.PHONY: clean
clean: 
	-$(RM) $(EXE) $(OBJECTS)