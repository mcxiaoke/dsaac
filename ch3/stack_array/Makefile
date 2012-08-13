RM=rm
EXE=stack_array.exe
CC=gcc
CXX=g++
CFLAGS=-O2 -g
CXXFLAGS=
LIBS=
LDFLAGS=-
OBJECTS=stack2.o

$(EXE): $(OBJECTS)
	$(CC) -o $(EXE) $(OBJECTS) $(CFLAGS)

.PHONY: clean
clean: 
	-$(RM) $(EXE) $(OBJECTS)