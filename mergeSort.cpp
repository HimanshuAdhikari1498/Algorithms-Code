#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
void display(int *a,int n)
{
	cout<<"\n[ ";
	for(int i=0; i<n; i++)
	{
		cout<<a[i]<<", ";
	}
	cout<<"\b\b]";
}

void Merge(int *a,int low,int mid,int high)
{
	int *c;
	c=new int[high-low+1];
	int k=0,i=low,j=mid+1;
	while(i<=mid and j<=high)
	{
		if(a[i]<a[j])
		{
			c[k]=a[i];
			i++;
		}
		else{
			c[k]=a[j];
			j++;
		}
		k++;
	}
	while(i<=mid)
	{
		c[k]=a[i];
		i++;
		k++;
	}
	while(j<=high)
	{
		c[k]=a[j];
		j++;
		k++;
	}
	for(int k=0; k<=high-low; k++)
	{
		a[low+k]=c[k];
	}
//	display(a,high-low+1);
	delete c;
}
void MergeSort(int *a,int low,int high)
{
	if(low<high)
	{
		int mid=floor((low+high)/2);
		MergeSort(a,low,mid);
		MergeSort(a,mid+1,high);
		Merge(a,low,mid,high);
	}
//	display(a,high-low+1);
}
int main()
{
	int d[5]={5,1,0,6,7};
	

	MergeSort(d,0,4);
	display(d,5);
	getch();
	return 0;
}









//
//void merge(int *a,int m,int *b,int n)
//{
//	int *c;
//	c=new int[m+n];
//	int k=0,i=0,j=0;
//	while(i<m and j<n)
//	{
//		if(a[i]<b[j])
//		{
//			c[k]=a[i];
//			i++;
//		}
//		else
//		{
//			c[k]=b[j];
//			j++;
//		}
//		k++;
//	}
//	while(i<m)
//	{
//		c[k]=a[i];
//		i++;
//		k++;
//	}
//	while(j<n)
//	{
//		c[k]=b[j];
//		j++;
//		k++;
//	}
//	display(c,m+n);
//}
