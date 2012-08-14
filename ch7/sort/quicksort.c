/*
 * quicksort.c
 *
 *  Created on: 2012-8-13
 *      Author: mcxiaoke
 */

#include "quicksort.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <assert.h>

/********************************************************************************
 *
 * 快速排序的平均情况下是O(nlogn)，
 * 但是一般都比其他运行时间为O(nlogn)的算法都要快，
 * 因为它隐藏的常数因子比较小，
 * 但是在最坏情况之下，快速排序的运行时间是O(n2)
 *
 * 快速排序是找出一个元素（理论上可以随便找一个）作为基准(pivot),
 * 然后对数组进行分区操作,
 * 使基准左边元素的值都不大于基准值,基准右边的元素值都不小于基准值，
 * 如此作为基准的元素调整到排序后的正确位置
 * 递归快速排序，将其他n-1个元素也调整到排序后的正确位置
 * 最后每个元素都是在排序后的正确位置，排序完成
 * 所以快速排序算法的核心算法是分区操作
 * 即如何调整基准的位置以及调整返回基准的最终位置以便分治递归
 *
 * 快速排序是一个就地排序，分而治之，大规模递归的算法
 * 从本质上来说，它是归并排序的就地版本
 *
 *该方法的基本思想是：
 1．先从数列中取出一个数作为基准数。
 2．分区过程，将比这个数大的数全放到它的右边，小于或等于它的数全放到它的左边
 3．再对左右区间重复第二步，直到各区间只有一个数
 *
 * 枢纽元的挑选会影响到算法的性能
 * 方法一：将序列的第一个元素作为枢纽元
 * 方法二：随机挑选一个数作为枢纽元
 * 方法三：三数中值法
 *
 *
 *详细分析
 *http://blog.csdn.net/zuiaituantuan/article/details/5978009
 * http://blog.csdn.net/yangalbert/article/details/7539046
 * http://www.cppblog.com/liyuxia713/archive/2012/06/28/80749.html
 *
 * 四种快速排序
 * http://mindlee.net/2011/07/28/four-quick-sort/
 *
 * 非递归实现
 * http://blog.csdn.net/yangalbert/article/details/7538951
 *
 * 单链表快速排序
 * http://blog.csdn.net/hackbuteer1/article/details/6666475
 *
 */

static int median3(int *data, int left, int right);

static int partition1(int *data, int left, int right);
static int partition3(int *data, int left, int right);

static void qsort1(int data[], int left, int right);
static void qsort2(int data[], int left, int right);
static void qsort3(int data[], int left, int right);
static void qsort4(int data[], int left, int right);
;
static void qsort5(int data[], int left, int right);

static void insertSort(int *data, int n) {
	int i, j;
	int temp;
	for (i = 1; i < n; i++) {
		temp = data[i];
		for (j = i; j > 0 && data[j - 1] > temp; j--) {
			data[j] = data[j - 1];
		}
		data[j] = temp;
	}
}

static void shellSort(int *data, int n) {
	int i, j;
	int step;
	int temp;
	for (step = n / 2; step > 0; step /= 2) {
		for (i = step; i < n; i++) {
			temp = data[i];
			for (j = i; j >= step && data[j - step] > temp; j -= step) {
				data[j] = data[j - step];
			}
			data[j] = temp;
		}
	}
}

// 原始快速排序，pivot取最左边的值
static void qsort1(int *data, int left, int right) {
	if (left < right) {
		int i = partition1(data, left, right);
		qsort1(data, left, i - 1);
		qsort1(data, i + 1, right);
	}
}

// 改进版快速排序，随机选取枢纽元
static void qsort2(int data[], int left, int right) {
	if (left < right) {
		int pos = rand() % (right - left + 1) + left;
		swap2(data, left, pos);
		int i = partition1(data, left, right);
		qsort2(data, left, i - 1);
		qsort2(data, i + 1, right);
	}
}

// 改进版快速排序，三数中值分割选取枢纽元
static void qsort3(int data[], int left, int right) {
	if (left < right) {
		int i = partition3(data, left, right);
		qsort3(data, left, i - 1);
		qsort3(data, i + 1, right);
	}
}

// 改进版快速排序，三数中值分割选取枢纽元
// 小数组采用插入排序
static void qsort4(int data[], int left, int right) {
	if (left + 20 <= right) {
		int i = partition3(data, left, right);
		qsort3(data, left, i - 1);
		qsort3(data, i + 1, right);
	} else {
		insertSort(data + left, right - left + 1);
	}
}

static void qsort5(int data[], int left, int right) {
	if (left + 20 <= right) {
		int i = partition3(data, left, right);
		qsort3(data, left, i - 1);
		qsort3(data, i + 1, right);
	} else {
		shellSort(data + left, right - left + 1);
	}
}

void quicksort1(int *data, int n) {
	unsigned long count = 0;
	clock_t start = clock();
	qsort1(data, 0, n - 1);
	timeinfo("quicksort1", n, count, clock() - start);
}

