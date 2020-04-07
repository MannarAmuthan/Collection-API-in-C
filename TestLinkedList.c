
#include "LinkedList.h"
//dataset class
#include "Student.h"

void testLinkedList(){
    int isAllTestsPassed=1;

     if(shouldCreateLinkedList()==0){
        isAllTestsPassed=0;
        printf("TestFailed : LinkedList Creation \n");
     }

     if(shouldAddAndGetElementLL()==0){
        isAllTestsPassed=0;
        printf("TestFailed : LinkedList Adding and Getting \n");
     }


     if(shouldInsertAndGetLL()==0){
        isAllTestsPassed=0;
        printf("TestFailed : LinkedList Inserting and Getting \n");
     }

     if(shouldGetIndexOfLL()==0){
        isAllTestsPassed=0;
        printf("TestFailed : LinkedList Getting index of element \n");
     }

     if(shouldGetSizeLL()==0){
        isAllTestsPassed=0;
        printf("TestFailed : LinkedList Getting size \n");
     }

     if(shouldRemoveAtLL()==0){
        isAllTestsPassed=0;
        printf("TestFailed : LinkedList Remove at position \n");
     }

     if(isAllTestsPassed==1){
        printf("TestsPassed : All Tests are passed in LinkedList \n");
     }
 }

int shouldCreateLinkedList(){
    LinkedList *list;
	list=linkedlist();
	if(list!=NULL){
	   return 1;
	}
	return 0;
}

int shouldAddAndGetElementLL(){
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

    if(compare(&a,a1)==0&&compare(&b,b1)==0){
    return 1;
    }
    return 0;
}

int shouldInsertAndGetLL(){
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

    if(compare(&c,a1)==0&&compare(&a,b1)==0){
       return 1;
    }
    return 0;
}

int shouldGetIndexOfLL(){
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


int shouldGetSizeLL(){
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

int shouldRemoveAtLL(){
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

    if(llist_size(list)==3&&compare(a1,&d)==0){
       return 1;
    }

    return 0;
}




