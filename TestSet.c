#include "Set.h"
//dataset class
#include "Student.h"


void testSet(){
     int isAllTestsPassed=1;

     if(CreateSet()==0){
        isAllTestsPassed=0;
        printf("TestFailed : Set Creation \n");
     }

     if(AddToSet()==0){
        isAllTestsPassed=0;
        printf("TestFailed : Add to set Creation \n");
     }

     if(checkElementPresentInSet()==0){
        isAllTestsPassed=0;
        printf("TestFailed : Check element present or not in set \n");
     }

     if(AddSetToAnotherSet()==0){
        isAllTestsPassed=0;
        printf("TestFailed : Add Set to another Set \n");
     }

     if(CheckIfSetIsSubsetOfGivenSet()==0){
        isAllTestsPassed=0;
        printf("TestFailed : Whether set is subset of other set \n");
     }

     if(isAllTestsPassed==1){
        printf("TestsPassed : All Tests are passed in Set \n");
      }


 }

int CreateSet(){
     Set* s;
     s=set(StudentCompare);
     if(s==NULL){
        return 0;
     }
     return 1;
}

int AddToSet(){
     struct Student a,b,c,d,*e,*f,*g,*h,*i;
     strcpy(a.name,"student 1");
     strcpy(b.name,"student 2");
     strcpy(c.name,"student 4");
     strcpy(d.name,"student 5");

     Set* s;
     s=set(StudentCompare);

     set_add(s,&a);
     set_add(s,&b);
     set_add(s,&c);


     if(s->list->size==3){
     return 1;
     }
     return 0;
}

int checkElementPresentInSet(){
     struct Student a,b,c,d,*e,*f,*g,*h,*i;
     strcpy(a.name,"student 1");
     strcpy(b.name,"student 2");
     strcpy(c.name,"student 4");
     strcpy(d.name,"student 5");

     Set* s;
     s=set(StudentCompare);

     set_add(s,&a);

     if(set_iscontains(s,&a)==0){
     return 0;
     }

     if(set_iscontains(s,&d)==1){
     return 0;
     }
     return 1;

}

int AddSetToAnotherSet(){
     struct Student a,b,c,d;
     strcpy(a.name,"student 1");
     strcpy(b.name,"student 2");
     strcpy(c.name,"student 4");
     strcpy(d.name,"student 5");

     Set* s;
     s=set(StudentCompare);

     set_add(s,&a);
     set_add(s,&b);

     Set* anotherS;
     anotherS=set(StudentCompare);

     set_add(anotherS,&c);
     set_add(anotherS,&d);
     set_addset(s,anotherS);

     if(set_iscontains(s,&c)==0){
     return 0;
     }
     if(set_iscontains(s,&d)==0){
     return 0;
     }
     return 1;
}

int CheckIfSetIsSubsetOfGivenSet(){
     struct Student a,b,c,d;
     strcpy(a.name,"student 1");
     strcpy(b.name,"student 2");
     strcpy(c.name,"student 4");
     strcpy(d.name,"student 5");

     Set* s;
     s=set(StudentCompare);

     set_add(s,&a);
     set_add(s,&b);
     set_add(s,&c);
     set_add(s,&d);


     Set* anotherS;
     anotherS=set(StudentCompare);

     set_add(anotherS,&c);
     set_add(anotherS,&d);

     if(set_issubset(s,anotherS)==0){
     return 0;
     }

     return 1;
}







