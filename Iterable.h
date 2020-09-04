/*
 * Iterable.h
 *
 *  Created on: Jun 23, 2019
 *      Author: AMUTHAN
 */

#ifndef ITERABLE_H_
#define ITERABLE_H_

typedef struct llist_iter{
    LinkedList* llist;
}
LinkedListIterator;

typedef struct alist_iter{
    ArrayList* alist;
}
ArrayListIterator;

typedef struct _iter{
    void* listIterator;
    Node* head;
    Node* ptr;
    int   index;
    int   (*hasNext)(struct _iter* i);
    void* (*getNext)(struct _iter* i);
}
Iterator;

Iterator* iterator_llist(LinkedList* list);
Iterator* iterator_alist(ArrayList* list);


int     llist_hasnext(Iterator* i);
int     alist_hasnext(Iterator* i);
void*   alist_getnext(Iterator* i);
void*   llist_getnext(Iterator* i);

#endif /* ITERABLE_H_ */
