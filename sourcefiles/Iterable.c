
#include"/Users/amuthanmannan/Documents/collection/Collection-API-in-C copy/collection.h"

Iterator* iterator_llist(LinkedList* list){
    LinkedListIterator* ll_iterator;
    ll_iterator=(LinkedListIterator*) malloc(sizeof(LinkedListIterator));
    ll_iterator->llist=list;

    Iterator* i;
    i=(Iterator*) malloc(sizeof(Iterator));
    i->head=list->head;
    i->ptr=list->head;
 	i->hasNext=llist_hasnext;
 	i->listIterator=ll_iterator;
 	i->getNext=llist_getnext;
 	i->index=0;
 	return i;
 }

Iterator* iterator_alist(ArrayList* list){
    ArrayListIterator* al_iterator;
    al_iterator=(ArrayListIterator*) malloc(sizeof(ArrayListIterator));
    al_iterator->alist=list;

    Iterator* i;
    i=(Iterator*) malloc(sizeof(Iterator));
    i->head=list->index;
    i->ptr=list->index;
 	i->hasNext=alist_hasnext;
 	i->listIterator=al_iterator;
 	i->getNext=alist_getnext;
 	i->index=0;
 	return i;
}



int llist_hasnext(Iterator* i){
      if(i->ptr==NULL){
	   if((i->index)==0){
		   return 1;
	   }
	       return 0;
	   }
	return 1;
}

int alist_hasnext(Iterator* i){
        ArrayListIterator* a_iter;
        a_iter=(ArrayListIterator*) i->listIterator;
		if(i->index>=a_iter->alist->size){
		   return 0;
		}
    return 1;
}

void* llist_getnext(Iterator* i){
	Node *curr;
	void* tobe;

	curr=i->ptr;
    if(curr==NULL){
       if(i->index==0){
    	  tobe=i->head->data;
       }
       else{
          tobe=NULL;
       }
    }
	tobe=i->ptr->data;
	i->ptr=(Node*)i->ptr->next;
    i->index=(i->index)+1;
    return tobe;
}

void* alist_getnext(Iterator* i){
	Node *curr;
	void* tobe;

	curr=i->ptr;
    if(curr==NULL){
       if(i->index==0){
    	  tobe=i->head->data;
       }
       else{
          tobe=NULL;
       }
    }
    ArrayListIterator* a_iter;
    a_iter=(ArrayListIterator*) i->listIterator;
	tobe=i->ptr->data;
	i->ptr=&(a_iter->alist->index[(i->index)+1]);
	i->index=(i->index)+1;
    return tobe;
}
