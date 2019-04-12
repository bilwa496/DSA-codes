#include"node.h"
#include<stdio.h>
#include<stdlib.h>
extern int *Arr[N];
extern int Num_Elements[N];
//Applies InsertionSort on a given row  by  sorting on the fields group number followed by member number

void ConvertListstoArray(Locality *start)
{
	int i = 0;
	Locality* list = start;
	int j=0;
	while(list!=NULL)
	{
		Num_Elements[j] = list->count;
		Member* t = list->first;
		Arr[j] = (int*)(malloc(sizeof(int)*list->count));
		while(t!=NULL)
		{
			(Arr[j][i]) = t->id;
		//	printf("%d,",Arr[j][i]);
			//arr[j][i] = t->id;
			t=t->next;
			i++;
		}
		//printf("%d\n",Num_Elements[j]);
		list=list->next;
		j++;
	}
}
 
// Num_Elements[N];
