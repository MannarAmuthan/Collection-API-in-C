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
 } Stack;

Stack* stack(){
Stack* st;
st=(Stack*)malloc(sizeof(Stack));
st->top=NULL;
st->size=0;
}

int push(Stack* stack,void* data){
	Node* node;
	node=init_node(data);
	if(stack->top==NULL){
		stack->top=node;
		stack->size=(stack->size)+1;
	}
	else{
		node->prev=stack->top;
		stack->top=node;
        stack->size=(stack->size)+1;
	}
	return 1;
}

void* peek(Stack* st){
	Node* top;
	top=st->top;
	return top->data;

}
void* pop(Stack* st){
	Node *top;
	top=st->top;
	st->top=st->top->prev;
    st->size=(st->size)-1;
	return top->data;

}

#endif /* STACK_H_ */
