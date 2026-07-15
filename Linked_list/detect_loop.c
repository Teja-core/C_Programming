#include<stdlib.h>
#include<stdio.h>
typedef struct node{
	int data;
	struct node * next;
}SLL;
void add_end(SLL **ptr,int data){
	SLL *temp=malloc(sizeof(SLL));
	if(temp == NULL){
		printf("memory is not allocated...\n");
		return;
	}
	temp->data=data;
	temp->next=NULL;
	if(*ptr == NULL){
		*ptr=temp;
		return;
	}
	SLL *end = *ptr;
	while(end->next){
		end=end->next;
	}
	end->next=temp;
}
void print_ll(SLL *ptr){
	if(ptr == NULL){
		printf("no data is available ...\n");
		return;
	}
	while(ptr){
		printf("%d->",ptr->data);
		ptr=ptr->next;
	}
	printf("NULL\n");
}
int detect_loop(SLL* ptr){
	if(ptr==NULL || ptr->next==NULL)
	{
		printf("no loop detected\n");
		printf("done...\n");
		return 0;
	}
	SLL* slow=ptr;
	SLL* fast=ptr;
	while(fast && fast->next){
		slow=slow->next;
		fast=fast->next->next;
		if(slow ==fast){
			printf("loop is detected..\n");
			return 1;
		}
	}
	printf("no loop is detected...\n");
	printf("in while loop...\n");
	return 0;
}
void main(){
	SLL *head=NULL;
	for(int i=0;i<4;i++)
	{
		add_end(&head,i);
	}
	print_ll(head);
	head->next->next->next->next=head->next;
	detect_loop(head);
}


