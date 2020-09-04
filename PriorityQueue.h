/*
 * PriorityQueue.h
 *
 *  Created on: Jul 13, 2019
 *      Author: AMUTHAN
 */

#ifndef PRIORITYQUEUE_H_
#define PRIORITYQUEUE_H_

typedef enum queue_type{
MIN_QUEUE,
MAX_QUEUE
}
QUEUE_TYPE;

typedef struct pri_que{
    ArrayList* list;
    Comparator* comp;
    QUEUE_TYPE queueType;
    int size;
}
PriorityQueue;

PriorityQueue* priorityQueue(QUEUE_TYPE queueType,int (*compareTo)(void* op1,void* op2));
void* pqueue_dequeue(PriorityQueue* pqueue);
void  pqueue_enqueue(PriorityQueue* pqueue,void* newData);

void pqueue_arrangeAfterExtract(PriorityQueue* pqueue,int index);
void pqueue_arrangeAfterInsert(PriorityQueue* pqueue,int index);

int isFirstElementHasHighPriority(PriorityQueue* pqueue,void* one,void* two);




#endif /* PRIORITYQUEUE_H_ */
