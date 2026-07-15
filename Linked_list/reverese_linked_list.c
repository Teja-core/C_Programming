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

///////////  reverse linked list   //////////////////
SLL* reverse_ll(SLL **ptr){
	SLL *prev=NULL;
	SLL* front=NULL;
	SLL * cur=*ptr;
	if(*ptr==NULL || (*ptr)->next==NULL){
		return *ptr;
	}

	while(cur){
		front=cur->next;
		cur->next=prev;
		prev=cur;
		cur=front;
	}
	return prev;
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
void main(){
	SLL *head=0;
	for(int i=0;i<5;i++)
	{
		add_begin(&head,i);
	}
	print_ll(head);
	SLL* head1=NULL;
	head1=reverse_ll(&head);
	print_ll(head1);
}
