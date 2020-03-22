/*
 * PriorityQueue.h
 *
 *  Created on: Jul 13, 2019
 *      Author: AMUTHAN
 */

#ifndef PRIORITYQUEUE_H_
#define PRIORITYQUEUE_H_

#include "Comparator.h"
#include "LinkedList.h"

typedef struct pri_que{
    LinkedList* list;
    Comparator* comp;
    int size;
}
PriorityQueue;

PriorityQueue* priorityQueue(int (*compareTo)(void* op1,void* op2)){
	PriorityQueue *q;
	q=(PriorityQueue*) malloc(sizeof(PriorityQueue));
	q->list=linkedlist();
	q->comp=getComparatorLL(compareTo,q->list);
	return q;

}

void enqueue(PriorityQueue* q,void* data){
	insertFirst(q->list,data);
	sortDesc(q->comp);
	q->size=q->list->size;
}
void* dequeue(PriorityQueue* q){
	Node* data;
	data=LLget(q->list,0);
	LLremove(q->list,0);
	sortDesc(q->comp);
	q->size=q->list->size;
	return data->data;
}

#endif /* PRIORITYQUEUE_H_ */
