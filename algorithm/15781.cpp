#include <iostream>
using namespace std;
int main()
{
	int n;
	int m;
	cin>>n;
	cin>>m;
	int *h = new int[n];
	int *a = new int[m];
	for(int i=0;i<n;i++)
	{
		cin>>h[i];
	}
	for(int i=0;i<m;i++)
	{
		cin>>a[i];
	}
	
	int max_a=0;
	int max_h=0;
	
	for(int i=0;i<n;i++)
	{
		if(max_h<h[i])
		{
			max_h=h[i];
		}
	}
	for(int i=0;i<m;i++)
	{
		if(max_a<a[i])
		{
			max_a=a[i];
		}
	}
	
	cout<<max_a+max_h<<endl; 
}
