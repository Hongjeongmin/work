#include<iostream>
using namespace std;
//15667
int main()
{
	int k,n;
	cin>>n;
	
	k = 1;
	while(true)
	{
		if(1+k+k*k==n)
		break;
		k++;
	}
	cout<<k;
	
	
}
