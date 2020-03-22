/*
 * Set.h
 *
 *  Created on: 04-Dec-2019
 *      Author: ELCOT
 */

#ifndef SET_H_
#define SET_H_



#include "LinkedList.h"

typedef struct set{
	LinkedList* list;
	Comparator *comparator;
}
Set;

int IsContains(Set* s, void* data);


Set *set(int (*comp)(void* op1,void* op2)){
	Set* s;
	s=(Set*)malloc(sizeof(Set));
	s->list=linkedlist();
	s->comparator=getComparatorLL(comp,s->list);
    return s;
}

int IsContains(Set* s, void* data){
	LinkedList* l=s->list;
	Node* n=l->head;
	while(n!=NULL){
		if(s->comparator->compareTo(n->data,data)==0){
			return 1;
		}
		n=(Node*)n->next;
	}
	return 0;
}

//add element if it is not present in sets
int addToSet(Set* s,void* data){
	if(IsContains(s,data)==0){
		LLadd(s->list,data);
		return 1;
	}
	return 0;
}

//add set o to set s, and avoid dublicate

void addSet(Set* s,Set* o){
	LinkedList* l=o->list;
	Node* n=l->head;
	while(n!=NULL){
		addToSet(s,n->data);
		n=(Node*)n->next;
	}
}

#endif /* SET_H_ */
