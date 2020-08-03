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

void secondlargest(int *a,int n){
	int i,max=a[0],smax=INT_MIN;
	for(i=1;i<n;i++){
		if(max<a[i]){
			smax=max;
			max=a[i];
		}
		else if(smax<a[i]){
			smax=a[i];
		}
	}
	printf("\nSecond largest is %d",smax);
}

int main(){
	int a[20],n;
	printf("Enter no of elements :");
	scanf("%d",&n);
	printf("\nEnter Elements :");
	input(a,n);
	display(a,n);
	secondlargest(a,n);
}
