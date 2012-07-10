RM=rm
EXE=queue2.exe
CC=gcc
CXX=g++
CFLAGS=-O2 -g -std=c99
CXXFLAGS=
LIBS=
LDFLAGS=-
OBJECTS=queue2.o

$(EXE): $(OBJECTS)
	$(CC) -o $(EXE) $(OBJECTS) $(CFLAGS)

.PHONY: clean
clean: 
	-$(RM) $(EXE) $(OBJECTS)