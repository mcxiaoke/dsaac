RM=rm
EXE=queue.exe
CC=gcc
CXX=g++
CFLAGS=-O2 -g -std=c99
CXXFLAGS=
LIBS=
LDFLAGS=-
OBJECTS=queue.o

$(EXE): $(OBJECTS)
	$(CC) -o $(EXE) $(OBJECTS) $(CFLAGS)

.PHONY: clean
clean: 
	-$(RM) $(EXE) $(OBJECTS)