//kruskal algorithm to find minimum spanning tree

#include<iostream>
#include<map>
#include<iterator>
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
};

//map E (weight, vertices)
//map(key,value)
//map is by default sorted with its keys;
void Kruskal(int n,int m,map<int,int> E){
	int i,j;
	int p,q;
	DisjointSet D;
	D.makeSet(n);
	map<int, int>::iterator itr;
	int edges=0;
	itr=E.begin();
	while(edges<n-1){
		i=(itr->second)/10;
		j=(itr->second)%10;
		p=D.find(i);
		q=D.find(j);
		if(D.equal(p,q)==false){
			D.merge(p,q);
			edges++;
			cout<<"(v"<<i<<" ,v"<<j<<"), ";
		}
		++itr;
	}
	cout<<"\b\b";
}
int main(){
	cout<<"\nEnter number of vertices : ";
	int n;
	cin>>n;
	map<int,int> E;
	int w;  //for each weight
	int e;	//for edge indecs
	int m;  //no of edges
	cout<<"\nEnter edges weights : (if not then give -1 ) :\n";
	for(int i=1; i<=n; i++){
		for(int j=i+1; j<=n; j++){
			cout<<"\nedge (v"<<i<<",v"<<j<<"):";
			cin>>w;
			if(w!=-1){
				e=i*10+j;
				E.insert(pair<int,int>(w,e));
				w++;
			}
		}
	}
	cout<<"\nThe minimum spanning tree with edges is : ";
	Kruskal(n,m,E);
	getch();
	
}
