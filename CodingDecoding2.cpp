#include<iostream>
#include<string.h>
#include<conio.h>
using namespace std;

char * Coding(char * s){
	int i=0;
	int j=1;
	while(s[i]!='\0'){
		s[i]=97+(s[i]-96)%26;
		s[j]=122-(123-s[j])%26;
		i=i+2;
		j=j+2;
	}
	return s;
}

int main(){
	char s[50];
	cout<<"\nEnter a Word:\n";
	cin.getline(s,50);
	cout<<"\nEncoded word:\n"<<Coding(s);
//	cout<<"\nDecoded word:\n"<<Decoding(s);
//	cout<<"\nEnter a word:\n";
//	cin.getline(s,50);
	
	getch();
}
