#include "queue.h"
#include "bst.h"
struct QueueRecord {
	int capacity;
	int front;
	int end;
	int size;
	void **data;
};

void queue_fatal(char *message) {
	printf(message);
	exit(1);
}

int queue_isEmpty(Queue q) {
	return q->size == 0;
}

int queue_isFull(Queue q) {
	return q->size == q->capacity;
}

void queue_clear(Queue q) {
	assert(q!=NULL);
	q->size = 0;
	q->front = 1;
	q->end = 0;
}

Queue queue_create(int maxSize) {
	Queue q;
	q = (Queue) malloc(sizeof(struct QueueRecord));
	if (q == NULL ) {
		queue_fatal("queue malloc failed.");
	}
	q->data = malloc(sizeof(void*) * maxSize);
	q->capacity = maxSize;
	if (q->data == NULL ) {
		queue_fatal("data array malloc failed.");
	}
	queue_clear(q);
	return q;
}

void queue_destroy(Queue q) {
	assert(q!=NULL);
	free(q->data);
	free(q);
}

void queue_print(Queue q) {
	assert(q!=NULL);
	if (queue_isEmpty(q)) {
		printf("queue is empty.\n");
		return;
	}
	for (int i = q->front; i < (q->front + q->size); i++) {

		int cursor = i;
		if (cursor >= q->capacity) {
			cursor = i - q->capacity;
		}
		printf("%d ", q->data[cursor]);
	}

	printf("\n");
}

void queue_enqueue(void* value, Queue q) {
	assert(q!=NULL);
	if (queue_isFull(q)) {
		queue_fatal("queue is full.");
	}
	q->size++;
	if (++q->end == q->capacity) {
		q->end = 0;
	}
	q->data[q->end] = value;
//	BST t= (BST)q->data[q->end];
//	printf("[queue_enqueue %d]\n", t->value);
}

void* queue_dequeue(Queue q) {
	assert(q!=NULL);
	if (queue_isEmpty(q)) {
		queue_fatal("queue is empty.");
	}
	q->size--;
	void* tmp = q->data[q->front];
	if (++q->front == q->capacity) {
		q->front = 0;
	}
	return tmp;
}

void* queue_front(Queue q) {
	assert(q!=NULL);
//	BST t= (BST)q->data[q->front];
//	printf("queue_front %d\n", t->value);
	return q->data[q->front];
}
