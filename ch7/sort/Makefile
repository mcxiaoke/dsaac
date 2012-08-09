CC=mingw32-gcc
CXX=mingw32-g++
CFLAGS=-O2 -g -std=c99 -Wall
#SRC = $(wildcard *.c)
#OBJS=$(patsubst %.c,%.o, $(SRC))

.PHONY: clean all

all: bubbleSort

bubbleSort: bubbleSort.o utils.o
	$(CC) -o bubbleSort bubbleSort.o utils.o $(CFLAGS)

clean: 
	-rm *.exe *.o