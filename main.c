#include<stdio.h>
#include"LinkedList.h"
#include "Iterable.h"
#include"Stack.h"
#include "DynamicList.h"
#include "HashMap.h"
#include "Comparator.h"

struct amuthan{
	int roll;
	char name[10];
};
int compare(void* one,void* two){
	struct amuthan *op1,*op2;
	op1=(struct amuthan*) one;
	op2=(struct amuthan*) two;

  if(op1->roll==op2->roll){
      return 0;
  }
  if(op1->roll>op2->roll){
      return 1;
  }
  if(op1->roll<op2->roll){
      return -1;
  }
}
void main(){
	struct amuthan a,b,c,d,e,f;
	strcpy(a.name,"amuthan");
	strcpy(b.name,"siva");
	strcpy(c.name,"ssssss");
	strcpy(d.name,"dd");
	strcpy(e.name,"ss");
	strcpy(f.name,"kkk");
	a.roll=10;b.roll=20;c.roll=30;d.roll=40;e.roll=50;f.roll=60;


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
    Iterator* i;
    i=LLgetIterator(list);


    while(hasNext(i)){
    	printf("%s ",((struct amuthan*)getNext(i))->name);
    }


/*
	Stack *st;
	st=stack();
	push(st,&a);
	push(st,&b);
	push(st,&c);
	push(st,&d);
	push(st,&e);
	push(st,&f);
	printf("%d \n",st->size);
	struct amuthan *data;
	pop(st);
	data=(struct amuthan*)pop(st);
    printf("%s %d \n",data->name,st->size);*/



	/*
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
 	printf("%s ",((struct amuthan*)getNext(i))->name);
 }

 */


/*
HashMap* map;
map=hashmap();
put(map,"am",&a);
put(map,"aa",&c);
put(map,"sm",&b);
put(map,"sarkar",&e);
removeKey(map,"aa");
void* data;
data=getValue(map,"sarkar");
printf(" data is %d",((struct amuthan*)data)->roll);
*/
Comparator* comp;
comp=getComparator(compare,i);
//sortDesc(comp);



}
