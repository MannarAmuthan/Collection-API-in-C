/*
 * Iterable.h
 *
 *  Created on: Jun 23, 2019
 *      Author: AMUTHAN
 */

#ifndef ITERABLE_H_
#define ITERABLE_H_

#include "LinkedList.h"
#include "DynamicList.h"
#include "PriorityQueue.h"


typedef struct iter_{
    Node* head;
    Node* ptr;
    int index;
    int type;
    ArrayList* alist;
    LinkedList* llist;
    int listSize;
}
Iterator;

Iterator* baseIterator(int listType){
 	Iterator* i;
 	i=(Iterator*) malloc(sizeof(Iterator));
 	i->index=0;
    i->type=listType;
    return i;
}

Iterator* LLgetIterator(LinkedList* list){
    Iterator* i;
    i=baseIterator(0);
 	i->head=list->head;
 	i->ptr=list->head;
 	i->llist=list;
 	return i;
 }

Iterator* ALgetIterator(ArrayList* list){
    Iterator* i;
    i=baseIterator(1);
	i->head=list->index;
	i->ptr=list->index;
	i->alist=list;
	return i;

}


Iterator* PQgetIterator(PriorityQueue* list){
    Iterator* i;
    i=baseIterator(0);
	i->head=list->list->head;
	i->ptr=list->list->head;
	i->llist=list->list;
	return i;

}
int hasNext(Iterator* i){
	if(i->type==0){
      if(i->ptr==NULL){
	   if((i->index)==0){
		   return 1;
	   }
	   return 0;
   }}
	else if(i->type==1){
		if(i->index>=i->alist->size){
		   return 0;
		}
	}
   return 1;
}
void* getNext(Iterator* i){

	Node *curr;
	void* tobe;

	curr=i->ptr;
    if(curr==NULL){
       if(i->index==0){
    	  tobe=i->head->data;
    	  }
       else{
          tobe=NULL;
    	  }
    	}

	if(i->type==0){
	   tobe=i->ptr->data;
	   i->ptr=(Node*)i->ptr->next;
       i->index=(i->index)+1;
	}

	else if(i->type==1){
	   tobe=i->ptr->data;
	   i->ptr=&(i->alist->index[(i->index)+1]);
	   i->index=(i->index)+1;
	}


	return tobe;
}

#endif /* ITERABLE_H_ */
