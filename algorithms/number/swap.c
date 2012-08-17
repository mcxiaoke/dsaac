/*
 * swap.c
 *
 *  Created on: 2012-8-17
 *      Author: mcxiaoke
 */

// 交换变量
// http://blog.csdn.net/haoni123321/article/details/7395592
void swap1(int *a, int*b){
	*a=*a+*b;
	*b=*a-*b;
	*a=*a-*b;
}

void swap2(int *a, int*b){
	*a=*a^*b;
	*b=*a^*b;
	*a=*a^*b;
}

void swap3(int *a, int*b){
	*a=*a * *b;
	*b=*a/(*b);
	*a=*a/(*b);
}
