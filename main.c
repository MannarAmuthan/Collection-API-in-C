#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "Student.h"
#include "LinkedList.h"
#include "ArrayList.h"
//#include "Iterable.h"
//#include "Stack.h"
//#include "DynamicList.h"
//#include "HashMap.h"
//#include "Comparator.h"
//#include "PriorityQueue.h"
//#include "Set.h"
#include "TestLinkedList.c"
#include "TestArrayList.c"

int main(){

	struct Student a,b,c,d,e,f;
	strcpy(a.name,"student 1");
	strcpy(b.name,"student 2");
	strcpy(c.name,"student 3");
	strcpy(d.name,"student 4");
	strcpy(e.name,"student 5");
	strcpy(f.name,"student 6");
	a.roll=10;b.roll=20;c.roll=30;d.roll=40;e.roll=50;f.roll=60;

    testLinkedList();
    testArrayList();

//Demo of using Linked List
/*
    printf("\nSample usages of Linkedlist \n");
	LinkedList *list;
	list=linkedlist();
	LLadd(list,&a);
	LLadd(list,&b);
	LLadd(list,&c);
	LLadd(list,&d);
	LLadd(list,&e);
	LLadd(list,&f);
	insertAfter(&a,list,&f);
	insertFirst(list,&c);
    LLremove(list,6);
    LLremove(list,3);
    Iterator* i;
    i=LLgetIterator(list);


    while(hasNext(i)){
    	printf("%s \n",((struct Student*)getNext(i))->name);
    }

*/



//Demo of using Stack

/*
    printf("\nSample usages of Stack \n");
	Stack *st;
	st=stack();
	push(st,&a);
	push(st,&b);
	push(st,&c);
	push(st,&d);
	push(st,&e);
	push(st,&f);
	printf("%d \n",st->size);
	struct Student *data;
	pop(st);
	data=(struct Student*)pop(st);
    printf("%s %d \n",data->name,st->size);
*/



	
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


