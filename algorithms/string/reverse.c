/*
 * reverse.c
 *
 *  Created on: 2012-8-17
 *      Author: mcxiaoke
 */

/*******************************************************************
 *  字符串反转
 *
 *  http://k-eckel.cnblogs.com/articles/195931.html
 *  http://www.cnblogs.com/kirinboy/archive/2010/04/23/1718538.html
 *  http://haolloyin.blog.51cto.com/1177454/560597
 *  http://blog.csdn.net/xiangshimoni/article/details/7606701
 *
 *  以单词为单位的字符串反转
 *  http://blog.csdn.net/lifesider/article/details/6526682
 *
 *  Java实现
 *  http://blog.csdn.net/xiaobluesky/article/details/6906855
 *
 */

#include "../utils.h"
#include <stdio.h>
#include <stdlib.h>

// 原始方法
char* reverse1(char* str) {
	int len = strlen(str);
	char t;
	for (int i = 0; i < len / 2; i++) {
		// 最原始方法，但是需要空间
		// char tmp = a[i];
		// a[i] = a[a.length-1-i];
		// a[a.length-1-i] = tmp;
		// 不用空间，用加减方法交换
		// a[a.length-1-i] += a[i];
		// a[i] = (char)(a[a.length-1-i] - a[i]);
		// a[a.length-1-i] -= a[i];
		// 不用空间，用异或方法交换
//         a[i] ^= a[a.length - 1 - i];
//         a[a.length - 1 - i] ^= a[i];
//         a[i] ^= a[a.length - 1 - i];
		t = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = t;
	}
	return str;
}

// 使用指针
char* reverse2(char* str) {
	if (!str) {
		return NULL ;
	}
	int len = strlen(str);
	char temp;
	for (int i = 0; i < len / 2; i++) {
		// 交换前后两个相应位置的字符
		temp = *(str + i);
		*(str + i) = *(str + len - 1 - i);
		*(str + len - 1 - i) = temp;
	}
	return str;
}

// 递归方法
char* reverse3(char* str, int len) {
	if (len <= 1)
		return str;
	char t = *str;
	*str = *(str + len - 1);
	*(str + len - 1) = t;
	return (reverse3(str + 1, len - 2) - 1);
}

// 反转，不用库函数
char* reverse4(char *str) {
	char* r = str;
	// 令p指向结束符
	char* p = str;
	while (*p != '\0')
		++p;
	// 令q指向字符串最后一个字符
	char* q = p - 1;
	// 使用p作为交换空间逐个交换字符
	while (q > str) {
		*p = *q;
		*q-- = *str;
		*str++ = *p;
	}
	*p = '\0'; // 恢复结束符
	return r;
}

// 指针简洁版
char * reverse5(char *str) {
	for (int i = 0, j = strlen(str) - 1; i < j; i++, j--) {
		str[i] ^= str[j] ^= str[i] ^= str[j];
	}
	return str;
}

void reverse_word(char *p, char *q) {
	while (p < q) {
		*p = *p ^ *q;
		*q = *p ^ *q;
		*p = *p++ ^ *q--;
	}
}

// 按单词反转字符串
char *reverse_sentence(char *s) {
	char *p = s;
	char *q = s;
	while (*q != '\0') {
		if (*q == ' ') { //查到一个单词
			reverse_word(p, q - 1);
			q++; //指向下一个单词道字符
			p = q;
		} else
			q++;
	}
	reverse_word(p, q - 1); //逆序最后一个单词
	reverse_word(s, q - 1); //整个句子逆序
	return s;
}
