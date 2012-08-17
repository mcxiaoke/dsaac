/*
 * kselect.h
 *
 *  Created on: 2012-8-17
 *      Author: mcxiaoke
 */

#ifndef KSELECT_H_
#define KSELECT_H_

int selectMax(int data[], int n, int k);

int selectMin(int data[], int n, int k);

int kselect(int data[], int n, int k);

int kselectHeapA(int data[], int n, int k);

int kselectHeapB(int data[], int n, int k);

int kselectQuick(int data[], int n, int k);

#endif /* KSELECT_H_ */
