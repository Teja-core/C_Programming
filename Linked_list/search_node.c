#include<stdio.h>
#include<stdlib.h>
typedef struct st{
	int data;
	struct st * next;
}node_t;
void add_at_first(node_t **ptr,int data){
	node_t *new;
	new=malloc(sizeof(node_t));
	if(new == NULL){
		printf("memory allocation is failed...\n");
		return;
	}
	new->data=data;
	new->next=*ptr;
	*ptr=new;
}
void print_ll(node_t *ptr){
	if(ptr == NULL){
		printf("no dat is available...\n");
		return;
	}
	while(ptr){
		printf("%d->",ptr->data);
		ptr=ptr->next;
	}
	printf("NULL\n");
}
node_t* search_node(node_t *ptr,int data){
	if(ptr == NULL){
		printf("no data available to search...\n");
		return NULL;
	}
	while(ptr){
		if(ptr->data == data){
			return ptr;
		}
		ptr=ptr->next;
	}
	return NULL;
}
void main(){
	node_t *head=NULL;
	int i=0;
	for(i=0;i<5;i++)
		add_at_first(&head,i);
	print_ll(head);
	int n;
	printf("enter the numbe rto be searched...\n");
	scanf("%d",&n);
	node_t *find=search_node(head,n);
	if(find == NULL){
		printf("number is not found..\n");
	}
	else{
		printf("the number is found at %d\n",find->data);
	}
}
