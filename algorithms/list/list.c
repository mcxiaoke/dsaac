/*
 * list.c
 *
 *  Created on: 2012-8-17
 *      Author: mcxiaoke
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int data;
	Node *next;
} Node;

// 链表逆序
Node * reverse1(Node* head) {
	if (head == NULL )
		return NULL ;
	Node* pre = head;
	Node* p = pre->next;
	Node * q = NULL;
	while (p != NULL ) {
		q = p->next;
		p->next = pre;
		if (pre == head) //反转后防止出现环
			pre->next = NULL;
		pre = p;
		p = q;
	}
	return pre;
}

Node * reverse2(Node* list, Node* pre = NULL ) {
	if (list == NULL )
		return list;
	Node *next = list->next;
	list->next = pre;
	return next == NULL ? list : Reverse(next, list);
}
