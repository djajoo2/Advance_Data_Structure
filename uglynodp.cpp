#include<iostream>
using namespace std;

int Min(int x,int y,int z){
	return (x<y)?(x<z?x:y):(y<z?y:z);
}

int NthUglyNo(int n){
	int arr[n];
	int mul2=2,mul3=3,mul5=5;
	int i2=0,i3=0,i5=0;
	arr[0]=1;
	int next_ugly;
	for(int i=1;i<n;i++){
		next_ugly=Min(mul2,mul3,mul5);
		arr[i]=next_ugly;
		if(next_ugly==mul2){
			i2++;
			mul2=arr[i2]*2;
		}
		if(next_ugly==mul3){
			i3++;
			mul3=arr[i3]*3;
		}
		if(next_ugly==mul5){
			i5++;
			mul5=arr[i5]*5;
		}
	}
	return next_ugly;
}

int main(){
	int n;
	cout<<"Enter Term :";
	cin>>n;
	cout<<NthUglyNo(n);
}
