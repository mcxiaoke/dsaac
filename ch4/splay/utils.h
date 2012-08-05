/*
 * utils.h
 *
 *  Created on: 2012-8-4
 *      Author: mcxiaoke
 */

#ifndef UTILS_H_
#define UTILS_H_

// 发生错误，结束程序
void fatal(char *message);

// 取两者中大者
int max(int m, int n);

// 显示调试信息
void loginfo(const char* fmt, ...);

#endif /* UTILS_H_ */
