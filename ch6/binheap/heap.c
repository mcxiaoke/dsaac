/*
 * heap.c
 *
 *  Created on: 2012-8-7
 *      Author: mcxiaoke
 */

/****************************************************************************************
 *
 * 二叉堆是完全二叉树或者是近似完全二叉树
 * 二叉堆满足二个特性：
 * 1．父结点的键值总是大于或等于（小于或等于）任何一个子节点的键值
 * 2．每个结点的左子树和右子树都是一个二叉堆（都是最大堆或最小堆）
 * 当父结点的键值总是大于或等于任何一个子节点的键值时为最大堆
 * 当父结点的键值总是小于或等于任何一个子节点的键值时为最小堆
 *
 *  二叉堆，最小堆
 *  使用完全二叉树实现
 *  完全二叉树的性质（数组实现）：
 *  对于位置i的元素，它的，
 *  左儿子在位置2i上，右儿子在位置2i+1上，父亲在i/2上
 *  参考书p135
 *
 *  堆序性质（最小堆）：任意节点小于它的所有后裔
 *
 *  http://blog.csdn.net/fairyroad/article/details/6408137
 *  http://hojor.iteye.com/blog/699121
 *  http://www.cnblogs.com/k-eckel/articles/211907.html
 *  http://dongxicheng.org/structure/heap/
 *
 *
 */
#include "heap.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

struct HeapStruct {
	int capacity;
	int size;
	int *elements;
};

//static void exchange(int i, int j, BinHeap h) {
//	int x = h->elements[i];
//	h->elements[i] = h->elements[j];
//	h->elements[j] = x;
//}
//
//static int leftChild(int i) {
//	return 2 * i;
//}
//
//static int rightChild(int i) {
//	return 2 * i + 1;
//}
//
//static int parent(int i) {
//	return i / 2;
//}

//从节点i向下
static void percolateDown(int i, BinHeap h) {
	assert(i < h->size);
	int x = h->elements[i]; // 当前节点的值
	int child; // 当前节点的孩子
	// i初始值为1， 从树根开始向下，逐层循环执行
	for (; i * 2 < h->size; i = child) {
		child = i * 2;
		// find smaller child: left child, right child+1
		if (child != h->size && h->elements[child + 1] < h->elements[child]) {
			// 寻找较小节点，如果右孩子小于左孩子，就向右，否则向左
			child++;
		}
		// 如果当前节点的孩子的值小于最末节点的值
		if (x > h->elements[child]) {
			h->elements[i] = h->elements[child];
		} else {
			break;
		}
	}
	h->elements[i] = x;
}

//从节点P上滤
static void percolateUp(int i, BinHeap h) {
	assert(i < h->size);
	int x = h->elements[i];
	int child;
	for (; h->elements[i / 2] > x; i = child) {
		child = i / 2;
		h->elements[i] = h->elements[child];
	}
	h->elements[i] = x;
}

//降低关键字的值
static void decreaseKey(int index, int value, BinHeap h) {
	h->elements[index] -= value;
	percolateUp(index, h);
}
//增加关键字的值
static void increaseKey(int index, int value, BinHeap h) {
	h->elements[index] += value;
	percolateDown(index, h);
}

BinHeap initializeBinHeap(int maxElements) {
	if (maxElements < QUEUE_MIN_SIZE) {
		fatal("size is too small.");
	}
	BinHeap q = malloc(sizeof(struct HeapStruct));
	if (q == NULL) {
		fatal("heap malloc failed.");
	}
	q->elements = malloc(sizeof(int) * (maxElements + 1));
	if (q->elements == NULL) {
		fatal("heap elements malloc failed.");
	}
	q->capacity = maxElements;
	q->size = 0;
	q->elements[0] = QUEUE_MIN_DATA;
	return q;

}

void buildBinHeap(int n, BinHeap h) {
	assert(h != NULL);
	int data[100];
	random(data, 100);
	printf("INPUT  DATA: \n");
	for (int i = 0; i < n; ++i) {
		printf("%2d ", data[i]);
	}
	printf("\n\n");

//	for (int i = 0; i < n; ++i) {
//		insertBinHeap(data[i], h);
//	}

	h->size=n;
	for(int i=0; i< n; ++i){
		h->elements[i+1]=data[i];
	}

	for(int i=n/2; i>0; i--){
		percolateDown(i, h);
	}


}

void destroyBinHeap(BinHeap q) {
	free(q->elements);
	free(q);
	q = NULL;
}

void clearBinHeap(BinHeap q) {
	q->size = 0;
}

void insertBinHeap(int x, BinHeap h) {
	if (isFullBinHeap(h)) {
		fatal("heap is full.");
	}
	h->elements[++h->size] = x;
	percolateUp(h->size - 1, h);
//	printf("insert value: %d\n", x);
//	printBinHeap(h);
}
int deleteMinBinHeap(BinHeap h) {
	if (isEmptyBinHeap(h)) {
		printf("heap is empty.");
		return h->elements[0];
	}

	int min = h->elements[1]; // 树根，最小值
	h->elements[1] = h->elements[h->size--];
	percolateDown(1, h);
	return min;

}

//删除节点
void delete(int P, BinHeap h) {
	decreaseKey(P, -10000, h);
	deleteMinBinHeap(h);
}

int findMinBinHeap(BinHeap q) {
	return q->elements[1];
}
int isEmptyBinHeap(BinHeap q) {
	return q->size == 0;
}
int isFullBinHeap(BinHeap q) {
	return q->size == q->capacity;
}

//打印二叉堆(优先队列)
void printBinHeap(BinHeap h) {
	int i;
	for (i = 1; i <= h->size; i++)
		printf("%2d ", h->elements[i]);
	putchar('\n');
}

void testBinHeap() {
	BinHeap h = initializeBinHeap(20);
	buildBinHeap(10, h);
	printf("OUTPUT DATA: \n");
	for (int i = 0; i < h->size; ++i) {
		printf("%2d ", i);
	}
	putchar('\n');
	for (int i = 0; i < h->size * 3; ++i) {
		putchar('-');
	}
	putchar('\n');
	printBinHeap(h);
	for (int i = 0; i < 6; i++) {
		deleteMinBinHeap(h);
		printBinHeap(h);
	}

//	int data[100];
//	random(data, 100);
//	for (int i = 0; i < 5; i++) {
//		insertBinHeap(-1*data[i], h);
//		printBinHeap(h);
//	}
}

void findKBinHeap(){
	int n=10000;
	int data[n];
	random(data,n);

	BinHeap h = initializeBinHeap(n);
	h->size=n;
	for(int i=0; i< n; ++i){
		h->elements[i+1]=data[i]+234;
	}
	for(int i=n/2; i>0; i--){
		percolateDown(i, h);
	}

	int k=100;
	for(int i=0; i< k; i++){
		deleteMinBinHeap(h);
		printf("No.%d is %d\n", i+1, h->elements[1]);
	}

}

