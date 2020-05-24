#include<iostream>
#include<conio.h>
#include<cmath>
using namespace std;
char * dec_to_hex(int n){
	int size=floor(log(n)/log(16))+1;
	char * hex =new char[size+1];
	int i=size-1;
	while(n>0){
		if(n%16<10){
			hex[i]=n%16+48;
		}else{
			hex[i]=n%16+55;
		}
		n=n/16;
		i--;
	}
	hex[size]='\0';
	return hex;
}
int main(){
	char *s;
	s=dec_to_hex(9);
	cout<<"\nhex="<<s;
	getch();
	
}




//#include <iostream>
//using namespace std;
//int main() {
//  cout << "Enter number :";
//  long unsigned int a;cin>>a;
//  float i = 0.1;
//  while(1){
//    if(i*i >=a) break;
//    i+=0.00001;
//  }
// 
//  cout<<"sqrt: "<<i;
//}
