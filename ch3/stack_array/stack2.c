#include "stack2.h"

#define EMPTY_POSITION (-1)
#define MIN_STACK_SIZE (5)

struct StackRecord{
    int size;
    int top;
    int *data;
};

Stack create(int initSize){
    Stack s;
    if(initSize<MIN_STACK_SIZE){
        fatal("stack size is too small");
    }
    s=(Stack)malloc(sizeof(struct StackRecord));
    if(s==NULL){
        fatal("stack malloc failed.");
    }
    s->data=malloc(sizeof(int)*initSize);
    s->size=initSize;
    clear(s);
    return s;
}


void destroy(Stack s){
    assert(s!=NULL);
    free(s->data);
    free(s);
}
int isEmpty(Stack s){
    assert(s!=NULL);
    return s->top==EMPTY_POSITION;
}
int isFull(Stack s){
    return s->top==s->size-1;
}
void clear(Stack s){
    assert(s!=NULL);
    s->top=EMPTY_POSITION;
}
void push(int value, Stack s){
    assert(s!=NULL);
    if(isFull(s)){
        fatal("stack is full");
    }
    //s->data[++s->top]=value;
    ++s->top;
    s->data[s->top]=value;
}
void pop(Stack s){
    assert(s!=NULL);
    if(isEmpty(s)){
        fatal("stack is empty.");
    }
    s->top--;
}
int top(Stack s){
    assert(s!=NULL);
    if(isEmpty(s)){
        fatal("stack is empty.");
    }
    return s->data[s->top];
}
int topAndPop(Stack s){
    assert(s!=NULL);
    if(isEmpty(s)){
        fatal("stack is empty.");
    }
    return s->data[s->top--];
}
void print(Stack s){
    assert(s!=NULL);
    if(isEmpty(s)){
        printf("stack is empty.\n");
    }else{
        for(int i=s->top;i>=0;i--){
            printf("[%d]--%d\n",i, s->data[i]);
        }
        printf("\n"); 
    }
}
void fatal(char *message){
    printf(message);
    exit(1);
}

int main(int argc, char **argv)
{
    Stack s=create(10);
    for(int i=0;i<10;i++){
        push(rand()%100,s);
    }
    printf("Stack Size: %d\n", s->size);
    printf("Stack Top: %d\n", s->top);
    print(s);
    pop(s);
    pop(s);
    print(s);
    printf("topAndPop: %d\n",topAndPop(s));
    print(s);
    clear(s);
    print(s);
	return 0;
}
