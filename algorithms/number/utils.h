/*
 * utils.h
 *
 *  Created on: 2012-8-4
 *      Author: mcxiaoke
 */

#ifndef UTILS_H_
#define UTILS_H_

// 整数转换为二进制字符串
char* itobin(int n,char * ps);

// 按组打印二进制字符串
void printbin(const char * str);

// 产生一个不重复随机数组，范围为0～size
void random(int data[], int size);

// 可以重复
void random2(int data[], int size);

// 可以重复，范围内的随机数
void random3(int data[], int size, int min, int max);

// 发生错误，结束程序
void fatal(char *message);

// 取两者中大者
int max(int m, int n);

// 显示调试信息
void loginfo(const char* fmt, ...);

void timeinfo(char* tag, int length, unsigned long count, long time);

// 交换两个整数
void swap(int *px, int *py);

// 交换数组的两个位置的值
void swap2(int data[], int i, int j);

void printArray(int *data, int n);

#endif /* UTILS_H_ */
