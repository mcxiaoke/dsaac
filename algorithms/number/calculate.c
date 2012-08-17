/*
 * calculate.c
 *
 *  Created on: 2012-8-17
 *      Author: mcxiaoke
 */

#include <stdio.h>
#include <stdlib.h>

// 不用控制语句求和
// http://blog.csdn.net/jiangyi711/article/details/5830916
int sum(int n)
{
    int i = 1;
    (n > 1) && (i = sum(n - 1) + n);
    return i;
}
