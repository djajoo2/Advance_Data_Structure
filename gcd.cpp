#include<stdio.h>

int gcd(int n1,int n2){
	if(n1==n2)
	return n1;
	
	if(n1>n2)
	return gcd(n1-n2,n2);
	
	if(n2>n1)
	return gcd(n1,n2-n1);
}

int main(){
	int n1,n2,l;
	printf("Enter two no : ");
	scanf("%d%d",&n1,&n2);
	l=gcd(n1,n2);
	printf("GCD of %d and %d is %d",n1,n2,l);
}
