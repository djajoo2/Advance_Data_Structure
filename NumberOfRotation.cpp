#include<stdio.h>

int NumberOfRotation(int *a,int n)
{
	int low=0,high=n-1;
	while(low<=high){
		if(a[low]<=a[high])
			return low;
		int mid=(low+high)/2;
		int next=(mid+1)%n;
		int prev=(mid-1+n)%n;
		
		if(a[mid]<=a[prev] && a[mid]<=a[next])
			return mid;
		
		else if(a[mid]<=a[high])
			high=mid-1;
		else if(a[mid]>=a[low])
			low=mid+1;
	}
	return -1;
}

int main(){
	int a[]={8,9,10,18,2,5,6};
	int n=sizeof(a)/sizeof(a[0]);
	int f=NumberOfRotation(a,n);
	printf("%d rotation to sort circular array",f);
	
}
