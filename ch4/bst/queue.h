#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#ifndef NULL
#define NULL   ((void *) 0)
#endif

struct QueueRecord;
typedef struct QueueRecord *Queue;

void queue_fatal(char *message);
int queue_isEmpty(Queue q);
int queue_isFull(Queue q);
void queue_clear(Queue q);
Queue queue_create(int maxSize);
void queue_destroy(Queue q);
void queue_print(Queue q);
void queue_enqueue(void* p, Queue q);
void* queue_dequeue(Queue q);
void* queue_front(Queue q);
