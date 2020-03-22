/*
 * DynamicArray.h
 *
 *  Created on: Jun 22, 2019
 *      Author: AMUTHAN
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_


typedef struct node{
void* data;
void* next;
void* prev;
int index;
}Node;

typedef struct Linkedlist{
	int size;
	Node* head;
	Node* tail;
}
LinkedList;


LinkedList* linkedlist();
void LLadd(LinkedList* list,void* node);
void* LLgetLast(LinkedList* list);
Node* init_node(void* node);
int insert(int pos,LinkedList* list,void* data);
Node* getObj(LinkedList* list,void* no);
Node* LLget(LinkedList* list,int pos);

LinkedList* linkedlist(){
	LinkedList* list;
	list=(LinkedList*)malloc(sizeof(LinkedList));
	list->head=NULL;
	list->tail=NULL;
	list->size=0;
	return list;
}

void LLadd(LinkedList* list,void* data){

    Node *head,*node;
    head=list->head;
    node=init_node(data);

    if(head==NULL){
    	list->head=node;
    }
    else{
    Node* lastEle;
    lastEle=LLgetLast(list);
    lastEle->next=node;
    }
    list->size=(list->size)+1;

}
int insertAfter(void* no,LinkedList* list,void* data){
   Node *curr,*new;
   curr=getObj(list,no);
   if(curr==NULL){
	   return 0;
   }
   new=init_node(data);
   new->next=curr->next;
   curr->next=new;
   list->size=(list->size)+1;
   return 1;
}
int insertFirst(LinkedList* list,void* data){
	Node *head,*node;
	node=init_node(data);
	head=list->head;
	if(head==NULL){
		list->head=node;
		return 1;
	}
	node->next=head;
	list->head=node;
	 list->size=(list->size)+1;
	return 1;
}

Node* getObj(LinkedList* list,void* no){
	Node* head;
	head=list->head;
	while(head!=NULL){
		if(head->data==no){
			return head;
		}
		head=head->next;
	}
	return NULL;
}

void* LLgetLast(LinkedList* list){
	Node* temp;
	temp=(Node*)list->head;

	while(1){
		if(temp->next==NULL){
			return (void*)temp;
		}
		temp=temp->next;
	}
	return NULL;
}
Node* LLget(LinkedList* list,int pos){
	Node* temp;
	temp=(Node*)list->head;
    int i=0;
			while(temp!=NULL){
				if(i==pos){
				//printf("returns %d \n",*(int*)(temp->data));
				return temp;
				}
				temp=temp->next;
				i++;
			}
    return NULL;
}

Node* LLremove(LinkedList* list,int pos){
	Node *temp,*prev;
	temp=(Node*)list->head;
	prev=temp;
    int i=1;
    if(pos==0){
    	list->head=list->head->next;
    	list->size=(list->size)-1;
    }

    else{
			while(1){
				temp=temp->next;
				if(i==list->size-1&&i==pos){
					//printf("here for %d %d \n",pos,list->size);
                  prev->next=NULL;
                  break;
				}
				else{

					if(temp==NULL){break;}
					if(i==pos){
						prev->next=temp->next;
						break;
					}
					prev=temp;
				}

				i++;
			}
			list->size=(list->size)-1;
    }
    return NULL;
}

int LLindexOf(LinkedList* list,Node* n){
	Node* curr;
	curr=list->head;
	int i=0;
	while(1){
		if(curr==n){
			return i;
		}
		curr=curr->next;
		if(curr==NULL){
			return -1;
		}
		i++;
	}
	return i;
}



Node* init_node(void* data){
    Node* n;
    n=(Node*)malloc(sizeof(Node));
    n->data=(void*)(data);
    n->next=NULL;
    n->prev=NULL;
    return n;
}
void LLaddNode(LinkedList* list,Node* node){
    Node *head;
    head=list->head;
    if(head==NULL){
    	list->head=node;
    }
    else{
    Node* lastEle;
    lastEle=LLgetLast(list);
    lastEle->next=node;
    }
    list->size=(list->size)+1;
}
#endif 
