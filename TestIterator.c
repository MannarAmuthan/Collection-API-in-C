#include "Iterable.h"


void testIterator(){
     int isAllTestsPassed=1;

     if(CreateIteratorForLinkedList()==0){
        isAllTestsPassed=0;
        printf("TestFailed : Iterator Creation for LinkedList \n");
     }

     if(CreateIteratorForArrayList()==0){
        isAllTestsPassed=0;
        printf("TestFailed : Iterator Creation for ArrayList \n");
     }

     if(IterateLinkedList()==0){
        isAllTestsPassed=0;
        printf("TestFailed : Iterator iteration for LinkedList \n");
     }

     if(IterateArrayList()==0){
        isAllTestsPassed=0;
        printf("TestFailed : Iterator iteration for ArrayList \n");
     }

     if(isAllTestsPassed==1){
        printf("TestsPassed : All Tests are passed in Iterator \n");
     }
 }


int CreateIteratorForLinkedList(){
        LinkedList *list;
        list=linkedlist();

        Iterator* iterator;
        iterator=iterator_llist(list);
        if(iterator==NULL){
        return 0;
        }
        return 1;
}

int CreateIteratorForArrayList(){

        ArrayList *list;
        list=arraylist();

        Iterator* iterator;
        iterator=iterator_alist(list);
        if(iterator==NULL){
        return 0;
        }
        return 1;
}

int IterateLinkedList(){
    struct Student a,b,c,d,e,f;
    strcpy(a.name,"student 1");
    strcpy(b.name,"student 2");
    strcpy(c.name,"student 3");
    strcpy(d.name,"student 4");
    a.roll=10;b.roll=20;c.roll=30;d.roll=40;

    LinkedList *list;
    list=linkedlist();
    llist_add(list,&a);
    llist_add(list,&b);
    llist_add(list,&c);
    llist_add(list,&d);
    Iterator* iterator;
    iterator=iterator_llist(list);
    int i=1;
    while(iterator->hasNext(iterator)==1){
    struct Student *a1;
    a1=(struct Student*)iterator->getNext(iterator);
        if(a1->roll!=i*10){
            return 0;
        }
    i++;
    }
    return 1;
}


int IterateArrayList(){
    struct Student a,b,c,d,e,f;
    strcpy(a.name,"student 1");
    strcpy(b.name,"student 2");
    strcpy(c.name,"student 3");
    strcpy(d.name,"student 4");
    a.roll=10;b.roll=20;c.roll=30;d.roll=40;

    ArrayList *list;
    list=arraylist();
    alist_add(list,&a);
    alist_add(list,&b);
    alist_add(list,&c);
    alist_add(list,&d);
    Iterator* iterator;
    iterator=iterator_alist(list);
    int i=1;
    while(iterator->hasNext(iterator)==1){
    struct Student *a1;
    a1=(struct Student*)iterator->getNext(iterator);
        if(a1->roll!=i*10){
            return 0;
        }
    i++;
    }
    return 1;
}















