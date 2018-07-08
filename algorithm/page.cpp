#include <iostream>
#include <fstream>
using namespace std;
int initial=0;
class Memory 
{
	public:
		Memory();
		int num;
		int pid;
		int page;
		int time;
		int lock;
		Memory *front;
		Memory *next;
};

Memory::Memory()
{
	num = 0;
	pid = 0;
	page = 0;
	time = 0;
	lock = 0;
	front = NULL;
	next = NULL;
}
typedef struct _L
{
	Memory *head;
}Memory_l;
Memory memory[10000];
Memory stored[10000];
void view(Memory_l &L)
{
	Memory *p;
	p = L.head;
	
	while(p != NULL)
	{
	//	cout<<p->num<<" "<<p->pid<<" "<<p->page<<endl;
		p = p->next;
	}
	cout<<endl;
}

void Add_m(Memory_l &L,int &i,int &num)// head를 잘받아야함 
{
	Memory *p;
	p = L.head;
	if(L.head == NULL)
	{
		L.head = &memory[initial];
		memory[initial].num = num;
		memory[initial].pid = stored[i].pid;
		memory[initial].page = stored[i].page; 
		memory[initial].time = i;
		initial++;
	}
	else
	{
		while(true)
		{
			if(p->next == NULL)
			{
				p->next = &memory[initial];
				memory[initial].num = num;
				memory[initial].pid = stored[i].pid;
				memory[initial].page = stored[i].page;
				memory[initial].time = i;
				initial++;
				break;
			}
			p = p->next;
		}
		
	}
}
///////////////////////////////////////////////
void FIFO(int &n,int &stored_end,ofstream &fout)
{
	Memory_l L;
	L.head = NULL;
	Memory *p;
	int page_fault = 0;
	int count;
	int num = 0;
	int time;
	int fault_num;
	for(int i=0;i<stored_end;i++)
	{
		p = L.head;
		count = 0;
		while(p !=NULL)
		{
			if(stored[i].pid == p->pid)
			{
				count ++;
			}
			if(count == n) break;
			p = p->next;
		}
		if(count == n) // page_fault or non page_fault
		{
			count = 0;
			// trade algorithm
			p = L.head;
			while(p != NULL)
			{
				if(p->pid == stored[i].pid && p->page == stored[i].page)
				{
					count++;
					break;
				}
				p = p->next;
			}
			if(count == 0)			
			 {
			 	page_fault++;
				p = L.head;
				time = 5001;
				count = 0;
				while(p != NULL)
				{
					if(stored[i].pid == p->pid)
				{
					if(time>p->time)
					{
						time = p->time;
					}
					count ++;
				}
				if(count == n) break;
				p = p->next;
				}
				p = L.head;
				while(p != NULL)
				{
					if(time == p->time)
					{
						p->pid = stored[i].pid;
						p->page = stored[i].page;
						p->time = i;

				//		cout<<"page_fault"<<endl;
				//		cout<<"지금 들어오는 놈: "<<stored[i].pid<<" "<<stored[i].page<<endl;
				//		view(L);
						break;
					}
					p = p->next;
				}
				
						 	
			 }
			 else //3개이면서 이미있을때 
			 {
			//	cout<<"Non page_fault"<<endl;
			//	cout<<"지금 들어오는 놈: "<<stored[i].pid<<" "<<stored[i].page<<endl;
			//	view(L);		 	
			 }

		}
		else//3개 이하 
		{
			p = L.head;
			count = 0;
			while(p != NULL)
			{
			
				if(stored[i].pid == p->pid && stored[i].page == p->page)
				{
					count ++;
				//	p->time = i;
				}
				if(count == 1) break;
				p = p->next;
			}
			if(count == 0)
			{
			
		//		cout<<"page_fault"<<endl;
		//		cout<<"지금 들어오는 놈: "<<stored[i].pid<<" "<<stored[i].page<<endl;
				Add_m(L,i,num);
				page_fault ++;
				num++;
			//	view(L);		
			}	
		}
		
	}
	
	fout<<"FIFO: "<<page_fault<<endl;
	p = L.head;
	
	while(p != NULL)
	{
		fout<<p->num<<" "<<p->pid<<" "<<p->page<<endl;
		//cout<<p->num<<" "<<p->pid<<" "<<p->page<<endl;
		p = p->next;
	}

	
	
}
////////////////////////////////////////////////
void LRU(int &n,int &stored_end,ofstream &fout)
{
	Memory_l L;
	L.head = NULL;
	Memory *p;
	int page_fault = 0;
	int count;
	int num = 0;
	int time;
	int fault_num;
	for(int i=0;i<stored_end;i++)
	{
		p = L.head;
		count = 0;
		while(p !=NULL)
		{
			if(stored[i].pid == p->pid)
			{
				count ++;
			}
			if(count == n) break;
			p = p->next;
		}
		if(count == n) // page_fault or non page_fault
		{
			count = 0;
			// trade algorithm
			p = L.head;
			while(p != NULL)
			{
				if(p->pid == stored[i].pid && p->page == stored[i].page)
				{
					p->time = i;
					count++;
					break;
				}
				p = p->next;
			}
			if(count == 0)// what is change at 3 over state			
			 {
			 	page_fault++;
				p = L.head;
				time = 5001;
				count = 0;
				while(p != NULL)
				{
					if(stored[i].pid == p->pid)
				{
					if(time>p->time)
					{
						time = p->time;
					}
					count ++;
				}
				if(count == n) break;
				p = p->next;
				}
				p = L.head;
				while(p != NULL)
				{
					if(time == p->time)
					{
						p->pid = stored[i].pid;
						p->page = stored[i].page;
						p->time = i;

					//	cout<<"page_fault"<<endl;
					//	cout<<"지금 들어오는 놈: "<<stored[i].pid<<" "<<stored[i].page<<endl;
						//view(L);
						break;
					}
					p = p->next;
				}
			 }
			 else //3개이면서 이미있을때 
			 {
			//	cout<<"Non page_fault"<<endl;
			//	cout<<"지금 들어오는 놈: "<<stored[i].pid<<" "<<stored[i].page<<endl;
			//	view(L);		 	
			 }

		}
		else//3개 이하 
		{
			p = L.head;
			count = 0;
			while(p != NULL)
			{
			
				if(stored[i].pid == p->pid && stored[i].page == p->page)
				{
					p->time = i;
					count ++;
				}
				if(count == 1) break;
				p = p->next;
			}
			if(count == 0)
			{
			
			//	cout<<"page_fault"<<endl;
			//	cout<<"지금 들어오는 놈: "<<stored[i].pid<<" "<<stored[i].page<<endl;
				Add_m(L,i,num);
				page_fault ++;
				num++;
			//	view(L);		
			}	
		}
		
	}
	
	fout<<"LRU: "<<page_fault<<endl;
	p = L.head;
	
	while(p != NULL)
	{
		fout<<p->num<<" "<<p->pid<<" "<<p->page<<endl;
	//	cout<<p->num<<" "<<p->pid<<" "<<p->page<<endl;
		p = p->next;
	}
}
/////////////////////////////////////////////////////////
void OPT(int &n,int &stored_end,ofstream &fout)
{
	Memory_l L;
	L.head = NULL;
	Memory *p;
	int page_fault = 0;
	int count;
	int num = 0;
	int time;
	int fault_num;
	for(int i=0;i<stored_end;i++)
	{
		p = L.head;
		count = 0;
		while(p !=NULL)
		{
			if(stored[i].pid == p->pid)
			{
				count ++;
			}
			if(count == n) break;
			p = p->next;
		}
		if(count == n) // page_fault or non page_fault
		{
		//	cout<<"case1"<<endl;
			count = 0;
			// trade algorithm
			p = L.head;
			while(p != NULL)
			{
				//cout<<"case2"<<endl;
				if(p->pid == stored[i].pid && p->page == stored[i].page)
				{
					//p->time = i;
					count++;
					break;
				}
				p = p->next;
			}
			if(count == 0)//what is change at 3 over state			
			{
			 //	cout<<"case3"<<endl;
			 	page_fault++;
			 	//cout<<"page_fault"<<endl;
			 	p = L.head;
			 	while(p != NULL)
			 	{
			 		//cout<<"case4"<<endl;
			 		p->lock = 0;
					p = p->next;	
				}
				count = 0;
			 	for(int j = i+1;j<stored_end;j++)
			 	{
			 		//cout<<"case5"<<endl;
			 		
			 		if(stored[i].pid == stored[j].pid)
					{
						//cout<<"case6"<<endl;
						p = L.head;
						while(p != NULL)
						{
							//cout<<"case7"<<endl;
							if(p->pid == stored[j].pid && p->page == stored[j].page)
							{
								//cout<<"case8"<<endl;
								if(p->lock == 0)
								{
									//cout<<"case9"<<endl;
									count++;
									p->lock = 1;
									//if(count != n-1) break;
								}
							}
							if(count == n-1) break;
							p = p->next;
						} 	
					}
					if(count == n-1) break;	
				}
				//cout<<"count : "<<count<<endl;
				//cout<<"case10"<<endl;
				if(count == n-1)
				{				
					p = L.head;
					while(p !=NULL)
					{
						//cout<<"case11"<<endl;
						if(p->pid == stored[i].pid)
						{
							//cout<<"case12"<<endl;
							if(p->lock == 0)
							{
								//cout<<"case13"<<endl;
								p->page = stored[i].page;
								p->time = i;
								
								//cout<<"지금 들어오는놈 "<<stored[i].pid<<" "<<stored[i].page<<endl;
								//view(L);
								break;
							}
						}
						p = p->next;
					}
				}
				else
				{
					/*
					p = L.head;
					cout<<"lock들어가기전"<<endl;
					while(p != NULL)
					{
						if(p->pid == stored[i].pid && p->lock == 0)
						{
							p->page = stored[i].page;
							p->time = i;
							cout<<"lock통과"<<endl;
							cout<<"지금 들어오는 놈: "<<stored[i].pid<<" "<<stored[i].page<<endl;									
							view(L);
							break;								
						}
						p = p->next;
					}
					*/
					
					time = 10000;
					p = L.head;
					
					while(p != NULL)
					{
						if(p->pid == stored[i].pid && p->lock == 0)
						{
							if(time > p->time)
							{
								time = p->time;
							}
						}
						p = p->next;
					}
					
					p = L.head;
					
					while(p != NULL)
					{
						if(p->time == time)
						{
							p->page = stored[i].page;
							p->time = i;
						//	cout<<"지금 들어오는 놈: "<<stored[i].pid<<" "<<stored[i].page<<endl;									
						//	view(L);
							break;					
						}
						p = p->next;
					}
					
					
				}
	 			
			 }
			 else //3개이면서 이미있을때 
			 {
			 	//cout<<"case14"<<endl;
			//	cout<<"Non page_fault"<<endl;
			//	cout<<"지금 들어오는 놈: "<<stored[i].pid<<" "<<stored[i].page<<endl;
			//	view(L);		 	
			 }

		}
		else//3개 이하 
		{
			//cout<<"case15"<<endl;
			p = L.head;
			count = 0;
			while(p != NULL)
			{
				//cout<<"case16"<<endl;
				if(stored[i].pid == p->pid && stored[i].page == p->page)
				{
					//cout<<"case17"<<endl;
					//p->time = i;
					count ++;
				}
				if(count == 1) 
				{
				//	cout<<"Non page_fault"<<endl;
				//	cout<<"지금 들어오는 놈: "<<stored[i].pid<<" "<<stored[i].page<<endl;
				//	view(L);					
					break;
				}
				p = p->next;
			}
			if(count == 0)
			{
				//cout<<"case18"<<endl;
			//	cout<<"page_fault"<<endl;
			//	cout<<"지금 들어오는 놈: "<<stored[i].pid<<" "<<stored[i].page<<endl;
				Add_m(L,i,num);
				page_fault ++;
				num++;
			//	view(L);		
			}	
		}
		
	}
	
	fout<<"OPT: "<<page_fault<<endl;
	p = L.head;
	
	while(p != NULL)
	{
		fout<<p->num<<" "<<p->pid<<" "<<p->page<<endl;
	//	cout<<p->num<<" "<<p->pid<<" "<<p->page<<endl;
		p = p->next;
	}
}
//////////////////////////////////////////////////
int main()
{

	int n;
	int stored_end;
	ifstream fin;
	
	fin.open("page.inp");
	
	fin>>n; // n is stored
	
	for(int i=0;;i++)
	{
		fin>> stored[i].pid;
		fin>> stored[i].page;
		if(stored[i].pid==-1&&stored[i].page==-1)
		{
			stored_end = i;
			break;
		}
	}
	fin.close();
	
	ofstream fout;
	fout.open("page.out");
	
	FIFO(n,stored_end,fout);
	LRU(n,stored_end,fout);
	OPT(n,stored_end,fout);
	fout.close();
	
	
	
	
	
	
	
	
}
