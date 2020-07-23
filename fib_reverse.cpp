#include<stdio.h>

int fib(int n){
	if(n==1)
	return 0;
	if(n==2)
	return 1;
	return fib(n-1)+fib(n-2);
}

void terms(int n){
	if(n==0)
	return;
	printf("%d\t",fib(n));
	terms(n-1);
}

int main(){
	int n;
	printf("Enter the value of n : ");
	scanf("%d",&n);
	terms(n);
}
