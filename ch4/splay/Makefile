RM=rm
EXE=splay.exe
CC=mingw32-gcc
CXX=mingw32-g++
CFLAGS=-O2 -g -std=c99 -Wall
#CXXFLAGS=
#LIBS=
OBJECTS=splay.o utils.o main.o

$(EXE): $(OBJECTS)
	$(CC) -o $(EXE) $(OBJECTS) $(CFLAGS)

.PHONY: clean
clean: 
	-$(RM) $(EXE) $(OBJECTS)