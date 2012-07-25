/*
 * BST.h
 *
 *  Created on: 2012-7-10
 *      Author: mcxiaoke
 */

#ifndef BST_H_
#define BST_H_

// 这个是二叉搜索树的ADT

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#ifndef NULL
#define NULL   ((void *) 0)
#endif

#define BST_MAX 10
#define STATCK_MAX 20

struct TREE_NODE;
typedef struct TREE_NODE TreeNode;
typedef struct TREE_NODE *BST;

void bst_create(BST *tree);
void bst_clear(BST tree);
void bst_destroy(BST tree);

BST bst_insert(int value, BST *ptree);
TreeNode* bst_search(int value, BST tree);
TreeNode* bst_delete(int value, BST tree);
int bst_retrieve(TreeNode* position);

void bst_preOrder(BST tree);
void bst_inOrder(BST tree);
void bst_postOrder(BST tree);
void bst_levelOrder(BST tree);

void bst_preOrderIter(BST tree);
void bst_inOrderIter(BST tree);
void bst_postOrderIter(BST tree);
void lbst_evelOrderIter(BST tree);

TreeNode* bst_successor(BST node);
TreeNode* bst_find(int value, BST tree);
TreeNode* bst_findMax(BST tree);
TreeNode* bst_findMin(BST tree);

#endif /* BST_H_ */
