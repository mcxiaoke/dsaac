/*
 * BST.c
 *
 * 二叉查找树的建立，操作和遍历
 *  Created on: 2012-7-10
 *      Author: mcxiaoke
 */

/****************************************************************************************
 二叉树基本概念
 每个结点最多有两棵子树，左子树和右子树，次序不可以颠倒。
 性质：
 1、非空二叉树的第n层上至多有2^(n-1)个元素。
 2、深度为h的二叉树至多有2^h-1个结点。

 前序遍历：根节点->左子树->右子树
 中序遍历：左子树->根节点->右子树
 后序遍历：左子树->右子树->根节点

 ****************************************************************************************/

#include "bst.h"
#include "stack.h"
#include "queue.h"

#include <time.h>

static void fatal(char *message);
static TreeNode* makeNode(int value);
static void show(BST tree);

// 建立二叉树，随机数据，依次插入
void bst_create(BST *ptree) {
	printf("Data: \t  ");
	srand((unsigned) time(NULL ));
//	srand(100);
	int data[100];
	for (int i = 0; i < 100; i++) {
		data[i] = i;
	}
	for (int i = 0; i < 100; i++) {
		int j = rand() % 100;
		int tmp = data[i];
		data[i] = data[j];
		data[j] = tmp;
	}
	for (int i = 0; i < BST_MAX; ++i) {
		int x = data[i];
		bst_insert(x, ptree);
		printf("%3d ", x);
	}
	printf("\n");
}

// 清空二叉树，释放内存
void bst_clear(BST tree) {
	if (tree != NULL ) {
		bst_clear(tree->left);
		bst_clear(tree->right);
		free(tree);
	}
}

// 销毁二叉树，置0
void bst_destroy(BST tree) {
	bst_clear(tree);
	tree = NULL;
}

// 节点插入，递归方法
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

// 删除节点，递归执行
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

// 二叉树的高度
int bst_height(BST tree) {
	if (tree == NULL ) {
		return 0;
	}
	int height, lh, rh;
	lh = bst_height(tree->left);
	rh = bst_height(tree->right);
	height = (lh > rh ? lh : rh) + 1;
	return height;
}

// 查找操作，递归版
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

// 查找操作，非递归版
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
// 结点x的后继是具有大于key[x]中的关键字最小者的那个结点
TreeNode* bst_successor(BST node) {
	// TODO
	assert(node!=NULL);
	if (node->right != NULL ) {
		return bst_findMin(node);
	}
	// 后继必须存在parent指针才能查找
	TreeNode* t = node->parent;
	while (t != NULL && node == t->right) {
		node = t;
		t = t->parent;
	}
	return t ;
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

// 前序遍历，递归版
void bst_preOrder(BST tree) {
	if (tree != NULL ) {
		show(tree);
		bst_preOrder(tree->left);
		bst_preOrder(tree->right);
	}
}

// 中序遍历，递归版
void bst_inOrder(BST tree) {
	if (tree != NULL ) {
		bst_inOrder(tree->left);
		show(tree);
		bst_inOrder(tree->right);
	}
}

// 后序遍历，递归版
void bst_postOrder(BST tree) {
	if (tree != NULL ) {
		bst_postOrder(tree->left);
		bst_postOrder(tree->right);
		show(tree);
	}
}

// 层次遍历，递归版
void bst_levelOrder(BST tree) {
	// 没有递归实现
	bst_postOrderIter(tree);
}

// 前序遍历，非递归版
void bst_preOrderIter(BST tree) {
	Stack s = stack_create(STATCK_MAX);
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

// 中序遍历，非递归版
void bst_inOrderIter(BST tree) {
	Stack s = stack_create(STATCK_MAX);
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

// 后序遍历，非递归版
void bst_postOrderIter(BST tree) {
	Stack s = stack_create(STATCK_MAX);
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

// 层次遍历，非递归版
void bst_levelOrderIter(BST tree) {
	assert(tree!=NULL);
	Queue queue = queue_create(STATCK_MAX);
	queue_enqueue(tree, queue);
	while (!queue_isEmpty(queue)) {
		BST p = queue_dequeue(queue);
		show(p);
		if (p->left != NULL ) {
			queue_enqueue(p->left, queue);
		}
		if (p->right != NULL ) {
			queue_enqueue(p->right, queue);
		}
	}
	queue_destroy(queue);
}

// 创建节点，辅助方法
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

// 显示节点值，辅助方法
static void show(BST tree) {
	if (tree != NULL ) {
		printf("%3d ", tree->value);
	}
}

// 发生错误，结束程序
static void fatal(char *message) {
	printf("%s\n", message);
	exit(1);
}

// 测试
int main(int argc, char **argv) {
	// 强制刷新缓冲区
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
	printf("\nLevelOrder:   ");
	bst_levelOrderIter(tree);
	return 0;
}

/**********************************************************************************************
 // 参考资料
 * http://blog.csdn.net/wangzirui0001/article/details/6854183
 * http://www.cnblogs.com/tanky_woo/archive/2011/05/03/2035160.html

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
