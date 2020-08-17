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

void detectloop(){
	struct node *ptr1=start,*ptr2=start;
	while(1){
		ptr1=ptr1->next;
		ptr2=ptr2->next->next;
		if(ptr1==NULL || ptr2==NULL){
			printf("\nNo cycle");
			break;
		}
		if(ptr1==ptr2){
			printf("\nCycle present");
			break;
		}
	}
}

int main(){
	printf("\nCreate list");
	createlist();
	printf("\nLinked list is :");
	display();
	detectloop();
	return 0;
}
