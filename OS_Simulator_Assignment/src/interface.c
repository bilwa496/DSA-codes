#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
// Define the functions
void menu()
{
	
	for( int i=1;i<=9;i++)
	{
		if(i==1)
		{
			printf("%d . Create a new list\n",i);
		}
		else if(i==2)
		{

			printf("%d . Insert a new element in a given list in sorted order\n",i);
		}
		else if(i==3)
		{

			printf("%d . Delete an element from a given list\n",i);
		}

		else if(i==4)
		{

			printf("%d . Count total elements excluding free list\n",i);
		}

		else if(i==5)
		{

			printf("%d . Count total elements of a list\n",i);
		}

		else if(i==6)
		{

			printf("%d . Display all lists\n",i);
		}

		else if(i==7)
		{

			printf("%d . Display free list\n",i);
		}

		else if(i==8)
		{

			printf("%d . Perform defragmentation\n",i);
		}

		else if(i==9)
		{

			printf("%d . Press 0 to exit\n",i);
		}
	}
	printf("Select an Option: ");
}