/*
 * Stack.h
 *
 *  Created on: Jun 23, 2019
 *      Author: AMUTHAN
 */

#ifndef STACK_H_
#define STACK_H_

#include"LinkedList.h"

typedef struct _stack{
      Node* top;
      int size;
}
Stack;

//API Functions
int   push(Stack* stk,void* newData);
void* peek(Stack* stk);
void* pop(Stack* stk);
int   stack_size(Stack* stk);


Stack* stack(){
       Stack* stk;
       stk=(Stack*)malloc(sizeof(Stack));
       stk->top=NULL;
       stk->size=0;
       return stk;
}

int push(Stack* stk,void* newData){
	Node* node;
	node=init_node(newData);

	if(stk->top==NULL){
		stk->top=node;
		stk->size=(stk->size)+1;
	}
	else{
		node->prev=stk->top;
		stk->top=node;
        stk->size=(stk->size)+1;
	}
	return 1;
}

void* peek(Stack* stk){
	Node* top;
	top=stk->top;
	return top->data;
}

void* pop(Stack* stk){
	Node *top;
	top=stk->top;
	if(top==NULL){
	return NULL;
	}
	stk->top=stk->top->prev;
    stk->size=(stk->size)-1;
	return top->data;
}

int stack_size(Stack* stk){
     return stk->size;
}

#endif /* STACK_H_ */
