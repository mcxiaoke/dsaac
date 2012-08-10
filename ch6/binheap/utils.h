/*
 * utils.h
 *
 *  Created on: 2012-8-4
 *      Author: mcxiaoke
 */

#ifndef UTILS_H_
#define UTILS_H_

// 产生一个随机数组，范围为0～size
void random(int data[], int size);

// 产生一个随机数组，范围为offset~offset+size
void random2(int data[], int size, int offset);

// 发生错误，结束程序
void fatal(char *message);

// 取两者中大者
int max(int m, int n);

// 显示调试信息
void loginfo(const char* fmt, ...);

// 交换两个整数
void swap(int *px, int *py);

// 交换数组的两个位置的值
void swap2(int data[], int i, int j);

#endif /* UTILS_H_ */
