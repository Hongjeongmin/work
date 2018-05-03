#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

int n; //process cnt
int m; // how resource
class Buffer
{
public:
	int *allocation;
	int p_num;
	int lock = 0;
	Buffer()
	{
		allocation = new int[m];
	}
	~Buffer()
	{
		delete[] allocation;
	}


};
class Process
{
public:
	int *max_need;
	int *allocation;
	int lock = 0; // lock = 1 is lock on
	Process()
	{
		max_need = new int[m];
		allocation = new int[m];
	}
	~Process()
	{
		delete[] max_need;
		delete[] allocation;
	}
};

int Safe_or_unsafe(Process *test_process, int *test_system_resource)
{
	for(int i=0;i<m;i++)
		if (test_system_resource[i] < 0) return 1;

	int cnt = 0;
	int cnt_m = 0;
	for (int count = 0; count<n; count++)
	{
		for (int i = 0; i<n; i++)
		{
			if (test_process[i].lock == 0)
			{
				for (int j = 0; j<m; j++)
				{
					if (test_system_resource[j] >= test_process[i].max_need[j] - test_process[i].allocation[j])
						cnt++;
				}
				if (cnt == m)
				{
					
					for (int j = 0; j<m; j++)
					{
						test_system_resource[j] += test_process[i].allocation[j];
						if(test_process[i].allocation[j] > test_process[i].max_need[j]) return 1;
						test_process[i].allocation[j] = 0;

					}
					test_process[i].lock = 1;
					cnt_m++;
				}
				cnt = 0;
			}
		}
	}
	if (cnt_m == n)
	{
		return 0; // is safe
	}
	else
	{
		return 1; //is unsafe
	}
}
//--------------------------main-----------------------------------
int main()
{
	string name; // this is one of request or release or quit11
	ifstream fin;

	fin.open("banker.inp"); // open file	

	fin >> n >> m;

	int *system_resource = new int[m];

	for (int i = 0; i<m; i++)
	{
		fin >> system_resource[i];
	}

	Process *process = new Process[n];

	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<m; j++)
		{
			fin >> process[i].max_need[j];
		}
	}

	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<m; j++)
		{
			fin >> process[i].allocation[j];
		}
	}

	int sum = 0; // individual resource

	for (int i = 0; i<m; i++) // present_system_resource
	{
		for (int j = 0; j<n; j++)
		{
			sum += process[j].allocation[i];
		}

		system_resource[i] -= sum;
		sum = 0;
	}



	//--------------------------------------------------------------

	int p_num;
	int *q_process = new int[m];
	int ignore = 0;
	int *test_system_resource = new int[m];
	int safe_or_unsafe = 0; // 0 is safe, 1 is unsafe
	Buffer buffer[100];
	int buffer_cnt = 0;
	int *test_bsystem_resource = new int[m];
	Process *test_process = new Process[n];
	Process *test_buffer = new Process[n];
	ofstream fout;
	fout.open("banker.out");

	

	while (true)
	{
		fin >> name;
		if (name == "request")
		{

			fin >> p_num;
			for (int i = 0; i<m; i++)
			{
				fin >> q_process[i];
			}

			////////////ok

			for (int i = 0; i<m; i++)
			{
				if (q_process[m] > process[p_num].max_need[m])
				{
					ignore++;
				}
			}
			//////////ok

			if (ignore == 0)//unignore
			{

				//------------------present's process states are stored at the test -------------
				for (int i = 0; i<n; i++)
				{
					for (int j = 0; j<m; j++)
					{
						test_process[i].allocation[j] = process[i].allocation[j];
						test_process[i].max_need[j] = process[i].max_need[j];
					}

					test_process[i].lock = 0;
				}

				for (int i = 0; i<m; i++)
				{
					test_system_resource[i] = system_resource[i];
				}

				//-------------------------------------------------------------------
				for (int i = 0; i<m; i++)
				{
					test_system_resource[i] -= q_process[i];
					test_process[p_num].allocation[i] += q_process[i];
				}

				//---------------safe or unsafe-----------------------------
				safe_or_unsafe = Safe_or_unsafe(&test_process[0], &test_system_resource[0]);

				if (safe_or_unsafe == 1)//is unsafe state ,go Q
				{
					for (int i = 0; i<m; i++)
					{
						buffer[buffer_cnt].allocation[i] = q_process[i];
					}
					buffer[buffer_cnt].p_num = p_num;
					buffer_cnt++;
					for (int i = 0; i<m; i++)
					{
						fout << system_resource[i] << " ";
					}
					fout << endl;
				}
				else//is safe state
				{

					cout << endl;
					for (int i = 0; i<m; i++)
					{
						process[p_num].allocation[i] += q_process[i];
						system_resource[i] -= q_process[i];
						fout << system_resource[i] << " ";
					}
					fout << endl;
				}

			}
			else
			{
				ignore = 0;
			}

		}
		//--------------------------------------------------request end-----------------------------
		//----------------------------------------release----------------------------------------
		else if (name == "release")
		{

			fin >> p_num;
			for (int i = 0; i<m; i++)
			{
				fin >> q_process[i];
			}
			for (int i = 0; i < m; i++)
			{
				if (process[p_num].max_need[i] < q_process[i])
					ignore++;
			}
			if(ignore==0)
			{
				for (int i = 0; i<m; i++)
				{
					process[p_num].allocation[i] -= q_process[i];
					system_resource[i] += q_process[i];
				}
	
				for (int i = 0; i<n; i++)
				{
					for (int j = 0; j<m; j++)
					{
						test_process[i].allocation[j] = process[i].allocation[j];
						test_process[i].max_need[j] = process[i].max_need[j];
					}
	
					test_process[i].lock = 0;
				}
	
				for (int i = 0; i<m; i++)
				{
					test_system_resource[i] = system_resource[i];
				}
				//////////////////////////////////////////////// QÃ³¸®
				for (int q = 0; q<buffer_cnt; q++)
				{
					for (int i = 0; i<n; i++)
					{
						for (int j = 0; j<m; j++)
						{
							test_process[i].allocation[j] = process[i].allocation[j];
							test_process[i].max_need[j] = process[i].max_need[j];
						}
	
						test_process[i].lock = 0;
					}
	
					for (int i = 0; i<m; i++)
					{
						test_system_resource[i] = system_resource[i];
					}
	
					if (buffer[q].lock == 0)
					{
						for (int j = 0; j<m; j++)
						{
							test_process[buffer[q].p_num].allocation[j] += buffer[q].allocation[j];
							test_system_resource[j] -= buffer[q].allocation[j];
						}
	
						safe_or_unsafe = Safe_or_unsafe(&test_process[0], &test_system_resource[0]);
						
						if (safe_or_unsafe == 0)
						{
							buffer[q].lock = 1;
							
							for (int j = 0; j<m; j++)
							{
								process[buffer[q].p_num].allocation[j] += buffer[q].allocation[j];
								system_resource[j] -= buffer[q].allocation[j];
	
							}
							for (int i = 0; i<n; i++)
							{
								for (int j = 0; j<m; j++)
								{
									test_process[i].allocation[j] = process[i].allocation[j];
									test_process[i].max_need[j] = process[i].max_need[j];
								}
	
								test_process[i].lock = 0;
							}
	
							for (int i = 0; i<m; i++)
							{
								test_system_resource[i] = system_resource[i];
							}
	
							
							q = -1;
	
						}
						else
						{
						}
	
					}
				}
				for (int i = 0; i < m; i++)
				{
					fout << system_resource[i] << " ";
				}
				fout << endl;
			}
		}
		//----------------------------------------------------------------------------------
		else if (name == "quit")
		{
			fin.close();
			fout.close();
			break; // quit is break;
		}



	}


}
