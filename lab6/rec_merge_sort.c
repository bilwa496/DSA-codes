#include <stdio.h>
#include <stdlib.h>
#include "merge.h"
#include "ms2.h"
#include "merge.h"
void mergeSort(Element Ls[], int l,int r)
{//left limit right limit
	if(l<r)
	{
		//printf("%d,%d\n",l,r);
		Element* Ls1= (Element*)(malloc(sizeof(Element)*(r-l+1)));
		int mid =(l+r)/2;
		mergeSort(Ls,l,mid);
		//printf("%d,%d",l,mid);
		mergeSort(Ls,mid+1,r);
		//printf("%d,%d",,mid);
	//	printf("%d,%d\n",l,r);
		
		merge(Ls+l,mid-l+1,Ls+(mid+1),r-mid,Ls1);//point of correction
		//printf("mid = %d,r=%d,l = %d\n",mid,r,l);
		for(int i=0;i<r-l+1;i++)
		{
			Ls[l+i] = Ls1[i];
	//		printf("%d = %.2f\t",i,Ls[i].cgpa);
		}
		free(Ls1);
	}
	
}

