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

static void random(int data[], int n) {
	srand((unsigned) time(NULL));
//	srand(9);
	for (int i = 0; i < n; i++) {
		data[i] = i;
	}
	for (int i = 0; i < n; i++) {
		int j = rand() % n;
		int tmp = data[i];
		data[i] = data[j];
		data[j] = tmp;
	}
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

void buildHeap(int n, BinHeap q) {
	assert(q != NULL);
	int data[n];
	random(data, n);
	printf("INPUT  DATA: \n");
	for (int i = 0; i < n; ++i) {
		printf("%d ", data[i]);
	}
	printf("\n\n");

	q->size = n;
	for (int i = 0; i < n; ++i) {
		q->elements[i + 1] = data[i];
	}
	for (int i = n / 2; i > 0; i--) {
		percolateDown(i, q);
	}
}

void destroyBinHeap(BinHeap q) {
	free(q->elements);
	free(q);
	q = NULL;
}

void clearBinHeap(BinHeap q) {
	q->size = 0;
	q->elements[0] = QUEUE_MIN_DATA;
}

void insertBinHeap(int x, BinHeap q) {
	if (isFullBinHeap(q)) {
		fatal("heap is full.");
	}
	int i;
	for (i = ++q->size; q->elements[i / 2] > x; i /= 2) {
		q->elements[i] = q->elements[i / 2];
	}
	q->elements[i] = x;

}
int deleteMinBinHeap(BinHeap q) {
	if (isEmptyBinHeap(q)) {
		printf("heap is empty.");
		return q->elements[0];
	}

	int minElement = q->elements[1];
	int lastElement = q->elements[q->size--];

	int i;
	int child;
	for (i = 1; i * 2 < q->size; i = child) {
		child = i * 2;
		// find smaller child: left child, right child+1
		if (child != q->size && q->elements[child + 1] < q->elements[child]) {
			child++;
		}
		if (lastElement > q->elements[child]) {
			q->elements[i] = q->elements[child];
		} else {
			break;
		}
	}
	q->elements[i] = lastElement;
	return minElement;

}

//从节点p下滤
void percolateDown(int p, BinHeap h) {
	int i = p;
	if (p > h->size) {
		printf("Out of the size !! : p=%d,size=%d\n", p, h->size);
		return;
	}
	int element = h->elements[p];
	while (i * 2 <= h->size) {
		int minChild =
				(2 * i != h->size)
						&& (h->elements[2 * i] > h->elements[2 * i + 1]) ?
						2 * i + 1 : 2 * i;
		if (element > h->elements[minChild]) {
			h->elements[i] = h->elements[minChild];
			i = minChild;
		} else
			break;
	}
	h->elements[i] = element;
}
//从节点P上滤
void percolateUp(int p, BinHeap h) {
	int i;
	if (p > h->size) {
		printf("Out of the size !!\n");
		return;
	}
	int element = h->elements[p];
	for (i = p; h->elements[i / 2] > element; i = i / 2)
		h->elements[i] = h->elements[i / 2];
	h->elements[i] = element;
}

//降低关键字的值
void decreaseKey(int P, int value, BinHeap h) {
	h->elements[P] -= value;
	percolateUp(P, h);
}
//增加关键字的值
void increaseKey(int P, int value, BinHeap h) {
	h->elements[P] += value;
	percolateDown(P, h);
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
		printf("%d ", h->elements[i]);
	putchar('\n');
}

void test() {
	BinHeap q = initializeBinHeap(20);
	buildHeap(10, q);
	printf("OUTPUT DATA: \n");
	for (int i = 0; i < 11; i++) {
		deleteMinBinHeap(q);
		printBinHeap(q);
	}
//
//	int data[20];
//	random(data, 20);
//	for (int i = 0; i < 20; i++) {
//		insertBinHeap(data[i], q);
//		printBinHeap(q);
//	}

}

