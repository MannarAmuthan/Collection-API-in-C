/*
 * Comparator.h
 *
 *  Created on: Jun 29, 2019
 *      Author: AMUTHAN
 */

#ifndef COMPARATOR_H_
#define COMPARATOR_H_

#include "Iterable.h"

typedef struct comp_{
	int (*compareTo)(void* op1,void* op2);
	ArrayList* alist;
	LinkedList* llist;
	int type;
}Comparator;


void sortDesc(Comparator* c);
void sortAsc(Comparator* c);
void bubbleSort(Comparator* comp,int mode);
void insertionSort(Comparator* comp,int mode);
void swap(Node *a, Node *b);

Comparator* getComparatorLL(int (*compareTo)(void* op1,void* op2), LinkedList* list){
Comparator* comp;
comp=(Comparator*) malloc(sizeof(Comparator));
comp->compareTo=compareTo;
comp->llist=list;
comp->type=0;
return comp;
}
Comparator* getComparatorAL(int (*compareTo)(void* op1,void* op2), ArrayList* list){
Comparator* comp;
comp=(Comparator*) malloc(sizeof(Comparator));
comp->compareTo=compareTo;
comp->alist=list;
comp->type=1;
return comp;
}

void sortDesc(Comparator* c){
	if(c->type==0){
		bubbleSort(c,1);
	}
	else if(c->type==1){
		insertionSort(c,1);
	}
}
void sortAsc(Comparator* c){
	if(c->type==0){
		bubbleSort(c,-1);
	}
	else if(c->type==1){
		insertionSort(c,-1);
	}
}
void bubbleSort(Comparator* comp,int mode)
{
    int swapped;
    Node *ptr1;
    Node *lptr = NULL;
    Node *start;
    LinkedList* list;list=comp->llist;
    start=list->head;

    /* Checking for empty list */
    if (start == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = start;

        while (ptr1->next != lptr)
        {
            if (comp->compareTo(ptr1,ptr1->next)==mode)
            {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}

void insertionSort(Comparator* comp,int mode){
	ArrayList *list;
	list=comp->alist;
	int size=list->size;
    for(int i=0;i<size-1;i++){
     for(int j=i+1;j<size;j++){
    	 if(comp->compareTo(list->index+i,list->index+j)==mode){
    		// printf("\n swapp... %d %d",*(int*)list->index[i].data,*(int*)list->index[j].data);
    		 Node temp;
    		 temp=list->index[i];
    		 list->index[i]=list->index[j];
    		 list->index[j]=temp;
    	 }
      }
     }
}

/* function to swap data of two nodes a and b*/
void swap(Node *a, Node *b)
{
 void* temp;
 temp=a->data;
 a->data=b->data;
 b->data=temp;
}
#endif /* COMPARATOR_H_ */
