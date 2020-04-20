
#include "ArrayList.h"
//data class
#include "Student.h"


void testArrayList(){
     int isAllTestsPassed=1;

     if(CreateArrayList()==0){
        isAllTestsPassed=0;
        printf("TestFailed : ArrayList Creation \n");
     }

     if(AddAndGetInArrayList()==0){
        isAllTestsPassed=0;
        printf("TestFailed : ArrayList Add and Get \n");
     }

     if(InsertInArrayList()==0){
        isAllTestsPassed=0;
        printf("TestFailed : ArrayList Insert \n");
     }

     if(RemoveInArrayList()==0){
        isAllTestsPassed=0;
        printf("TestFailed : ArrayList Remove \n");
     }

     if(SetInArrayList()==0){
        isAllTestsPassed=0;
        printf("TestFailed : ArrayList Set \n");
     }

     if(isAllTestsPassed==1){
        printf("TestsPassed : All Tests are passed in ArrayList \n");
     }
 }


 int CreateArrayList(){
     ArrayList* list;
     list=arraylist();
     if(list==NULL){
        return 0;
     }
     return 1;
 }

 int AddAndGetInArrayList(){
     ArrayList* list;
     list=arraylist();
     struct Student a,b;
     strcpy(a.name,"student 1");
     strcpy(b.name,"student 2");
     a.roll=10;b.roll=20;
     alist_add(list,&a);
     alist_add(list,&b);

     struct Student *a1,*b1;
     a1=(struct Student*)alist_get(list,0);
     b1=(struct Student*)alist_get(list,1);

     if(StudentCompare(a1,&a)==0&&StudentCompare(b1,&b)==0){
        return 1;
     }

     return 0;
 }

 int InsertInArrayList(){
     ArrayList* list;
     list=arraylist();
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

     if((StudentCompare(a1,&a)==0&&StudentCompare(b1,&c)==0)&&StudentCompare(c1,&b)==0){
        return 1;
     }

     return 0;

 }

 int RemoveInArrayList(){
      ArrayList* list;
      list=arraylist();
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

      if(StudentCompare(a1,&c)==0&&StudentCompare(b1,&b)==0){
         return 1;
      }

      return 0;

 }


 int SetInArrayList(){
      ArrayList* list;
      list=arraylist();
      struct Student a,b,c,d,e;
      strcpy(a.name,"student 1");
      strcpy(b.name,"student 2");
      strcpy(c.name,"student 3");
      strcpy(d.name,"student 4");
      strcpy(e.name,"student 5");

      a.roll=10;b.roll=20,c.roll=30,d.roll=40,e.roll=50;
      alist_add(list,&a);
      alist_add(list,&b);
      alist_add(list,&c);
      alist_set(list,&d,0);
      alist_set(list,&e,2);

      struct Student *a1,*b1;
      a1=(struct Student*)alist_get(list,0);
      b1=(struct Student*)alist_get(list,2);

      if(StudentCompare(a1,&d)==0&&StudentCompare(b1,&e)==0){
         return 1;
      }

      return 0;

 }
