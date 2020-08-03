#include<stdio.h>
#include<limits.h>

void input(int *a,int n){
	int i;
	for(i=0;i<n;i++)
	scanf("%d",(a+i));
}


void display(int *a,int n){
	int i;
	for(i=0;i<n;i++)
	printf("%d\t",a[i]);
}

void linearsearch(int *a,int n,int e){
	int i,f=0;
	for(i=0;i<n;i++){
		if(a[i]==e){
			f=1;
		}
	}
	if(f==1)
	printf("\nElement found");
	else
	printf("\nElement not found");
}

int main(){
	int a[20],n,e;
	printf("Enter no of elements :");
	scanf("%d",&n);
	printf("\nEnter Elements :");
	input(a,n);
	display(a,n);
	printf("\nEnter Element to search :");
	scanf("%d",&e);
	linearsearch(a,n,e);
}
