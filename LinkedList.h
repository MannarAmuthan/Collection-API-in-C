/*
 * DynamicArray.h
 *
 *  Created on: Jun 22, 2019
 *      Author: AMUTHAN
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_


typedef struct node{
    void* data;
    void* next;
    void* prev;
    int index;
}
Node;

typedef struct Linkedlist{
	int size;
	Node* head;
	Node* tail;
}
LinkedList;


LinkedList* linkedlist();
Node* init_node(void* node);


//API Functions
void  llist_add(LinkedList* list,void* newData);
void* llist_tail(LinkedList* list);
int   llist_insertAfter(LinkedList* list,void* nextTo,void* newData);
int   llist_insertFirst(LinkedList* list,void* newData);
void* llist_get(LinkedList* list,int pos);
int   llist_indexof(LinkedList* list,void* data);
int   llist_size(LinkedList* list);
void  llist_removeAt(LinkedList* list,int pos);


//Util functions for inside usage
Node* LLgetObj(LinkedList* list,void* data);
Node* LLget(LinkedList* list,int pos);
void  LLaddNode(LinkedList* list,Node* newNode);

#endif 
