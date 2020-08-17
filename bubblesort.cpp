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

void bubblesort(){
	int f,temp;
	struct node *ptr,*last=NULL;
	do{
		f=0;
		ptr=start;
		while(ptr->next!=last){
			if(ptr->data>ptr->next->data){
				temp=ptr->data;
				ptr->data=ptr->next->data;
				ptr->next->data=temp;
				f=1;
			}
			ptr=ptr->next;
		}
		last=ptr;
	}while(f);
}

int main(){
	printf("\nCreate list");
	createlist();
	printf("\nLinked list is :");
	display();
	bubblesort();
	printf("\nAfter bubble sort list is :");
	display();
	return 0;
}
