/*
 * bubbleSort.c
 *
 *  Created on: 2012-8-9
 *      Author: mcxiaoke
 */

#include "bubbleSort.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/***************************************************************************************

 冒泡排序（Bubble Sort）是一种简单的排序算法
 它重复地走访过要排序的数列，一次比较两个元素，如果他们的顺序错误就把他们交换过来
 冒泡排序对个项目需要O(N*2)的比较次数，且可以原地排序
 尽管这个算法是最简单了解和实作的排序算法之一，但它对于少数元素之外的数列排序是很没有效率的
 冒泡排序是与插入排序拥有相等的执行时间，但是两种法在需要的交换次数却很大地不同
 在最坏的情况，冒泡排序需要次交换，而插入排序只要最多交换
 冒泡排序的实现通常会对已经排序好的数列拙劣地执行O（N*2），而插入排序在这个例子只需要O(N)个运算
 因此很多现代的算法教科书避免使用冒泡排序，而用插入排序取代之
 冒泡排序如果能在内部循环第一次执行时，使用一个旗标来表示有无需要交换的可能，也有可能把最好的复杂度降低到

 冒泡排序算法的运作如下：
 比较相邻的元素。如果第一个比第二个大，就交换他们两个。
 对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对。在这一点，最后的元素应该会是最大的数。
 针对所有的元素重复以上的步骤，除了最后一个。
 持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较。

 局部冒泡排序
 对于N个无序数据，我们在进行一趟冒泡排序时，
 如果第k个数据和第k+1个数据逆序，
 那么对第k+1个数据进行一趟向前的冒泡排序，使其移动到合适的位置，
 也就是说让前面k+1个数据调节为正序
 因为这种冒泡法只对前k+1个数据冒泡处理，所以我们称它为局部冒泡

 冒泡排序是稳定的，简单的，低效的

 鸡尾酒排序是冒泡排序的一种变形
 http://zh.wikipedia.org/wiki/鸡尾酒排序

 http://zh.wikipedia.org/wiki/冒泡排序
 http://www.codeforge.cn/read/171983/bubble.c__html
 http://blog.csdn.net/morewindows/article/details/6657829

 */

// 原始的冒泡排序算法
void bubbleSort(int *data, int n) {
	unsigned long count = 0;
	int i, j;
	clock_t start = clock();
	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			count++;
			if (data[j] > data[j + 1]) {
				swap(&data[j], &data[j + 1]);
			}
		}
	}
	timeinfo("BubbleSort1", n, count, clock() - start);
}

// 冒泡排序改进版
// 添加交换标志，减少不必要的比较
void bubbleSort2(int *data, int n) {
	unsigned long count = 0;
	int i, j;
	int exchange = 1;
	clock_t start = clock();
	for (i = n - 1; i > 0; i--) {
		// 如果上一轮没有交换，说明排序完成，提前结束
		if (!exchange) {
			break;
		}
		exchange = 0;
		for (j = 0; j < i; j++) {
			count++;
			if (data[j] > data[j + 1]) {
				swap(&data[j], &data[j + 1]);
				exchange = 1;
			}
		}
	}
	timeinfo("BubbleSort2", n, count, clock() - start);
}

// 鸡尾酒排序，冒泡排序的变形，双向
void bubbleSort3(int *data, int n) {
	unsigned long count = 0;
	int bottom = 0;
	int top = n - 1;
	int exchange = 1;
	clock_t start = clock();
	while (exchange) {
		int i;
		exchange = 0;
		for (i = bottom; i < top; i++) {
			count++;
			if (data[i] > data[i + 1]) {
				swap(&data[i], &data[i + 1]);
				exchange = 1;
			}
		}
		top--;
		int j;
		for (j = top; j > bottom; j--) {
			count++;
			if (data[j] < data[j - 1]) {
				swap(&data[j], &data[j - 1]);
				exchange = 1;
			}
		}
		bottom++;
	}
	timeinfo("BubbleSort3", n, count, clock() - start);
}

// 局部冒泡排序
void bubbleSort4(int *data, int n) {
	unsigned long count = 0;
	int i, j;
	clock_t start = clock();
	for (i = 0; i < n - 1; i++) {
		if (data[i] > data[i + 1]) {
			j = i + 1;
			while (j > 0 && data[j] < data[j - 1]) {
				swap(&data[j], &data[j - 1]);
				count++;
				j--;
			}
		}
	}
	timeinfo("BubbleSort4", n, count, clock() - start);
}

static void timer() {
	int i = 10;
	for (i = 1000; i < 100001; i *= 2) {
		int size = sizeof(int) * i;
		int *tmp = malloc(size);
		int *data = malloc(size);
		random(tmp, i);

		memcpy(data, tmp, size);
		bubbleSort(data, i);

		memcpy(data, tmp, size);
		bubbleSort2(data, i);

		memcpy(data, tmp, size);
		bubbleSort3(data, i);

		memcpy(data, tmp, size);
		bubbleSort4(data, i);

		free(data);
		free(tmp);
		printf("\n");
	}
}

static void simpleTest() {
	for (int j = 0; j < 40; j++) {
		int i = 10000;
		int size = sizeof(int) * i;
		int *tmp = malloc(size);
		int *data = malloc(size);
		random2(tmp, i);

		memcpy(data, tmp, size);
		bubbleSort(data, i);

		memcpy(data, tmp, size);
		bubbleSort2(data, i);

		memcpy(data, tmp, size);
		bubbleSort3(data, i);

		memcpy(data, tmp, size);
		bubbleSort4(data, i);

		free(data);
		free(tmp);
		printf("\n");
	}
}

int main(int argc, char **argv) {
	setvbuf(stdout, 0, _IONBF, 0);
//	timer();
	simpleTest();
	return 0;
}
