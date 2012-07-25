#ifndef _STACK_H_
#define _STACK_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct STACK_NODE;
typedef struct STACK_NODE StackNode;
typedef struct STACK_NODE *PStackNode;
typedef struct STACK_NODE *Stack;

Stack stack_create(int size);
void stack_destroy(Stack s);
int stack_isEmpty(Stack s);
void stack_clear(Stack s);
void stack_push(void *data, Stack s);
void stack_pop(Stack s);
void* stack_top(Stack s);
void stack_print(Stack s);

#endif
