#include "stack.h"

struct STACK_NODE
{
    void *data;
    StackNode *next;
};

static void fatal(char *message);


// create stack
Stack stack_create(int size)
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
void stack_destroy(Stack s)
{
    assert(s!=NULL);
    stack_clear(s);
    free(s);
}

//check is empty
int stack_isEmpty(Stack s)
{
    return s->next==NULL;
}

// clear stack
void stack_clear(Stack s)
{
    while(!stack_isEmpty(s)){
    	stack_pop(s);
    }
}

// push value to stack
void stack_push(void *data, Stack s)
{
	PStackNode newNode;
    newNode=(PStackNode)malloc(sizeof(StackNode));
    if(newNode==NULL)
    {
        fatal("new node malloc failed");
    }
    newNode->data=data;
    newNode->next=s->next;
    s->next=newNode;

}

// pop top node, not return
void stack_pop(Stack s)
{
    assert(s!=NULL);
    PStackNode node=s->next;
    s->next=s->next->next;
    free(node);
}

// return top value, not pop
void* stack_top(Stack s)
{
    if(stack_isEmpty(s))
    {
        fatal("empty stack");
    }
    return s->next->data;
}

// print stack values
void stack_print(Stack s){
    assert(s!=NULL);
    if(stack_isEmpty(s)){
        printf("stack is empty.\n");
        return;
    }
    
    printf("stack: ");
    PStackNode node=s->next;
    while(node!=NULL){
        printf("%d ", node->data);
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


