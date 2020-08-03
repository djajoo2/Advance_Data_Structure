#include<stdio.h>

int main(){
	int a[5]={1,2,3,4,5};
	int (*p)[5];
	p=&a;
	printf("%d\t%d\n",a,p);
	printf("%d\t%d\n",a+1,p+1);
}
