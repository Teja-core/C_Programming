#include<stdlib.h>
#include<stdio.h>
typedef struct st{
	int data;
	struct st * next;
}node_t;
void add_end(node_t **ptr,int data){
	node_t *temp;
	temp=malloc(sizeof(node_t));
	temp->data=data;
	temp->next=NULL;
	if(*ptr== NULL){
		*ptr=temp;
		return;
	}
	node_t *t=*ptr;
	while(t->next){
		t=t->next;
	}
	t->next=temp;
	
}
void print_ll(node_t *ptr){
	if(ptr == NULL)
	{
		printf("ther is no data ..\n");
		return;
	}
	while(ptr)
	{
		printf("%d->",ptr->data);
		ptr=ptr->next;
	}
	printf("NULL\n");
}
void remove_link(node_t **ptr){
	if(*ptr == NULL || (*ptr)->next ==NULL)
	{
		printf("no loop in linked list...\n");
		return;
	}

	node_t *slow=*ptr, *fast=*ptr;
	while(fast && fast->next)
	{
		slow=slow->next;
		fast=fast->next->next;
		if(slow == fast){
			printf("there is loop in linked lis...\n");
			break;
		}
	}
	if(fast == NULL || fast->next == NULL)
	{
		printf("no loop is detected...\n");
		return;
	}
	if(slow ==fast){
		slow =*ptr;
		node_t *prev=NULL;
		while(slow != fast)
		{
			slow=slow->next;
			fast=fast->next;
			prev=slow;
		}
		if(slow == fast){
		printf("the loop is starting at %d\n",slow->data);
		prev->next=NULL;
		printf("loop is removed succesfully...\n");
		return;
		}

	}
	printf("there is no loop detected in linke dlist ...\n");
}


void  main(){
	node_t *head;
	int i=0;
	for(i=0;i<5;i++){
	add_end(&head,i);
	}
	//print_ll(head);
	head->next->next->next->next=head->next->next;
	remove_link(&head);
	print_ll(head);
}

