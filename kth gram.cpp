#include<iostream>
#include<conio.h>
#include<cstring>
#include<string.h>
using namespace std;
// kth gram of a string of n word
void get_k_gram(string s[],int n,int k){
	for(int i=0; i<n-k+1; i++){
		for(int j=i; j<=i+k-1; j++){
			cout<<s[j]<<" ";
		}
		cout<<", ";
	}
	cout<<"\b\b";
}
int main(){
	string s[7]={"Jamia","Millia","Islamia","is","a","central","University"};
//	cout<<s[0];
	get_k_gram(s,7,3);
	getch();
	
}
