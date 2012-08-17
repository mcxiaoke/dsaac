/*
 * number_reverse.c
 *
 *  Created on: 2012-8-17
 *      Author: mcxiaoke
 */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/******************************************************************************
 *  按位反转整数
 */

// 按位反转字符
unsigned char reverse8(unsigned char c) {
	c = (c & 0x55) << 1 | (c & 0xAA) >> 1;
	c = (c & 0x33) << 2 | (c & 0xCC) >> 2;
	c = (c & 0x0F) << 4 | (c & 0xF0) >> 4;
	return c;
}

// 反转整数，不是按位 1234-->4321
int reverse_int(int n) {
	int rn = 0;
	while (n > 0) {
		rn = rn * 10 + n % 10;
		n /=10;
	}
	return rn;
}

// 按位反转整数
unsigned long reverse(unsigned long x) {
	x = (x & 0x55555555) << 1 | (x & 0xAAAAAAAA) >> 1;
	x = (x & 0x33333333) << 2 | (x & 0xCCCCCCCC) >> 2;
	x = (x & 0x0F0F0F0F) << 4 | (x & 0xF0F0F0F0) >> 4;
	x = (x & 0x00FF00FF) << 8 | (x & 0xFF00FF00) >> 8;
	x = (x & 0x0000FFFF) << 16 | (x & 0xFFFF0000) >> 16;
	return x;
}

/******************************************************************************
 *  求二进制1的个数
 *
 *  http://www.cnblogs.com/graphics/archive/2010/06/21/1752421.html
 */

// 整数中1的个数
int bitcount1(unsigned int n) {
	unsigned int c = 0; // 计数器
	while (n > 0) {
		if ((n & 1) == 1) // 当前位是1
			++c; // 计数器加1
		n >>= 1; // 移位
	}
	return c;
}

// 整数中1的个数
int bitcount2(unsigned int n) {
	unsigned int c = 0; // 计数器
	for (c = 0; n; n >>= 1) // 循环移位
		c += n & 1; // 如果当前位是1，则计数器加1
	return c;
}

// 整数中1的个数
int bitcount3(unsigned int n) {
	unsigned int c = 0;
	for (c = 0; n; ++c) {
		n &= (n - 1); // 清除最低位的1
	}
	return c;
}

// 整数中1的个数 查表法
int bitcount4(unsigned int n) {
	unsigned int table[256] = { 0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4,
			1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 1, 2, 2, 3, 2, 3, 3,
			4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5,
			5, 6, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3,
			4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5,
			4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 1, 2, 2,
			3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4,
			4, 5, 4, 5, 5, 6, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3,
			4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 2, 3, 3, 4, 3, 4, 4, 5,
			3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6,
			7, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6,
			6, 7, 5, 6, 6, 7, 6, 7, 7, 8, };

	return table[n & 0xff] + table[(n >> 8) & 0xff] + table[(n >> 16) & 0xff]
			+ table[(n >> 24) & 0xff];
}

// 平行算法
int bitcount5(unsigned int n) {
	n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
	n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
	n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
	n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
	n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);

	return n;
}

int bitcount6(unsigned int n) {
	unsigned int tmp = n - ((n >> 1) & 033333333333)
			- ((n >> 2) & 011111111111);
	return ((tmp + (tmp >> 3)) & 030707070707) % 63;
}

int main(int argc, char *argv[]) {
	unsigned long n = 1;
	unsigned long bn = reverse(n);
	printf("%ld %ld", n, bn);
	return 0;
}
