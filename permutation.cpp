//to find all possible permutation of a set of characters
#include<iostream>
#include<conio.h>
using namespace std;
void print(char *a,int n){
	cout<<"[";
	for(int i=0; i<n; i++){
		cout<<a[i];
	}
	cout<<"]	";
}
void permutation(char *a,int k,int n){
	if(k==n){
		print(a,n);
	}
	char temp;
	for(int i=k; i<n; i++){
		temp=a[i];
		a[i]=a[k];
		a[k]=temp;
		permutation(a,k+1,n);
		temp=a[i];
		a[i]=a[k];
		a[k]=temp;
	}
}

int main(){
	char *a;
	int n;
	cout<<"\nEnter numbers of elements of set A:";
	cin>>n;
	cout<<"\nEnter elements of set A:\n";
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	cout<<"\nthe permutation of set A is:\n";
	permutation(a,0,n);
	getch();
	
}
