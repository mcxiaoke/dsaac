#ifndef _LIST_H_
#define _LIST_H_

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct NODE Node;
typedef Node* List;

// create a list
List createList();
// destroy a list
void destroyList(List list);
// return first node
Node* first(List list);
// return last node
Node* last(List list);
// list is or not empty
int isEmpty(List list);
// node is or not the last one
int isLast(Node* node, List list);
// find value in list
Node* find(int value, List list);
// delete value in list
void delete(int value, List list);
// insert value after node
Node* insert(int value, Node* node, List list);
// insert value before node
void insertBefore(int value, Node* node, List list);
// find previous node
Node* findPrev(Node* node, List list);
// find next node
Node* findNext(Node* node, List list);
// print list
void print(List list);
// clear list nodes
void clear(List list);
// length of list
int length(List list);
// print error and exit
void fatal(char *message);

#endif
