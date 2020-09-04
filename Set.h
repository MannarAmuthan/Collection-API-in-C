/*
 * Set.h
 *
 *  Created on: 04-Dec-2019
 *      Author: ELCOT
 */

#ifndef SET_H_
#define SET_H_

typedef struct set{
	LinkedList* list;
	Comparator *comparator;
}
Set;

Set *set(int (*comp)(void* op1,void* op2));

int  set_iscontains(Set* s, void* data);
int  set_add(Set* s,void* data);
void set_addset(Set* s,Set* o);
int set_issubset(Set* s,Set* o);

#endif /* SET_H_ */
