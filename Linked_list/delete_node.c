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
void del_at_first(node_t **ptr){
	if(*ptr == NULL){
		printf("ther is no node to delete...\n");
		return;
	}
	node_t *del=*ptr;
	*ptr=(*ptr)->next;
	free(del);
}
void del_at_last(node_t **ptr){
	if(*ptr == NULL){
		printf("thers is no node to be delete...\n");
		return;
	}
	node_t * last=*ptr;
	node_t *del=NULL;
	while(last->next->next){
		last=last->next;
	}
	del=last->next;
	last->next=NULL;
	free(del);
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
void del_at_pos(node_t **ptr, int pos){
	if(pos<=0 || (*ptr == NULL))			//handling invalid position
	{
		printf("invalid pos...\n");
		return;
	}
	node_t *del;
	if(pos ==1){					//handling deleting at first position
		del=*ptr;				//special case handling
		*ptr=(*ptr)->next;
		free(del);
		return;
	}
	int i=1;
	node_t *temp=*ptr;
	for(i=1;i<pos-1 &&temp !=NULL ;i++)		//traverse to previous node to be deleted
	{
		temp=temp->next;
	}
	if(temp ==NULL || temp->next == NULL){		//range checking
		printf("pos is out of range...\n");
		return;
	}
	del=temp->next;
	temp->next=del->next;			//del node
	free(del);
}
void main(){
	node_t *head=NULL;
	int i=0,num;
	for(i=0;i<5;i++){
		add_at_first(&head,i);
	}
	print_ll(head);
	del_at_first(&head);
	print_ll(head);
	del_at_last(&head);
	print_ll(head);
	int n;
	printf("enter the pos to be del...\n");
	scanf("%d",&n);
	del_at_pos(&head,n);
	print_ll(head);
}

