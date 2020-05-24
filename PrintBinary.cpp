//to print all possible binary numbers in n - bits
#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;

//function to find binary representation of a decimal number n
long int Binary(int n){
	long int bin=0;
	int p=1;
	while(n){
		if(n%2==1)
			bin=bin+p;
		p=p*10;
		n=n/2;
	}
	return bin;
}
void print(int *a,int n){
//	cout<<"";
	for(int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
	cout<<"\n";
}

//factorial function
int fact(int n){
	int fact=1;
	for(int i=1; i<=n; i++){
		fact=fact*n;
	}
	return fact;
}


//function to find all possible binary representation of n bits
void permutation(int n){
	int a[n];
	for(int i=0; i<n; i++){
		a[i]=0;
	}
	print(a,n);	
	for(int i=1; i<=pow(2,n)-1; i++){
		if(a[n-1]==0){
			a[n-1]=1;
			print(a,n);
		}
		else{
			a[n-1]=0;
			for(int j=n-2; j>=0; j--){
				if(a[j]==1){
					a[j]=0;
				}
				else{
					a[j]=1;
					print(a,n);
					break;
				}
			}
			
		}
	}

}

int main(){
	cout<<Binary(8)<<"\n";
	permutation(3);
	getch();
}
