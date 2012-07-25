#include "stack.h"

// main 
int main(int argc, char** argv)
{
    
    Stack s;
    s=createStack(0);
    int i;
    for(i=0;i<10;i++){
        pushStack(rand()%100,s);
    }
    
    printStack(s);
    printf("Top: %d\n",topStack(s));
    popStack(s);
    popStack(s);
    printStack(s);
    printf("Top: %d\n",topStack(s));
    clearStack(s);
    printStack(s);
    exit(0);
}
