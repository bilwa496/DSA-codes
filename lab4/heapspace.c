#include <stdio.h>
#include <stdlib.h>
#include "ll.h"
#include "heapspace2.h"
int total_space  = 0;
node* myalloc(int m)
{
	node* a = (node*)(malloc(m));
	
	if(a==NULL)
	{
		printf("Failure\n");
		return a;
	}
	total_space += m;
	printf("Call = %d\t",total_space);
	for(int i=0;i<m;i++)
	{
		printf("%u \t",a+i);
	}
	return a;
}
void myfree(node* x,int size)
{

	total_space -= size;
	printf("%d\t",total_space);
	free(x);	
}
