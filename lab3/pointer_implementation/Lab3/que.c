#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "que.h"

queue* newQ()
{
	//return empty queue
	queue* newq =(queue*) malloc(sizeof(queue));
	newq->head = NULL;
	newq->tail = NULL;
	newq->size = 0 ; 
	return newq;
}
bool isEmpty(queue* q)
{
	if(q->head == NULL && q->tail == NULL)
	{
		return true;
	}
	else
		return false;
}
queue* delQ(queue* q)
{
	if(q!=NULL)
	{
	node* temp = q->head;
	q->head = (q->head)->next;
	q->size--;
	free(temp);
	}
	return q;	
}
struct Element front(queue* q)
{
	return ((q->head)->ele);
}
queue* addQ(queue* q,struct Element e)
{
	node* newnode= (node*)(malloc(sizeof(node)));
	newnode->ele = e;
	newnode->next = NULL;
	(q->tail)->next = newnode;
	q->tail = newnode;
	q->size++;
	return q; 
}
int lengthQ(queue* q)
{
	return q->size;
}	
/*void printQ(Queue* q)
{
	node* temp = q->front;
	while(temp!=NULL)
	{
		printf("%d -> ",(temp->ele).val);
		temp = temp->next;
	}
}*/
