#include<iostream>
#include<cmath>
#include<conio.h>
//to square root of a number
using namespace std;
double Sqrt(int n){
	double g1= n/2.0,g2;
	
	while(true){
		cout<<"g1="<<g1<<endl;
		g2=(g1+n/g1)/2.0;
		cout<<"g2="<<g2<<endl;
		if(abs(g1-g2)<0.0000001){
			break;
		}
		g1=g2;
	}
	return g2;
}
int main(){
//	for(int i=2;i<=20; i++){
//		cout<<i<<"   "<<Sqrt(i)<<"   "<<sqrt(i)<<"\n";
//	}
//	cout<<Sqrt(20)<<endl;
	cout<<Sqrt(64000);
	getch();
}









//#include <iostream>
//using namespace std;
//int main() {
//  cout << "Enter number :";
//  long unsigned int a;cin>>a;
//  
//  int e =1;
//  while(e*e < a){
//    e++;
//  }
//  float i = --e;
//  while(1){
//    if(i*i >=a) break;
//    i+=0.00001;
//  }
// 
//  cout<<"sqrt: "<<i;
//}
