#include<iostream>
#include<cstring>
#include<conio.h>
using namespace std;

char * Coding(char * s){
	int i=0;
	int j=1;
	while(s[i]!='\0'){
		if(s[i]=='z' || s[i]=='Z'){
			s[i]=s[i]-25;
		}else{
			s[i]=s[i]+1;
		}
		if(s[j]=='a' || s[j]=='A'){
			s[j]=s[j]+25;
		}else{
			s[j]=s[j]-1;	
		}
		i=i+2;
		j=j+2;
	}
	return s;
}
char * Decoding(char * s){
	int i=0;
	int j=1;
	while(s[i]!='\0'){
		if(s[i]=='a' || s[i]=='A'){
			s[i]=s[i]+25;
		}else{
			s[i]=s[i]-1;
		}
		if(s[j]=='z' || s[j]=='Z'){
			s[j]=s[j]-25;
		}else{
			s[j]=s[j]+1;	
		}
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
	cout<<"\nDecoded word:\n"<<Decoding(s);
	getch();
}
