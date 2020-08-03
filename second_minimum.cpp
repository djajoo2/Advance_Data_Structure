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

void secondminimum(int *a,int n){
	int i,min=a[0],smin=INT_MAX;
	for(i=1;i<n;i++){
		if(min>a[i]){
			smin=min;
			min=a[i];
		}
		else if(smin>a[i]){
			smin=a[i];
		}
	}
	printf("\nSecond mimimum is %d",smin);
}

int main(){
	int a[20],n;
	printf("Enter no of elements :");
	scanf("%d",&n);
	printf("\nEnter Elements :");
	input(a,n);
	display(a,n);
	secondminimum(a,n);
}
