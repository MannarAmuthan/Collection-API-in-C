#include "sourcefiles/HashMap.c"
//dataset class
#include "Student.h"


void testHashMap(){
     int isAllTestsPassed=1;

     if(CreateHashMap()==0){
        isAllTestsPassed=0;
        printf("TestFailed : HashMap Creation \n");
     }

     if(PutAndGetInHashMapWithIntegerKeys()==0){
        isAllTestsPassed=0;
        printf("TestFailed : HashMap Put and Get with Integer keys\n");
     }

     if(PutAndGetInHashMapWithStringKeys()==0){
        isAllTestsPassed=0;
        printf("TestFailed : HashMap Put and Get with String keys\n");
     }

     if(PutAndGetInHashMapWithFractionalNumbers()==0){
        isAllTestsPassed=0;
        printf("TestFailed : HashMap Put and Get with Fractional numbers\n");
     }

     if(isAllTestsPassed==1){
        printf("TestsPassed : All Tests are passed in Hashmap \n");
     }
 }

int CreateHashMap(){
     HashMap* map;
     map=hashmap(STRING);
     if(map==NULL){
        return 0;
     }
     return 1;
}

int PutAndGetInHashMapWithIntegerKeys(){
     HashMap* map;
     map=hashmap(INTEGER);
     struct Student a,b,c,d,*e,*f,*g,*h,*i;
     strcpy(a.name,"student 1");
     strcpy(b.name,"student 2");
     strcpy(c.name,"student 4");
     strcpy(d.name,"student 5");
     a.roll=10;b.roll=20;c.roll=7000,d.roll=6999;

     int keys[]={5677,7654,87,9,1,3};

     hashmap_put(map,&keys[0],&a);
     hashmap_put(map,&keys[1],&b);
     hashmap_put(map,&keys[2],&c);
     hashmap_put(map,&keys[3],&d);
     hashmap_put(map,&keys[4],&a);
     hashmap_put(map,&keys[5],&c);

     e=(struct Student*)hashmap_get(map,&keys[5]);
     f=(struct Student*)hashmap_get(map,&keys[4]);
     g=(struct Student*)hashmap_get(map,&keys[1]);
     h=(struct Student*)hashmap_get(map,&keys[2]);
     i=(struct Student*)hashmap_get(map,&keys[3]);

     if(e->roll!=7000){return 0;}
     if(f->roll!=10){return 0;}
     if(g->roll!=20){return 0;}
     if(h->roll!=7000){return 0;}
     if(i->roll!=6999){return 0;}

     return 1;
}

int PutAndGetInHashMapWithStringKeys(){
     HashMap* map;
     map=hashmap(STRING);
     struct Student a,b,c,d,*e,*f,*g,*h,*i,*j,test,*testP;
     strcpy(a.name,"student 1");
     strcpy(b.name,"student 2");
     strcpy(c.name,"student 4");
     strcpy(d.name,"student 4");
     strcpy(test.name,"student 4");
     a.roll=10;b.roll=20;c.roll=7000,d.roll=6999,test.roll=43;

     hashmap_put(map,"This is key one",&a);
     hashmap_put(map,"This is key one!",&b);
     hashmap_put(map,"key 2",&c);
     hashmap_put(map,"key 21",&d);
     hashmap_put(map,"key 333",&a);
     hashmap_put(map,"!@#$%^&*",&c);


     e=(struct Student*)hashmap_get(map,"!@#$%^&*");
     f=(struct Student*)hashmap_get(map,"key 333");
     g=(struct Student*)hashmap_get(map,"key 21");
     h=(struct Student*)hashmap_get(map,"key 2");
     i=(struct Student*)hashmap_get(map,"This is key one!");
     j=(struct Student*)hashmap_get(map,"This is key one");

     if(e->roll!=7000){return 0;}
     if(f->roll!=10){return 0;}
     if(g->roll!=6999){return 0;}
     if(h->roll!=7000){return 0;}
     if(i->roll!=20){return 0;}
     if(j->roll!=10){return 0;}

     return 1;
}



int PutAndGetInHashMapWithFractionalNumbers(){
     HashMap* map;
     map=hashmap(FRACTIONAL_NUMBER);
     struct Student a,b,c,d,*e,*f,*g,*h,*i,*j;
     strcpy(a.name,"student 1");
     strcpy(b.name,"student 2");
     strcpy(c.name,"student 4");
     strcpy(d.name,"student 4");
     a.roll=10;b.roll=20;c.roll=7000,d.roll=6999;

     float keys[]={1122.55,444.44,34,1.00001,546};
     hashmap_put(map,&keys[0],&a);
     hashmap_put(map,&keys[1],&b);
     hashmap_put(map,&keys[2],&c);
     hashmap_put(map,&keys[3],&d);
     hashmap_put(map,&keys[4],&a);
     hashmap_put(map,&keys[5],&c);


     e=(struct Student*)hashmap_get(map,&keys[5]);
     f=(struct Student*)hashmap_get(map,&keys[4]);
     g=(struct Student*)hashmap_get(map,&keys[3]);
     h=(struct Student*)hashmap_get(map,&keys[2]);
     i=(struct Student*)hashmap_get(map,&keys[1]);
     j=(struct Student*)hashmap_get(map,&keys[0]);

     if(e->roll!=7000){return 0;}
     if(f->roll!=10){return 0;}
     if(g->roll!=6999){return 0;}
     if(h->roll!=7000){return 0;}
     if(i->roll!=20){return 0;}
     if(j->roll!=10){return 0;}

     return 1;
}





