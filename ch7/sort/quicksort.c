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

static int median(int data[], int left, int right) {
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
	swap2(data, center, right - 1);
	return data[right - 1];

}

static void qsort1(int data[], int left, int right) {
	int i, j;
	int pivot;
	if (left < right) {
		pivot = median(data, left, right);
		i = left;
		j = right - 1;
		for (;;) {
			while (data[++i] < pivot) {
			}
//			do {
//				++i;
//			} while (i < pivot);
			while (data[--j] > pivot) {
			}
//			do {
//				--j;
//			} while (j > pivot);
			if (i < j) {
				swap2(data, i, j);
			} else {
				break;
			}
		}
		swap2(data, i, right - 1);
		qsort1(data, left, i - 1);
		qsort1(data, i + 1, right);

	}

}

static void qsort2(int data[], int left, int right){
	if(left<right){
		int pivot=data[left];
		int i=left;
		int j=right;
		while(i<j){
			while(data[i]<pivot && i<j){
				++i;
			}
			if(i<j){
				data[i++]=data[j];
			}
			while(data[j]>pivot && i<j){
				--j;
			}
			if(i<j){
				data[j--]=data[i];
			}
		}
		data[i]=pivot;
		qsort2(data, left, i-1);
		qsort2(data, i+1, right);
	}
}

void quicksort(int *data, int n) {
	unsigned long count = 0;
	clock_t start = clock();
	qsort2(data, 0, n - 1);
	timeinfo("heapSort", n, count, clock() - start);
}

static void timer() {
	int i;
	for (i = 1000000; i < 100000001; i *= 2) {
		int size = sizeof(int) * i;
		int *data = malloc(size);
		random3(data, i,0,i);
		quicksort(data, i);
		free(data);
//		printf("\n");
	}
}

static void test() {
	int n = 10;
	int data[n];
	random(data, n);
	printArray(data, n);
	quicksort(data, n);
	printArray(data, n);
}

int main(int argc, char **argv) {
	setvbuf(stdout, 0, _IONBF, 0);
	test();
	timer();
	return 0;
}
