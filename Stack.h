/*
 * Stack.h
 *
 *  Created on: Jun 23, 2019
 *      Author: AMUTHAN
 */

#ifndef STACK_H_
#define STACK_H_

typedef struct _stack{
      Node* top;
      int size;
}
Stack;

Stack* stack();

//API Functions
int   push(Stack* stk,void* newData);
void* peek(Stack* stk);
void* pop(Stack* stk);
int   stack_size(Stack* stk);


#endif /* STACK_H_ */
