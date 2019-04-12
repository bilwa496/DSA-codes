#include<stdio.h>
#include"node.h"

extern int * Arr[N];
extern int Num_Elements[N];

void Merge_GM(int *Ls1, int sz1, int * Ls2, int sz2, int* Ls)
{
	
	int i=0;
	int j=0;
	int k=0;
	//BOOL IsLower_GM( int id1, int id2)
	while(i<sz1 && j<sz2)
	{
		if(IsLower_GM(Ls1[i],Ls2[j]) == TRUE)
		{
			Ls[k] = Ls2[i];
			i++;
			k++;
		}
		else
		{
		Ls[k] = Ls2[j];
		j++;
		k++;
		}
	}
	while(i<sz1 && j>=sz2)
	{
			Ls[k] = Ls1[i];
			i++;
			k++;
	}
	while(j<sz2 && i>=sz1)
	{
		Ls[k] = Ls2[i];
		i++;
		k++;
	}	  
}

void Merge_Arr()
{
      int l = 0;
      int r = N;
      int total = 0;
      for(int i=0;i<N;i++)
      {
      	total+= Num_Elements[i];
      }
      
      	int* Ls = (int*)(malloc(sizeof(int)*total);
      	int k = 0;
      	for(int i=0;i<N;i++)
      	{
      		for(int j= 0;j<Num_Elements[i];j++)
      		{
      			Ls[k] = *(Arr[i]+j);
      			k++;
      		}
      	}
      for(int k=1;k<=r;k=2*k)
      {
	      for(int left=l;left<r;left+= 2*k)
	      {
	      	int mid = left+k-1;
	      	int right ;
	      	if(left+2*k-1<r)
	      		right = left+2*k-1;
	      	else
	      		right = r;
	//      	int Ls1 = 
      	int* Ls1 = (int*)(malloc(sizeof(int)*total);;
	      	 //Merge_GM(int *Ls1, int sz1, int * Ls2, int sz2, int* Ls)
	      	 Merge_GM(Ls+left,mid-left+1,Ls+mid+1,right-mid,Ls1);
	      	for(int i=0;i<right-left-1;i++)
	      	{
	      		Ls[left+i] = Ls1[i];
	      	}
	      }
      } 

}
/*
int * Arr[N];
int Num_Elements[N];*/

