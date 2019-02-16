#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ll.h"
#include "heapspace2.h"
node* createlist(int n)
{
	int random_number;
	node* head = myalloc(sizeof(node));
	n--;
	random_number = 100;
	head->value = random_number;
	node* temp = head;
	//printf("%d",head->value);

	for(int i=0;i<n;i++)
	{
			node* newnode = myalloc(sizeof(node));
			newnode->value = i+1;
			newnode->next=NULL;
			temp->next = newnode;
	//		printf("%d ->  ",temp->next->value);
			temp=  temp->next;	

	}
	return head;
}

node* createCycle(node* ls)
{
	node* temp1= ls;
	node* traverse = ls;
	int random_number = 5;
	while(temp1->next!=NULL)
	{
		temp1=temp1->next;
	}
	while(traverse!=NULL)
	{
		if(traverse->value == random_number)
		{
			temp1->next =traverse;
			printf("%d\t",traverse->value);
			break;
		}
		traverse = traverse->next;
	}
	return ls;
} 

bool isCyclic(node* head)//Hare Tortoise Alo
{
	node* hare = head;
	node* tort = head;

	while(hare!=NULL && tort!=NULL)
	{
		hare = (hare->next)->next;
		tort = tort->next;
		if(hare==tort)
		{
		//	printf("%d",hare->value);
			return true;
		}
	}
	return false;
}
void printlist(node* head)
{
	node* temp = head;
	node* fastptr = head;
	node* slowptr = head;
	if(!isCyclic(head))
	{
		while(temp!=NULL)
		{
			printf("%d -> ",temp->value);
			temp = temp->next;
		}
	}
	else
	{
		while(fastptr!=NULL && slowptr!=NULL)
		{
			fastptr = (fastptr->next)->next;
			slowptr = slowptr->next;
			if(slowptr==fastptr)
			{
			//	printf("%d",hare->value);
				break;
			}
		}
			//printf("fastptr = %d",fastptr->value);
		int count = 0;

		fastptr = fastptr->next;
		count++;
		while(slowptr!=fastptr)
		{
			fastptr = fastptr->next;
			count++;
		}
		//printf("%d\t",count);
		slowptr = head;
		fastptr = head;
		for(int i=0;i<count;i++)
		{
			fastptr = fastptr->next;
		}
		while(fastptr!=slowptr)
		{
			fastptr = fastptr->next;
			slowptr = slowptr->next;
		}
		while(temp!= fastptr)
		{
			printf("%d -> ",temp->value);
			temp = temp->next;
		}

		printf("%d -> ",temp->value);
		temp = temp->next;
		while(temp!= fastptr)
		{
			printf("%d -> ",temp->value);
			temp = temp->next;
		}
		printf("%d",temp->value);
		printf(" Cycle completed\n");

	}
	printf("\n");
}

bool linkreversal(node* head)
{
	node* next= NULL;
	node* current = head;
	node* prev =NULL;
	if(head!=NULL)
	{
		while(current!=NULL /*&& head->next!=NULL*/)
		{
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
			if(head == current)
			{
				printf("Cyclic\n");
				return true;
			}			
		}
	}
	
	return false;
}
//Measure the run time of the algorithm
node* makeCircularList(node* head)
{
	node* temp = head;

	node* slowptr = head;
	node* fastptr = head;
	node* safe;
	if(!isCyclic(head))
	{

	while(temp->next!=NULL)
		{
			temp = temp->next;
		}
		temp->next=head;
		if(isCyclic(head))
		{
			printf("Success\n");
		}
	}
	else if(isCyclic(head))
	{
	//if there exists a loop
	
		while(fastptr!=NULL && slowptr!=NULL)
	{
		fastptr = (fastptr->next)->next;
		slowptr = slowptr->next;
		if(slowptr==fastptr)
		{
		//	printf("%d",hare->value);
			break;
		}
	}
		//printf("fastptr = %d",fastptr->value);
		int count = 0;

			fastptr = fastptr->next;
			count++;
			while(slowptr!=fastptr)
			{
				fastptr = fastptr->next;
				count++;
			}
		//printf("%d\t",count);
		slowptr = head;
		fastptr = head;
		for(int i=0;i<count;i++)
		{
			fastptr = fastptr->next;
		}
		while(fastptr!=slowptr)
		{
			fastptr = fastptr->next;
			slowptr = slowptr->next;
		}
		while(temp!=fastptr)
		{
			safe = temp;
			temp= temp->next;
			myfree(safe,sizeof(node));
		}
	//	printf("fastptr = %d\t",fastptr->value);
		head = fastptr;
	}
	return head;
	
}	

/*
/*Challenges Left: Figure out a way to break the circular ll after printing only once.

My Algo:
until slowptr!=fatsptr continue traversal
then
	  Freeze one pointer where it was and increment the other pointer in one step counting the steps you make and when they both meet again, the count will give you the length of the loop (this is same as counting the number of elements in a circular link list).

then
	 Reset both pointers to the start of the
	 link list, increment one pointer to the length of loop times and then start the second pointer. increment both pointers
	  in one step and when they meet again, it will be the start of the loop (this is same as finding the nth element from the end of the link list).*/
