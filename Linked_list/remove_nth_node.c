#include<stdlib.h>
#include<stdio.h>
typedef struct st{
	int data;
	struct st * next;
}node_t;
void add_at_first(node_t **ptr,int data){
	node_t *temp=NULL;
	temp=malloc(sizeof(node_t));
	temp->data=data;
	temp->next=*ptr;
	*ptr=temp;
}
void print_ll(node_t *ptr){
	if(ptr == NULL){
		printf("no data is presented..\n");
		return;
	}
	while(ptr){
		printf("%d->",ptr->data);
		ptr=ptr->next;
	}
	printf("NULL\n");
}

/*********************  move fast pointer n+1 times 
			then move both slow and fast pointer at same time
			untill fast reaches null then slow->next will stop at node to be deleted 
			then we need to delete slow->next node ************/

void remove_nth_node(node_t **ptr,int num){
	if(num<=0 || *ptr==NULL){
		printf("invalid case...\n");
		return;
	}
	node_t dummy;
	dummy.next=*ptr;
	int i=0;
	node_t *slow=&dummy;
	node_t *fast=&dummy;
	for(i=0;i<=num;i++)
	{
		if(fast== NULL){
			printf("invalid position...\n");
			return;
		}
		fast=fast->next;
	}
	while(fast){
		slow=slow->next;
		fast=fast->next;
	}
	node_t *del=slow->next;
	slow->next=slow->next->next;
	free(del);
	*ptr=dummy.next;
}
void main(){
	node_t *head=NULL;
	int i=0,num;
	for(i=0;i<5;i++){
		add_at_first(&head,i);
	}
	print_ll(head);
	printf("enter the number to be deleted from last...\n");
	scanf("%d",&num);
	remove_nth_node(&head,num);
	print_ll(head);
}

