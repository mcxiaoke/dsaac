#include "stack.h"

struct Node
{
    int value;
    PNode next;
};
// create stack
Stack create(int size)
{
    Stack s;
    s=(Stack)malloc(sizeof(struct Node));
    if(s==NULL)
    {
        fatal("stack malloc failed.");
    }
    s->next=NULL;
    return s;

}
// destroy stack
void destroy(Stack s)
{
    assert(s!=NULL);
    clear(s);
    free(s);
}

//check is empty
int isEmpty(Stack s)
{
    return s->next==NULL;
}

// clear stack
void clear(Stack s)
{
    while(!isEmpty(s)){
        pop(s);
    }
}

// push value to stack
void push(int value, Stack s)
{
    PNode newNode;
    newNode=(PNode)malloc(sizeof(struct Node));
    if(newNode==NULL)
    {
        fatal("new node malloc failed");
    }
    newNode->value=value;
    newNode->next=s->next;
    s->next=newNode;

}

// pop top node, not return
void pop(Stack s)
{
    assert(s!=NULL);
    PNode node=s->next;
    s->next=s->next->next;
    free(node);
}

// return top value, not pop
int top(Stack s)
{
    if(isEmpty(s))
    {
        fatal("empty stack");
    }
    return s->next->value;
}

// print stack values
void print(Stack s){
    assert(s!=NULL);
    if(isEmpty(s)){
        printf("stack is empty.\n");
        return;
    }
    
    printf("stack: ");
    PNode node=s->next;
    while(node!=NULL){
        printf("%d ", node->value);
        node=node->next;
    }
    printf("\n");
    
}

// fatal error message
void fatal(char *message)
{
    printf("Fatal error: %s",message);
    exit(0);
}


