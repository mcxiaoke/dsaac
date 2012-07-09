RM=rm
EXE=stack_list.exe
CC=gcc
CXX=g++
CFLAGS=-O2 -g -std=c99
CXXFLAGS=
LIBS=
LDFLAGS=
OBJECTS=stack.o main.o

$(EXE): $(OBJECTS)
	$(CC) -o $(EXE) $(OBJECTS) $(CFLAGS)

.PHONY: clean
clean: 
	-$(RM) $(EXE) $(OBJECTS)
test:
	-$(EXE)