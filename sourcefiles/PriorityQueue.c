
#include"/Users/amuthanmannan/Documents/collection/Collection-API-in-C copy/collection.h"

PriorityQueue* priorityQueue(QUEUE_TYPE queueType,int (*compareTo)(void* op1,void* op2)){
	PriorityQueue *q;
	q=(PriorityQueue*) malloc(sizeof(PriorityQueue));
	q->list=arraylist();
	q->comp=alist_comparator(compareTo);
	q->queueType=queueType;
	q->size=0;
	return q;
}

void* pqueue_dequeue(PriorityQueue* pqueue){
         void* maxNode;
         if(pqueue->size>0){
            maxNode=alist_get(pqueue->list,0);
            pqueue_arrangeAfterExtract(pqueue,0);
            pqueue->size=pqueue->size-1;
	 	    return maxNode;
	 	 }
	 	 return NULL;
}

void  pqueue_enqueue(PriorityQueue* pqueue,void* newData){
	 	 alist_add(pqueue->list,newData);
	 	 pqueue_arrangeAfterInsert(pqueue,pqueue->size);
	 	 pqueue->size=pqueue->size+1;
}

void pqueue_arrangeAfterExtract(PriorityQueue* pqueue,int index){
	 	 int childIndexOne=(2*index)+1;
	 	 int childIndexTwo=(2*index)+2;
         ArrayList *list;
         list=pqueue->list;

	 	 if(list->size<=childIndexOne){
	 	    alist_remove(list,index);
	 	    return;
	 	 }
	 	 if(list->size<=childIndexTwo){
	 	    alist_set(list,alist_get(list,childIndexOne),index);
	 	    alist_remove(list,childIndexOne);
	 	    return;
	 	 }

          void *childOne,*childTwo;
	 	  childOne=alist_get(list,childIndexOne);
	 	  childTwo=alist_get(list,childIndexTwo);

	 	  if(isFirstElementHasHighPriority(pqueue,childOne,childTwo)>=0){
	 	 	 alist_set(list,childOne,index);
	 	 	 index=childIndexOne;
		  }
	 	 else{
	 	 	 alist_set(list,childTwo,index);
	 	 	 index=childIndexTwo;
		  }
		  pqueue_arrangeAfterExtract(pqueue,index);

}

void pqueue_arrangeAfterInsert(PriorityQueue* pqueue,int index){
         if(index==0){return;}
         int parentIndex=(index-1)/2;
         if(parentIndex<0){return;}

         ArrayList *list;
         list=pqueue->list;

         void *parent,*child;
	 	 parent=alist_get(pqueue->list,parentIndex);
	 	 child=alist_get(pqueue->list,index);

         if(isFirstElementHasHighPriority(pqueue,child,parent)>=0){
               alist_set(list,parent,index);
               alist_set(list,child,parentIndex);
               pqueue_arrangeAfterInsert(pqueue,parentIndex);
         }

}

int isFirstElementHasHighPriority(PriorityQueue* pqueue,void* one,void* two){
   if(pqueue->queueType==MIN_QUEUE){
        int result=pqueue->comp->compareTo(one,two);
        if(result<0){
           return 1;
        }
        if(result==0){return 0;}
   }
      if(pqueue->queueType==MAX_QUEUE){
           int result=pqueue->comp->compareTo(one,two);
           if(result>0){
              return 1;
           }
           if(result==0){return 0;}
      }
   return -1;
}
