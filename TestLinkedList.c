
#include "LinkedList.h"
//data class
#include "Student.h"

void testLinkedList(){
    int isAllTestsPassed=1;

     if(CreateLinkedList()==0){
        isAllTestsPassed=0;
        printf("TestFailed : LinkedList Creation \n");
     }

     if(AddAndGetInLinkedList()==0){
        isAllTestsPassed=0;
        printf("TestFailed : LinkedList Adding and Getting \n");
     }


     if(InsertAndGetInLinkedList()==0){
        isAllTestsPassed=0;
        printf("TestFailed : LinkedList Inserting and Getting \n");
     }

     if(GetIndexOfElementInLinkedList()==0){
        isAllTestsPassed=0;
        printf("TestFailed : LinkedList Getting index of element \n");
     }

     if(GetSizeOfLinkedList()==0){
        isAllTestsPassed=0;
        printf("TestFailed : LinkedList Getting size \n");
     }

     if(RemoveInLinkedList()==0){
        isAllTestsPassed=0;
        printf("TestFailed : LinkedList Remove at position \n");
     }

     if(isAllTestsPassed==1){
        printf("TestsPassed : All Tests are passed in LinkedList \n");
     }
 }

int CreateLinkedList(){
    LinkedList *list;
	list=linkedlist();
	if(list!=NULL){
	   return 1;
	}
	return 0;
}

int AddAndGetInLinkedList(){
    struct Student a,b;
    strcpy(a.name,"student 1");
    strcpy(b.name,"student 2");
    a.roll=10;b.roll=20;

    LinkedList *list;
    list=linkedlist();
    llist_add(list,&a);
    llist_add(list,&b);

    struct Student *a1,*b1;
    a1=(struct Student*)llist_get(list,0);
    b1=(struct Student*)llist_get(list,1);

    if(StudentCompare(&a,a1)==0&&StudentCompare(&b,b1)==0){
        return 1;
    }
    return 0;
}

int InsertAndGetInLinkedList(){
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
    llist_insertFirst(list,&c);
    llist_insertAfter(list,&a,&d);

    struct Student *a1,*b1;
    a1=(struct Student*)llist_get(list,0);
    b1=(struct Student*)llist_get(list,1);

    if(StudentCompare(&c,a1)==0&&StudentCompare(&a,b1)==0){
       return 1;
    }
    return 0;
}

int GetIndexOfElementInLinkedList(){
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
    llist_insertFirst(list,&c);
    llist_insertAfter(list,&a,&d);


    if(llist_indexof(list,&c)==0&&llist_indexof(list,&d)==2){
       return 1;
    }
    return 0;
}


int GetSizeOfLinkedList(){
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

    if(llist_size(list)!=2){
       return 0;
    }

    llist_insertFirst(list,&c);
    llist_insertAfter(list,&a,&d);

    if(llist_size(list)==4){
       return 1;
    }

    return 0;

}

int RemoveInLinkedList(){
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
    llist_insertFirst(list,&c);
    llist_insertAfter(list,&a,&d);

    struct Student *a1;
    llist_removeAt(list,0);
    a1=(struct Student*) llist_get(list,1);

    if(llist_size(list)==3&&StudentCompare(a1,&d)==0){
       return 1;
    }

    return 0;
}




