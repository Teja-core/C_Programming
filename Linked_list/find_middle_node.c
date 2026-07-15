#include<stdlib.h>
#include<stdio.h>

///////   typedef structure  ////////////////////
typedef struct node{
	int data;
	struct node * next;
}SLL;

///////////     add nodes at beginning   //////////////
void add_begin(SLL **ptr,int data){
	SLL *temp;
	temp=malloc(sizeof(SLL));
	if(temp == NULL){
		printf("memory allocation is failed...\n");
		return;
	}
	temp->data=data;
	temp->next=*ptr;
	*ptr=temp;
}

//////////////////////  print linked list  ///////////////////////

void print_ll(SLL *temp){
	if(temp==NULL){
		printf("no data is available...\n");
		return;
	}
	while(temp){
		printf("%d->",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
}
void find_middle(SLL *ptr){
	if(ptr==NULL){
		printf("there is no middle node..\n");
		return;
	}
	SLL *slow=ptr;
	SLL *fast=ptr;
	while(fast && fast->next)
	{
		slow=slow->next;
		fast=fast->next->next;
	}
	printf("the middle nod is %d \n",slow->data);

}
void main(){
	SLL *head=0;
	for(int i=0;i<5;i++)
	{
		add_begin(&head,i);
	}
	print_ll(head);
	find_middle(head);
}
