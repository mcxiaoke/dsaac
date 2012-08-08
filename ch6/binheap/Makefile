CC=mingw32-gcc
CXX=mingw32-g++
CFLAGS=-O2 -g -std=c99 -Wall
#SRC = $(wildcard *.c)
#OBJS=$(patsubst %.c,%.o, $(SRC))

.PHONY: clean all

all: binheap findk

binheap: main.o heap.o utils.o
	$(CC) -o binheap main.o heap.o utils.o $(CFLAGS)
	
findk: findk.o heap.o utils.o
	$(CC) -o findk findk.o heap.o utils.o $(CFLAGS)

clean: 
	-rm *.exe *.o