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

int binarysearch(int *a,int n,int e){
	int i,low=0,high=n-1,mid;
	while(low<=high){
		mid=(low+high)/2;
		if(a[mid]==e){
			return mid;
		}
		else if(mid+1<=high && a[mid+1]==e){
			return mid+1;
		}
		if(mid-1>=low && a[mid-1]==e){
			return mid-1;
		}
		else if(e>a[mid]){
			low=mid+2;
		}
		else{
			high=mid-2;
		}
	}
	return -1;
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
	//only for sorted array
	int f=binarysearch(a,n,e);
	if(f==-1)
		printf("\nElement not found");
	else
		printf("\nElement Found");
}
