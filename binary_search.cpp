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

void binarysearch(int *a,int n,int e){
	int i,low=0,high=n-1,mid,f=0;
	while(low<=high){
		mid=(low+high)/2;
		if(a[mid]==e){
			f=1;
			break;
		}
		else if(e>a[mid]){
			low=mid+1;
		}
		else{
			high=mid-1;
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
	//only for sorted array
	binarysearch(a,n,e);
}
