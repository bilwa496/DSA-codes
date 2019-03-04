#include <stdio.h>
#include <stdlib.h>
#include "qsort.h"
void printRecords(record* arr,int size)
{
	printf("\nSorting\n");
	for(int i=0;i<size;i++)
	{
		printf("%s %ld\n",(arr+i)->name,(arr+i)->empid);
	}
}

int main()
{
	FILE* f = fopen("10","r");
	record arr[10];
	int i =0;
	while(fscanf(f,"%s %ld",arr[i].name,&arr[i].empid)!=-1)
	{
		printf("%s %ld\n",arr[i].name,arr[i].empid);
		i++;
	}
	record* ans = (record*)(malloc(sizeof(record)*10));
	ans = quicksort(arr,10,0);
	printRecords(ans,10);
}
