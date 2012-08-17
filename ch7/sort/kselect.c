/*
 * kselect.c
 *
 *  Created on: 2012-8-17
 *      Author: mcxiaoke
 */

/***************************************************************************
 * 寻找第K大的数
 * 方法一：排序后选择第K个数
 * 方法二：使用堆
 * 方法三：快速排序的变种
 * 方法四：计数/位图
 *
 * 方法总结
 * http://www.cnblogs.com/zhjp11/archive/2010/02/26/1674227.html
 *
 * 求两个已排序数组的中位数
 * http://blog.csdn.net/beiyeqingteng/article/details/6992685
 *
 * 第K个数实现
 * http://blog.csdn.net/v_JULY_v/article/details/6403777
 *
 * 分析
 * http://blog.csdn.net/titer1/article/details/7674947
 *
 *
 */

#include "kselect.h"
#include "utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

//#if defined(WIN32) || defined(WIN64)
#include <windows.h>
#define sleep(n) Sleep(n)
//#else
//#include <unistd.h>
//#endif

static void buildMaxHeap(int *data, int size);
static void deleteMax(int *data, int size);
static void percolateDown(int *data, int index, int size);

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

int selectMax(int data[], int n, int k) {
	return 0;
}

int selectMin(int data[], int n, int k) {
	return 0;
}

//  第K大的元素
int kselect(int data[], int n, int k) {
	return 0;
}

int kselectHeapA(int data[], int n, int k) {
	buildMaxHeap(data, n);
	for (int i = 0; i < k - 1; ++i) {
		deleteMax(data, n - i);
	}
	return data[0];
}

int kselectHeapB(int data[], int n, int k) {
	buildMaxHeap(data, k);
	for (int i = k; i < n; ++i) {
		if (data[i] > data[0]) {
			swap(&data[i], &data[0]);
			percolateDown(data, 0, k);
		}
	}
	return data[k - 1];
}

int kselectQuick(int data[], int n, int k) {
	// p186
//	   if(l < r)
//	    {
//	        int pivot = partition(arr, l, r);
//	        if(pivot == k - 1)
//	            return arr[pivot];
//	        else if(pivot < k - 1)
//	            return quickSelect(arr, k, pivot + 1, r);
//	        else
//	            return quickSelect(arr, k, l, pivot - 1);
//	    }
	return 0;
}

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

static void test() {
	int n = 10;
	int data[n];
	for (int i = 0; i < 10; i++) {
		random(data, n);
		sleep(1000);
//		random3(data, n, 0, 100);
		printArray(data, n);
		int k = kselectHeapB(data, n, 6);
//		printArray(data, n);
		insertSort(data, n);
		printArray(data, n);
		printf("select is %d \n\n", k);

	}
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}
