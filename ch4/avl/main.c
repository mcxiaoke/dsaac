/*
 * main.c
 *
 *  Created on: 2012-8-3
 *      Author: mcxiaoke
 */

#include "avl.h"

int main(int argc, char **argv){
	setvbuf(stdout, 0, _IONBF, 0);
	AvlTree t=NULL;
	avl_create(&t);
	avl_inOrder(t);
	return 0;
}
