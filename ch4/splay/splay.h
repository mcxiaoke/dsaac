/*
 * splay.h
 *
 *  Created on: 2012-8-5
 *      Author: mcxiaoke
 */

#ifndef SPLAY_H_
#define SPLAY_H_

/*  数据类型定义  */
typedef struct NODE {
	int value;
	struct NODE *left;
	struct NODE *right;
//    struct NODE *parent;
} Node;
typedef Node * Position;
typedef Node * SplayTree;

/*  接口函数声明  */

/*  操作: 初始化一棵伸展树    */
/*  操作前:    ptree 指向一棵伸展树   */
/*  操作后:    该树被初始化为空    */
void spt_create(SplayTree * pt);

void spt_clear(SplayTree t);

void spt_destroy(SplayTree t);

/*  操作: 确定一棵伸展树是否为空 */
/*  操作前:    tree 是一棵已初始化的伸展树    */
/*  操作后:    如果该树为空, 返回1; 否则返回0  */
int spt_isEmpty(const SplayTree t);

/*  操作: 确定一棵伸展树是否已满 */
/*  操作前:    (该函数不接受任何参数)    */
/*  操作后:    如果该树已满,返回1; 否则返回0   */
int spt_isFull(SplayTree t);

/*  操作: 向树中添加一个结点(非递归)  */
/*  操作前:    tree 是一棵已初始化的伸展树, item 是一个Item类型数据  */
/*  操作后:    如果可能, 拥有 item 数据的结点被添加到树中, 返回新树的根节点; 否则返回原树 */
SplayTree spt_insert(SplayTree t, int x);

/*  操作: 向树中添加一个结点(递归)   */
/*  操作前:    tree 是一棵已初始化的伸展树, item 是一个Item类型数据  */
/*  操作后:    如果可能, 拥有 item 数据的结点被添加到树中, 返回新树的根节点; 否则返回原树 */
SplayTree spt_insert2(SplayTree t, int x);

/*  操作: 找到树中最大数据的结点 */
/*  操作前:    tree 是一棵已初始化的伸展树    */
/*  操作后:    如果可能, 返回树中最大数据结点的指针; 否则返回NULL   */
Position spt_findMax(const SplayTree t);

/*  操作: 找到树中最小数据的结点 */
/*  操作前:    tree 是一棵已初始化的伸展树    */
/*  操作后:    如果可能, 返回树中最小数据结点的指针; 否则返回NULL   */
Position spt_findMin(const SplayTree t);

/*  操作: 查找指定数据的结点并放到根节点的位置  */
/*  操作前:    tree 是一棵已初始化的伸展树, item 是指定的被查找的数据   */
/*  操作后:    如果可能, 被找到的结点作为根节点, 返回该结点; 否则返回原树    */
SplayTree spt_find(SplayTree t, int x);

/*  操作: 查找指定数据的结点并放到跟结点的位置(使用栈) */
/*  操作前:    tree 是一棵已初始化的伸展树, item 是指定的被查找的数据   */
/*  操作后:    如果可能, 被找到的结点作为跟结点, 返回该结点; 否则返回原树    */
SplayTree spt_findUseStack(SplayTree t, int x);

/*  操作: 删除指定数据所在结点  */
/*  操作前:    tree 是一棵已初始化的伸展树, item 是指定的被删除的数据   */
/*  操作后:    如果可能, 拥有 item 数据的结点被删除, 返回新树的结点; 否则返回原树 */
SplayTree spt_delete(SplayTree t, int x);

/*  操作: 将一个函数以中序作用于树中所有结点   */
/*  操作前:    tree 是一棵已初始化的伸展树   */
/*  操作后:    该函数以中序被作用于树中所有结点一次  */
void spt_inOrder(const SplayTree t);

#endif /* SPLAY_H_ */
