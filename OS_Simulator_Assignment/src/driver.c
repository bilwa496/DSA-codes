/************************************************
*Name:Indraneel Ghosh							*    										  
*ID:2016B1A70938P							  	*
*												*
*												*
*************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "interface.h"
#include <string.h>
#define MAX 700

//driver code for the function
int main()
{
	int arr[3*MAX];
	listhead heads[MAX];
	createfreelist(arr);
	
	menu();
	int option,m,key;
	scanf(" %d", &option);
	int count = 0;
	while(option!=0)
	{
		if(option==1)
		{
	//		printf("list no : %d",count);
			int flag = createlist(arr,heads,count);
			if(flag==1)
			{
	//				printf("%d\t",heads[count].elementcount);
				count++;

			}
		}
		else if(option==2)
		{
			printf("List you want to insert in: ");
			scanf(" %d",&m);
			printf("\nEnter the key value: ");
			scanf(" %d",&key);
			if(m>count)
			{
				printf("List %d does not exist\n",m); 
			}
			else
			{
				sortedinsert(heads,m-1,key,arr);
			}
			printf("\n");

		}
		else if(option==3)
		{
			/*List you want to delete from: here user inputs list number n
Enter the key value: here user inputs integer m*/
			printf("List you want to delete from: ");
			scanf(" %d",&m);
			printf("\nEnter the key value: ");
			scanf(" %d",&key);
			if(m>count)
			{
				printf("List %d does not exist",m); 
			}
			else
			{
				heads[m-1]= deletenode(key,heads[m-1],arr);
			}
			printf("\n");

		}
		else if(option==4)
		{
			printf("Total number of nodes in all lists are: %d\n",totallist(arr));
		}
		else if(option==5)
		{
			printf("Enter the list number: ");
			scanf(" %d",&m);
			//printf("%d",heads[m-1].elementcount);
			if(count>=m)
			{
				printf("Total number of nodes in list %d are %d\n",m,countlist(heads[m-1]));
			}
			else
			{
			//	printf("%d",count);
				printf("Such a List does not exist\n");
			}

		}
		else if(option==6)
		{
			printalllist(heads,count,arr);
		}
		else if(option == 7)
		{
			printfreelist(arr);
		}
		else if(option == 8)
		{
			defrag(heads,count,arr); 
		}
		menu();
		scanf(" %d", &option);

	}

}