#include<iostream>
#include<vector>
#include<conio.h>
using namespace std;
class DisjointSet{
	int *u;
	public:
	void makeSet(int n){
		u=new int[n];
		for(int i=0; i<n; i++){
			u[i]=i+1;		//initially it creates all disjoint sets
		}
	}
	int find(int i){
		int j=i;
		while(u[j-1]!=j){
			j=u[j-1];
		}
		return j;
	}
	
	//p=find(element) q=find(2nd element)
	void merge(int p,int q){        
		if(p<q){
			u[q-1]=p;
		}else{
			u[p-1]=q;
		}
	}
	bool equal(int p,int q){
		if(p==q)
			return true;
		else
			return false;
	}
	void displaySets(int n){
		vector<vector<int> > sets(n);
		
		for(int i=1; i<=n; i++){
			int index=find(i)-1;
			sets[index].push_back(i);
		}
		for(int i=0; i<sets.size(); i++){
			if(sets[i].size()>0){
				cout<<"{";
				for(int j=0; j<sets[i].size(); j++){
					cout<<sets[i][j]<<", ";
				}
				cout<<"\b\b},";
			}
			
		}
	}
};
int main(){
	while(1){
		cout<<"\n1.make set\t2.find\t3.merge(p,q)\t4.isequal(p,q)\t5.displaySets\t6.exit\nSelect option:";
		int opt;
		cin>>opt;
		DisjointSet D;
		int n,x,y,z;
		switch(opt){
			case 1:
				cout<<"\nEnter number of elements : ";
				cin>>n;
				D.makeSet(n);
				break;
			case 2:
				cout<<"\nEnter the elemet to find its root : ";
				cin>>x;
				cout<<"\nIt belongs to set having root node : "<<D.find(x);
				break;
			case 3:
				cout<<"\nEnter two elemets to merge their sets if belongs to diff sets : ";
				cin>>y>>z;
				D.merge(D.find(y),D.find(z));
				break;
			case 4:
				cout<<"\nEnter two elemets to find that they belongs to same set or not : ";
				cin>>y>>z;
				cout<<D.equal(D.find(y),D.find(z));
				break;
			case 5:
				cout<<"\nDisaply all sets : "<<endl;
				D.displaySets(n);
				break;
			case 6:
				exit(0);
			default:
				cout<<"\ntry again! please !"<<endl;				
		}
	}
	getch();
}
