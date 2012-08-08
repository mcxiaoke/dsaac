/*
 * heap.h
 *
 *  Created on: 2012-8-7
 *      Author: mcxiaoke
 */

#ifndef HEAP_H_
#define HEAP_H_

/************************************************************************************
 *
 *  二叉堆ADT和实现（优先级队列 PriorityQueue）
 *
 */
#define QUEUE_MIN_SIZE 8
#define QUEUE_MIN_DATA -10000
#define QUEUE_MAX_DATA 10000

struct HeapStruct;
typedef struct HeapStruct *BinHeap;

BinHeap initializeBinHeap(int maxElements);
void buildBinHeap(int n, BinHeap q);
void destroyBinHeap(BinHeap q);
void clearBinHeap(BinHeap q);
void insertBinHeap(int x, BinHeap q);
int deleteMinBinHeap(BinHeap q);
int findMinBinHeap(BinHeap q);
int isEmptyBinHeap(BinHeap q);
int isFullBinHeap(BinHeap q);

void delete(int P,BinHeap h);
void printBinHeap(BinHeap h);

void testBinHeap();

void findKBinHeap();

#endif /* HEAP_H_ */
