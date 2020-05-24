//prim's algorithm to find minimum spanning tree

#include<iostream>
#include<conio.h>
using namespace std;
//prim's algorithm
void Prime(int n,int **W){
	int nearest[n-1];
	int mindist[n-1];
	for(int i=0; i<n-1; i++){
		nearest[i]=1;
		mindist[i]=W[0][i+1];	
	}
	int near;
	cout<<"\nminimum spanning tree edges :\n";
	for(int k=1; k<=n-1; k++){
		int min=INT_MAX;
		for(int i=0; i<n-1; i++){
			if(mindist[i]>=0 and mindist[i]<min){
				min=mindist[i];
				near=i;		
			}	
		}
		cout<<"(v"<<nearest[near]<<",v"<<near+2<<")\t";
		mindist[near]=-1;
		for(int i=0; i<n-1 ;i++){
			if(W[near+1][i+1]<mindist[i]){
				mindist[i]=W[near+1][i+1];
				nearest[i]=near+2;
			}
		}
	}
}
int main(){
	cout<<"\nEnter number of vertices in graph : ";
	int n;
	cin>>n;
	int **W=new int*[n];
	for(int i=0; i<n ;i++){
		W[i]=new int[n];
	}
	
//	int W[5][5]={{0,1,3,1000,1000},{1,0,3,6,1000},{3,3,0,4,2},{1000,6,4,0,5},{1000,1000,2,5,0}};
	cout<<"\nEnter weight between egdes if not(then give 1000):\n";
	for(int i=0; i<n ; i++){
		for(int j=i; j<n ;j++){
			if(i!=j){
			cout<<"\n edge (v"<<i+1<<",v"<<j+1<<"):";
			int weight;
			cin>>weight;
			W[i][j]=W[j][i]=weight;
			}else{
				W[i][j]=0;
			}
		}
	}
	cout<<"\nweighted matrix:\n";
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<W[i][j]<<"\t";
		}
		cout<<endl;
	}
	Prime(n,W);
	getch();
}
