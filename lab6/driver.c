#include <stdio.h>
#include <stdlib.h>
#include "merge.h"
#include "ms2.h"
#include "fl.h"
int main()
{
	Element* ls =(Element*) (malloc(sizeof(Element)*1500));
	FILE* fptr = fopen("1024.txt","r");
	char name[10];
	float cgpa;
	if(fptr == NULL)
	{
		printf("Error!\n");
	}
	int i = 0;
	while(fscanf(fptr,"%[^,],%f\n",ls[i].name,&ls[i].cgpa)!=-1)
	{
		printf("%s,%f\n",ls[i].name,ls[i].cgpa);
		i++;
	}
	printf("%d\n",i);
	mergeSort(ls,0,i-1);//Recursive Skeleton 
	for(int j=0;j<i;j++)
	{
		printf("sorted= %s,%f\n",ls[j].name,ls[j].cgpa);
	
	}
	
}	
