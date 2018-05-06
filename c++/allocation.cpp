#include<iostream>
#include<fstream>
#define MAX 1000;
using namespace std;

class Process
{
public:
	int arr_time;
	int bur_time;
	int size;
	Process(){}
	~Process()
	{
	}
};
class Buffer
{
public:
	Buffer * front;
	Buffer * next;
	int num;
	int arr_time;
	int size;
};
class Memory
{
public:
	Memory *next;//next Memory address
	Memory *front;
	int address=0;
	int process=-1;//empty state
	int size=0;
	int return_time=0;
};
typedef struct _L
{
	Memory *head;
	Memory *cul;
	Memory *tail;
}linkedList;
typedef struct _Q
{
	Buffer *head;
	Buffer *tail;
}linkedQ;
linkedList Z;
void Creat_memory(Process &process, Memory &data,linkedList &L, int &num, int &time) //this space is divided and add
{

	if (data.size == process.size)
	{
		data.process = num;
		data.return_time = process.bur_time + time;
	}
	else
	{
		Memory *memory = new Memory[1];

		if (data.front == NULL)
		{
			//cout << "crate_m_data->front == NULL case" << endl;
			L.head = memory;
			memory->front = NULL;
			memory->next = &data;
			data.front = memory;
		}
		else
		{
			Z.head = data.front;
			Z.head->next = memory;
			memory->front = Z.head;
			memory->next = &data;
			data.front = memory;
		}
		memory->address = data.address;
		memory->process = num;
		memory->return_time = process.bur_time + time;
		memory->size = process.size;
		data.address = memory->address + memory->size;
		data.size = data.size - memory->size;
	}
}
void Delete_memory(Memory &data,linkedList &L)// this is delete and sum
{
	//linkedList *Z = new linkedList[1];
	if (data.front == NULL && data.next == NULL)
	{
		//cout << "M_delete case: 0 " << endl;
		data.process = -1;
	}
	else if (data.front == NULL && data.next != NULL)
	{
		if (data.next->process == -1)
		{
			//cout << "M_delete case: 1" << endl;
			data.next->address = data.address;
			data.next->size = data.next->size + data.size;
			data.next->front = NULL;
			L.head = data.next;
			delete[] &data;
		}
		else
		{
		//	cout << "M_delete case: 2 " << endl;
			data.process = -1;
		}

	}
	else if (data.front != NULL && data.next == NULL)
	{
		if (data.front->process == -1)
		{
		//	cout << "M_delete case: 3 " << endl;
			data.front->size = data.front->size + data.size;
			data.front->next = NULL;
			L.tail = data.front;
			delete[] &data;
		}
		else
		{
		//	cout << "M_delete case: 4 " << endl;
			data.process = -1;

		}
	}
	else
	{
		if (data.front->process == -1 && data.next->process == -1)
		{

			if (data.front->front == NULL && data.next->next == NULL)
			{
				//cout << "M_delete case: 5 " << endl;
				L.head = &data;
				L.tail = &data;
				data.address = 0;
				data.size = MAX;
				data.process = -1;
				delete[] data.front;
				delete[] data.next;
				data.front = NULL;
				data.next = NULL;

			}
			else if (data.front->front == NULL && data.next->next != NULL)
			{
			//	cout << "M_delete case: 6 " << endl;
				L.head = data.next;
				data.next->address = data.front->address;
				data.next->size = data.front->size + data.size + data.next->size;
				data.next->front = NULL;
				delete[] data.front;
				delete[] &data;
				

			}
			else if (data.front->front != NULL && data.next->next == NULL)
			{
			//	cout << "M_delete case: 7 " << endl;
				L.tail = data.front;
				data.front->size = data.front->size + data.size + data.next->size;
				data.front->next = NULL;
				delete[] data.next;	
				delete[] &data;
					
				

			}
			else
			{
			//	cout << "M_delete case: 8 " << endl;
				Z.head = data.front->front;
				Z.tail = data.next->next;
				data.size = data.front->size + data.size + data.next->size;
				data.address = data.front->address;
				data.process = -1;
				Z.head->next = &data;
				Z.tail->front = &data;
				delete[] data.front;
				delete[] data.next;								
				data.front = Z.head;
				data.next = Z.tail;							
				

		
			}
		}
		else if (data.front->process == -1 && data.next->process != -1)
		{
			if (data.front->front == NULL)
			{
			//	cout << "M_delete case: 9 " << endl;
				L.head = &data;
				data.process = -1;
				data.size = data.front->size + data.size;
				data.address = data.front->address;
				delete[] data.front;
				data.front = NULL;
								
				
			}
			else
			{
		//		cout << "M_delete case: 10 " << endl;
			//	cout << "data->front->process: " << data->front->process << endl;
		//		cout << "data->front->->front->process: " << data->front->front->process << endl;
				Z.head = data.front->front;
				data.process = -1;
				data.size = data.front->size + data.size;
				data.address = data.front->address;
				delete[] Z.head->next;
				Z.head->next = &data;
				data.front = Z.head;					
				


			}

		}
		else if (data.front->process != -1 && data.next->process == -1)
		{
			if (data.next->next == NULL)
			{
			//	cout << "M_delete case: 11 " << endl;
				L.tail = &data;
				data.process = -1;
				data.size = data.size + data.next->size;
				delete[] data.next;	
				data.next = NULL;
							
				

			}
			else
			{
			//	cout << "M_delete case: 12 " << endl;
				Z.tail = data.next->next;
				data.process = -1;
				data.size = data.size + data.next->size;
				delete[] data.next;		
				data.next = Z.tail;
				Z.tail->front = &data;						
					


			}
		}
		else
		{
		//	cout << "M_delete case: 13 " << endl;
			data.process = -1;
		}

	}
}
void Save_Q(Process &data,linkedQ &Q,int &num)//
{
	Buffer *new_buffer = new Buffer[1];

	new_buffer->num = num;
	new_buffer->arr_time = data.arr_time;
	new_buffer->size = data.size;

	
	if (Q.head == NULL && Q.tail == NULL)
	{
		Q.head = new_buffer;
		Q.tail = new_buffer;
		new_buffer->front = NULL;
		new_buffer->next = NULL;
	}
	else
	{
		new_buffer->front = Q.tail;
		new_buffer->next = NULL;
		Q.tail->next = new_buffer;
		Q.tail = new_buffer;
	}
}
void Delete_Q(Buffer &data, linkedQ &Q)
{

	if ( data.front == NULL && data.next == NULL)
	{
		//cout << "Delete_Q case 1" << endl;
		Q.head = NULL;
		Q.tail = NULL;
		delete[] &data;
	}
	else if (data.front == NULL && data.next != NULL)
	{
	//	cout << "Delete_Q case 2" << endl;
		Q.head = data.next;
		data.next->front = NULL;
		delete[] &data;
	}
	else if (data.front != NULL && data.next == NULL)
	{
	//	cout << "Delete_Q case 3" << endl;
		Q.tail = data.front;		
		data.front->next = NULL;
		delete[] &data;
	}
	else
	{
	//	cout << "Delete_Q case 4" << endl;
	//	cout << "Q_data->next" << data->next << endl;
	//	cout << "Q_data->front" << data->front << endl;
		data.front->next = data.next;
		data.next->front = data.front;
		delete[] &data;
	}
}
void View_M(linkedList *L)
{
	Memory *p=L->head;
	cout << "------Memory stats------" << endl;
	while (p != NULL)
	{
		cout << "<" << p->address << " " << p->process << " " << p->size << "> ";
		p = p->next;
	}
	cout << endl;
}
void View_Q(linkedQ *Q)
{
	Buffer *q; 
	q = Q->head;
	cout << "-----Q_state------" << endl;
	while (q != NULL)
	{
		cout << "<" << q->num << "> ";
		q = q->next;
	}
	cout << endl;
}
int first_fit(Process *process,int &n);
int best_fit(Process *process,int &n);
int worst_fit(Process *process,int &n);


