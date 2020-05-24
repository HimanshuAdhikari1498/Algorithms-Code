//truth table  of n bits
#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
void print(char *a,int n){
	cout<<"[";
	for(int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
	cout<<"]\n";
}
void PrintTruthTable(int n){
	int k;
	int  countif=0;
	int countwhile=0;
	char *a=new char[n];
	for(int i=0; i<n; i++){
		a[i]='F';
	}	
	print(a,n);
	for(int i=1; i<=pow(2,n)-1; i++){
		int j=n-1;
		k=i;
		while( k!=0){
			countwhile++;
			if(k%2==1){
				countif++;
				a[j]='T';
			}else{
				a[j]='F';
			}
			j--;
			k=k/2;
		}
		print(a,n);
	}
	cout<<"count if="<<countif<<"\ncount while="<<countwhile;
}
int main(){
	int n;
	cout<<"\nEnter value of no. of binary bits to print its truth table: \n";
	cin>>n;
	PrintTruthTable(n);
}

