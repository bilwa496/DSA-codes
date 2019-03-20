#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "multiQ.h"
MultiQ* createMQ(int num)
{
	MultiQ* newmq = (MultiQ*)(malloc(sizeof(MultiQ)));
	newmq->qnum = (queue*)(malloc(sizeof(queue)*num));
	newmq->mqsize = num;
	
	return newmq;
	 //list of num queues created
}//create a list of num queues
MultiQ* addMQ(MultiQ* mq, struct Task t)
{
	 struct Element x;
	 x.val = t;
	 
	 //(mq->qnum+t.priority) =y;
	 queue* loc = mq->qnum+t.priority;
	  loc = addQ((mq->qnum+t.priority),x);
}//adds t to the queue
struct Task nextMQ(MultiQ* mq)
{
//tracking priority
	return ((((mq->qnum))->head)->ele).val;
}// return the front of the non-empty Queue with highest priority
MultiQ* delNextMQ(MultiQ* mq)
{
	queue* temp = mq->qnum;
	mq->qnum = mq->qnum+1;	
	delQ(temp);
	return mq;
}//deletes the front of the non-empty queue in mq
bool isEmptyMQ(MultiQ* mq)
{
	for(int i = 0;i!= (mq->mqsize) ;i++)
	{
		if(!isEmpty((mq->qnum)+i))
		{
		return false;
		}
	}
	return true;
}
int sizeMQ(MultiQ *mq)
{
	int siz = 0;
	for(int i=0;i< mq->mqsize;i++)
	{
		siz+= lengthQ(mq->qnum+i);
	}
	return siz;
}
int sizeMQbyPriority(MultiQ *mq, int p)
{
	return (lengthQ((mq->qnum)+p));
}//returns number of items in mq with the priority p
queue* getQueueFromMQ(MultiQ *mq, int p)
{
	return ((mq->qnum)+p);
}//returns the queue with priority p


