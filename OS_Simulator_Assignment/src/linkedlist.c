/************************************************
*Name:Indraneel Ghosh							*    										  
*ID:2016B1A70938P							  	*
*												*
*												*
*************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#define MAX 700
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
		head[count].elementcount = 1; 
		printf("SUCCESS\n");
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
		arr[i+1] = i+3;
	//prev has some garbage
	}
	arr[3*MAX-2]= -1;
} 

void sortedinsert(listhead h[],int count, int value,int arr[])
{
	int tracker = h[count].head;
		//prev tracker	
	//printf("runs\n");
	//printf("%d",freed);
	if(h[count].head ==-1 && freed !=-1)
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
		int i;
		int prev=-1;
		int flag = 0;
	
		for(i=0;i<h[count].elementcount;i++)
		{
		//			printf("tracer\t");
			if(value>arr[tracker])
			{
				prev = tracker;//tracking the previous element
				tracker = arr[tracker+1];	
				flag++	;
			//	printf("trace\t");
			}
			else
			{
			//	printf("tracing\t");
				int temp = arr[freed+1];
				if(i==0)
				{
					h[count].head = freed;
				}
				arr[freed+1]=tracker;
				arr[freed] = value;
				arr[freed+2] = prev;
				arr[tracker+2]=freed;
				if(prev!=-1)//if not the first
				{
					arr[prev+1]=freed;
				}
				freed = temp;
				h[count].elementcount++;
				break;
			}
		}

		if(flag==h[count].elementcount)
		{
			int temp = freed;
			freed = arr[freed+1];//freed updated
			arr[temp] = value;
			arr[temp+1] = -1;
			arr[prev+1] = temp;
			arr[temp+2] = prev;
			h[count].elementcount++;
	//		printf("exec\n");
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
//	printf("%d",arr[h.head]);

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
		//		printf("ran em");
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
//	printf("%d\n",freed);
}

void printfreelist(int arr[])
{
	int tracker = freed;	
	printf("Elements of free list are:\n");
	printf("[");
	int elements= MAX - totallist(arr);
	int counter = 0;
	while(tracker!=-1  && counter<elements-1 )
	{
		printf("%d, ",tracker+1);
		tracker =  arr[tracker+1];
		counter++;
	}
	//tracker =  arr[tracker+1];

	printf("%d ",tracker+1);
	printf("]\n");
}

void defrag(listhead h[],int count,int arr[])
{
	int marker,x;	
	int a[3*MAX];
	for(int i=0;i<3*MAX;i+=3)
	{
		a[i+1] = i+3;
		a[i+2]=-1;
	}
	a[3*MAX-2] = -1;
	for(int i=0;i<count;i++)
	{
		if(h[i].elementcount!=-1)
		{
			marker = h[i].head;
	//		printf("%d",arr[marker]);
			h[i].head =x;
			int j = 0;
			for(j=0;j<h[i].elementcount;j++)
			{
				a[x] = arr[marker];
				//printf("%d",arr[marker]);
				if(x!=0)
				{
					a[x+2] = x-3;//prev is set
				}
				else
				{
					a[2] =-1; 
				}
				marker= arr[marker+1];
				x+=3;
			} 
			x-=3;
			if(x>=3 && j>=2)
			{
				arr[x+2] = x-3;
			}
			else
			{
				a[x+2] = -1;
			}
			a[x+1] = -1;
		}
		x+=3;
	}
	printf("SUCCESS\n");
	freed = x;
	for(int i=0;i<3*MAX;i++)
	{
		arr[i] = a[i];
	}
	// printalllist(h,count, arr);
}