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

int findoccurence(int *a,int n,int e,int i){
	int low=0,high=n-1,mid,result=-1;
	while(low<=high){
		mid=(low+high)/2;
		if(a[mid]==e){
			result=mid;
			if(i==1)
				high=mid-1;
			else
				low=mid+1;
		}
		else if(e>a[mid]){
			low=mid+1;
		}
		else{
			high=mid-1;
		}
	}
	return result;
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
	int first=findoccurence(a,n,e,1);
	int last=findoccurence(a,n,e,2);
	if(first==-1)
		printf("\nElement not found");
	else
		printf("First occurence is %d and last occurence is %d",first,last);
}
