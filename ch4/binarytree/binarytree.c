/*
 * binarytree.c
 *
 *  Created on: 2012-7-10
 *      Author: mcxiaoke
 */


#include "binarytree.h"

struct TREE_NODE{
	int value;
	BinaryTree left;
	BinaryTree right;
};

BinaryTree create(int length){
	int *data;
	data=(int*)malloc(sizeof(int)*length);
	if(data==NULL){
		fatal("data array malloc failed.");
	}
	srand((unsigned)time(NULL));
	int i;
	for (int i = 0; i < length; ++i) {
		data[i]=rand()%100;
	}
	return create2(data,length);

}
BinaryTree create2(int *data, int length){
	BinaryTree root;
	BinaryTree current;
	for (int i = 0; i < length; ++i) {
		TreeNode *node=(TreeNode*)malloc(sizeof(TreeNode));
		if(node==NULL){
			fatal("TreeNode malloc failed.");
		}

	}


	return NULL;
}

void fatal(char *message){
	printf("%s\n",message);
	exit(1);
}

int main(int argc, char **argv){
	printf("hello, binary tree.\n");
	return 0;
}
