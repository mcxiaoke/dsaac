/*
 * heapSort.c
 *
 *  Created on: 2012-8-10
 *      Author: mcxiaoke
 */

#include "heapSort.h"
#include "utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

/******************************************************************************
 *
 堆排序的过程是：
 1. 建立一个堆（最大堆）H[0..n-1]
 2. 把堆首（最大值）和堆尾互换
 3. 把堆的尺寸缩小1，并调用percolateDown(0),目的是把新的数组顶端数据调整到相应位置
 4. 重复步骤2，直到堆的尺寸为1
 平均复杂度
 堆排序的平均时间复杂度为O(N*LogN)，空间复杂度为O(1)

 http://blog.csdn.net/midgard/article/details/4070074
 http://www.slyar.com/blog/slyar-heap-sort-c.html
 http://www.nowamagic.net/algorithm/algorithm_HeapSortStudy.php
 http://www.cnblogs.com/xiaosuo/archive/2010/03/08/1654258.html
 http://771816006-qq-com.iteye.com/blog/1486861

 排序算法
 http://blog.csdn.net/xiaowei_cqu/article/details/7770838
 http://www.cnblogs.com/Clingingboy/archive/2010/07/02/1770057.html

 */

static void buildMaxHeap(int *data, int size);
static void deleteMax(int *data, int size);
static void percolateDown(int *data, int index, int size);
static void timer();

// 希尔排序
void heapSort(int *data, int n) {
	unsigned long count = 0;
	clock_t start = clock();
	buildMaxHeap(data, n);
//	printArray(data, n);
//	printf("------------------------------------\n");
	int i;
	for (i = n; i > 1; i--) {
		// 删除到i=2时就可以了
		deleteMax(data, i);
		count++;
//		printf("[%d] ", n-i+1);
//		printArray(data, n);
	}
	timeinfo("heapSort", n, count, clock() - start);
}

void heapSort2(int *data, int n) {
	// from:http://www.cnblogs.com/richselian/archive/2012/01/04/2311837.html
	int top = n;
	int bottom = n;
	int child = n;
	int i = child;
	int tmp;
	for (; bottom > 0; i = child) {
		tmp = data[child];
		int lchild = i * 2 + 1;
		int rchild = i * 2 + 2;
		if (lchild < bottom && tmp < data[lchild]) {
			child = lchild;
		}
		if (rchild < bottom && tmp < data[rchild]) {
			child = rchild;
		}
		if (i < child) {
			swap2(data, i, child);
		} else {
			if (top > 0) {
				child = --top;
			} else {
				swap2(data, 0, --bottom);
				child = 0;
			}
		}
	}
}

// 建立最大堆
static void buildMaxHeap(int *data, int size) {
	int i;
	//由于所有树叶无需进行下滤（没有孩子）
	//所以只对0 - size/2的结点进行下滤即可
	for (i = size / 2 - 1; i >= 0; i--) {
		percolateDown(data, i, size);
	}

}

// 删除树根，最大值移到最后
static void deleteMax(int *data, int size) {
//	size--;
//	swap(&data[0], &data[size]);
//	percolateDown(data, 0, size);
	swap2(data, 0, size - 1); // 堆树根与最后一个data[size-1];交换
	percolateDown(data, 0, --size);
}

// 向下过滤调整
// 以0为根的话，左孩子为i*2+1，右孩子为i*2+2;
static void percolateDown(int *data, int i, int size) {
	int tmp = data[i]; // 当前节点的值
	int child = 0; // 当前节点的孩子
	for (; i * 2 + 1 < size; i = child) {
		/* i的左孩子为2*i+1,右孩子为2*i+2 */
		child = i * 2 + 1;
		// 让child指向孩子中较大的一个
		if (child != size - 1 && data[child + 1] > data[child]) {
			child++; //如果右孩子大于左孩子，就向右，否则向左
		}
		// 如果孩子节点大
		if (tmp < data[child]) {
			// 交换当前节点和它的子节点
			data[i] = data[child];
		} else {
			break;
		}
	}
	data[i] = tmp;
}

static void timer() {
	int i;
	for (i = 10000000; i < 1000000001; i *= 2) {
		int size = sizeof(int) * i;
		int *data = malloc(size);
		if (data == NULL ) {
			fatal("data malloc failed.");
		}
		random3(data, i,0,i);
		heapSort(data, i);
		free(data);
//		printf("\n");
	}
}

static void test() {
	int n = 10;
	int data[n];
	random(data, n);
	printArray(data, n);
	heapSort(data, n);
	printArray(data, n);
}

int main(int argc, char **argv) {
	setvbuf(stdout, 0, _IONBF, 0);
	timer();
//	test();
	return 0;
}
