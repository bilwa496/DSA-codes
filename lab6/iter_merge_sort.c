#include <stdio.h>
#include <stdlib.h>
#include "ms2.h"
#include "merge.h"
int min(int a,int b)
{
	if(a>b)
		return b;
	else 
		return a; 
}
void mergeSort(Element Ls[], int l, int r) 
{ 
	printf("iterative implementation\n");
   	int k, left;
   	for (k=1; k<=r; k = 2*k) 
	{	
		for (left=l; left<r; left += 2*k) 
		{ 
		   int mid = left + k - 1; 
	  
		   int right = min(left + 2*k - 1, r); 
	  
		   // Merge Ls[left...mid] & Ls[mid+1...right] 
		   Element* Ls1 = (Element*)(malloc(sizeof(Element)*(right-left+1)));
		   merge(Ls+left,mid-left+1,Ls+mid+1,right-mid,Ls1);
		   for(int i=0;i<right-left+1;i++)
		   {
		   	Ls[left+i] = Ls1[i];
		   } 
	       } 
	 } 
} 
