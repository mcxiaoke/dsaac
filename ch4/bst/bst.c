/*
 * BST.c
 *
 *  Created on: 2012-7-10
 *      Author: mcxiaoke
 */

#include "bst.h"
#include "stack.h"

#include <time.h>

static void fatal(char *message);
static TreeNode* makeNode(int value);
static void show(BST tree);
static void swap(void *a, void *b);
int* random(int size);

struct TREE_NODE {
	int value;
	BST left;
	BST right;
};

void bst_create(BST *ptree) {
	printf("Data: \t  ");
	srand((unsigned) time(NULL ));
	int data[100];
	for(int i=0; i< 100; i++){
		data[i]=i;
	}
	for(int i=0; i< 100; i++){
		int j=rand()%100;
		int tmp=data[i];
		data[i]=data[j];
		data[j]=tmp;
	}
	for (int i = 0; i < BST_MAX; ++i) {
		int x = data[i];
		bst_insert(x, ptree);
		printf("%3d ", x);
	}
	printf("\n");
}

void bst_clear(BST tree) {
	if (tree != NULL ) {
		bst_clear(tree->left);
		bst_clear(tree->right);
		free(tree);
	}
}
void bst_destroy(BST tree) {
	bst_clear(tree);
	tree = NULL;
}

BST bst_insert(int value, BST *ptree) {
	assert(ptree!=NULL);

	if (*ptree == NULL ) {
		*ptree = makeNode(value);
//		printf("Insert \t%4d\n", (*ptree)->value, *ptree);
		return *ptree;
	}

	BST tree = *ptree;
	if (value < tree->value) {
		return bst_insert(value, &(tree->left));
	} else if (value > tree->value) {
		return bst_insert(value, &(tree->right));
	} else {
		return NULL ;
	}
}

TreeNode* bst_delete(int value, BST tree) {
	TreeNode *tmpNode;
	if (tree == NULL ) {
		fatal("node not found.\n");
	}
	if (value < tree->value) {
		tree->left = bst_delete(value, tree->left);
	} else if (value > tree->value) {
		tree->right = bst_delete(value, tree->right);
	} else if (tree->left && tree->right) {
		tmpNode = bst_findMin(tree->right);
		tree->value = tmpNode->value;
		tree->right = bst_delete(tree->value, tree->right);
	} else {
		tmpNode = tree;
		if (tree->left == NULL ) {
			tree = tree->right;
		} else if (tree->right == NULL ) {
			tree = tree->left;

		}
		free(tmpNode);
	}
	return tree;
}

// 递归版查找
TreeNode* bst_search(int value, BST tree) {
	if (tree == NULL ) {
		return NULL ;
	} else if (value == tree->value) {
		return tree;
	} else if (value < tree->value) {
		return bst_search(value, tree->left);
	} else {
		return bst_search(value, tree->right);
	}
}

//非递归版查找
TreeNode* bst_find(int value, BST tree) {
//	return bst_search(value, tree);
	while (tree != NULL && value != tree->value) {
		if (value < tree->value) {
			tree = tree->left;
		} else {
			tree = tree->right;
		}
	}
	return tree;
}

// 查找某一节点的后继
// 后继定义：Node的后继是指这一节点的值在所有大于Node的节点中最小的那个节点
TreeNode* bst_successor(BST node) {
	// TODO
	return NULL ;
}

// 查找最大值节点，递归版本
TreeNode* bst_findMax(BST tree) {
	if (tree == NULL ) {
		return NULL ;
	}
	if (tree->right == NULL ) {
		return tree;
	} else {
		return bst_findMax(tree->right);
	}
}

// 查找最小值节点，非递归版本
TreeNode* bst_findMin(BST tree) {
	if (tree != NULL ) {
		while (tree->left != NULL ) {
			tree = tree->left;
		}
	}
	return tree;
}

