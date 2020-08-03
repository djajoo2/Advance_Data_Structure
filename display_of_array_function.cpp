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

int main(){
	int a[20],n;
	printf("Enter no of elements :");
	scanf("%d",&n);
	printf("\nEnter Elements :");
	input(a,n);
	display(a,n);
}
