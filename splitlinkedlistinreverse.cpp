#include<iostream>
using namespace std;

struct node{
	int data;
	struct node *next;
};

void push(struct node **start,int data){
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->next=*start;
	*start=newnode;	 
}

void movenode(struct node **destref,struct node **sourceref){
	if(*sourceref==NULL){
		return;
	}
	struct node *newnode=*sourceref;
	*sourceref=(*sourceref)->next;	
	newnode->next=*destref;
	*destref=newnode;
}

void split(struct node *start,struct node **a,struct node **b){
	struct node *current=start,*t1=NULL,*t2=NULL;
	while(current!=NULL){
		movenode(&t1,&current);
		
		if(current!=NULL)
		movenode(&t2,&current);
	}
	*a=t1;
	*b=t2;
}

void display(struct node *ptr){
	while(ptr!=NULL){
		printf("%d\t",ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
}

int main(){
	int keys[]={1,2,3,4,5,6,7};
	int n=sizeof(keys)/sizeof(keys[0]);
	struct node *start=NULL;
	for(int i=n-1;i>=0;i--)
		push(&start,keys[i]);
	struct node *a=NULL,*b=NULL;
	split(start,&a,&b);	
	display(a);
	display(b);
	return 0;
}
