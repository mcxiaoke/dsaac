CC=gcc
CXX=g++
CFLAGS=-O2 -g -std=c99

all: main.o
	$(CC) -o main.exe main.o $(CFLAGS)
main.o: main.c
	$(CC) -c main.c -o main.o
.PHONY: clean
clean:
	-rm main.o main.exe