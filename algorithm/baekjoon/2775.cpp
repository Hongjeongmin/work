#include<iostream>
using namespace std;
int dp[16][16];
int look(int k, int n)
{
	int sum = 0;
	int &ref = dp[k][n];
	if (ref != -1)
	{
		return ref;
	}
	if (k == 0)
	{
		return n;
	}

	for (int i = 1; i <= n; i++)
	{
		sum += look(k - 1, i);
	}
	return sum;
	
}
int main(void)
{
	int T;
	int k;
	int n;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			for (int w = 0; w < 16; w++)
			{
				dp[j][w] = -1;
			}
		}
		cin >> k;
		cin >> n;

		cout << look(k, n) << endl;
	}
}