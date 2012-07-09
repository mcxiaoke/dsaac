#ifndef _STACK_H_
#define _STACK_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Node;
typedef struct Node *PNode;
typedef PNode Stack;

Stack create(int size);
void destroy(Stack s);
int isEmpty(Stack s);
void clear(Stack s);
void push(int value, Stack s);
void pop(Stack s);
int top(Stack s);
void print(Stack s);
void fatal(char *message);


#endif
