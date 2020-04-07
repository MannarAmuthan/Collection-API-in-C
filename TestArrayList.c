#include "ArrayList.h"


void testArrayList(){
     int isAllTestsPassed=1;

     if(shouldCreateArrayList()==0){
        isAllTestsPassed=0;
        printf("TestFailed : ArrayList Creation \n");
     }

     if(shouldAddAndGetAL()==0){
        isAllTestsPassed=0;
        printf("TestFailed : ArrayList Add and Get \n");
     }

     if(shouldInsertAL()==0){
        isAllTestsPassed=0;
        printf("TestFailed : ArrayList Insert \n");
     }

     if(shouldRemoveAL()==0){
        isAllTestsPassed=0;
        printf("TestFailed : ArrayList Remove \n");
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

 int shouldAddAndGetAL(){
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

 int shouldInsertAL(){
     ArrayList* list;
     list=arrayList();
     struct Student a,b,c;
     strcpy(a.name,"student 1");
     strcpy(b.name,"student 2");
     strcpy(c.name,"student 3");
     a.roll=10;b.roll=20;
     alist_add(list,&a);
     alist_add(list,&b);
     alist_insert(list,&c,1);

     struct Student *a1,*b1,*c1;
     a1=(struct Student*)alist_get(list,0);
     b1=(struct Student*)alist_get(list,1);
     c1=(struct Student*)alist_get(list,2);

     if((compare(a1,&a)==0&&compare(b1,&c)==0)&&compare(c1,&b)==0){
        return 1;
     }

     return 0;

 }

 int shouldRemoveAL(){
      ArrayList* list;
      list=arrayList();
      struct Student a,b,c;
      strcpy(a.name,"student 1");
      strcpy(b.name,"student 2");
      strcpy(c.name,"student 3");
      a.roll=10;b.roll=20;
      alist_add(list,&a);
      alist_add(list,&b);
      alist_insert(list,&c,1);
      alist_remove(list,0);

      struct Student *a1,*b1;
      a1=(struct Student*)alist_get(list,0);
      b1=(struct Student*)alist_get(list,1);

      if(compare(a1,&c)==0&&compare(b1,&b)==0){
         return 1;
      }

      return 0;

 }

