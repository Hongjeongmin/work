#include <iostream>
using namespace std;
int main(void)
{
	int n;
	cin>>n;
	int **p = new int*[n];
	for(int i=0;i<n;i++)
	{
		p[i] = new int[2];
		cin>>p[i][0];
		cin>>p[i][1];
	}
	
	int case12=0,case13=0,case14=0,case15=0,case23=0,case24=0,case25=0,case34=0,case35=0,case45=0;
	
	for(int i=0;i<n;i++)
	{
		if((p[i][0]==1&&p[i][1]==2) || (p[i][0]==2&&p[i][1]==1))
		{
			case12++;
		}
		else if((p[i][0]==1&&p[i][1]==3) || (p[i][0]==3&&p[i][1]==1))
		{
			case13++;
		}
		else if((p[i][0]==1&&p[i][1]==4) || (p[i][0]==4&&p[i][1]==1))
		{
			case14++;
		}
		else if((p[i][0]==1&&p[i][1]==5) || (p[i][0]==5&&p[i][1]==1))
		{
			case15++;
		}
		else if((p[i][0]==2&&p[i][1]==3) || (p[i][0]==3&&p[i][1]==2))
		{
			case23++;
		}
		else if((p[i][0]==2&&p[i][1]==4) || (p[i][0]==4&&p[i][1]==2))
		{
			case24++;
		}
		else if((p[i][0]==2&&p[i][1]==5) || (p[i][0]==5&&p[i][1]==2))
		{
			case25++;
		}
		else if((p[i][0]==3&&p[i][1]==4) || (p[i][0]==4&&p[i][1]==3))
		{
			case34++;
		}
		else if((p[i][0]==3&&p[i][1]==5) || (p[i][0]==5&&p[i][1]==3))
		{
			case35++;
		}
		else if((p[i][0]==4&&p[i][1]==5) || (p[i][0]==5&&p[i][1]==4))
		{
			case45++;
		}																
	}
	
	if((case13==1&&case14==1)||(case13==1&&case34==1)||(case14==1&&case34))
	{
		if(case12==0&&case23==0&&case24==0&&case25==0&&case45==0)
		{
			cout<<"Wa-pa-pa-pa-pa-pa-pow!"<<endl;
		}
		else
		{
			cout<<"Woof-meow-tweet-squeek"<<endl;
		}
	}
	else
	{
		cout<<"Woof-meow-tweet-squeek"<<endl;
	}
	
	
}
