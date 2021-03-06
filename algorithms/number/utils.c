/*
 * utils.c
 *
 *  Created on: 2012-8-4
 *      Author: mcxiaoke
 */

#include "utils.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEBUG

//整数转换成二进制串
char* itobin(int n,char * ps){
    int i;
    static int size = 8 * sizeof(int);
    for(i=size-1;i>=0;i--,n >>=1)
        ps[i]=(01 & n) + '0';
    ps[size]='\0';
    return ps;
}

//4位一组显示二进制字符串
void printbin(const char * str){
    int i=0;
    while(str[i]){
        putchar(str[i]);
        if(++i %4 ==0 && str[i])
            putchar(' ');
    }
}

void random(int data[], int size) {
	srand((unsigned) time(NULL ));
	for (int i = 0; i < size; i++) {
		data[i] = i;
	}
	for (int i = size - 1; i > 0; i--) {
		int j = rand() % (i + 1);
		swap2(data, i, j);
	}
}

void random2(int data[], int size) {
	srand((unsigned) time(NULL ));
	for (int i = 0; i < size; i++) {
		data[i] = rand() % (size + 1);
	}
}

void random3(int data[], int size, int min, int max) {
	srand((unsigned) time(NULL ));
	for (int i = 0; i < size; i++) {
		data[i] = rand() % (max - min + 1) + min;
	}
}

void timeinfo(char* tag, int length, unsigned long count, long time) {
#ifdef DEBUG
	printf("%s Num: %-10d\tCount: %-10u\tTime: %ldms\n", tag, length, count,
			time);
#endif
}

void swap(int *px, int *py) {
	int tmp = *px;
	*px = *py;
	*py = tmp;
}

void swap2(int data[], int i, int j) {
	int tmp = data[i];
	data[i] = data[j];
	data[j] = tmp;
}

void printArray(int *data, int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%2d ", data[i]);
	}
	printf("\n");
}

// 发生错误，结束程序
void fatal(char *message) {
	printf("%s\n", message);
	exit(1);
}

// 取两者中大者
int max(int m, int n) {
	return (m > n) ? m : n;
}

// 显示调试信息
void loginfo(const char* fmt, ...) {
#ifdef DEBUG
	va_list vs;
	char buf[256];
	va_start(vs, fmt);
	vsprintf(buf, fmt, vs);
	printf(buf);
//	fflush(stdout);
	va_end(vs);
#endif
}
