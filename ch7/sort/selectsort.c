/*
 * selectsort.c
 *
 *  Created on: 2012-8-14
 *      Author: mcxiaoke
 */

#include "selectsort.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <assert.h>

// 选择排序
// http://www.cnblogs.com/Clingingboy/archive/2010/07/02/1770057.html

void selectSort(int *data, int n) {
	int i, j, max;
	//outer loop
	for (i = n - 1; i > 0; i--) {
		max = i;
		for (j = 0; j < i; j++) {
			//compare inner with min value
			if (data[j] > data[max]) {
				//mark max
				max = j;
			}
		}
		//swap
		int temp = data[i];
		data[i] = data[max];
		data[max] = temp;
	}
}

int main(int argc, char **argv) {
	return 0;
}
