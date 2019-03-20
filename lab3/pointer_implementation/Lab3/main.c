#include <stdio.h>
#include <stdlib.h>
#include "multiQ.h"

MultiQ* loadData(FILE* f)
{
	MultiQ* mq = createMQ(100);
	f = fopen("input100.txt",'r');
	struct Task ans[100];
	char c;
	for(int i=0;i<100;i++)
	{
	fscanf(f,"%d",ans[i].tid);
	fscanf(f,"%c",&c);
	fscanf(f,"%d",&ans[i].priority);
	mq = addMQ(mq, ans[i]);
//	MultiQ* addMQ(MultiQ* mq, struct Task t)
	}
	
	
} 
int main()
{
	return 0;
}
