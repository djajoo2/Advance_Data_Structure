#include<stdio.h>

int lcm(int n1,int n2,int max){
	if(max%n1==0 && max%n2==0)
	return max;
	
	return lcm(n1,n2,max+n1);
}

int main(){
	int n1,n2,l;
	printf("Enter two No. : ");
	scanf("%d%d",&n1,&n2);
	if(n1>n2)
	l=lcm(n1,n2,n1);
	if(n2>n1)
	l=lcm(n2,n1,n2);
	printf("LCM of %d and %d is %d",n1,n2,l);
}
