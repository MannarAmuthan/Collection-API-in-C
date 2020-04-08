#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#include "Iterable.h"
//#include "Stack.h"
//#include "DynamicList.h"
//#include "HashMap.h"
//#include "Comparator.h"
//#include "PriorityQueue.h"
//#include "Set.h"
#include "TestLinkedList.c"
#include "TestArrayList.c"
#include "TestStack.c"
#include "TestComparator.c"
#include "TestIterator.c"

int main(){

//You can find how to use this library by looking test codes.
    testLinkedList();
    testArrayList();
    testStack();
    testComparator();
    testIterator();


	
//Demo of using ArrayList and Comparator for sorting
/*
    printf("\nSample usages of Arraylist and sorting using Comparator\n");
    ArrayList* al;
    al=arrayList();

    addAL(al,&a);
    addAL(al,&b);
    addAL(al,&c);
    addAL(al,&d);
    addAL(al,&e);
    addAL(al,&f);
    addAL(al,&a);
    addAL(al,&e);
    addAL(al,&f);
    addAL(al,&a);
    addAL(al,&b);
    addAL(al,&b);

    removeAL(al,0);
    removeAL(al,1);
    insertAtAL(al,&f,0);
    insertAtAL(al,&a,11);
    addAL(al,&e);

    Iterator* i;
    i=ALgetIterator(al);


    while(hasNext(i)){
 	  printf("%s \n",((struct Student*)getNext(i))->name);
    }

    Comparator* comp;
    comp=getComparatorAL(compare,al);
    sortAsc(comp);


    printf("after sorting.. \n");
    Iterator* i1;
    i1=ALgetIterator(al);


    while(hasNext(i1)){
 	printf("%s \n",((struct Student*)getNext(i1))->name);
    }
*/



//Demo of using HashMap
/*
   printf("\nSample usage of Hashmap\n");
   HashMap* map;
   map=hashmap();
   put(map,"am",&a);
   put(map,"aa",&c);
   put(map,"sm",&b);
   put(map,"keyy",&e);
   removeKey(map,"aa");
   void *data,*data2;
   data=getValue(map,"keyy");
   data2=getValue(map,"sm");
   printf("data is %d\n",((struct Student*)data)->roll);
   printf("data is %d\n",((struct Student*)data2)->roll);
*/




//Demo of using Linked List and Comparator for Sorting

/*
   printf("\nSample usages of Linkedlist and sorting using comparator\n");
   LinkedList *list1;
   list1=linkedlist();
   LLadd(list1,&b);
   LLadd(list1,&d);
   LLadd(list1,&c);

   Iterator* i1;
   i1=LLgetIterator(list1);

   Comparator* comp;
   comp=getComparatorLL(compare,list1);
   sortDesc(comp);

   printf("after sorting.. \n");
   while(hasNext(i1)){
	  printf("%s ",((struct Student*)getNext(i1))->name);
   }
*/

//Demo of using Priority Queue

/*
    printf("\nsample usages of priorityQueue\n");
	PriorityQueue *q;
	q=priorityQueue(compare);
	enqueue(q,&d);
	enqueue(q,&b);
	enqueue(q,&c);
	enqueue(q,&a);
	enqueue(q,&e);
	dequeue(q);
    struct Student *got;
    got=(struct Student*)dequeue(q);
    printf("got.. %s \n",got->name);
	Iterator* i;
	i=PQgetIterator(q);
	printf("state of queue.. \n");
	while(hasNext(i)){
		printf("%s \n",((struct Student*)getNext(i))->name);
	}
*/

//Demo of using ArrayList again
	
/*
	 ArrayList* al;
	 al=arrayList();

	 addAL(al,&a);
	 addAL(al,&b);
	 addAL(al,&c);
	 addAL(al,&d);
	 addAL(al,&e);
	 addAL(al,&f);

	 removeAL(al,0);
	 removeAL(al,1);
	 insertAtAL(al,&f,0);
	 insertAtAL(al,&a,4);
	 addAL(al,&e);

	 Iterator* i;
	 i=ALgetIterator(al);


	 while(hasNext(i)){
	 	printf("%s ",((struct Student*)getNext(i))->name);
	 }

	 Comparator* comp;
	 comp=getComparatorAL(compare,al);
	 sortAsc(comp);


	 printf("after sorting.. \n");
	 Iterator* i1;
	 i1=ALgetIterator(al);


	 while(hasNext(i1)){
	 	printf("%s ",((struct Student*)getNext(i1))->name);
	 }
*/
	
//Demo of using Sets

/*
     printf("\nsample usages of set\n");
	 Set *s,*anotherSet;
	 s=set(compare);
	 addToSet(s,&b);
	 addToSet(s,&c);
	 addToSet(s,&d);
	 addToSet(s,&e);
	 addToSet(s,&b);
	 anotherSet=set(compare);
	 addToSet(anotherSet,&a);
	 addToSet(anotherSet,&f);
	 addToSet(anotherSet,&c);
	 addToSet(anotherSet,&d);

	 addSet(s,anotherSet);


	 Iterator* i1;
	 i1=LLgetIterator(s->list);
	 while(hasNext(i1)){
		printf("%s ",((struct Student*)getNext(i1))->name);
	}
*/

	
return 1;

}


