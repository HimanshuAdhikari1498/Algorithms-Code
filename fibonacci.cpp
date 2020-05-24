#include<iostream>
#include<conio.h>
using namespace std;
long long int fibonacii_iterative(long int  n){
	long long int f1=1,f2=1;
	while(n>2){
		long int temp=f2;
		f2=f2+f1;
		f1=temp;
		n--;
	}
	return f2;
}
long long int fibonacii_rec(long int n){
	if(n==1 || n==2){
		return 1;
	}else{
		return fibonacii_rec(n-1)+fibonacii_rec(n-2);
	}
}
int main(){
	long int n;
	cout<<"\nEnter a number to find all fibonacii numbers between 1 to that no.:";
	cin>>n;
	int i=3;
	long long int fib=fibonacii_rec(i);
	while(fib<n){
		cout<<fib<<", ";
		i++;
		fib=fibonacii_rec(i);
	}
	cout<<"\b\b";
	getch();
}
