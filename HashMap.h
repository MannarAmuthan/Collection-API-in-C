/*
 * HashMap.h
 *
 *  Created on: Jun 29, 2019
 *      Author: AMUTHAN
 */

#ifndef HASHMAP_H_
#define HASHMAP_H_

typedef struct node_hash{
	char* key;
	char* realKey[10];
	void* data;
} HashNode;
typedef struct hash_{
	HashNode* index;
	int capacity;
} HashMap;

HashMap* hashmap(){
	HashMap* map;
	map=(HashMap*) malloc(sizeof(HashMap));
	map->index=(HashNode*) malloc(sizeof(HashNode)*256);
	map->capacity=256;
	return map;
}
HashNode* init_hashnode(void* key,void* data){
	HashNode* n;
	n=(HashNode*) malloc(sizeof(HashNode));
	n->key=(char*) key;
	n->data=data;
	strcpy(n->realKey,key);
	//printf("copied %s %s \n",n->realKey,key);
	return n;
}

int put(HashMap* map,void* key,void* data){
	unsigned char has=*((char*)key);
	HashNode* n;
	n=init_hashnode(key,data);
	//printf("put on %d",has);
	while(1){
		//printf("current %d \n",has);
	if((map->index+has)->data==(void*)NULL){
		//printf("put on here %d ",has);
        *(map->index+has)=*n;
		break;
		}
	if(has==256){
		map->index=(HashNode*)realloc(map->index,sizeof(*map->index)+sizeof(HashNode));
		*(map->index+has)=*n;
		map->capacity=map->capacity+1;
		break;
	}
	has=has+1;
	}

}
void* getValue(HashMap* map,void* key){
	unsigned char has=*((char*)key);

	while(1){
		//printf("current %d \n",has);
		if((map->index+has)->data!=(void*)NULL){
			if(!strcmp((map->index+has)->realKey,(char*)key)){
				//printf("%s same %s \n",(map->index+has)->realKey,(char*)key);
			//if(*(map->index+has)->realKey==*(char*)key){
				return (map->index+has)->data;
				break;
			}
			}
		has=has+1;
		}
return NULL;

}

void removeKey(HashMap* map,void* key){
	unsigned char has=*((char*)key);

	while(1){
		//printf("current %d \n",has);
		if((map->index+has)->data!=(void*)NULL){
			if(!strcmp((map->index+has)->realKey,(char*)key)){
				//printf("%s same %s \n",(map->index+has)->realKey,(char*)key);
			//if(*(map->index+has)->realKey==*(char*)key){
				(map->index+has)->data=(void*)NULL;
				break;
			}
			}
		if((map->capacity)<has){
			break;
		}
		has=has+1;
		}
}
#endif /* HASHMAP_H_ */
