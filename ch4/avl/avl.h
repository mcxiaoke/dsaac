/*
 * avl.h
 *
 *  Created on: 2012-8-2
 *      Author: mcxiaoke
 */

#ifndef AVL_H_
#define AVL_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define DATA_MAX 10

struct AVL_NODE;
typedef struct AVL_NODE AvlNode;
typedef struct AVL_NODE *Position;
typedef struct AVL_NODE *AvlTree;

AvlTree avl_create(AvlTree* pt);
AvlTree avl_clear(AvlTree t);
Position avl_find(int x, AvlTree t);
Position avl_findMin(AvlTree t);
Position avl_findMax(AvlTree t);
AvlTree avl_insert(int x , AvlTree t);
AvlTree avl_delete(int x , AvlTree t);
void avl_inOrder(AvlTree t);


#endif /* AVL_H_ */
