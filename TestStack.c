#include "Stack.h"


void testStack(){
     int isAllTestsPassed=1;

     if(shouldCreateStack()==0){
              isAllTestsPassed=0;
              printf("TestFailed : Stack Creation \n");
     }

     if(shouldPush()==0){
              isAllTestsPassed=0;
              printf("TestFailed : Stack Push \n");
     }

     if(shouldPop()==0){
              isAllTestsPassed=0;
              printf("TestFailed : Stack Pop \n");
     }

     if(shouldPeek()==0){
              isAllTestsPassed=0;
              printf("TestFailed : Stack Peek \n");
     }

     if(shouldGetSizeStack()==0){
              isAllTestsPassed=0;
              printf("TestFailed : Stack get Size \n");
     }

     if(isAllTestsPassed==1){
        printf("TestsPassed : All Tests are passed in Stack \n");
     }
 }


int shouldCreateStack(){
     Stack* stk;
     stk=stack();
     if(stk==NULL){
        return 0;
     }
     return 1;
}

int shouldPush(){
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


int shouldPop(){
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
       if(stack_size(stk)==2&&compare(a1,&c)==0){
       return 1;
       }
       return 0;
}


int shouldPeek(){
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
       if(stack_size(stk)==3&&compare(a1,&c)==0){
       return 1;
       }
       return 0;
  }


int shouldGetSizeStack(){
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






