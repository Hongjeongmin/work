#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

void E(string input,int e_start,int e_end);
void F(string input,int f_start,int f_end);
void T(string input,int t_start,int t_end);
void D(char c);
void N(string input);

int main()
{
	int e_start = 0;
	int e_end = 0;
	int input_len;
	string input;
	
	cin >> input;
	
	e_end = input.length()-1;
	
	E(input,e_start,e_end);
	cout<<"It's a clear"<<endl;
	
}

void E(string input,int e_start,int e_end)
{
	//cout<<"E call"<<endl;
	int count=0;
	int t_start = e_start;
	int t_end;
		if(input[e_start]=='+')
	{
		cout<<"error"<<endl;
		exit(1);
	}
	else if(input[e_end]=='+')
	{
		cout<<"error"<<endl;
		exit(1); 
	}
	
	for(int i = e_start;i<=e_end;i++)
	{

		if(input[i]=='+')
		{
			t_end = i-1;
			T(input,t_start,t_end);
			t_start = i+1;
		}
		else if(input[i]=='(')
		{
			for(int j = i+1;j<=e_end;j++)
			{
				if(input[j]=='(')
				{
					count ++;
				}
				else if(input[j]==')')
				{
					if(count==0)
					{
						i=j;
						count=0;
						break;
					}
					count --;
				}
			}
		}

	}
	T(input,t_start,e_end);
}
void T(string input,int t_start,int t_end)
{
	//cout<<"T call"<<endl; 
	int count = 0;
	int f_start = t_start;
	int f_end; 
	if(input[t_start]=='*')
	{
		cout<<"error"<<endl;
		exit(1); 
	}
	else if(input[t_end]=='*')
	{
		cout<<"error"<<endl;
		exit(1);
	}
	
	for(int i = t_start;i<=t_end;i++)
	{

		if(input[i]=='*')
		{
			f_end = i-1;
			F(input,f_start,f_end);
			f_start = i+1;
		}
		else if(input[i]=='(')
		{
			for(int j = i+1;j<=t_end;j++)
			{
				if(input[j]=='(')
				{
					count ++;
				}
				else if(input[j]==')')
				{
					if(count==0)
					{
						i=j;
						count=0;
						break;
					}
					count --;
				}
			}
		}
	}
	F(input,f_start,t_end);
}
void F(string input,int f_start, int f_end)
{
	//cout<<"F call"<<endl;
	string input_f;
	string c;
	if(input[f_start]=='(')
	{
		E(input,f_start+1,f_end-1);
	}
	else if(input[f_start]==')')
	{
		cout<<"error"<<endl;
		exit(1); 
	}
	else
	{
		for(int i = f_start;i<=f_end;i++)
		{
			c = input[i];
			input_f.append(c);
		}
		N(input_f);
		
	}
}
void N(string input)
{
	//cout<<"N call"<<endl;
	
	int len = input.length();
	if(len == 0)
	{
		cout<<"error"<<endl;
		exit(1);
	}
	
	for(int i=0;i<len;i++)
	{
		D(input[i]);
	}
}
void D(char c)
{
	//cout<<"D call"<<endl;
	if(isdigit(c) == true)
	{
		return;
	}
	else
	{
		cout<<"error"<<endl;
		exit(1);
	}
}
