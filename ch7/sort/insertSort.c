/*
 * insertSort.c
 *
 *  Created on: 2012-8-10
 *      Author: mcxiaoke
 */

#include "insertSort.h"
#include "utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

/**************************************************************************************
 *  插入排序
 一般来说，插入排序都采用in-place在数组上实现。具体算法描述如下：
 1. 从第一个元素开始，该元素可以认为已经被排序
 2. 取出下一个元素，在已经排序的元素序列中从后向前扫描
 3. 如果该元素（已排序）大于新元素，将该元素移到下一位置
 4. 重复步骤3，直到找到已排序的元素小于或者等于新元素的位置
 5. 将新元素插入到该位置后
 6. 重复步骤2~5

 如果目标是把n个元素的序列升序排列，那么采用插入排序存在最好情况和最坏情况
 最好情况就是，序列已经是升序排列了，在这种情况下，需要进行的比较操作需(n-1)次即可
 最坏情况就是，序列是降序排列，那么此时需要进行的比较共有n(n-1)/2次
 插入排序的赋值操作是比较操作的次数减去(n-1)次。平均来说插入排序算法复杂度为O(n2)
 因而，插入排序不适合对于数据量比较大的排序应用。
 但是，如果需要排序的数据量很小，例如，量级小于千，那么插入排序还是一个不错的选择
 插入排序在工业级库中也有着广泛的应用，在STL的sort算法和stdlib的qsort算法中，
 都将插入排序作为快速排序的补充，用于少量元素的排序（通常为8个或以下）


 http://zh.wikipedia.org/zh/插入排序
 http://www.nocow.cn/index.php/排序算法
 http://www.cnblogs.com/Clingingboy/archive/2011/09/12/2174140.html

 */

// 直接插入排序
void insertSort(int *data, int n) {
	unsigned long count = 0;
	clock_t start = clock();
	int i, j;
	int temp;
	for (i = 1; i < n; i++) {
		temp = data[i];
		//与前面已排序的数逐一比较，大于temp时，该数移后
		// 短路求值，如果j=0循环结束，不会计算data[j-1]
		for (j = i; j > 0 && data[j - 1] > temp; j--) {
			data[j] = data[j - 1];
			count++;
		}
		data[j] = temp;
//		printArray(data, n);
	}
	timeinfo("insertSort", n, count, clock() - start);
}

// 折半插入排序
// http://www.cnblogs.com/Clingingboy/archive/2011/09/12/2174140.html
void insertSort2(int *data, int n) {
	for (int i = 1; i < n; i++) {
		int temp = data[i];
		int low = 0;
		int high = i;
		while (low < high) {
			int middle = (low + high) / 2;
			if (data[middle] < temp) {
				low = middle + 1;
			} else {
				high = middle - 1;
			}
		}
		for (int j = i - 1; j > high; j--) {
			data[j + 1] = data[j];
		}
		data[high + 1] = temp;
	}
}

// 二路插入排序
void insertSort3(int *data, int n) {
}

static void timer() {
	int i;
	for (i = 1000; i < 100001; i *= 2) {
		int size = sizeof(int) * i;
		int *tmp = malloc(size);
		int *data = malloc(size);
		random(tmp, i);

		memcpy(data, tmp, size);
		insertSort(data, i);

		free(data);
		free(tmp);
//		printf("\n");
	}
}

int main(int argc, char **argv) {
	setvbuf(stdout, 0, _IONBF, 0);
	timer();
	return 0;
}
