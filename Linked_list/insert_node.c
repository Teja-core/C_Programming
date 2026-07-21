#include<stdlib.h>
#include<stdio.h>
typedef struct st{
	int data;
	struct st * next;
}node_t;
void add_at_first(node_t **ptr,int data){
	node_t *new;
	new=malloc(sizeof(node_t));
	if(new == NULL){
		printf("memory is not allocated...\n");
		return;
	}
	new->data=data;
	new->next=*ptr;
	*ptr=new;
}
void add_at_last(node_t **ptr,int data){
	node_t *new;
	new=malloc(sizeof(node_t));
	if(new ==NULL){
		printf("memory is not allocated..\n");
		return;
	}
	new->data=data;
	new->next=NULL;
	if(*ptr == NULL){			        	//check whether head is null or having data
		*ptr=new;
		return;
	}
	node_t *t=*ptr;
	while(t->next){						//find last node
		t=t->next;
	}
	t->next=new;						//update last node to newly created node
}

void add_at_position(node_t **ptr, int data, int pos){
	if(pos <=0){									//check valid position it should greater than zero	
		printf("invalid position...\n");
		return;
	}
	if(pos ==1 ){									//if inserting at head position
		add_at_first(ptr,data);
		return;
	}
	int i=0;
	node_t *temp=*ptr;
	for(i=1;i<pos-1 && temp!=NULL;i++)						//rotate loop untill one step before postion where we will insert newly created node 
	{
		temp=temp->next;
	}
	if(temp == NULL){							// check for reached last of linked list or not
		printf("pos os out of range...\n");
		return;
	}										//allocate memory for new node
	node_t *new;
	new=malloc(sizeof(node_t));
	if(new==NULL){
		printf("memory allocation is failed...\n");
		return;
	}
	new->data=data;
	new->next=temp->next;							//insert new node 
	temp->next=new;
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

void main(){
	node_t *head=NULL;
	int i=0,num;
	for(i=0;i<5;i++){
		add_at_first(&head,i);
	}
	print_ll(head);
	for(i=0;i<5;i++){
		add_at_last(&head,i);
	}
	print_ll(head);
	int n,data;
	printf("enter the pos and data to be insrted...\n");
	scanf("%d%d",&n,&data);
	add_at_position(&head,data,n);
	print_ll(head);
}

