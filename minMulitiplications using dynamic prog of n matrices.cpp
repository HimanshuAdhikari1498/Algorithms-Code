#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<ctime>
//minimum number of multiplications required to multiply n number of matrices
//and to get the optimal order in which these are to be multiplied
using namespace std;
int minimumMul(int d[],int **P ,int n){
	int M[n+1][n+1];
	for(int i=1; i<=n; i++){
		M[i][i]=0;
	}
	for(int diagonal=1; diagonal<n; diagonal++){
		for(int i=1; i<=n-diagonal; i++){
			int j=i+diagonal;
			M[i][j]=M[i][i]+M[i+1][j]+d[i-1]*d[i]*d[j];
			P[i][j]=i;
			for(int k=i+1; k<=j-1; k++){
				if((M[i][k]+M[k+1][j]+d[i-1]*d[k]*d[j])<M[i][j]){
					M[i][j]=M[i][k]+M[k+1][j]+d[i-1]*d[k]*d[j];
					P[i][j]=k;
				}
			}
		}
	}
	return M[1][n];
}
void order(int i,int j,int **P){
	if(i==j){
		cout<<"A"<<i;
	}else{
		int k=P[i][j];
		cout<<"(";
		order(i,k,P);
		order(k+1,j,P);
		cout<<")";
	}
}
int main(){
	int n;
	int *d;
	cout<<"\nEnter number of matrices : ";
	cin>>n;
	d=new int[n+1];
	cout<<"\nEnter the order of matrices : "<<endl;
	for(int i=0; i<n; i++){
		cout<<"\nEnter r"<<i+1<<":";
		cin>>d[i];
	}
	cout<<"\nEnter c"<<n<<":";
	cin>>d[n];
	int **P=new int*[n+1];
	for(int i=0; i<=n; i++){
		P[i]=new int[n+1];
	}
	cout<<"\nMinimum no of multiplications:"<<minimumMul(d,P,n);
	cout<<"\nOptimal order for multiplications of "<<n<<" matrices : \n";
	order(1,n,P);
	getch();
	
}
