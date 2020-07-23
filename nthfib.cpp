#include<stdio.h>

int fib(int n){
	if(n==1)
	return 0;
	if(n==2)
	return 1;
	return fib(n-1)+fib(n-2);
}
int main(){
	int n;
	printf("Enter the value of n : ");
	scanf("%d",&n);
	printf("The nth term is %d",fib(n));
}
