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
}
Node;

typedef struct Linkedlist{
	int size;
	Node* head;
	Node* tail;
}
LinkedList;


LinkedList* linkedlist();
Node* init_node(void* node);


//API Functions
void  llist_add(LinkedList* list,void* newData);
void* llist_tail(LinkedList* list);
int   llist_insertAfter(LinkedList* list,void* nextTo,void* newData);
int   llist_insertFirst(LinkedList* list,void* newData);
void* llist_get(LinkedList* list,int pos);
int   llist_indexof(LinkedList* list,void* data);


//Util functions for inside usage
Node* LLgetObj(LinkedList* list,void* data);
Node* LLremove(LinkedList* list,int pos);
Node* LLget(LinkedList* list,int pos);
void  LLaddNode(LinkedList* list,Node* newNode);




LinkedList* linkedlist(){
	LinkedList* list;
	list=(LinkedList*)malloc(sizeof(LinkedList));
	list->head=NULL;
	list->tail=NULL;
	list->size=0;
	return list;
}


Node* init_node(void* data){
    Node* n;
    n=(Node*)malloc(sizeof(Node));
    n->data=(void*)(data);
    n->next=NULL;
    n->prev=NULL;
    return n;
}



void llist_add(LinkedList* list,void* newData){
    Node *newNode;
    newNode=init_node(newData);
    LLaddNode(list,newNode);
}


int llist_insertAfter(LinkedList* list,void* nextTo,void* newData){
   Node *curr,*newNode;
   curr=LLgetObj(list,nextTo);
   if(curr==NULL){
	   return 0;
   }
   newNode=init_node(newData);
   newNode->next=curr->next;
   curr->next=newNode;
   list->size=(list->size)+1;
   return 1;
}


int llist_insertFirst(LinkedList* list,void* newData){
	Node *head,*node;
	node=init_node(newData);
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

void* llist_tail(LinkedList* list){
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

void* llist_get(LinkedList* list,int pos){
	Node* temp;
	temp=(Node*)list->head;
    int i=0;
			while(temp!=NULL){
				if(i==pos){
				return temp->data;
				}
				temp=temp->next;
				i++;
			}
    return NULL;
}

int llist_indexof(LinkedList* list,void* data){
	Node *curr,*n;
	n=LLgetObj(list,data);
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

void LLaddNode(LinkedList* list,Node* newNode){
    Node *head;
    head=list->head;
    if(head==NULL){
    	list->head=newNode;
    }
    else{
    Node* lastEle;
    lastEle=LLget(list,list->size-1);
    lastEle->next=newNode;
    }
    list->size=(list->size)+1;
}

Node* LLgetObj(LinkedList* list,void* data){
	Node* head;
	head=list->head;
	while(head!=NULL){
		if(head->data==data){
			return head;
		}
		head=head->next;
	}
	return NULL;
}


Node* LLget(LinkedList* list,int pos){
	Node* temp;
	temp=(Node*)list->head;
    int i=0;
			while(temp!=NULL){
				if(i==pos){
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






#endif 
