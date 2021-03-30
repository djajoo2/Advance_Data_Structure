// print the ugly number
#include<iostream>
using namespace std;

int isUgly(int n){
	while(n%2==0)
	n=n/2;
	while(n%3==0)
	n=n/3;
	while(n%5==0)
	n=n/5;
	if(n==1)
	return 1;
	else
	return 0;
}

int main(){
	int n;
	cout<<"Enter Term : ";
	cin>>n;
	int count=1;
	int i=1;
	while(count<n){
		i++;
		if(isUgly(i)){
			count++;
		}
	}
	cout<<i;
}
