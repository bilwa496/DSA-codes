#include <stdio.h>
#include <stdlib.h>
#include "merge.h"
void merge(Element Ls1[], int sz1, Element Ls2[], int sz2, Element Ls[])
{
	int j = 0;
	int s1 = 0,s2 = 0;
	/*printf("merging size Arrays:\t");
	printf("sz1 = %d , sz2 = %d\n",sz1,sz2);  
	for(int i=0;i<sz1;i++)
	{
		printf("%.2f\t",Ls1[i].cgpa);
	}
	for(int i=0;i<sz2;i++)
	{
		printf("%.2f\t",Ls2[i].cgpa);
	}*/
	while(s1<sz1 && s2<sz2)
	{	if(Ls1[s1].cgpa<Ls2[s2].cgpa )
		{
			Ls[j] = Ls1[s1];
			j++;
			s1++;
		}
		else if (Ls2[s2].cgpa < Ls1[s1].cgpa)
		{
			Ls[j] = Ls2[s2];
			j++;
			s2++;
		}
		else if (Ls2[s2].cgpa == Ls1[s1].cgpa)
		{
			Ls[j] = Ls1[s1];
			j++;
			s1++;
		}
	}	
	while(s2<sz2)
	{
		Ls[j] = Ls2[s2];
		j++;
		s2++;
	}
	while(s1<sz1)
	{
		Ls[j] = Ls1[s1];
		j++;
		s1++;
	}
	
//printf("operated");
		
}




