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
/*int main(void){
	struct timeval t1,t2;
	double elapsedTime;
	unsigned int N=10;
	//while(N<10000){
		LinkedList *l=createList(N);
		printf("Total heap space=%u\n", spaceAllocated);
		l=createCycle(l);
		//gettimeofday(&t1, NULL);
		printf("%s\n",testCyclic(l));
		gettimeofday(&t2, NULL);
		elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
		elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
		printf("Total time is %f ms.\n for %u", elapsedTime,N);
		l=makeCircularList(l);
		printf("%s\n",testCyclic(l));
		myfree(l);
		N*=10;
	//}
}*/