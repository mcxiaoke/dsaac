/*
 * string.c
 *
 *  Created on: 2012-8-17
 *      Author: mcxiaoke
 */

/**************************************************************************
 *  字符串操作函数
 * http://blog.chinaunix.net/uid-26565142-id-3086346.html
 *
 */

#include <stdio.h>
#include <stdlib.h>

// 去掉首尾空格
void trim(char* str) {
	if (str == NULL )
		return;
	int flag = 0; //true表示还没有遇到空格
	int newp = 0;	 //标记新的字符串结尾处
	for (int i = 0; str[i]; i++)	 //并没有处理'/0'字符
			{
		if (str[i] != ' ') {
			str[newp++] = str[i];
			flag = 1;
		} else if (flag) {
			//之前没有遇到空格且现在遇到的字符为空格，
			//将第一个空格存放到结果字符串中
			str[newp++] = str[i];
			flag = 0;
		} else
			//之前遇到的是空格，现在也是空格，不处理。
			//这也直接将字符串前面的空格字符去掉了。
			continue;
	}
	//剔除字符结尾的空格，并加上结束符
	if (newp > 0 && str[newp - 1] == ' ')
		str[newp - 1] = 0x0;
	else
		//newp总是指向最后一个字符的后面
		str[newp] = 0x0;
}

// 去掉收尾空格，合并中间空格
//http://www.cnblogs.com/dartagnan/archive/2011/09/26/2191917.html
void remove_space(char* str) {
	int keep_space = 0;
	int new_str_end = 0;
	for (int i = 0; str[i]; ++i) {
		//如果遍历得到的此字符不是空格，则将标志符置为true；在进行else if语句时便可加入一空格；加入空格后标志符为false；这样就达到了缩进空格的目的；
		if (str[i] != ' ') {
			str[new_str_end++] = str[i];
			keep_space = 1;
		}
		//如果遍历得到的此字符是空格，则将标志符置为false；
		else if (keep_space) {
			str[new_str_end++] = str[i];
			keep_space = 0;
		}
	}
	//在进行最后处理时，判断最后一个字符是否为空格；如果是，则根据题目要求，将其去除；如果不是，则在其后面添加字符串结束符
	if (new_str_end > 0 && str[new_str_end - 1] == ' ') {
		str[new_str_end - 1] = '\0';
	} else {
		str[new_str_end] = '\0';
	}
}
