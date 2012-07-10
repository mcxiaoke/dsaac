/*
 * binarytree.h
 *
 *  Created on: 2012-7-10
 *      Author: mcxiaoke
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_

// 这个是二叉搜索树的ADT

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#ifndef NULL
#define NULL   ((void *) 0)
#endif

struct TREE_NODE;
typedef struct TREE_NODE TreeNode;
typedef struct TREE_NODE *Position;
typedef struct TREE_NODE *BinaryTree;

BinaryTree create(int len);
BinaryTree create2(int array[], int length);
BinaryTree clear(BinaryTree tree);
void destroy(BinaryTree tree);

BinaryTree insert(int value, BinaryTree tree);
BinaryTree delete(int value, BinaryTree tree);
int retrieve(Position position);

void preorderTraverse(BinaryTree tree);
void inorderTraverse(BinaryTree tree);
void postorderTraverse(BinaryTree tree);

void preorderTraverse2(BinaryTree tree);
void inorderTraverse2(BinaryTree tree);
void postorderTraverse2(BinaryTree tree);

Position find(int value, BinaryTree tree);
Position findMax(BinaryTree);
Position findMin(BinaryTree tree);

void fatal(char *message);

#endif /* BINARYTREE_H_ */
