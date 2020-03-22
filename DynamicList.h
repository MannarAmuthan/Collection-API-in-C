/*
 * DynamicList.h
 *
 *  Created on: Jun 25, 2019
 *      Author: AMUTHAN
 */

#ifndef DYNAMICLIST_H_
#define DYNAMICLIST_H_

#include "LinkedList.h"
typedef struct dynamlist{
	Node *index;
	int pointer;
	int size;
	int capacity;
} ArrayList;

ArrayList* arrayList(){
	ArrayList* list;
    list=(ArrayList*) malloc(sizeof(ArrayList));
    list->index=(Node*)malloc(sizeof(Node)*10);
    list->size=0;
    list->pointer=0;
    list->capacity=10;
    return list;

}

int addAL(ArrayList* list, void* data){
	Node* node;
	node=init_node(data);
	if((list->size)>=10){
		list->index=(Node*)realloc(list->index,((list->capacity)*sizeof(Node))*2);
		list->capacity=(list->capacity)*2;
	}
	*(list->index+(list->pointer))=*node;
	list->pointer=(list->pointer)+1;
	list->size=list->size+1;
	return 1;
}
void* getAL(ArrayList* list,int n){
	return (list->index+(n))->data;
}
int removeAL(ArrayList* list,int n){
	if(n>-1&&n<list->size){
	for(int i=n;i<list->size-1;i++){
		list->index[i]=list->index[i+1];
	}
	list->size=(list->size)-1;
	return 1;
	}
	else{
		return 0;
	}
}

int insertAtAL(ArrayList* list,void* data,int n){
	Node* node;
	node=init_node(data);
	  if(list->size>=list->capacity-1){
			list->index=(Node*)realloc(list->index,((list->capacity)*sizeof(Node))*2);
			list->capacity=(list->capacity)*2;
	  }
	  if(n<list->capacity&&n>-1){
		  for(int i=list->size-1;i>=n;i--){
			  list->index[i+1]=list->index[i];
		  }
		  list->index[n]=*node;
		  list->size=(list->size)+1;
		  return 1;
	  }
	  else{
		  return 0;
	  }
}



#endif /* DYNAMICLIST_H_ */
