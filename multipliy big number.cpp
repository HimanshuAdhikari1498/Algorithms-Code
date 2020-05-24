#include<iostream>
#include<cstring>
#include<vector>
#include<conio.h>

using namespace std;

//function to multiply a very big number to a number in integer range
//s-multiplicand
//n-multiplier
void Multiply(string s,int n){
	vector<int> num;
	for(int i=0; i<s.length(); i++){
		num.push_back(s[i]-48);
	}
	int carry=0;
	for(int i=num.size()-1; i>=0; i--){
		int temp=num[i];
		num[i]=(num[i]*n+carry)%10;
		carry=(temp*n+carry)/10;
	}
	cout<<s<<"*"<<n<<"=";
	while(carry){
		num.insert(num.begin(),carry%10);
		carry/=10;
	}
	
	for(int i=0; i<num.size(); i++){
		cout<<num[i];
	}
}
void multiply2(string s,int n){
	int num[100];
	int j=99;
	for(int i=s.length()-1; i>=0; i--){
		num[j]=s[i]-48;
		j--;
	}
	int carry=0;
	for(int i=99; i>=100-s.length()-1; i--){
		int temp=num[i];
		num[i]=(num[i]*n+carry)%10;
		carry=(temp*n+carry)/10;
	}
	j=100-s.length()-2;
	while(carry){
		num[j]=carry%10;
		carry/=10;
		j--;
	}
	cout<<"\n"<<s<<"*"<<n<<"=";
	for(int i=j+1; i<=99 ; i++){
		cout<<num[i];
	}
}
int main(){
	string s;
	int n;
	cout<<"\nEnter multiplicand : ";
	cin>>s;
	cout<<"\nEnter multiplier : ";
	cin>>n;
//	multiply2(s,n);
	Multiply(s,n);
	getch();
}
