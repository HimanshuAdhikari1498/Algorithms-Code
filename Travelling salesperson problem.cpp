#include<iostream>
#include<conio.h>
#include<math.h>
#include<cmath>
using namespace std;
class TravelSalesperson {
	int **P;
	int **D;
	int **A;
	int **W;
	int n;
	int pow2n;
	public:
		TravelSalesperson(){
			cout<<"\nEnter number of vertices : ";
			cin>>n;
			P=new int*[n];
			W=new int*[n];
			for(int i=0; i<n ;i++){
				P[i]=new int[n];
				W[i]=new int[n];
			}
			pow2n=pow(2,n-1);
			D=new int*[n];
			for(int i=0; i<n; i++){
				D[i]=new int[pow2n];
			}
			A=new int*[pow2n];
			for(int i=0; i<pow2n; i++){
				A[i]=new int[n-1];
			}
			cout<<"\nenter values of weighted matrix(enter 10000 for infinity) : \n";
			for(int i=0; i<n ; i++){
				for(int j=0; j<n ;j++){
					if(i==j){
						W[i][j]=0;
					}else{
						cout<<"\nweight between v"<<i+1<<" and v"<<j+1<<":";
						cin>>W[i][j];
					}	
				}
			}
			for(int i=0; i<pow2n; i++){
				for(int j=0; j<n-1; j++){
					A[i][j]=0;
				}
			}
			for(int i=0; i<n; i++){
				for(int j=0; j<pow2n; j++){
					D[i][j]=0;
				}
			}
			for(int i=0; i<n; i++){
				for(int j=0; j<n ; j++){
					P[i][j]=0;
				}
			}
		}
		
		int Travel(){
			GenerateA();
			for(int i=1; i<=n-1; i++){
				D[i][0]=W[i][0];
			}
			for(int k=1; k<=n-2; k++){ 
				for(int l=0; l<C(n-1,k); l++){
					for(int i=1; i<=n-1; i++){
						
						int *subset=new int[C(n-1,k)];
						subset=getSubsets(k);
						int row=subset[l];
						if(A[row][i-1]==0){
							int *indexj=new int[k];
							indexj=getindexJ(row,k);
							int firstindex=indexj[0];
							int min=W[i][firstindex]+D[firstindex][map(indexj,firstindex,k)];
							P[i][row]=firstindex;
							for(int m=2; m<=k; m++){
								int j=indexj[m-1];
								if(min>(W[i][j]+D[j][map(indexj,j,k)])){
									min=W[i][j]+D[j][map(indexj,j,k)];
									P[i][row]=j;
								}
							}
							D[i][row]=min;
						}
					}
				}
			}
			int k=3;
			int l=C(n-1,k)-1;
			int *subset=new int[C(n-1,k)];
			subset=getSubsets(k);
			int *indexj=new int[k];
			int row=subset[l];
			indexj=getindexJ(row,k);
			
			int min=W[0][1]+D[1][map(indexj,1,k)];
			P[0][(pow2n-1)]=1;
			for(int j=2; j<n; j++){
				if(min>W[0][j]+D[j][map(indexj,j,k)]){
					min=W[0][j]+D[j][map(indexj,j,k)];
					P[0][(pow2n-1)]=j;
				}
			}
			D[0][(pow2n-1)]=min;
			return min;
		}
		//for generating matrix A with its index = bin expansion in n-1 bits
		void GenerateA(){
			int k;
			for(int i=0; i<n-1; i++){
				A[0][i]=0;
			}	
			for(int i=1; i<pow2n; i++){
				int j=n-2;
				k=i;
				while( k!=0){
					if(k%2==1){
						A[i][j]=1;
					}else{
						A[i][j]=0;
					}
					j--;
					k=k/2;
				}
			}
			
		}
		//to map from vertex to index of A
		int map(int indexj[],int j,int k){
			if(k==1){
				return 0;
			}
			int bin=0;
			int binArray[n-1];
			for(int i=0; i<n-1; i++){
				binArray[i]=0;
			}
			for(int i=0; i<k; i++){
				if(indexj[i]!=j){
					int index=indexj[i]-1;
					binArray[index]=1;
				}	
			}
			int p=1;
			for(int i=n-2; i>=0; i--){
				bin=bin+binArray[i]*p;
				p=p*10;
			}
//			cout<<"\nmap="<<bintodec(bin);
			return bintodec(bin);
		}
		//to get index of A for each subset which element is present 
		int * getindexJ(int subset,int k){
			int *a=new int[k];
			int j=0;
			for(int i=0; i<n-1; i++){
				if(A[subset][i]==1){
					a[j]=i+1;
					j++;
				}
			}
			return a;
		}
		//to get index value of A of subsets having k elements
		int * getSubsets(int k){
			int bin;
			int j=0;
			int *m=new int[C(n-1,k)];
			for (int  i=1; i<pow2n; i++){
				bin=dectobin(i);
				if(CountOne(bin)==k){
					m[j]=i;
					j++;
				}	
			}
			return m;
		}
		//conversion from dec to bin
		int dectobin(int n){
			int bin=0;
			int p=1;
			while(n){
				bin=bin+n%2*p;
				p=p*10;
				n=n/2;
			}
			return bin;
		}
		//conversion from bin to dec
		int bintodec(int bin){
			int dec=0;
			int i=0;
			while(bin){
				dec=dec+(bin%10)*pow(2,i);
				bin=bin/10;
				i++;
			}
			return dec;
		}
		//Combination nCk
		int C(int n,int k){
			return (fact(n)/(fact(n-k)*fact(k)));
		}
		//factorial function
		int fact (int n){
			int fat=1;
			for(int i=2; i<=n; i++ ){
				fat=fat*i;
			}
			return fat;
		}
		//counts number of ones present in binary number
		int CountOne(int n){
			int count=0;
			while(n){
				if(n%10==1){
					count++;
				}
				n=n/10;
			}
			return count;
		}
		
		void displayW(){
			cout<<"\nWeighted matrix is : \n";
			for(int i=0; i<n ; i++){
				for(int j=0; j<n; j++){
						cout<<W[i][j]<<"\t";	
				}
				cout<<endl;
			}
		}
		void displayD(){
			cout<<"\nD matrix is : \n";
			for(int i=0; i<n ; i++){
				for(int j=0; j<pow2n; j++){
						cout<<D[i][j]<<"\t";	
				}
				cout<<endl;
			}
		}
		
};



	

int main(){
	TravelSalesperson T;
	T.displayW();
	cout<<"\nmin path length="<<T.Travel();
//	T.displayD();
//	cout<<"\nPath: ";
//	T.getPath(0,3);
//	cout<<"->v1";
	getch();	
}
