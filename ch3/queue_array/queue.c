#include "queue.h"

struct QueueRecord
{
    int capacity;
    int front;
    int end;
    int size;
    int *data;
};

static void printInfo(Queue q)
{
    if(q==NULL)
    {
        printf("queue is null.\n");
    }
    else
    {
        printf("Size: %d, Front: %d, End: %d\n",
               q->size,q->front,q->end);
    }

}

void fatal(char *message)
{
    printf(message);
    exit(1);
}

int isEmpty(Queue q)
{
    return q->size==0;
}

int isFull(Queue q)
{
    return q->size==q->capacity;
}

void clear(Queue q)
{
    assert(q!=NULL);
    q->size=0;
    q->front=1;
    q->end=0;
}

Queue create(int maxSize)
{
    Queue q;
    q=(Queue)malloc(sizeof(struct QueueRecord));
    if(q==NULL)
    {
        fatal("queue malloc failed.");
    }
    q->data=malloc(sizeof(int)*maxSize);
    q->capacity=maxSize;
    if(q->data==NULL)
    {
        fatal("data array malloc failed.");
    }
    clear(q);
    return q;
}

void destroy(Queue q)
{
    assert(q!=NULL);
    free(q->data);
    free(q);
}

void print(Queue q)
{
    assert(q!=NULL);
    if(isEmpty(q))
    {
        printf("queue is empty.\n");
        return;
    }
    for(int i=q->front; i<(q->front+q->size); i++)
    {

        int cursor=i;
        if(cursor>=q->capacity)
        {
            cursor=i-q->capacity;
        }
        printf("%d ", q->data[cursor]);
    }

    printf("\n");
}

void enqueue(int value, Queue q)
{
    assert(q!=NULL);
    if(isFull(q))
    {
        fatal("queue is full.");
    }
    q->size++;
    if(++q->end==q->capacity)
    {
        q->end=0;
    }
    q->data[q->end]=value;
}

int dequeue(Queue q)
{
    assert(q!=NULL);
    if(isEmpty(q))
    {
        fatal("queue is empty.");
    }
    q->size--;
    int tmp= q->data[q->front];
    if(++q->front==q->capacity)
    {
        q->front=0;
    }
    return tmp;
}

int front(Queue q)
{
    assert(q!=NULL);
    return q->data[q->front];
}

int main(int argc, char **argv)
{
    Queue q=create(10);
    for(int i=0; i<10; i++)
    {
        enqueue(i, q);
        print(q);
    }
    printInfo(q);
    printf("===========================\n");
    for(int i=0; i<8; i++)
    {
        dequeue(q);
        print(q);
    }
    printInfo(q);
    printf("===========================\n");
    for(int i=0; i<7; i++)
    {
        enqueue(-i,q);
        print(q);
    }
    printInfo(q);
    printf("===========================\n");
    for(int i=0; i<6; i++)
    {
        dequeue(q);
        print(q);
    }
    printInfo(q);
    printf("===========================\n");
    clear(q);
    print(q);
}
