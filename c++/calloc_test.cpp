#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main()
{
	int m;
	int **arr_1 = new int[m][5];
	int *arr_2;
	int i;
	int j;
	
	scanf("%d",&m);
	
	for(i =0 ; i< m;i++)
	{
		for(j =0; j<5;j++)
		{
			arr_1[i][j] = i+1;
		}
	}
	//arr_2 = (int*) malloc(sizeof(int)*5);
	arr_2 = (int**) calloc(m,sizeof(int[5]));
	
	for(i = 0; i< m; i++)
	{
		for(j =0; j<5;j++)
		{
			arr_2[i][j] = arr_1[i][j];
			printf("%d ",arr_2[i][j]);
		}
	}
	
	free(arr_2);
	return 0;
}
