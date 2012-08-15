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

 快速排序的优化方法包括：
 1、将递归算法修改为非递归算法；
 2、需要排序的元素个数如果少于8个，则使用插入排序代替快速排序；
 3、使用仿函数（函数对象），而不是函数指针：
 模版库会将比较函数展开，从而避免函数调用带来的开销；
 4、使用多线程：快速排序是分而治之的思想，每个独立的段可以并行进行排序。
 因此可以利用计算机的并行处理能力来提高排序的性能；
 *
 * 枢纽元的挑选会影响到算法的性能
 * 方法一：将序列的第一个元素作为枢纽元
 * 方法二：随机挑选一个数作为枢纽元
 * 方法三：三数中值法
 *
 * 快速排序优化详细分析
 * http://blog.csdn.net/zuiaituantuan/article/details/5978009
 * http://www.wutianqi.com/?p=2368
 * http://blog.csdn.net/yangalbert/article/details/7539046
 * http://www.cppblog.com/liyuxia713/archive/2012/06/28/80749.html
 *
 * 四种快速排序和优化
 * http://mindlee.net/2011/07/28/four-quick-sort/
 * http://mindlee.net/2011/07/29/quick-sort-optimization/
 *
 * 非递归实现
 * http://blog.csdn.net/yangalbert/article/details/7538951
 * http://www.codeproject.com/Articles/29467/Quick-Sort-Without-Recursion
 *
 * 单链表快速排序
 * http://blog.csdn.net/hackbuteer1/article/details/6666475
 *
 * MPI并行版
 * http://www.cnblogs.com/jiahaipeng/archive/2010/04/06/1705050.html
 *
 * pthread版
 * http://fhtr.blogspot.com/2009/01/multi-threaded-qsort-in-c.html
 *
 */

static int median3(int *data, int left, int right);

static int partition1(int *data, int left, int right);
static int partition2(int *data, int left, int right);
static int partition3(int data[], int left, int right);
static int partition4(int data[], int left, int right);
static int partition5(int data[], int left, int right);

static void qsort1(int data[], int left, int right);
static void qsort2(int data[], int left, int right);
static void qsort3(int data[], int left, int right);
static void qsort4(int data[], int left, int right);
static void qsort5(int data[], int left, int right);

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
//		int pos = rand() % (right - left + 1) + left;
//		swap2(data, left, pos);
		int i = partition2(data, left, right);
		qsort2(data, left, i - 1);
		qsort2(data, i + 1, right);
	}
}

// 改进版快速排序，三数中值分割选取枢纽元
// 此方法来自DSAAC
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
	if (left < right) {
		int i = partition4(data, left, right);
		qsort4(data, left, i - 1);
		qsort4(data, i + 1, right);
	}
}

static void qsort5(int data[], int left, int right) {
	if (left < right) {
//		int pos = rand() % (right - left + 1) + left;
//		swap2(data, left, pos);
		int i = partition5(data, left, right);
		qsort5(data, left, i - 1);
		qsort5(data, i + 1, right);
	}
}

// 优化尾递归
static void qsort6(int data[], int left, int right) {
	while (left < right) {
		int i = partition5(data, left, right);
		qsort5(data, left, i - 1);
//		qsort5(data, i + 1, right);
		left = i + 1;
	}
}

// 非递归版本
static void qsort7(int data[], int left, int right) {
	typedef struct {
		int beg;
		int end;
	} sbe;

	int n = right - left + 1;
	sbe arr[n];

	int m;
	int p;
	int beg, end, i, j;

	m = 0;
	arr[0].beg = 0;
	arr[0].end = n - 1;

	for (;;) {
		if (m < 0)
			break;
		beg = arr[m].beg;
		end = arr[m--].end;

		if (beg >= end)
			continue;

		// partition
		p = data[beg];
		i = beg;
		j = end + 1;
		for (;;) {
			while (++i <= end && data[i] < p)
				;  // ! while( A[++i] < p ); error
			while (data[--j] > p)
				;
			if (i > j)
				break;
			swap(&data[i], &data[j]);
		}
		swap(&data[j], &data[beg]);

		arr[++m].beg = beg;
		arr[m].end = j - 1;
		arr[++m].beg = j + 1;
		arr[m].end = end;
	}
}

void quicksort1(int *data, int n) {
	qsort1(data, 0, n - 1);
}

void quicksort2(int *data, int n) {
	qsort2(data, 0, n - 1);
}

void quicksort3(int *data, int n) {
	qsort3(data, 0, n - 1);
}

void quicksort4(int *data, int n) {
	qsort4(data, 0, n - 1);
}

