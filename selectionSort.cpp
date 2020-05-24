#include<iostream>
#include<conio.h>
using namespace std;
void SelectionSort(int *a,int n){
	for (int i=0; i<n-1; i++){
		int j=i;
		for(int k=i+1; k<n; k++){
			if(a[k]<a[j]){
				j=k;
			}
		}
		if(i!= j){
			int temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
}
void display(int *a,int n){
	cout<<"[";
	for(int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
	cout<<"]\n";
}
int main(){
	int  a[]={3,4,5,6,1,9};
	display(a,6);
	SelectionSort(a,6);
	display(a,6);
	getch();
	
	
}
