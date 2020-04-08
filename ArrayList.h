/*
 * DynamicList.h
 *
 *  Created on: Jun 25, 2019
 *      Author: AMUTHAN
 */

#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_

#include "LinkedList.h"

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


ArrayList* arraylist(){
	ArrayList* list;
    list=(ArrayList*) malloc(sizeof(ArrayList));
    list->index=(Node*)malloc(sizeof(Node)*10);
    list->size=0;
    list->pointer=0;
    list->capacity=10;
    return list;

}

int alist_add(ArrayList* list, void* newData){
	Node* node;
	node=init_node(newData);
	if((list->size)>=10){
		list->index=(Node*)realloc(list->index,((list->capacity)*sizeof(Node))*2);
		list->capacity=(list->capacity)*2;
	}
	*(list->index+(list->pointer))=*node;
	list->pointer=(list->pointer)+1;
	list->size=list->size+1;
	return 1;
}

void* alist_get(ArrayList* list,int pos){
	return (list->index+(pos))->data;
}

int alist_remove(ArrayList* list,int pos){
	if(pos>-1&&pos<list->size){
	for(int i=pos;i<list->size-1;i++){
		list->index[i]=list->index[i+1];
	}
	list->size=(list->size)-1;
	return 1;
	}
	else{
		return 0;
	}
}

int alist_insert(ArrayList* list,void* newData,int pos){
	Node* node;
	node=init_node(newData);
	  if(list->size>=list->capacity-1){
			list->index=(Node*)realloc(list->index,((list->capacity)*sizeof(Node))*2);
			list->capacity=(list->capacity)*2;
	  }
	  if(pos<list->capacity&&pos>-1){
		  for(int i=list->size-1;i>=pos;i--){
			  list->index[i+1]=list->index[i];
		  }
		  list->index[pos]=*node;
		  list->size=(list->size)+1;
		  return 1;
	  }
	  else{
		  return 0;
	  }
}



#endif /* ARRAYLIST_H_ */
