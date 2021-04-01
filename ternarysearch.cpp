//ternary search
#include<iostream>
using namespace std;

int ternarysearch(int l,int r,int arr[],int key){
	while(r>=l){
		int mid1=l+(r-l)/3;
		int mid2=r-(r-l)/3;
		
		if(arr[mid1]==key)
		return mid1;
		if(arr[mid2]==key)
		return mid2;
		
		if(key<arr[mid1])
		r=mid1-1;
		else if(key>arr[mid2])
		l=mid2+1;
		else
		{
			l=mid1+1;
			r=mid2-1;
		}
	}
}

int main(){
	int arr[]={1,2,3,4,5,6,7,8,9,10,11,23};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<ternarysearch(0,n-1,arr,10);
}
