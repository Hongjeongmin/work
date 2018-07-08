#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	string s;
	cin>>s;
	int i;
	int cnt=0;
	
	for(i=0;i<s.length();i++)
	{
		if(s[i]=='p')
		{
			i++;
			if(s[i]!='i')
			{
				cout<<"NO"<<endl;
				cnt++;
				break;
			}
		}
		else if(s[i]=='k')
		{
			i++;
			if(s[i]!='a')
			{
				cout<<"NO"<<endl;
				cnt++;
				break;
			}
		}
		else if(s[i]=='c')
		{
			i++;
			if(s[i]=='h')
			{
				i++;
				if(s[i]!='u')
				{
					cout<<"NO"<<endl;
					cnt++;
					break;
				}
			}
			else
			{
				cout<<"NO"<<endl;
				cnt++;
				break;
			}
		}
		else
		{
			cout<<"NO"<<endl;
			cnt++;
			break;
		}
	}
	if(cnt==0)
	{
		cout<<"YES"<<endl;
	}
}