int main(void)
{
	//----------------------file reading---------------------
	int n; // process cnt
	ifstream fin;
	
	fin.open("allocation.inp");

	fin >> n; // n is stored


	Process *process = new Process[n];

	for (int i = 0; i < n; i++)
	{
		fin >> process[i].arr_time;
		fin >> process[i].bur_time;
		fin >> process[i].size;
	}
	fin.close();
	//cout << "파일 받기 완료" << endl;
	//--------------------------------------------------------
	//---------------------file writing-----------------------
	

	
	ofstream fout;
	fout.open("allocation.out");
	fout << first_fit(&process[0], n) << endl;
	fout << best_fit(&process[0], n) << endl;
	fout << worst_fit(&process[0], n) << endl;
	fout.close();
	//---------------------------------------------------------

}

////// P n-1 값 출력해야함
int first_fit(Process *process,int &n)
{
	//cout << "-------fisrst_fit-------" << endl;
	Memory *memory = new Memory[1]; // basic memory
	Memory *p;
	Buffer *q;
	Buffer *q_t;
	linkedList L;
	linkedQ Q;// list Q's head and tail stored
	//ealry value
	int time = 0;
	int cnt = 0; //it is number of succes counted
	memory->size = MAX;
	memory->front = NULL;
	memory->next = NULL;
	Q.head = NULL;
	Q.tail = NULL;
	L.head = memory;
	L.tail = memory;
	//View_M(&L);
	//------------first_fit----------
	for(time;;time++)
	{
		cout <<"---------"<< time <<"--------" <<endl;
		//------------------- return_memory------------
		p = L.head;
		while (p != NULL)
		{
			//cout << "h" << endl;
			if (p->return_time == time && p->process != -1)
			{
				//cout << "h-1" << endl;
				View_M(&L);
				//View_Q(&Q);
				//cout << "process[" << p->process << "] return_time: " << p->return_time << endl;
				//cout << "Delete_memory: " << p->process << endl;
				Delete_memory(*p, L); 
				p = L.head;
			//	View_M(&L);
			//	View_Q(&Q);
			}
			else
			{
				//cout << "h-2" << endl;
				p = p->next;
				//cout << "h-3" << endl;
			}
		}
		//cout << "p" << endl;
		//---------------------------------------------

		//----------------------Q -> memory ??-----------------------
		q = Q.head;
		while (q != NULL)
		{
			q_t = q->next;
			p = L.head;
			while (p != NULL)
			{
				if (q->size <= p->size && p->process == -1)
				{
					Creat_memory(process[q->num], *p, L, q->num, time);
					View_M(&L);
					if (q->num == n - 1)
					{
						p = L.head;
						while (p != NULL)
						{
							if (p->process == n - 1)
							{
								return p->address;
							}
							p = p->next;
						}
					}
					Delete_Q(*q, Q);
					break;
				}
				p = p->next;
			}
			q = q_t;
		}	
		//----------------------------input->M,enable case is input->Q -------------
		
		for (int i = cnt; i < n; i++)
		{
			//cout << "a" << endl;
			p = L.head;
			if (process[i].arr_time == time)
			{
				//list start point
				while (p != NULL)
				{
					//cout << "b" << endl;
					if (p->process == -1)//empty state?
					{
						if (p->size>= process[i].size)//enoght size?
						{
							Creat_memory(process[i], *p,L,i,time);
							View_M(&L);
							//---------------return---------------
							if (i == n - 1)
							{
								p = L.head;
								while (p != NULL)
								{
									//cout << "c" << endl;
									if (p->process == n - 1)
									{
										return p->address;
									}
									p = p->next;
								}
							}
							//------------------------------------
							cnt++;//도착하는시간이 순서대로 라고 가정함.
							break;
						}
					}
					p = p->next;
					if (p == NULL)//it must stored at Q
					{
					//	cout << "Save_Q(process[" << i << "])" << endl;
						Save_Q(process[i], Q, i);
						//View_Q(&Q);
					}
				}
			}
		}

	}
	//-------------------------------
}
int best_fit(Process *process,int &n)
{

	//------------best_fit-------------
	//cout << "-------best_fit-------" << endl;
	Memory *memory = new Memory[1]; // basic memory
	Memory *p;
	Memory *best;
	Buffer *q;
	Buffer *q_t;
	linkedList L;
	linkedQ Q;// list Q's head and tail stored
			  //ealry value
	int time = 0;
	int cnt = 0; //it is number of succes counted
	memory->size = MAX;
	memory->front = NULL;
	memory->next = NULL;
	Q.head = NULL;
	Q.tail = NULL;
	L.head = memory;
	L.tail = memory;
	//View_M(&L);
	//-------------------------------
	for (time;; time++)
	{
		//------------------- return_memory------------
		p = L.head;
		while (p != NULL)
		{
			//cout << "h" << endl;
			if (p->return_time == time && p->process != -1)
			{
				//cout << "h-1" << endl;
				//View_M(&L);
				//cout << "process[" << p->process << "] return_time: " << p->return_time << endl;
				//cout << "Delete_memory: " << p->process << endl;
				Delete_memory(*p, L); // probelom
				p = L.head;
				//View_M(&L);
			}
			else
			{
				//cout << "h-2" << endl;
				p = p->next;
				//cout << "h-3" << endl;
			}
		}
		//cout << "p" << endl;
		//-------------------------------------
		//---------------Q->M-----------------
		q = Q.head;
		while (q != NULL)
		{
			q_t = q->next;
			p = L.head;
			best = NULL;
			while (p != NULL)
			{
				if (p->size >= q->size && p->process == -1)
				{
					if (best == NULL)
					{
						best = p;
					}
					else
					{
						if (best->size > p->size)
						{
							best = p;
						}
					}

				}
				p = p->next;
			}
			if (best != NULL)
			{
				Creat_memory(process[q->num], *best, L, q->num, time);
				//View_M(&L);
				if (q->num == n - 1)
				{
					p = L.head;
					while (p != NULL)
					{
						if (p->process == n - 1)
						{
							return p->address;
						}
						p = p->next;
					}
				}
				Delete_Q(*q, Q);
			}
			q = q_t;
		}

		//---------------------input -> M ,enable case is input -> Q ------------ 
		for (int i = cnt; i < n; i++)
		{
			if (process[i].arr_time == time)
			{
				p = L.head;
				best = NULL;
				while (p != NULL)
				{
					if (p->size >= process[i].size && p->process == -1)
					{
						if (best == NULL)
						{
							best = p;
						}
						else
						{
							if (best->size > p->size)
							{
								best = p;
							}
						}

					}
					p = p->next;
				}
				if (best != NULL)
				{
					cnt++;
					Creat_memory(process[i], *best, L, i, time);
					//View_M(&L);
					if (i == n - 1)
					{
						p = L.head;
						while (p != NULL)
						{
							if (p->process == n - 1)
							{
								return p->address;
							}
							p = p->next;
						}
					}
				}
				else
				{
					Save_Q(process[i], Q, i);
				}
			}
		}
	}
}
int worst_fit(Process *process,int &n)
{

	//------------worst_fit-------------
	//cout << "-------worst_fit-------" << endl;
	Memory *memory = new Memory[1]; // basic memory
	Memory *p;
	Memory *best;
	Buffer *q;
	Buffer *q_t;
	linkedList L;
	linkedQ Q;// list Q's head and tail stored
			  //ealry value
	int time = 0;
	int cnt = 0; //it is number of succes counted
	memory->size = MAX;
	memory->front = NULL;
	memory->next = NULL;
	Q.head = NULL;
	Q.tail = NULL;
	L.head = memory;
	L.tail = memory;
	//View_M(&L);
	//-------------------------------
	for (time;; time++)
	{
		//------------------- return_memory------------
		p = L.head;
		while (p != NULL)
		{
			//cout << "h" << endl;
			if (p->return_time == time && p->process != -1)
			{
				//cout << "h-1" << endl;
				//View_M(&L);
				//cout << "process[" << p->process << "] return_time: " << p->return_time << endl;
				//cout << "Delete_memory: " << p->process << endl;
				Delete_memory(*p, L); // probelom
				p = L.head;
				//View_M(&L);
			}
			else
			{
				//cout << "h-2" << endl;
				p = p->next;
				//cout << "h-3" << endl;
			}
		}
		//cout << "p" << endl;
		//-------------------------------------
		//---------------Q->M-----------------
		q = Q.head;
		while (q != NULL)
		{
			q_t = q->next;
			p = L.head;
			best = NULL;
			while (p != NULL)
			{
				if (p->size >= q->size && p->process == -1)
				{
					if (best == NULL)
					{
						best = p;
					}
					else
					{
						if (best->size < p->size)
						{
							best = p;
						}
					}

				}
				p = p->next;
			}
			if (best != NULL)
			{
				Creat_memory(process[q->num], *best, L, q->num, time);
				if (q->num == n - 1)
				{
					p = L.head;
					while (p != NULL)
					{
						if (p->process == n - 1)
						{
							return p->address;
						}
						p = p->next;
					}
				}
				Delete_Q(*q, Q);
			}
			q = q_t;
		}

		//---------------------input -> M ,enable case is input -> Q ------------ 
		for (int i = cnt; i < n; i++)
		{
			if (process[i].arr_time == time)
			{
				p = L.head;
				best = NULL;
				while (p != NULL)
				{
					if (p->size >= process[i].size && p->process == -1)
					{
						if (best == NULL)
						{
							best = p;
						}
						else
						{
							if (best->size < p->size)
							{
								best = p;
							}
						}

					}
					p = p->next;
				}
				if (best != NULL)
				{
					cnt++;
					Creat_memory(process[i], *best, L, i, time);
					if (i == n - 1)
					{
						p = L.head;
						while (p != NULL)
						{
							if (p->process == n - 1)
							{
								return p->address;
							}
							p = p->next;
						}
					}
				}
				else
				{
					Save_Q(process[i], Q, i);
				}
			}
		}
	}
}