#include <iostream>
using namespace std;
int main()
{
	int n;
	int k_num;
	cin>>n;
	cin>>k_num;
	int *k = new int[k_num];
	for(int i=0;i<k_num;i++)
	{
		cin>>k[i];
	}
	
	for(int i=0;i<k_num;i++)
	{
		int m=1;
		int cnt=0;
		while(true)
		{
			if(m<=k[i])
			{
				m = m+2;
				cnt++;
			}
			else
			{
				break;
			}
		}
		k[i]=cnt;
	}
	for(int i=0;i<k_num;i++)
	{
		n=n-k[i];
		if(n<=0)
		{
			cout<<"YES"<<endl;
			break;
		}
	}
	if(n>0)
	{
		cout<<"NO"<<endl;
	}
}
