#include<stdio.h>

int main(){
	int a[5]={1,2,3,4,5};
	int *p[]={a,a+1,a+2,a+3,a+4};
	int i;
	for(i=0;i<5;i++){
		printf("%d\t%d\t%d\t%d\n",a+i,*(p+i),*(a+i),**(p+i));
	}
}
