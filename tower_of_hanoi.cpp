#include<stdio.h>

void Towerofhanoi(int n,char from,char dest,char aux){
	if(n==1){
		printf("Move disk 1 from %c to %c\n",from,dest);
		return;
	}
	Towerofhanoi(n-1,from,aux,dest);
	printf("Move disk %d from %c to %c\n",n,from,dest);
	Towerofhanoi(n-1,aux,dest,from);
}

int main(){
	int n;
	printf("Enter no of disk :");
	scanf("%d",&n);
	Towerofhanoi(n,'A','C','B');
}
