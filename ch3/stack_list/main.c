#include "stack.h"

// main 
int main(int argc, char** argv)
{
    
    Stack s;
    s=create(0);
    int i;
    for(i=0;i<10;i++){
        push(rand()%100,s);
    }
    
    print(s);
    printf("Top: %d\n",top(s));
    pop(s);
    pop(s);
    print(s);
    printf("Top: %d\n",top(s));
    clear(s);
    print(s);
    exit(0);
}
