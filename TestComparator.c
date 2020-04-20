#include "Comparator.h"
//data class
#include "Student.h"


void testComparator(){
     int isAllTestsPassed=1;

     if(GetComparatorForLinkedList()==0){
        isAllTestsPassed=0;
        printf("TestFailed : Getting comparator for LinkedList \n");
     }

     if(GetComparatorForArrayList()==0){
        isAllTestsPassed=0;
        printf("TestFailed : Getting comparator for ArrayList \n");
     }

     if(CheckEqualityBetweenTwoElements()==0){
        isAllTestsPassed=0;
        printf("TestFailed : Comparator isEqual method \n");
     }


     if(SortLinkedListInAscendingOrder()==0){
        isAllTestsPassed=0;
        printf("TestFailed : Sorting LinkedList in ascending order \n");
     }

     if(SortLinkedListInDescendingOrder()==0){
        isAllTestsPassed=0;
        printf("TestFailed : Sorting LinkedList in descending order \n");
     }

     if(SortArrayListInAscendingOrder()==0){
        isAllTestsPassed=0;
        printf("TestFailed : Sorting ArrayList in ascending order \n");
     }

     if(SortArrayListInDescendingOrder()==0){
        isAllTestsPassed=0;
        printf("TestFailed : Sorting ArrayList in descending order \n");
     }

     if(isAllTestsPassed==1){
        printf("TestsPassed : All Tests are passed in Comparator \n");
     }
 }

int GetComparatorForLinkedList(){
    Comparator* comparator;
    //adding Student's comparator method as a comparator
    comparator=llist_comparator(StudentCompare);
    if(comparator!=NULL){
        return 1;
    }
    return 0;
}



int GetComparatorForArrayList(){
    Comparator* comparator;
    //adding Student's comparator method as a comparator
    comparator=alist_comparator(StudentCompare);
    if(comparator!=NULL){
        return 1;
    }
    return 0;
}

int CheckEqualityBetweenTwoElements(){
    struct Student a,b,c,d,e,f;
    strcpy(a.name,"student 1");
    a.roll=10;

    struct Student *a1;
    a1=(struct Student*)malloc(sizeof(struct Student));
    a1->roll=10;

    Comparator* comparator;
    comparator=llist_comparator(StudentCompare);
    if(comparator->isEqual(comparator,&a,a1)==1){
    return 1;
    }
    return 0;

}

int SortLinkedListInAscendingOrder(){
    struct Student a,b,c,d,e,f;
    strcpy(a.name,"student 1");
    strcpy(b.name,"student 2");
    strcpy(c.name,"student 3");
    strcpy(d.name,"student 4");
    a.roll=10;b.roll=20;c.roll=30;d.roll=40;

    LinkedList *list;
    list=linkedlist();
    llist_add(list,&b);
    llist_add(list,&a);
    llist_insertFirst(list,&c);
    llist_insertAfter(list,&a,&d);

    Comparator* comparator;
    comparator=llist_comparator(StudentCompare);
    comparator->sortAscending(comparator,list);

    if(!((llist_indexof(list,&a)==0)&&(llist_indexof(list,&b)==1))){
        return 0;
    }
    if(!((llist_indexof(list,&c)==2)&&(llist_indexof(list,&d)==3))){
        return 0;
    }
    return 1;
}

int SortLinkedListInDescendingOrder(){
    struct Student a,b,c,d,e,f;
    strcpy(a.name,"student 1");
    strcpy(b.name,"student 2");
    strcpy(c.name,"student 3");
    strcpy(d.name,"student 4");
    a.roll=10;b.roll=20;c.roll=30;d.roll=40;

    LinkedList *list;
    list=linkedlist();
    llist_add(list,&b);
    llist_add(list,&a);
    llist_insertFirst(list,&c);
    llist_insertAfter(list,&a,&d);

    Comparator* comparator;
    comparator=llist_comparator(StudentCompare);
    comparator->sortDescending(comparator,list);

    if(!((llist_indexof(list,&a)==3)&&(llist_indexof(list,&b)==2))){
        return 0;
    }
    if(!((llist_indexof(list,&c)==1)&&(llist_indexof(list,&d)==0))){
        return 0;
    }
    return 1;
}

int SortArrayListInAscendingOrder(){
     struct Student a,b,c,d,e,f;
     strcpy(a.name,"student 1");
     strcpy(b.name,"student 2");
     strcpy(c.name,"student 3");
     strcpy(d.name,"student 4");
     a.roll=10;b.roll=20;c.roll=30;d.roll=40;

     ArrayList *list;
     list=arraylist();
     alist_add(list,&b);
     alist_add(list,&a);
     alist_insert(list,&c,1);
     alist_insert(list,&d,1);

     Comparator* comparator;
     comparator=alist_comparator(StudentCompare);
     comparator->sortAscending(comparator,list);

     for(int i=0;i<list->size-1;i++){
       if(comparator->compareTo(alist_get(list,i),alist_get(list,i+1))==1){
           return 0;
       }
     }
     return 1;
}

int SortArrayListInDescendingOrder(){
    struct Student a,b,c,d,e,f;
    strcpy(a.name,"student 1");
    strcpy(b.name,"student 2");
    strcpy(c.name,"student 3");
    strcpy(d.name,"student 4");
    a.roll=10;b.roll=20;c.roll=30;d.roll=40;

    ArrayList *list;
    list=arraylist();
    alist_add(list,&b);
    alist_add(list,&a);
    alist_insert(list,&c,1);
    alist_insert(list,&d,1);

    Comparator* comparator;
    comparator=alist_comparator(StudentCompare);
    comparator->sortDescending(comparator,list);

    for(int i=0;i<list->size-1;i++){
      if(comparator->compareTo(alist_get(list,i),alist_get(list,i+1))==-1){
          return 0;
      }
    }
    return 1;
}

