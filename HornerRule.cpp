#include<iostream>
#include<conio.h>
using namespace std;

//Horners rule
int HornerRule(int *a,int n,int x){
	int exp=a[n]*x;
	for(int i=n-1; i>=1; i--){
		exp=(exp+a[i])*x;
	}
	exp=exp+a[0];
	return exp;
}
int main(){
	int  *a,n,x;
	cout<<"\nEnter degree of polynomial: ";
	cin>>n;
	cout<<"\nEnter coefficients of polynomial:\n";
	for(int i=0; i<=n; i++){
		cout<<"a["<<i<<"]=";
		cin>>a[i];
	}
	cout<<"\nEnter the value of x : ";
	cin>>x;
	cout<<"\nThe value of polynomial is: \n"<<HornerRule(a,n,x);
	getch();
}
