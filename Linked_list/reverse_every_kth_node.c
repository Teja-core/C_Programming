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
void reverse_kth(node_t **ptr,int k){
	node_t dummy;
	dummy.next=*ptr;
	int i=0;
	node_t *prevGroup=&dummy;
	while(1){
		node_t * kth=prevGroup;
		for(i=0;i<k && kth;i++)
		{
			kth=kth->next;
		}
		if(kth == NULL){
			break;
		}
		printf("kth element is %d\n",kth->data);
		node_t *nextGroup=kth->next;

		node_t *prev=nextGroup;
		node_t *curr=prevGroup->next;

		while(curr !=nextGroup){
			node_t *temp=curr->next;
			curr->next=prev;
			prev=curr;
			curr=temp;
		}

		node_t *temp=prevGroup->next;
		prevGroup->next=kth;
		prevGroup=temp;
	}
	*ptr= dummy.next;
}
void main(){
	node_t *head=NULL;
	int i=0;
	for(i=1;i<7;i++)
		add_at_first(&head,i);
	print_ll(head);
	reverse_kth(&head,3);
	print_ll(head);
}
