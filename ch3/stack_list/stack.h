#ifndef _STACK_H_
#define _STACK_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct STACK_NODE;
typedef struct STACK_NODE StackNode;
typedef struct STACK_NODE *PStackNode;
typedef struct STACK_NODE *Stack;

Stack createStack(int size);
void destroyStack(Stack s);
int isEmptyStack(Stack s);
void clearStack(Stack s);
void pushStack(int value, Stack s);
void popStack(Stack s);
int topStack(Stack s);
void printStack(Stack s);

#endif
