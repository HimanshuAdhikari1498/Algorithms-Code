//to find all k-grams of a string containing n words
#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
void get_k_gram(char **s,int n,int k){
	for(int i=0; i<n-k+1; i++){
		for(int j=i; j<=i+k-1; j++){
			cout<<s[j]<<" ";
		}
		cout<<" ,";
	}
	cout<<"\b"<<endl;
}
int main(){
	string str;
	cout<<"\nEnter a string to get its n-gram:\n";
	getline(cin,str);
	int countWord=1;
	int stringLength=str.length();
	for(int i=0; i<stringLength; i++){
		if(str[i]==' '){
			countWord++;
		}
	}
	str[stringLength]='\0';
	char **s=new char*[countWord];
	for(int i=0; i<countWord; i++){
		s[i]=new char[25];
	}
	int j=0;
	int k=0;
	for(int i=0; i<=stringLength; i++){
		if(str[i]==' '){
			s[j][k]='\0';
			j++;
			k=0;	
		}else{
			s[j][k]=str[i];
			k++;
		}	
	}
	for(int i=1; i<=countWord; i++){
		cout<<"\n"<<i<<" -gram:\n";
		get_k_gram(s,countWord,i);
	}
	getch();
	
}
