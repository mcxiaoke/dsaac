#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#ifndef NULL
#define NULL   ((void *) 0)
#endif

struct QueueRecord;
typedef struct QueueRecord *Queue;

void fatal(char *message);
int isEmpty(Queue q);
int isFull(Queue q);
void clear(Queue q);
Queue create();
void destroy(Queue q);
void print(Queue q);
void enqueue(int value, Queue q);
int dequeue(Queue q);
int front(Queue q);
