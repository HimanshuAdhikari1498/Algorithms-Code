#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<ctime>
using namespace std;
//divide and conquer approach
unsigned long long Bin1(int n,int k){
	if(k==0 or k==n){
		return 1;
	}else{
		return Bin1(n-1,k-1)+Bin1(n-1,k);
	}
}
//dynamic programming by storing coeff. into memory of 2d array
unsigned long long  Bin2(int n,int k){
	unsigned long long int B[n+1][k+1];
	for(int i=0; i<=n; i++){
		for(int j=0; j<=min(i,k); j++){
			if(j==0 or j==i){
				B[i][j]=1;
			}else{
				B[i][j]=B[i-1][j-1]+B[i-1][j];
			}
		}
	}
	return B[n][k];
}
//dynamic prog by storing coeff. in the 1d array
unsigned long long Bin3(int n,int k){
	unsigned long long B[k+1];
	for(int i=0; i<=n; i++){
		for(int j=min(i,k); j>=0; j--){
			if(j==0 or j==i){
				B[j]=1;
			}else{
				B[j]=B[j]+B[j-1];
			}
		}
	}
	return B[k];
}
int min(int i,int j){
	return (i<j?i:j);
}
int main(){
	long int startTime;
	long int stopTime;
	long int startTime2;
	long int stopTime2;
	long int startTime3;
	long int stopTime3;
	cout<<"\nCalculate Binary coeffienct nCk:"<<endl;
	cout<<"\nEnter n and k : ";
	int  n,k;
	cin>>n>>k;
	//bin1
	cout<<"\ndivide and conquer method (recursive)";
	startTime=clock();
//	cout<<"\n"<<n<<"C"<<k<<"="<<Bin1(n,k)<<endl;
	stopTime=clock();
	cout<<"\nTime elapsed ( in milliseconds): "<<(stopTime-startTime)/double(CLOCKS_PER_SEC)*1000<<endl; //time in milliseconds 
	cout<<"\nTime elapsed (in nanoseconds): "<<(stopTime-startTime)/double(CLOCKS_PER_SEC)*1000*1000000<<endl;//nanoseconds
	//bin2
	cout<<"\nDynamic prog using 2d array storage";
	startTime2=clock();
	cout<<"\n"<<n<<"C"<<k<<"="<<Bin2(n,k)<<endl;
	stopTime2=clock();
	cout<<"\nTime elapsed ( in milliseconds): "<<(stopTime2-startTime2)/double(CLOCKS_PER_SEC)*1000<<endl; //time in milliseconds 
	cout<<"\nTime elapsed (in nanoseconds): "<<(stopTime2-startTime2)/double(CLOCKS_PER_SEC)*1000*1000000<<endl;//nanoseconds
	//bin3
	cout<<"\nDynamic prog using 1d array storage";
	startTime3=clock();
	cout<<"\n"<<n<<"C"<<k<<"="<<Bin3(n,k)<<endl;
	stopTime3=clock();
	cout<<"\nTime elapsed ( in milliseconds): "<<(stopTime3-startTime3)/double(CLOCKS_PER_SEC)*1000<<endl; //time in milliseconds 
	cout<<"\nTime elapsed (in nanoseconds): "<<(stopTime3-startTime3)/double(CLOCKS_PER_SEC)*1000*1000000<<endl;//nanoseconds
	
	getch();
}
