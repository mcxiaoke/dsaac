RM=rm
EXE=stack_array.exe
CC=gcc
CXX=g++
CFLAGS=-O2 -g -std=c99
CXXFLAGS=
LIBS=
LDFLAGS=-
OBJECTS=stack2.o

$(EXE): $(OBJECTS)
	$(CC) -o $(EXE) $(OBJECTS) $(CFLAGS)

clean: 
	-$(RM) $(EXE) $(OBJECTS)
test:
	-$(EXE)