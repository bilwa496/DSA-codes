#include "node.h"
#include<stdio.h>

extern int * Arr[N];
extern int Num_Elements[N];

/*
void InsertionSort_GM(int arr[], int n) 
{


 
}

BOOL IsLower_GM(int id1, int id2) 
*/
void InsertionSort_GM(int * row, int size)
{
	int* a = row;
	for(int i=2;i<size;i++)
	{
		int v = a[i];
		int j = i;
		while(IsLower_GM(v,a[j-1])==TRUE && j>=1)
		{
		a[j] = a[j-1];
		j--;
		}
		a[j] =v;
	}
}

void InsertionSort_Arr()
{
	for(int i=0;i<N;i++)
	{
		InsertionSort_GM(Arr[i], Num_Elements[i]);
	}

}

/*
int * Arr[N];
int Num_Elements[N];*/
