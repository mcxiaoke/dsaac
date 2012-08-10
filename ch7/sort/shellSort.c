/*
 * shellSort.c
 *
 *  Created on: 2012-8-10
 *      Author: mcxiaoke
 */

#include "shellSort.h"
#include "utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

/******************************************************************************
 *  希尔排序Shell Sort

原作者建议的步长是N/2
Hibbard增量为1，3，7，...，2^k-1
其它较好的增量序列参看DSAAC 170页

 http://zh.wikipedia.org/wiki/希尔排序
 http://www.cnblogs.com/Clingingboy/archive/2010/07/02/1770057.html
 http://www.cnblogs.com/Clingingboy/archive/2011/09/12/2174140.html

 */

// 希尔排序
void shellSort(int *data, int n) {
	unsigned long count = 0;
	clock_t start = clock();
	int i, j;
	int step;
	int temp;
	for (step = n / 2; step > 0; step /= 2) {
		for (i = step; i < n; i++) {
			temp = data[i];
			for (j = i; j >= step && data[j - step] > temp; j -= step) {
				count++;
				data[j] = data[j - step];
			}
			data[j] = temp;
		}
//		printf("shellSort step=%d\n", step);
//		printArray(data, n);
	}
	timeinfo("shellSort", n, count, clock() - start);
}

void shellSort2(int *data, int n) {

}

static void timer(){
	int i;
//	i=10;
	for (i = 1000; i < 100001; i *= 2) {
		int size = sizeof(int) * i;
		int *tmp = malloc(size);
		int *data = malloc(size);
		random(tmp, i);

		memcpy(data, tmp, size);
		shellSort(data, i);

		free(data);
		free(tmp);
		printf("\n");
	}
}

int main(int argc, char **argv) {
	setvbuf(stdout, 0, _IONBF, 0);
	timer();
	return 0;
}
