#include<stdio.h>

int prime(int n,int i){
	if(i==1)
	return 1;
	
	if(n%i==0)
	return 0;
	
	return prime(n,i-1);
	
}

int main(){
	int n,l;
	printf("Enter the value of n : ");
	scanf("%d",&n);
	if(prime(n,n/2)){
		printf("Prime No");
	}
	else{
		printf("Not a Prime No");
	}
}