void quicksort2(int *data, int n) {
	unsigned long count = 0;
	clock_t start = clock();
	qsort2(data, 0, n - 1);
	timeinfo("quicksort2", n, count, clock() - start);
}

void quicksort3(int *data, int n) {
	unsigned long count = 0;
	clock_t start = clock();
	qsort3(data, 0, n - 1);
	timeinfo("quicksort3", n, count, clock() - start);
}

void quicksort4(int *data, int n) {
	unsigned long count = 0;
	clock_t start = clock();
	qsort4(data, 0, n - 1);
	timeinfo("quicksort4", n, count, clock() - start);
}

void quicksort5(int *data, int n) {
	unsigned long count = 0;
	clock_t start = clock();
	qsort5(data, 0, n - 1);
	timeinfo("quicksort5", n, count, clock() - start);
}

static void timer() {
	int i;
	for (i = 10000000; i < 1000000001; i *= 2) {
		int size = sizeof(int) * i;
		int *tmp = malloc(size);
		if (tmp == NULL ) {
			fatal("tmp malloc failed.");
		}
		int *data = malloc(size);
		if (data == NULL ) {
			fatal("data malloc failed.");
		}
		random(tmp, i);

		memcpy(data, tmp, size);
		quicksort1(data, i);

		memcpy(data, tmp, size);
		quicksort2(data, i);

		memcpy(data, tmp, size);
		quicksort3(data, i);

		memcpy(data, tmp, size);
		quicksort4(data, i);

		memcpy(data, tmp, size);
		quicksort5(data, i);

		free(data);
		free(tmp);
		printf("\n");
	}
}

static void assertTest() {
	typedef void (*sort)(int *, int n);
	sort sorts[] =
			{ quicksort1, quicksort2, quicksort3, quicksort4, quicksort5 };
	int num = 3;
	int n = 10000;
	int data[n];
	printf("QuickSort Test Beginl!\n");
	for (int k = 0; k < 1000; k++) {
		random(data, n);
		int tmp[n];
		for (int i = 0; i < num; i++) {
			memcpy(tmp, data, n * sizeof(int));
			sorts[i](tmp, n);
			for (int i = 0; i < n; i++) {
				assert(tmp[i]==i);
			}
//			memset(tmp, 0, n * sizeof(int));
		}
		printf(".");
	}
	printf("\nQuickSort Test All Successful!\n");
}

static void test() {
	typedef void (*sort)(int *, int n);
	sort sorts[] =
			{ quicksort1, quicksort2, quicksort3, quicksort4, quicksort5 };
	int num = 3;
	int i;
	int n = 10;
	int data[n];
	random(data, n);
	printf("Input Data: ");
	printArray(data, n);
	int tmp[n];
	for (i = 0; i < num; i++) {
		memcpy(tmp, data, n * sizeof(int));
		sorts[i](tmp, n);
		printf("QuickSort%d: ", i + 1);
		printArray(tmp, n);
		memset(tmp, 0, n * sizeof(int));
	}
	printf("--------------------\n");
}

int main(int argc, char **argv) {
	setvbuf(stdout, 0, _IONBF, 0);
//	for(int i=0; i< argc; i++){
//		printf("[%d]: %s\n",i, argv[i]);
//	}
	if (argc < 2) {
		test();
	} else if (strcmp(argv[1], "time") == 0) {
		timer();
	} else if (strcmp(argv[1], "test") == 0) {
		assertTest();
	}
	return 0;
}

static int median3(int *data, int left, int right) {
	int center = (left + right) / 2;
	if (data[left] > data[center]) {
		swap2(data, left, center);
	}
	if (data[left] > data[right]) {
		swap2(data, left, right);
	}
	if (data[center] > data[right]) {
		swap2(data, center, right);
	}
	// 三次比较后，data[left]<=data[center]<=data[right]
	swap2(data, center, right - 1);
	return data[right - 1];
}

static int partition3(int *data, int left, int right) {
	// 最后一个不需要移动
	// 因为pivotMedian返回时，最右边的数大于pivot
	// pivot位于 right-1的位置，因此j初始化为right-1
	int pivot = median3(data, left, right);
	int i = left;
	int j = right - 1;
	while (i < j) {
		while (data[++i] < pivot) {
		}
		while (data[--j] > pivot) {
		}
		if (i < j) {
			swap2(data, i, j);
		}
	}
	swap2(data, i, right - 1);
	return i;
}

static int partition1(int *data, int left, int right) {
	int i = left;
	int j = right;
	// 枢纽元，简单的取第一个元素
	int pivot = data[left];
	// 两端交替扫描
	// i从左边开始，j从右边开始

	// 从左到右找第一个小于pivot的数
	while (i < j) {
		while (i < j && data[j] > pivot) {
			j--;
		}
		if (i < j) {
			// 比枢纽元小的移到左边
			data[i++] = data[j];
		}
		// 从右到左找第一个大于pivot的数
		while (i < j && data[i] < pivot) {
			i++;
		}
		if (i < j) {
			// 比枢纽元大的移到右边
			data[j--] = data[i];
		}
	}
	// 枢纽元移到正确位置
	data[i] = pivot;
	return i;
}
