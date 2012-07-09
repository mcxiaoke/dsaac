#include "queue2.h"

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

struct QueueRecord
{
    Node *front;
    Node *rear;
};

static Node* makeNode(int value)
{
    Node *node;
    node=(Node*)malloc(sizeof(struct Node));
    if(node==NULL)
    {
        fatal("makeNode(): malloc node failed.\n");
    }
    node->value=value;
    node->next=NULL;
    return node;
}

void fatal(char *message)
{
    printf(message);
    exit(1);
};


int isEmpty(Queue q)
{
    assert(q!=NULL);
    return q->front==NULL || q->rear==NULL;
}

int isFull(Queue q)
{
    return 0;
}

void clear(Queue q)
{
    assert(q!=NULL);
    while(q->front!=NULL)
    {
        Node *cur=q->front;
        q->front=q->front->next;
        free(cur);
    }
    q->rear=NULL;
}
Queue create()
{
    Queue q;
    q=(Queue)malloc(sizeof(struct Node));
    if(q==NULL)
    {
        fatal("queue malloc failed");
    }
    q->front=NULL;
    q->rear=NULL;
    return q;
}

void destroy(Queue q)
{
    assert(q!=NULL);
    clear(q);
    free(q);
}
void print(Queue q)
{
    assert(q!=NULL);
    if(isEmpty(q))
    {
        printf("queue is empty.");
    }
    else
    {
        for(Node* cur=q->front; cur!=NULL; cur=cur->next)
        {
            printf("%d ",cur->value);
        }
    }
    printf("\n");
}
void enqueue(int value, Queue q)
{
    assert(q!=NULL);
    Node *node=makeNode(value);
    if(isEmpty(q))
    {
        q->front=node;
        q->rear=node;
    }
    else
    {
        q->rear->next=node;
        q->rear=node;
    }
}
int dequeue(Queue q)
{
    assert(q!=NULL);
    if(isEmpty(q))
    {
        fatal("queue is empty.\n");
    }
    int value=q->front->value;
    q->front=q->front->next;
    return value;
}
int front(Queue q)
{
    assert(q!=NULL);
    if(isEmpty(q))
    {
        fatal("queue is empty");
    }
    return q->front->value;
}

int main(int argc, char **argv)
{
    printf("===========================A\n");
    Queue q=create();
    for(int i=0; i<10; i++)
    {
        enqueue(i, q);
        print(q);
    }
    printf("===========================B\n");
    for(int i=0; i<8; i++)
    {
        dequeue(q);
        print(q);
    }
    printf("===========================C\n");
    for(int i=0; i<7; i++)
    {
        enqueue(-i,q);
        print(q);
    }
    printf("===========================D\n");
    for(int i=0; i<6; i++)
    {
        dequeue(q);
        print(q);
    }
    printf("===========================E\n");
    clear(q);
    print(q);
    printf("hello, world!");
    exit(0);
}
