#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int b;
int stored_end;
int a = 0;
int current_track = 0;
int temp;
int move;
	
class Memory
{
	public:
		int request;
		int track;
		int lock;
		Memory();
};
Memory::Memory()
{
	request = 0;
	track = 0;
	lock = 0;
}

Memory stored[100];
int Track_move_time(int x,int y)
{
	if(x > y)
	{
		return x - y;
	}
	else
	{
		return y - x;
	}
}
void FCFS(ofstream &fout)
{
	
	for(int i =0;i<stored_end;i++)
	{
		if(stored[i].request <= a)
		{
			a = a+Track_move_time(current_track,stored[i].track);
			a = a+b;
			current_track = stored[i].track;
		}
		else
		{
			a = stored[i].request;
			i--;
		}
	}
	cout<<a<<" "<<current_track<<endl;
	fout<<a<<" "<<current_track<<endl;
	fout.close();
	}
void SSTF(ofstream &fout)
{
	int cnt = 0;
	int count = 0;

	while(true)
	{
		temp = 10000;
		count = 0;
		if(cnt == stored_end) break;// ¸Þ¸ð¸®¿¡ ÀÕ´Â°Å ´Ùº½ 
		for(int i=0;i<stored_end;i++)
		{ 
			if(stored[i].lock == 0 && stored[i].request <= a)
			{
				count++;
				if(Track_move_time(current_track,stored[i].track)<temp)
				{
					temp = Track_move_time(current_track,stored[i].track);
					move = i;
				}
			}

		} 
		if(count==0)
		{
			a++;
		}
		else
		{
					stored[move].lock =1;
					a = a + Track_move_time(current_track,stored[move].track);
					a = b + a;
					current_track = stored[move].track;
					cnt++;			
		}
				
		
	
	}
	cout<<a<<" "<<current_track<<endl;
	fout<<a<<" "<<current_track<<endl;
	fout.close();
	
}
void LOOK(ofstream &fout)
{
	int director = 1; // 1 is right , 0 is left
	int count;
	int cnt = 0;
	int pass;
	while(true)
	{
		if(cnt == stored_end) break;
		if(director == 1) //right
		{
		//	cout<<"------>"<<endl;
			pass = 0;
			while(true)
			{
				count = 0;
				for(int i=0;i<stored_end;i++)
				{
					if(stored[i].lock == 0 && stored[i].request <= a && current_track == stored[i].track)
					{
						a = b + a;
						stored[i].lock = 1;
						cnt++;			
						pass++;
						//cout<<"get"<<endl;
						if(cnt == stored_end) break;
					}
				}		
				if(cnt == stored_end) break;		
				for(int i=0;i<stored_end;i++)
				{
					if(stored[i].lock == 0 && stored[i].request <= a && current_track <= stored[i].track)
					{
						count++;
						break;
					}
				}
				if(count != 0 )
				{
					current_track++;
					a++;
					pass++;
				//	cout<<"time: "<<a<<"current_track: "<<current_track<<"pass: "<<pass<<endl;
				}

				else if(pass != 0)
				{
					director = 0;
					break;	
				}	
				else 
				{
				
					a++;
					pass++;
					//cout<<"time: "<<a<<"current_track: "<<current_track<<"pass: "<<pass<<endl;					
				}				
			}
			
		}
		else//left
		{
		//	cout<<"<------"<<endl;
			pass =0;
			while(true)
			{
				count = 0;
				for(int i=0;i<stored_end;i++)
				{
					if(stored[i].lock == 0 && stored[i].request <= a && current_track == stored[i].track)
					{
						a = b + a;
						stored[i].lock = 1;
						cnt++;
						pass++;			
					//	cout<<"get"<<endl;
						if(cnt == stored_end) break;
					}
				}		
				if(cnt == stored_end) break;		
				for(int i=0;i<stored_end;i++)
				{
					if(stored[i].lock == 0 && stored[i].request <= a && current_track >= stored[i].track)
					{
						count++;
						break;
					}
				}
				if(count != 0)
				{
					current_track--;
					a++;
					pass++;
					//cout<<"time: "<<a<<"current_track: "<<current_track<<"pass: "<<pass<<endl;
				}
			
				else if(pass != 0)
				{
					director = 1;
					break;	
				}		
				else 
				{
					
					a++;
					pass++;
					//cout<<"time: "<<time<<"current_track: "<<current_track<<"pass: "<<pass<<endl;					
				}	
						
			}			
		}
		
	}
	cout<<a<<" "<<current_track<<endl;
	fout<<a<<" "<<current_track<<endl;
	fout.close();
}

int main(void)
{	
	string name;
	ifstream fin;
	
	fin.open("disk.inp");
	
	fin>>name;
	fin>>b;
	
	for(int i=0;;i++)
	{
		fin>>stored[i].request;
		fin>>stored[i].track;
		if(stored[i].request == -1 && stored[i].track == -1)
		{
			stored_end = i;
			break;
		}
	}
	fin.close();
	ofstream fout;
	fout.open("disk.out");
	
	if(name == "FCFS")
	{
		FCFS(fout);
	}
	else if(name == "SSTF")
	{
		SSTF(fout);
	}
	else if(name == "LOOK")
	{
		LOOK(fout);
	}
	return 0;
}

