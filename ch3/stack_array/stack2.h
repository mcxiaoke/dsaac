#ifndef _STACK2_H_
#define _STACK2_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct StackRecord;
typedef struct StackRecord *Stack;

Stack create(int size);
void destroy(Stack s);
int isEmpty(Stack s);
int isFull(Stack s);
void clear(Stack s);
void push(int value, Stack s);
void pop(Stack s);
int top(Stack s);
int topAndPop(Stack s);
void print(Stack s);
void fatal(char *message);


#endif
