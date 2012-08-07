CC=mingw32-gcc
CXX=mingw32-g++
CFLAGS=-O2 -g -std=c99 -Wall
SRC = $(wildcard *.c)
OBJS=$(patsubst %.c,%.o, $(SRC))

EXE=binheap.exe

all: $(EXE)

$(EXE):$(OBJS)
	$(CC) -o $(EXE) $(OBJS) $(CFLAGS)

.PHONY: clean
clean: 
	-rm $(EXE) $(OBJS)