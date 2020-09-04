
#include"/Users/amuthanmannan/Documents/collection/Collection-API-in-C copy/collection.h"

Comparator* init_comparator(int (*compareTo)(void* op1,void* op2)){
    Comparator* comp;
    comp=(Comparator*) malloc(sizeof(Comparator));
    comp->compareTo=compareTo;
    comp->isEqual=isEqual;
    return comp;
}

Comparator* llist_comparator(int (*compareTo)(void* op1,void* op2)){
    Comparator* comp;
    comp=init_comparator(compareTo);
    comp->sortAscending=llist_sortAscending;
    comp->sortDescending=llist_sortDescending;
    return comp;
}

Comparator* alist_comparator(int (*compareTo)(void* op1,void* op2)){
    Comparator* comp;
    comp=init_comparator(compareTo);
    comp->sortAscending=alist_sortAscending;
    comp->sortDescending=alist_sortDescending;
    return comp;
}

int isEqual(Comparator* c,void* op1,void* op2){
     if(c->compareTo(op1,op2)==0){
        return 1;
     }
     return 0;
}

void llist_sortAscending(Comparator* c,LinkedList* list){
     bubbleSort(list,c,-1);
}

void llist_sortDescending(Comparator* c,LinkedList* list){
     bubbleSort(list,c,1);
}

void alist_sortAscending(Comparator* c,ArrayList* list){
     insertionSort(list,c,-1);
}

void alist_sortDescending(Comparator* c,ArrayList* list){
     insertionSort(list,c,1);
}

//Mode represents sorting order, -1 for ascending order, and 1 for descending order.

void bubbleSort(LinkedList* list,Comparator* comp,int mode)
{
    int swapped;
    Node *ptr1;
    Node *lptr;
    lptr=NULL;
    Node *start;
    start=list->head;

    if (start == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = start;

        while (ptr1->next != lptr)
        {
            if (comp->compareTo(ptr1,ptr1->next)==mode)
            {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}

void insertionSort(ArrayList *list,Comparator* comp,int mode){
	int size=list->size;
    for(int i=0;i<size-1;i++){
     for(int j=i+1;j<size;j++){
    	 if(comp->compareTo(list->index+i,list->index+j)==mode){
    		 Node temp;
    		 temp=list->index[i];
    		 list->index[i]=list->index[j];
    		 list->index[j]=temp;
    	 }
      }
     }
}

/* function to swap data of two nodes a and b*/
void swap(Node *a, Node *b)
{
    void* temp;
    temp=a->data;
    a->data=b->data;
    b->data=temp;
}