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
int count_nodes(node_t *ptr){
	int count=0;
	while(ptr){
		count++;
		ptr=ptr->next;
	}
	return count;
}
void main(){
	node_t *head=NULL;
	int i=0;
#if 1
	for(i=0;i<5;i++){
		add_at_first(&head,i);
	}
#endif
	print_ll(head);
	printf("no.of nodes is %d\n",count_nodes(head));
}

