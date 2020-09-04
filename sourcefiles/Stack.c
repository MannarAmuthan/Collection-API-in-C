#include"/Users/amuthanmannan/Documents/collection/Collection-API-in-C copy/collection.h"

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
