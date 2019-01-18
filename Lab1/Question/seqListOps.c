/***********file:   Ops.c *********/
#include <stdio.h>

#include "storage.h"
#include "compare.h"
int nextfreeloc = 0;
Store st;

SeqList createlist()
{
 SeqList sl;
 sl.head = nextfreeloc++;
 sl.size = 0;
 st[sl.head].next = -1;
 return (sl);
}

void printJob (Job j)
{
printf ("JOB ID = %d, Priority = %d, Arr time = %d, Arrival time = %d \n",j.id,j.pri,j.et,j.at);
}


int inputJobs (JobList list)
{
 int i; int size;

 printf("\n Enter the Number of Jobs :");
 scanf("%d", &size);

 for (i=0;i<size;i++)
 {
  printf ("\nEnter job ID");
  scanf ("%d",&list[i].id);
  printf ("Enter Priority (from 0 - 2)");
  scanf ("%d",&list[i].pri);
  printf ("Execution Time");
  scanf ("%d",&list[i].et);
  printf ("Arrival Time");
  scanf ("%d",&list[i].at);
 }
 return size;
}

SeqList insert(Job j , SeqList sl)
{
//more effiecient implementation
	if(sl.head == -1)//empty
	{
		st[sl.head].ele = j;
	}

 int it,temp;
 for (i=sl.head ; st[i].next != -1 ; i=st[i].next)
 {
  if (compare(st[st[i].next].ele , j) == GREATER)// found point
   break;
 }
 temp = nextfreeloc++;
 //create an element
 st[temp].next = st[i].next;
 st[temp].ele = j;
 st[i].next = temp;//set the next index as that of temp
 sl.size++;
}

/*
SeqList insert(Job j , SeqList sl)
{
	int flag = -1;
	int it = sl.head;
	Job temp,temp1;
	if(sl.head == -1)//empty
	{
		st[sl.head].ele = j;
	}
	while(it!=-1)
	{
		while(compare(j,st[it].ele) != GREATER && it!=-1)
		{
		it = st[it].next;
		}
		temp = st[it].ele;
		st[it].ele = j;
		flag =1;
		it = st[it].next;
		while(it!= -1 && flag==1)
		{
		temp1 = st[it].ele;
		st[it].ele = temp;
		temp = temp1;
		it = st[it].next;
		}
	}
	if(flag == 1)
	{
		st[nextfreeloc++].ele = temp;
	}
	else
	{
		st[nextfreeloc++].ele = j;
	}		
	//Implement this function
	//
	sl.size++;
	return sl;
 }
 */ 
void insertelements (JobList list , int size, SeqList s[3])
{
	int i;
	for(i=0;i<3;i++)
	{
		s[i]=createlist();
	}
	//lists created
	for(i=0;i<size;i++)
	{
		if(list[i].pri == PRI_0)
		{
			insert(list[i],s[0]);
		}
		else if(list[i].pri == PRI_1)
		{
			insert(list[i],s[1]);	
		}
		else
		{
			insert(list[i],s[2]);
		}	
	}

// Implement this function

}

void copy_sorted_ele(SeqList s[3] , JobList ele)
{

	int i=0;
	int j;
	for(j=2;j>=0;j--)
	{
		int it = s[j].head;
		while(it !=-1)
		{
			ele[i] = st[it].ele;
			it = st[it].next;
			i++;
		}
	}

		
	

// Implement this function

}

void printlist(SeqList sl)
{
	int it = sl.head;
	while(it!=-1)
	{
		printJob(st[it].ele);
		it = st[it].next;
	}		


// Implement this function

}

void printJobList(JobList list, int size)
{
	for(int i = 0;i<size;i++)
	{
	 printJob(list[i]);
	}

// Implement this function

}

void sortJobList(JobList list, int size)
{
 SeqList seq[3];
 seq[0] = createlist();
 seq[1] = createlist();
 seq[2] = createlist();
 insertelements (list, size, seq);

 printlist(seq[0]);   
 printlist(seq[1]);
 
 printlist(seq[2]);
 copy_sorted_ele (seq , list); 
}
