
#include<iostream>
#include<cmath>
#include<ctime>
#include<conio.h>
using namespace std;
int * factorial(int n){
	int length;
	double logvalue=0;
	for(int i=2; i<=n; i++){
		logvalue+=log10(i);
	}
	length=(int)logvalue+1;
	int *fact=new int[length];
	for(int i=0; i<length; i++){
		fact[i]=-1;
	}
	fact[length-1]=1;
	
	for(int i=2; i<=n; i++){
		int j=length-1;
		int carry=0;
		while(fact[j]!=-1){
			int temp=fact[j];
			fact[j]=(fact[j]*i+carry)%10;
			carry=(temp*i+carry)/10;
			j--;
		}
		while(carry>0){
			fact[j]=carry%10;
			carry=carry/10;
			j--;
		}
	}
	return fact;
}
int main(){
	cout<<"\nEnter a number to find its factorial : ";
	int n;
	cin>>n;
	int length;
	double logvalue=0;
	for(int i=2; i<=n; i++){
		logvalue+=log10(i);
	}
	length=(int)logvalue+1;
	int *fact=factorial(n);
	cout<<n<<"!=\n";
	for(int i=0; i<length; i++){
		cout<<fact[i];
	}
	cout<<"\nNo. of digits : "<<length;	
	getch();
}
//int main(){
//	cout<<"\nEnter five big number to find factorial time : "<<endl;
//	int nums[5];
//	int time[5];
//	for(int i=0 ; i<5; i++){
//		cin>>nums[i];
//	}
//	for(int i=0; i<5; i++){
//		long int startTime=clock();
//		factorial(nums[i]);
//		long int endTime=clock();
//		time[i]=(int)((endTime-startTime)/double(CLOCKS_PER_SEC)*1000);//time in milliseconds
//	}
//	cout<<"\n(number, time in ms)\n";
//	for(int i=0; i<5; i++){
//		cout<<"( "<<nums[i]<<" , "<<time[i]<<" )\n";
//	}
//	getch();
//}
