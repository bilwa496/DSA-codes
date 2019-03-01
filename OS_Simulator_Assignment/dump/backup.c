/************************************************
*Name:Indraneel Ghosh							*    										  
*ID:2016B1A70938P							  	*
*												*
*												*
*************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#define MAX 100
//define struct and function
// data,next,prev


int createlist(int arr[],listhead head[],int count)
{
	head[count].elementcount = 0;
	head[count].head = -1;
	//indices must be placed such that the list is added one after the other
	int m;
	printf("The sequence number of the newly created list is: %d\n",count+1);
	printf("Enter key value to be inserted in the newly created list- ");	
	scanf(" %d",&m);
	if(freed!=-1)
	{
		head[count].head = freed;
		int temp = freed;
		arr[freed] = m;
		freed = arr[freed+1];//stores the address next
		arr[temp+1] = -1;
		arr[temp+2] = -1;
		head[count].elementcount=1; 
		printf("SUCCESS\n");
	//	printf("%d\t",head[count].elementcount);
		//printf("head= %d\t",head[count].head);
		return 1;
	}
	else
	{
		printf("FAILURE: MEMORY NOT AVAILABLE\n");
		return 0;
	}
}

void createfreelist(int arr[])
{
	freed = 0;
	for(int i=0;i<(3*MAX-2);i+=3)
	{
		//arr[i]=data;
		arr[i+1] = i+3;

	//printf("%d\t",arr[i+1]);
		//prev has some garbage
	}
	arr[3*MAX-2]= -1;
} // returns freed pointer

void sortedinsert(listhead h[],int count, int value,int arr[])
{
	int tracker = h[count].head;
	int prev=-1;//prev tracker	
	//printf("runs\n");
	//printf("%d",freed);
	//if(count+1)
	if(h[count].head==-1 && freed !=-1)
	{
		int temp = freed;
		freed=arr[freed+1];
		arr[temp]=value;
		arr[temp+2] = -1;
		arr[temp+1] = -1;
		h[count].elementcount++;
		h[count].head = temp;
	}

	if(freed!=-1 && h[count].head!=-1)
	{
		
		//printf("%d\n",h[count].elementcount);
		int counter = 0;
		int i;
		for(i=0;i<h[count].elementcount;i++)
		{
		//			printf("tracer\t");
		
			if(value>arr[tracker])
			{
				prev = tracker;//tracking the previous element
				tracker = arr[tracker+1];
				counter++;
			//	printf("trace\t");
			}
			else if(counter!=h[count].elementcount)//not traversed entirely
			{
		//					printf("tracing\t");
		
				int temp = freed;
				if(i==0)
				{
					h[count].head = temp;
				}
				freed = arr[freed+1];
				arr[temp] = value;
				arr[tracker+2] = temp;
				arr[temp+1] = tracker;
				arr[temp+2] = prev;
				h[count].elementcount++;
				if(prev!=-1)
				{
					arr[prev+1]=freed;
				}
				break;
			}
		}

			if(counter==h[count].elementcount)
			{
				int temp = freed;
				arr[temp] = value;
				freed = arr[freed+1];//freed updated
				arr[prev+1] = temp;
				arr[temp+1] = -1;
				arr[temp+2] = prev;
				h[count].elementcount++;
//				printf("exec\n");
			}
		
    }
	else
	{
		printf("FAILURE: MEMORY NOT AVAILABLE\n");		
	}
}


listhead deletenode(int value,listhead h,int arr[])
{
	int tracker = h.head;
//	printf("%d\t",h.head);
	int flag = 0;
	if(h.head == -1)
	{
		printf("FAILURE: LIST EMPTY\n");
		return h;
	}
	printf("%d",arr[h.head]);
	printf("%d",freed);
	
	while(tracker!=-1)
	{
		//deleting head
		if(arr[h.head] == value)
		{
			int temp = arr[h.head+1];
			//if head is not the only elements
			if(temp!=-1)
			{
				int t = h.head;
				h.head = arr[h.head+1];
				arr[arr[t+1]+2] = -1;
				arr[t+1] = freed;
				freed = t;
				flag = 1;
				arr[t] = -10000;//emptied
				h.elementcount--;
		//							printf("ran em");
	

			}
			//head is the only element
			else
			{

				arr[h.head+1] = freed;
				freed = h.head;
				arr[h.head] = -10000;
				h.head = -1;
				flag = 1;  					
				h.elementcount--;
		//				printf("ran");
			}
			break;
		}
		else if(arr[tracker]==value && tracker!=h.head)
		{
			int temp = tracker;
			int fr = freed;
			int prev = arr[tracker+2];
			int nextel = arr[tracker+1];
			arr[arr[tracker+1]+2] = prev;
			arr[prev+1] = arr[tracker+1];
			arr[tracker+2] = -1;
			freed = temp;
			arr[freed+1] = fr;
			arr[freed]  = -1;
			flag = 1;
			h.elementcount--;
			//printf("ranx");
			break;
		}
		tracker = arr[tracker+1];
	}
	if(!flag)
	{
		printf("FAILURE: ELEMENT NOT THERE\n");

	}
	return h;
}

int totallist(int arr[])
{
	int count = 0;
	int tracker = freed;
	while(tracker!=-1)
	{
		count++;
		tracker = arr[tracker+1];
	}
	return (MAX-count);
}

int countlist(listhead head)
{
	return head.elementcount;
}

void printalllist(listhead heads[], int size, int arr[])
{
	for(int i=0;i<size;i++)
	{
		if(heads[i].head!=-1)
		{

		printf("Elements of List %d are\n",(i+1));
		printf("Key\tPrev\tNext\n");
		int tracker = heads[i].head;
		//printf("%d",tracker);
		//tracker = arr[tracker+1];
			while(tracker != -1)
			{
				printf("%d\t",arr[tracker]);
				if(arr[tracker+2]==-1)
				{
					printf("NIL\t");
				}
				else
				{
					printf("%d\t",arr[tracker+2]+1);			
				}
				if(arr[tracker+1]==-1)
				{
					printf("NIL\n");
				}
				else
				{
					printf("%d\n",arr[tracker+1]+1);			
				}
				tracker = arr[tracker+1];
			}
		}
		printf("\n");
	}
}

void printfreelist(int arr[])
{
	int tracker = freed;	
	printf("Elements of free list are:\n");
	printf("[");
	while(tracker!=-1)
	{
		printf("%d, ",tracker+1);
		tracker =  arr[tracker+1];
	}
	printf("]\n");
}

void defrag(listhead h[],int count,int arr[])
{
	int a[3*MAX];//local copy
	for(int i=0;i<(3*MAX-2);i+=3)
	{
		a[i+1] = i+3;
	}
	a[3*MAX-2]= -1;
	//initialized the array to a free list
	//Objective is to work with every free list and populate and return the modified list
	int x,header = 0;
	for(int i=0;i<count;i++)
	{
		if(h[i].head!=-1)
		{
			a[i+2] = -1;
			x = h[i].head;//can be used for traversing the original list
			h[i].head = header;//head modified
			int marker = x; //marking the head  
			while(x!=-1)
			{
				a[header] = arr[x];
				if(marker==x)
				{
					arr[header+2] = -1;
				}
				else
				{
					arr[header+2] = header - 3;
				}
			//	int temp = arr[header+1];
				x = arr[x+1];//travel forward in arr
				header+=3;
			}  
			header-=3;
			arr[header+1] = -1;
			if(header>=3 && h[i].elementcount>1)
			{
				a[header+2] = header-3;
			}
			else
			{
				a[header+2] = -1;
			}
		}
	}
	freed = header+3;//new position of freed
	printf("SUCCESS\n");
	for(int i=0;i<3*MAX;i++)
	{
		arr[i] = a[i];
	}
	//Case of failure?
//	return a;
}
	
