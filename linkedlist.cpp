#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node {
	int data;
	struct node *next;
}*start=NULL;

void createlist(){
	char ch;
	struct node *newnode,*current;
	do{
		newnode=(struct node *)malloc(sizeof(struct node));
		if(newnode==NULL){
			printf("\nMemory error");
			break;
		}
		printf("\nEnter data : ");
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		if(start==NULL){
			start=newnode;
		}
		else{
			current->next=newnode;
		}
		current=newnode;
		printf("\nEnter more data(y/n) : ");
		ch=getche();
		printf("\n");
	}while(ch!='n');
}

void display(){
	struct node *ptr;
	ptr=start;
	while(ptr!=NULL){
		printf("%d\t",ptr->data);
		ptr=ptr->next;
	}
}

void deallocation(){
	struct node *ptr;
	if(start==NULL)
		return;

	while(start){
		ptr=start;
		start=start->next;
		ptr->next=NULL;
		free(ptr);
	}
}

struct node *Newnode(int x){
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	if(newnode==NULL){
		return NULL;
	}
	newnode->data=x;
	newnode->next=NULL;
	return newnode;
}

void insertion_at_first(){
	int x;
	struct node *newnode;
	printf("\nEnter data : ");
	scanf("%d",&x);
	newnode=Newnode(x);
	if(newnode==NULL){
		printf("\nMemory error");
		return;
	}
	newnode->next=start;
	start=newnode;
}

void insertion_at_last(){
	int x;
	struct node *newnode,*ptr;
	printf("\nEnter data : ");
	scanf("%d",&x);
	newnode=Newnode(x);
	if(newnode==NULL){
		printf("\nMemory error");
		return;
	}
	if(start==NULL){
		start=newnode;
		return;
	}
	ptr=start;
	while(ptr->next!=NULL){
		ptr=ptr->next;
	}
	ptr->next=newnode;
}

void insertion_before_given_data(){
	int x,y;
	struct node *newnode,*ptr;
	printf("\nEnter data : ");
	scanf("%d",&x);
	printf("\nEnter data before which data add : ");
	scanf("%d",&y);
	if(start==NULL){
		printf("\nInsertion not possible");
		return;
	}
	if(start->data==y){
		newnode=Newnode(x);
		if(newnode==NULL){
			printf("\nMemory error");
			return;
		}
		newnode->next=start;
		start=newnode;
		return;
	}
	ptr=start;
	while(ptr!=NULL && ptr->next->data!=y){
		ptr=ptr->next;
	}
	if(ptr==NULL){
		printf("\nInsertion not possible");
		return;
	}
	newnode=Newnode(x);
	if(newnode==NULL){
		printf("\nMemory error");
		return;
	}
	newnode->next=ptr->next;
	ptr->next=newnode;
}

void insertion_after_given_data(){
	int x,y;
	struct node *newnode,*ptr;
	printf("\nEnter data : ");
	scanf("%d",&x);
	printf("\nEnter data before which data add : ");
	scanf("%d",&y);
	if(start==NULL){
		printf("\nInsertion not possible");
		return;
	}
	ptr=start;
	while(ptr!=NULL && ptr->data!=y){
		ptr=ptr->next;
	}
	if(ptr==NULL){
		printf("\nInsertion not possible");
		return;
	}
	newnode=Newnode(x);
	if(newnode==NULL){
		printf("\nMemory error");
		return;
	}
	newnode->next=ptr->next;
	ptr->next=newnode;
}

void deletion_at_first(){
	struct node *ptr;
	if(start==NULL){
		printf("\nDeletion not possible");
		return;
	}
	ptr=start;
	start=start->next;
	ptr->next=NULL;
	free(ptr);
}

void deletion_at_last(){
	struct node *ptr,*prev;
	if(start==NULL){
		printf("\nDeletion not possible");
		return;
	}
	if(start->next==NULL){
		free(start);
		start=NULL;
		return;
	}
	ptr=start;
	while(ptr->next!=NULL){
		prev=ptr;
		ptr=ptr->next;
	}
	prev->next=NULL;
	free(ptr);
}

void deletion_according_given_data(){
	int x;
	struct node *ptr,*prev;
	printf("\nEnter data to delete :");
	scanf("%d",&x);
	if(start==NULL){
		printf("\nDeletion not possible");
		return;
	}
	if(start->data==x){
		ptr=start;
		start=start->next;
		ptr->next=NULL;
		free(ptr);
		return;
	}
	prev=ptr=start;
	while(ptr!=NULL && ptr->data!=x){
		prev=ptr;
		ptr=ptr->next;
	}
	if(ptr==NULL){
		printf("\nDeletion not posible");
		return;
	}
	prev->next=ptr->next;
	ptr->next=NULL;
	free(ptr);
}

int main(){
	int choice;
	printf("\nCreate list");
	createlist();
	printf("\nLinked list is :");
	display();
	do{
		printf("\n1. Insert at first\n2. Insert at last\n3. Insert after given node\n4. Insert before given node\n5. Deletion at first\n6. Deletion at last\n7. Delete a particular data\n8. Display\n9. Deallocation\n10. Exit");
		printf("\nEnter choice :");
		scanf("%d",&choice);
		switch(choice){
		case 1:insertion_at_first();
			break;
		case 2:insertion_at_last();
			break;
		case 3:insertion_after_given_data();
			break;
		case 4:insertion_before_given_data();
			break;
		case 5:deletion_at_first();
			break;
		case 6:deletion_at_last();
			break;
		case 7:deletion_according_given_data();
			break;
		case 8:display();
			break;
		case 9:deallocation();
			break;	
		case 10:exit(0);
			break;
	}
	}while(choice!=10);
}
