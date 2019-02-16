#include <stdio.h>
#include <stdlib.h>
#include "heapspace2.h"
#include "ll.h"
int main()
{
	int n =10;
	node* x = createlist(n);
	printf("Total heap space=%u\n", total_space);
	printlist(x);
	x = createCycle(x);
	printlist(x);
	if(isCyclic(x))
	{
		printf("true\n");
	}
	else
	{
		printf("False");
	}
	
	x = makeCircularList(x);

	printlist(x);
	if(linkreversal(x))
	{
		printf("true\n");
	}
	
		
	/*int random_number = rand()%(250000-100000)+100000;
	int *x = myalloc(random_number);
	myfree(x,random_number);
	while(x!=NULL)
	{
		x = myalloc(random_number);
		myfree(x,random_number);
		random_number = rand()%(250000-100000)+100000;
	}
	printf("No Memory!\n");
	*/
	return 0;
}