void bst_preOrder(BST tree) {
	if (tree != NULL ) {
		show(tree);
		bst_preOrder(tree->left);
		bst_preOrder(tree->right);
	}
}
void bst_inOrder(BST tree) {
	if (tree != NULL ) {
		bst_inOrder(tree->left);
		show(tree);
		bst_inOrder(tree->right);
	}
}
void bst_postOrder(BST tree) {
	if (tree != NULL ) {
		bst_postOrder(tree->left);
		bst_postOrder(tree->right);
		show(tree);
	}
}
void bst_levelOrder(BST tree) {
	//TODO
}

void bst_preOrderIter(BST tree) {
	Stack s = stack_create(BST_MAX);
	while (tree != NULL || !stack_isEmpty(s)) {
		if (tree != NULL ) {
			show(tree);
			stack_push(tree, s);
			tree = tree->left;
		} else {
			tree = (BST) stack_top(s);
			stack_pop(s);
			tree = tree->right;
		}
	}
	stack_destroy(s);
}

void bst_inOrderIter(BST tree) {
	Stack s = stack_create(BST_MAX);
	while (tree != NULL || !stack_isEmpty(s)) {
		if (tree != NULL ) {
			stack_push(tree, s);
			tree = tree->left;
		} else {
			tree = (BST) stack_top(s);
			show(tree);
			stack_pop(s);
			tree = tree->right;
		}
	}
	stack_destroy(s);
}
void bst_postOrderIter(BST tree) {
	Stack s = stack_create(BST_MAX);
	BST p = tree;
	BST q = NULL;
	while (p != NULL || !stack_isEmpty(s))  //栈空时结束
	{
		while (p != NULL ) {
			stack_push(p, s);
			p = p->left;
		}
		p = stack_top(s);
		if (p->right == NULL || p->right == q) {
			show(p);
			q = stack_top(s);
			stack_pop(s);
			p = NULL;
		} else {
			p = p->right;
		}
	}
	stack_destroy(s);
}
void bst_levelOrderIter(BST tree) {
	//TODO
}

static TreeNode* makeNode(int value) {
	TreeNode* node = (TreeNode*) malloc(sizeof(TreeNode));
	if (node != NULL ) {
		node->value = value;
		node->left = NULL;
		node->right = NULL;
		//printf("makeNode: %d [0x%x]\n", value, node);
	}
	return node;
}

static void show(BST tree) {
	if (tree != NULL ) {
		printf("%3d ", tree->value);
	}
}

static void swap(void *a, void *b) {
	void *tmp = a;
	a = b;
	b = tmp;
}

int* random(int size){
	assert(size>0);
	int data[size];
	return data;
}

static void fatal(char *message) {
	printf("%s\n", message);
	exit(1);
}

int main(int argc, char **argv) {
	setvbuf(stdout, 0, _IONBF, 0);
	BST tree=NULL;
	bst_create(&tree);
	printf("\nPreOrder Rec: ");
	bst_preOrder(tree);
	printf("\nPreOrder Cir: ");
	bst_preOrderIter(tree);
	printf("\n\nInOrder Rec:  ");
	bst_inOrder(tree);
	printf("\nInOrder Cir:  ");
	bst_inOrderIter(tree);
	printf("\n\nPostOrder Rec:");
	bst_postOrder(tree);
	printf("\nPostOrder Cir:");
	bst_postOrderIter(tree);

	return 0;
}

/**********************************************************************************************
 // 参考资料

 // 二叉查找树完整实现见：
 // http://www.cnblogs.com/tanky_woo/archive/2011/05/03/2035160.html

 // 非递归遍历
 // http://www.slyar.com/blog/bitree-unrecursion-c.html

 // 层次遍历
 * http://blog.csdn.net/flyfeifei66/article/details/5382510
 *
 C++模板实现
 http://blog.csdn.net/kevinzhangyang/article/details/6650071
 http://blog.csdn.net/fans_men/article/details/6954253

 // 逆波兰表达式求解
 // http://blog.kingsamchen.com/archives/637
  *
  * 非递归遍历
  * http://www.cnblogs.com/yuchen198112/archive/2007/01/02/610065.html
  *
  * 二叉树遍历
  * http://blog.csdn.net/hackbuteer1/article/details/6583988


 **********************************************************************************************/
