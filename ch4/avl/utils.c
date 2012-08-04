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

#undef DEBUG

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
void loginfo(const char* fmt, ...){
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
