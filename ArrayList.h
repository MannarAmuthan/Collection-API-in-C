/*
 * DynamicList.h
 *
 *  Created on: Jun 25, 2019
 *      Author: AMUTHAN
 */

#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_

typedef struct dynamlist{
	Node *index;
	int pointer;
	int size;
	int capacity;
} ArrayList;

ArrayList* arraylist();

int    alist_add(ArrayList* list, void* newData);
void*  alist_get(ArrayList* list,int pos);
int    alist_remove(ArrayList* list,int pos);
int    alist_insert(ArrayList* list,void* newData,int pos);
int    alist_set(ArrayList* list,void* newData,int pos);


#endif /* ARRAYLIST_H_ */
