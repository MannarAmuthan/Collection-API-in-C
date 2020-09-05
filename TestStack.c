#include "collection.h"
//data class
#include "Student.h"


void testStack(){
     int isAllTestsPassed=1;

     if(CreateStack()==0){
              isAllTestsPassed=0;
              printf("TestFailed : Stack Creation \n");
     }

     if(PushInStack()==0){
              isAllTestsPassed=0;
              printf("TestFailed : Stack Push \n");
     }

     if(PopInStack()==0){
              isAllTestsPassed=0;
              printf("TestFailed : Stack Pop \n");
     }

     if(PeekInStack()==0){
              isAllTestsPassed=0;
              printf("TestFailed : Stack Peek \n");
     }

     if(GetSizeOfStack()==0){
              isAllTestsPassed=0;
              printf("TestFailed : Stack get Size \n");
     }

     if(isAllTestsPassed==1){
        printf("TestsPassed : All Tests are passed in Stack \n");
     }
 }


int CreateStack(){
     Stack* stk;
     stk=stack();
     if(stk==NULL){
        return 0;
     }
     return 1;
}

int PushInStack(){
      Stack* stk;
      stk=stack();

      struct Student a,b,c,d,e,f;
      strcpy(a.name,"student 1");
      strcpy(b.name,"student 2");
      strcpy(c.name,"student 3");
      strcpy(d.name,"student 4");
      a.roll=10;b.roll=20;c.roll=30;d.roll=40;

      push(stk,&a);
      push(stk,&b);
      push(stk,&c);
      if(stack_size(stk)==3){
      return 1;
      }
      return 0;
}


int PopInStack(){
       Stack* stk;
       stk=stack();

       struct Student a,b,c,d,e,f;
       strcpy(a.name,"student 1");
       strcpy(b.name,"student 2");
       strcpy(c.name,"student 3");
       strcpy(d.name,"student 4");
       a.roll=10;b.roll=20;c.roll=30;d.roll=40;

       push(stk,&a);
       push(stk,&b);
       push(stk,&c);

       struct Student *a1;
       a1=(struct Student*)pop(stk);
       if(stack_size(stk)==2&&StudentCompare(a1,&c)==0){
       return 1;
       }
       return 0;
}


int PeekInStack(){
       Stack* stk;
       stk=stack();

       struct Student a,b,c,d,e,f;
       strcpy(a.name,"student 1");
       strcpy(b.name,"student 2");
       strcpy(c.name,"student 3");
       strcpy(d.name,"student 4");
       a.roll=10;b.roll=20;c.roll=30;d.roll=40;

       push(stk,&a);
       push(stk,&b);
       push(stk,&c);

       struct Student *a1;
       a1=(struct Student*)peek(stk);
       if(stack_size(stk)==3&&StudentCompare(a1,&c)==0){
       return 1;
       }
       return 0;
  }


int GetSizeOfStack(){
       Stack* stk;
       stk=stack();

       struct Student a,b,c,d,e,f;
       strcpy(a.name,"student 1");
       strcpy(b.name,"student 2");
       strcpy(c.name,"student 3");
       strcpy(d.name,"student 4");
       a.roll=10;b.roll=20;c.roll=30;d.roll=40;

       push(stk,&a);
       push(stk,&b);
       push(stk,&c);
       push(stk,&d);

       if(stack_size(stk)!=4){
       return 0;
       }

       pop(stk);
       pop(stk);

       if(stack_size(stk)==2){
       return 1;
       }
       return 0;

}






