#include "collection.h"
//dataset class
#include "Student.h"

void testPriorityQueue(){
     int isAllTestsPassed=1;

     if(CreatePriorityQueue()==0){
        isAllTestsPassed=0;
        printf("TestFailed : PriorityQueue Creation \n");
     }

     if(InsertInPriorityQueue()==0){
        isAllTestsPassed=0;
        printf("TestFailed : PriorityQueue Insertion\n");
     }
     if(ExtractInMinimumPriorityQueue()==0){
        isAllTestsPassed=0;
        printf("TestFailed : PriorityQueue Extraction - Minimum Queue \n");
     }

     if(ExtractInMaximumPriorityQueue()==0){
        isAllTestsPassed=0;
        printf("TestFailed : PriorityQueue Extraction - Maximum Queue \n");
     }


     if(isAllTestsPassed==1){
         printf("TestsPassed : All Tests are passed in PriorityQueue \n");
     }

}

int CreatePriorityQueue(){
    PriorityQueue* pq;
    pq=priorityQueue(MIN_QUEUE,StudentCompare);
    if(pq==NULL){
    return 0;
    }
    return 1;
}

int InsertInPriorityQueue(){

    PriorityQueue* pq;
    pq=priorityQueue(MIN_QUEUE,StudentCompare);

    struct Student a,b,c,d,e,f;
    strcpy(a.name,"student 1");
    strcpy(b.name,"student 2");
    strcpy(c.name,"student 3");
    strcpy(d.name,"student 4");
    a.roll=10;b.roll=20;c.roll=30;d.roll=40;
    pqueue_enqueue(pq,&a);
    pqueue_enqueue(pq,&b);
    pqueue_enqueue(pq,&c);
    pqueue_enqueue(pq,&d);

    if(pq->size==4){
        return 1;
    }
    return 0;
}

int ExtractInMinimumPriorityQueue(){
    PriorityQueue* pq;
    pq=priorityQueue(MIN_QUEUE,StudentCompare);

    struct Student a,b,c,d,e,f;
    strcpy(a.name,"student 1");
    strcpy(b.name,"student 2");
    strcpy(c.name,"student 3");
    strcpy(d.name,"student 4");
    a.roll=10;b.roll=20;c.roll=30;d.roll=40;
    pqueue_enqueue(pq,&d);
    pqueue_enqueue(pq,&c);
    pqueue_enqueue(pq,&a);
    pqueue_enqueue(pq,&b);

    ArrayList* list;
    list=pq->list;
    struct Student *a1,*b1,*c1,*d1;
 //   printf("%d %d %d %d\n",((struct Student*)alist_get(list,0))->roll,((struct Student*)alist_get(list,1))->roll,((struct Student*)alist_get(list,2))->roll,((struct Student*)alist_get(list,3))->roll);

    a1=(struct Student*)pqueue_dequeue(pq);
    b1=(struct Student*)pqueue_dequeue(pq);
    c1=(struct Student*)pqueue_dequeue(pq);
    d1=(struct Student*)pqueue_dequeue(pq);

 //   printf("%d %d %d %d\n",a1->roll,b1->roll,c1->roll,d1->roll);


    if(StudentCompare(a1,&a)!=0){ return 0;}
    if(StudentCompare(b1,&b)!=0){return 0;}
    if(StudentCompare(c1,&c)!=0){return 0;}
    if(StudentCompare(d1,&d)!=0){return 0;}

    return 1;
}

int ExtractInMaximumPriorityQueue(){
    PriorityQueue* pq;
    pq=priorityQueue(MAX_QUEUE,StudentCompare);

    struct Student a,b,c,d,e,f;
    strcpy(a.name,"student 1");
    strcpy(b.name,"student 2");
    strcpy(c.name,"student 3");
    strcpy(d.name,"student 4");
    a.roll=10;b.roll=20;c.roll=30;d.roll=40;
    pqueue_enqueue(pq,&d);
    pqueue_enqueue(pq,&c);
    pqueue_enqueue(pq,&a);
    pqueue_enqueue(pq,&b);
    pqueue_enqueue(pq,&d);

    ArrayList* list;
    list=pq->list;
    struct Student *a1,*b1,*c1,*d1,*a11;

    a1=(struct Student*)pqueue_dequeue(pq);
    a11=(struct Student*)pqueue_dequeue(pq);
    b1=(struct Student*)pqueue_dequeue(pq);
    c1=(struct Student*)pqueue_dequeue(pq);
    d1=(struct Student*)pqueue_dequeue(pq);


    if(StudentCompare(a1,&d)!=0){ return 0;}
    if(StudentCompare(a11,&d)!=0){ return 0;}
    if(StudentCompare(b1,&c)!=0){return 0;}
    if(StudentCompare(c1,&b)!=0){return 0;}
    if(StudentCompare(d1,&a)!=0){return 0;}

    return 1;
}