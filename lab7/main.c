#include <stdio.h>
#include <stdlib.h>
#include "qsort.h"
#include <math.h>
#include <sys/time.h>

void printRecords(record* arr,int size)
{
	printf("\nSorting\n");
	for(int i=0;i<size;i++)
	{
		printf("%s %ld\n",(arr+i)->name,(arr+i)->empid);
	}
}
void testRun(record arr[],int n,double result[])
{
	struct timeval t1,t2,t3;
	record  arr1[n],arr2[n];
	for(int i=0;i<n;i++)
	{
		arr1[i] = arr[i];
		arr2[i] = arr[i];
	}
	if(n>0)
	{
	printf("\t %d",n);
	gettimeofday(&t1,NULL);
	quicksort(arr2,n,0);
	gettimeofday(&t2,NULL);
	double elapsedTime = (t2.tv_sec - t1.tv_sec)*1000.0;
	elapsedTime += (t2.tv_usec-t1.tv_usec)/1000.0;
//	printf("qsort time = %f",elapsedTime);
	result[0] = elapsedTime;
	gettimeofday(&t2,NULL);
	insertionsort(arr1,n);
	gettimeofday(&t3,NULL);
	 elapsedTime = (t3.tv_sec - t2.tv_sec)*1000.0;
	elapsedTime += (t3.tv_usec-t2.tv_usec)/1000.0;
	//printf("isort time = %f",elapsedTime);
	
	result[1] = elapsedTime;
	}
}

int estimateCutoff(record arr[],int n)//Objective is to find the first occurence
{
	double results[2];

	record newarr[n];

	int min=0;
	int max=n;
	int cutoff;
	double time;
	int mid=(min+max)/2;
	//time = record[1]-record[0]
	while(max > min)
	{
		mid=(min+max)/2;
		testRun(arr,mid,results);
		if(results[1]-results[0]>0.0)
		{
			min = mid+1;
		}
		else if (results[1]-results[0]<0.0)
		{
			max = mid+1;
		}
		else
		{
			return mid;
		}
	}


}

int main()
{
	struct timeval t1,t2;
	gettimeofday(&t1,NULL);
	FILE* f = fopen("100","r");
	record arr[100];
	int i =0;
	while(fscanf(f,"%s %ld",arr[i].name,&arr[i].empid)!=-1)
	{
		printf("%s %ld\n",arr[i].name,arr[i].empid);
		i++;
	}
	//record* ans = (record*)(malloc(sizeof(record)*10));
	int cutoff  = estimateCutoff(arr,100);
	
	// quicksort(arr,50,0);
	//printRecords(arr,10);
	gettimeofday(&t2,NULL);
	double elapsedTime = (t2.tv_sec - t1.tv_sec)*1000.0;
	elapsedTime += (t2.tv_usec-t1.tv_usec)/1000.0;
	printf("Elapsed Time = %f\n",elapsedTime);
	printf("cutoff = %d", cutoff);
}

/*
Finding Time 
struct timeval t1, t2;
double elapsedTime;
// start timer
gettimeofday(&t1, NULL);
// do something or call a function
// ...
// stop timer
gettimeofday(&t2, NULL);
// compute and print the elapsed time in millisec
elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
*/
