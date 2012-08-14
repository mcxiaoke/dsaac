/*
 * mergeSort.c
 *
 *  Created on: 2012-8-10
 *      Author: mcxiaoke
 */

#include "mergeSort.h"
#include "utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

/***********************************************************************
 *
归并操作(merge)
也叫归并算法，指的是将两个已经排序的序列合并成一个序列的操作
归并排序算法依赖归并操作。

归并操作的过程如下：
1. 申请空间，使其大小为两个已经排序序列之和，该空间用来存放合并后的序列
2. 设定两个指针，最初位置分别为两个已经排序序列的起始位置
3. 比较两个指针所指向的元素，选择相对小的元素放入到合并空间，并移动指针到下一位置
4. 重复步骤3直到某一指针达到序列尾
5. 将另一序列剩下的所有元素直接复制到合并序列尾


http://zh.wikipedia.org/zh/归并排序
http://www.cnblogs.com/FlyingBread/archive/2007/02/02/636990.html
http://blog.csdn.net/morewindows/article/details/6678165

 *
 */

static void msort(int *data, int *tmp, int left, int right);
static void merge(int *data, int *tmp, int leftIndex, int rightIndex,
		int rightEnd);

void mergeSort(int *data, int n) {
	unsigned long count = 0;
	clock_t start = clock();
	int *tmp = malloc(n * sizeof(int));
	if (tmp == NULL ) {
		fatal("array malloc failed.");
	}
	msort(data, tmp, 0, n - 1);
	free(tmp);
	timeinfo("mergeSort", n, count, clock() - start);
}

static void msort(int *data, int *tmp, int left, int right) {
	int center;
	if (left < right) {
		center = (left + right) / 2;
		msort(data, tmp, left, center);
		msort(data, tmp, center + 1, right);
		merge(data, tmp, left, center + 1, right);
	}
}

static void merge(int *data, int *tmp, int leftIndex, int rightIndex,
		int rightEnd) {
	// DSAAC p175-176
	int leftEnd;
	int length;
	int tmpIndex;
	leftEnd = rightIndex - 1;
	tmpIndex = leftIndex;
	length = rightEnd - leftIndex + 1;
	while (leftIndex <= leftEnd && rightIndex <= rightEnd) {
		if (data[leftIndex] <= data[rightIndex]) {
			tmp[tmpIndex++] = data[leftIndex++];
		} else {
			tmp[tmpIndex++] = data[rightIndex++];
		}
	}
	while (leftIndex <= leftEnd) {
		tmp[tmpIndex++] = data[leftIndex++];
	}

	while (rightIndex <= rightEnd) {
		tmp[tmpIndex++] = data[rightIndex++];
	}

	for (int i = 0; i < length; i++, rightEnd--) {
		data[rightEnd] = tmp[rightEnd];
	}

}

static void timer() {
	int i;
	for (i = 1000000; i < 1000000001; i *= 2) {
		int size = sizeof(int) * i;
		int *data = malloc(size);
		random3(data, i,0,i);
		mergeSort(data, i);
		free(data);
//		printf("\n");
	}
}

static void test() {
	int n = 10;
	int data[n];
	random(data, n);
	printArray(data, n);
	mergeSort(data, n);
	printArray(data, n);
}

int main(int argc, char **argv) {
	setvbuf(stdout, 0, _IONBF, 0);
	timer();
//	test();
	return 0;
}
