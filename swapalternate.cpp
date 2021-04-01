#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct node{
	int data;
	struct node *next;
};

void push(struct node **start,int data){
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->next=*start;
	*start=newnode;
}

void display(struct node *ptr){
	while(ptr!=NULL){
		printf("%d\t",ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
}

void swap(struct node *start){
	int temp;
	if(start==NULL)
		return;
	while(start && start->next!=NULL){
		temp=start->data;
		start->data=start->next->data;
		start->next->data=temp;
		start=start->next->next;
	}
}

int main(){
	int keys[]={1,2,3,4,5,6,7,8};
	int n=sizeof(keys)/sizeof(int);
	struct node *start=NULL;
	for(int i=n-1;i>=0;i--)
		push(&start,keys[i]);
	display(start);
	swap(start);
	display(start);
}
