/*
 * Comparator.h
 *
 *  Created on: Jun 29, 2019
 *      Author: AMUTHAN
 */

#ifndef COMPARATOR_H_
#define COMPARATOR_H_

typedef struct comp_{
	int  (*compareTo)      (void* op1,void* op2);
	int  (*isEqual)        (struct comp_* c,void* op1,void* op2);
	void (*sortAscending)  (struct comp_* c,void* list);
	void (*sortDescending) (struct comp_* c,void* list);
}
Comparator;

Comparator* init_comparator(int (*compareTo)(void* op1,void* op2));
Comparator* llist_comparator(int (*compareTo)(void* op1,void* op2));
Comparator* alist_comparator(int (*compareTo)(void* op1,void* op2));

void llist_sortAscending(Comparator*  c,LinkedList* list);
void llist_sortDescending(Comparator* c,LinkedList* list);
void alist_sortAscending(Comparator*  c,ArrayList* list);
void alist_sortDescending(Comparator* c,ArrayList* list);

void bubbleSort(LinkedList* list,Comparator* comp,int mode);
void insertionSort(ArrayList *list,Comparator* comp,int mode);
void swap(Node *a, Node *b);
int isEqual(Comparator* c,void* op1,void* op2);


#endif /* COMPARATOR_H_ */
