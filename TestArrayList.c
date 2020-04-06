#include "ArrayList.h"


void testArrayList(){
     int isAllTestsPassed=1;

     if(shouldCreateArrayList()==0){
        isAllTestsPassed=0;
        printf("TestFailed : ArrayList Creation \n");
     }

     if(shouldAddAndGetLL()==0){
        isAllTestsPassed=0;
        printf("TestFailed : ArrayList Add and Get \n");
     }


     if(isAllTestsPassed==1){
         printf("TestsPassed : All Tests are passed in ArrayList \n");
     }
 }


 int shouldCreateArrayList(){
     ArrayList* list;
     list=arrayList();
     if(list==NULL){
     return 0;
     }
     return 1;
 }

 int shouldAddAndGetLL(){
     ArrayList* list;
     list=arrayList();
     struct Student a,b;
     strcpy(a.name,"student 1");
     strcpy(b.name,"student 2");
     a.roll=10;b.roll=20;
     alist_add(list,&a);
     alist_add(list,&b);

     struct Student *a1,*b1;
     a1=(struct Student*)alist_get(list,0);
     b1=(struct Student*)alist_get(list,1);

     if(compare(a1,&a)==0&&compare(b1,&b)==0){
     return 1;
     }

     return 0;
 }

 int shouldInsert(){


 }

