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

int binarysearch(int *a,int low,int high,int e){
	if(low>high)
		return 0;
	
	int mid=(low+high)/2;
	
	if(a[mid]==e)
		return 1;
	else if(a[mid]<e)
		binarysearch(a,mid+1,high,e);
	else
		binarysearch(a,low,mid-1,e);
}

int main(){
	int a[20],n,e,f;
	printf("Enter no of elements :");
	scanf("%d",&n);
	printf("\nEnter Elements :");
	input(a,n);
	display(a,n);
	printf("\nEnter Element to search :");
	scanf("%d",&e);
	//only for sorted array
	f=binarysearch(a,0,n-1,e);
	if(f)
		printf("\nElement Found");
	else
		printf("\nElement Not found");
}
