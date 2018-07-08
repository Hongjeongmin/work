#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
int b;
int n;
char s1[10];
char s2[10];
string s;
typedef struct Data
{
	int _0=0;
	int _1=0;
	int _2=0;
	int _3=0;
	int _4=0;
	int _5=0;
	int _6=0;
	int _7=0;
	int _8=0;
	int _9=0;	
}data;
data _data;
int Over_lap(int &a, int &b)//1 is overlap
{
	_data._0=0;
	_data._1=0;
	_data._2=0;
	_data._3=0;
	_data._4=0;
	_data._5=0;
	_data._6=0;
	_data._7=0;
	_data._8=0;
	_data._9=0;
	sprintf(s1,"%d",a);
	sprintf(s2,"%d",b);
	s=s1;
	s.append(s2);
	
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='0')
		{
			_data._0++;
			if(_data._0==2) return 1;
		}
		else if(s[i]=='1')
		{
			_data._1++;
			if(_data._1==2) return 1;		
		}
		else if(s[i]=='2')
		{
			_data._2++;
			if(_data._2==2) return 1;		
		}
		else if(s[i]=='3')
		{
			_data._3++;
			if(_data._3==2) return 1;		
		}
		else if(s[i]=='4')
		{
			_data._4++;
			if(_data._4==2) return 1;		
		}
		else if(s[i]=='5')
		{
			_data._5++;
			if(_data._5==2) return 1;			
		}
		else if(s[i]=='6')
		{
			_data._6++;
			if(_data._6==2) return 1;			
		}
		else if(s[i]=='7')
		{
			_data._7++;
			if(_data._7==2) return 1;			
		}
		else if(s[i]=='8')
		{
			_data._8++;
			if(_data._8==2) return 1;		
		}
		else if(s[i]=='9')
		{
			_data._9++;
			if(_data._9==2) return 1;			
		}
										
	}

	return 0;
	
}
int Is_true(int &a)
{
	b = n-a;
	if(Over_lap(a,b) == 1) return 0;
	return 1; // non overlap a 
	
}
int main()
{

	try
	{
		string input;
		int len;
		int output = -1;
		int t;
		cin>>input;
		n = atoi(input.c_str());
		len = input.length();
		if(len>=10) throw n;

		if(n>999999) 
		{
			for(int i=1;i<999999;i++)
			{		
				//cout<<i<<" + "<<n-i<<endl;
				if(Is_true(i) == 1)
				{
					output = b;
					break;
				}
			}			
		}
		else
		{
			for(int i=1;i<n;i++)
			{		
				if(Is_true(i) == 1)
				{
					output = b;
					break;
				}
			}			
		}

		if(output==-1)
		{
			cout<<output<<endl;
		}
		else
		{
			cout<<output<<" + "<<n-output<<endl;
		}			
	}
	catch(int input)
	{
		cout<<"-1"<<endl;
	}
}
