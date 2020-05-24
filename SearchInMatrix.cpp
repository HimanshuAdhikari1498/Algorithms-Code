#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;
//to search an element in a sorted matrix 
class Matrix{
	int n;
	int **a;
	public:
	Matrix(){
		cout<<"\nEnter the order of the square matrix : ";
		cin>>n;
		a=new int*[n];
		for(int i=0; i<n; i++){
			a[i]=new int[n];
		}
	}
	void generateMatrix(){
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cout<<"\nEnter a["<<i+1<<","<<j+1<<"]=";
				cin>>a[i][j];
			}
		}
	}
	void display(){
		cout<<endl;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cout<<a[i][j]<<"\t";
			}
			cout<<endl;
		}
	}
	int * SearchInMatrix(int x){
		int *index=new int[2];
		index[0]=-1;
		index[1]=-1;
		if(x<a[0][0] or x>a[n-1][n-1]){
			cout<<"\nElement does not exist!";
			return index;
		}
		int i=0;
		int j=n-1;
		while(i<=n-1 and j>=0){
			if(x==a[i][j]){
				index[0]=i;
				index[1]=j;
				return index;
			}else if(x>a[i][j]){
				i++;
			}else{
				j--;
			}
		}
		return index;
	}
};
int main(){
	Matrix m;
	int *index=new int[2];
	cout<<"\nEnter the elements of sorted matrix : "<<endl;
	m.generateMatrix();
	m.display();
	char ans;
	do{
		cout<<"\nEnter a value to search in the matrix : ";
		int x;
		cin>>x;
		index=m.SearchInMatrix(x);
		if(index[0]==-1){
			cout<<"\nElement not exist in the matrix";
		}else{
			cout<<x<<" is at the position : rowNo ="<<index[0]+1<<" colNo = "<<index[1]+1<<endl;
		}
		cout<<"\nDo you want to search more ? y or n : ";
		cin>>ans;
	}while(ans=='y' or ans=='Y');
	getch();
}



//int * SearchInMatrix(int **a,int n,int x){
//	int *index=new int[2];
//	index[0]=-1;
//	index[1]=-1;
//	if(x<a[0][0] or x>a[n-1][n-1]){
//		cout<<"\nElement does not exist!";
//		return;
//	}
//	int i=0;
//	int j=n-1;
//	while(i<=n-1 and j>=0){
//		if(x==a[i][j]){
//			index[0]=i;
//			index[1]=j;
//			return index;
//		}else if(x>a[i][j]){
//			i++;
//		}else{
//			j--;
//		}
//	}
//	return index;
//}
