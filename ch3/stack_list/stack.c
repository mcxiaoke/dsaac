#include "stack.h"

struct STACK_NODE
{
    int value;
    StackNode *next;
};

static void fatal(char *message);


// create stack
Stack createStack(int size)
{
    Stack s;
    s=(Stack)malloc(sizeof(StackNode));
    if(s==NULL)
    {
        fatal("stack malloc failed.");
    }
    s->next=NULL;
    return s;

}
// destroy stack
void destroyStack(Stack s)
{
    assert(s!=NULL);
    clearStack(s);
    free(s);
}

//check is empty
int isEmptyStack(Stack s)
{
    return s->next==NULL;
}

// clear stack
void clearStack(Stack s)
{
    while(!isEmptyStack(s)){
        popStack(s);
    }
}

// push value to stack
void pushStack(int value, Stack s)
{
	PStackNode newNode;
    newNode=(PStackNode)malloc(sizeof(StackNode));
    if(newNode==NULL)
    {
        fatal("new node malloc failed");
    }
    newNode->value=value;
    newNode->next=s->next;
    s->next=newNode;

}

// pop top node, not return
void popStack(Stack s)
{
    assert(s!=NULL);
    PStackNode node=s->next;
    s->next=s->next->next;
    free(node);
}

// return top value, not pop
int topStack(Stack s)
{
    if(isEmptyStack(s))
    {
        fatal("empty stack");
    }
    return s->next->value;
}

// print stack values
void printStack(Stack s){
    assert(s!=NULL);
    if(isEmptyStack(s)){
        printf("stack is empty.\n");
        return;
    }
    
    printf("stack: ");
    PStackNode node=s->next;
    while(node!=NULL){
        printf("%d ", node->value);
        node=node->next;
    }
    printf("\n");
    
}

// fatal error message
static void fatal(char *message)
{
    printf("Fatal error: %s",message);
    exit(0);
}


