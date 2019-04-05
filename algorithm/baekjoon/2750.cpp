#include<iostream>
using namespace std;
// mergeSort
int n;
int N[1001];
int P[1001];
void Merge(int p, int q, int r)
{
	int i = p; int j = q + 1; int k = p;
	while (i <= q || j <= r)
	{

		if (i > q)
		{
			P[k++] = N[j++];
		}
		else if (j > r)
		{
			P[k++] = N[i++];
		}
		else if (N[i] < N[j])
		{
			P[k++] = N[i++];
		}
		else 
		{
			P[k++] = N[j++];
		}
	}
	for (int x = p; x <= r; x++)
	{
		N[x] = P[x];
	}
}
void MergeSort(int p,int r)
{
	if(p<r)
	{
		int q = (p+r)/2;
		MergeSort(p,q); // 2section
		MergeSort(q+1,r); // 2section
		Merge(p,q,r);
	}
}
int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> N[i];
	}
	MergeSort(0, n - 1);
	for (int i = 0; i < n; i++)
	{
		cout << N[i]<<endl;
	}
}