void quicksort5(int *data, int n) {
	qsort5(data, 0, n - 1);
//	if (n < 2)
//		return;
//	int pivot = data[n / 2];
//	int *left = data;
//	int *right = data + n - 1;
//	while (left <= right) {
//		while (*left < pivot)
//			left++;
//		while (*right > pivot)
//			right--;
//		if (left <= right) {
//			swap(left, right);
//			left++;
//			right--;
//		}
//	}
//	quicksort5(data, right - data + 1);
//	quicksort5(left, data + n - left);
}

void quicksort6(int *data, int n) {
	qsort6(data, 0, n - 1);
}

void quicksort7(int *data, int n) {
	qsort7(data, 0, n - 1);
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

// 单向扫描分割法
// 中文维基百科页面的方法
static int partition2(int data[], int left, int right) {
	int pivot = data[left];
	int i = left;
	int k = left + 1;
	for (; k <= right; ++k) {
		if (data[k] <= pivot) {
			swap(&data[++i], &data[k]);
		}
	}
	swap(&data[left], &data[i]);
	return i;
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

// 此方法来自DSAAC
static int partition3(int *data, int left, int right) {
	// 最后一个不需要移动
	// 因为pivotMedian返回时，最右边的数大于pivot
	// pivot位于 right-1的位置，因此j初始化为right-1
	int pivot = median3(data, left, right);
	int i = left;
	int j = right - 1;
	while (i < j) {
		while (data[++i] < pivot)
			;
		while (data[--j] > pivot)
			;
		if (i < j) {
			swap2(data, i, j);
		}
	}
	swap2(data, i, right - 1);
	return i;
}

// 此方法有问题，测试失败
static int partition4(int data[], int left, int right) {
	int pivot = data[left];
	int i = left;
	int j = right + 1;
	while (1) {
		while (data[++i] < pivot) {
		}
		while (data[--j] > pivot) {
		}
		if (i >= j) {
			break;
		}
		swap(&data[i], &data[j]);
	}
	data[left] = data[j];
	data[j] = pivot;
	return j;
}

static int partition5(int data[], int left, int right) {
	int pivot = data[left];
	int i = left;
	int j = right;
	while (i < j) {
		while (i < j && data[j] >= pivot)
			--j;
		data[i] = data[j];
		while (i < j && data[i] <= pivot)
			++i;
		data[j] = data[i];
	}
	data[i] = pivot;
	return i;
}

static void timer() {
	int i;
	for (i = 1000000; i < 100000001; i *= 2) {
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
		unsigned long count = 0;
		clock_t start = clock();
		quicksort1(data, i);
		timeinfo("quicksort1", i, count, clock() - start);

		memcpy(data, tmp, size);
		start = clock();
		quicksort2(data, i);
		timeinfo("quicksort2", i, count, clock() - start);

		memcpy(data, tmp, size);
		start = clock();
		quicksort3(data, i);
		timeinfo("quicksort3", i, count, clock() - start);

		memcpy(data, tmp, size);
		start = clock();
		quicksort4(data, i);
		timeinfo("quicksort4", i, count, clock() - start);

		memcpy(data, tmp, size);
		start = clock();
		quicksort5(data, i);
		timeinfo("quicksort5", i, count, clock() - start);

		memcpy(data, tmp, size);
		start = clock();
		quicksort6(data, i);
		timeinfo("quicksort6", i, count, clock() - start);

		memcpy(data, tmp, size);
		start = clock();
		quicksort7(data, i);
		timeinfo("quicksort7", i, count, clock() - start);

		free(data);
		free(tmp);
		printf("\n");
	}
}

static void assertTest() {
	typedef void (*sort)(int *, int n);
	sort sorts[] = { quicksort1, quicksort2, quicksort3, quicksort4, quicksort5,
			quicksort6, quicksort7 };
	int num = 7;
	int n = 1000;
	int data[n];
	printf("QuickSort Test Beginl!\n");
	for (int k = 0; k < 1000; k++) {
		random(data, n);
		int tmp[n];
		for (int i = 0; i < num; i++) {
			memcpy(tmp, data, n * sizeof(int));
			sorts[i](tmp, n);
			for (int i = 0; i < n; i++) {
//				printf("[assert] Index: %d Value: %d\n", i, tmp[i]);
				assert(tmp[i]==i);
			}
		}
		printf(".");
	}
	printf("\nQuickSort Test All Successful!\n");
}

static void test() {
	typedef void (*sort)(int *, int n);
	sort sorts[] = { quicksort1, quicksort2, quicksort3, quicksort4, quicksort5,
			quicksort6, quicksort7 };
	int num = 7;
	int i;
	int n = 10;
	int data[n];
//	random(data, n);
	random3(data, n, 0, n - 1);
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
