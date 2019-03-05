#include "List.h"
void printList1(List list)
{
	Node temp = list->first;
	while(temp!=NULL)
	{
		printf("Name: %s, Marks: %f\n", temp->record->name, temp->record->marks);
		temp=temp->next;
	}

	return;
}
List createList(Student studArray, int arraySize)
{
	List ls = (List)(myalloc(sizeof(struct list)));
	ls->first = NULL;
	ls->last = NULL;
	ls->count = arraySize;
	if(arraySize ==0)
		return ls; 
	int i = 0;
	if(ls->first==NULL)
	{
		Node x  = (Node)(myalloc(sizeof(struct node)));
		x->record = (studArray+i); 
		x->next = NULL;
		ls->first = x;
		ls->last = x;
		i++;
	}
//insert first
	while(ls->first!=NULL && i<arraySize)
	{
		Node temp = ls->first;
		Node x  = (Node)(myalloc(sizeof(struct node)));
		x->record = (studArray+i); 
		x->next = temp;
		ls->first = x;
		i++;
	}
	return ls;
}

void insertInOrder(List list, Node newNode)
{	if(list->count==0)
	{
		list->first = newNode;
		list->last = newNode;
		newNode->next = NULL;
		list->count++;
		return;
	}

	Node temp = list->first;
	Node prev = list->first;
	while(temp!=NULL)
	{
		if(temp->record->marks < newNode->record->marks)
			{
				prev = temp;
				temp = temp->next;
			}
		else
			break;
		
	}
		
		
	if(temp==NULL)
	{
		
		list->last = newNode;
		prev->next = newNode;
		newNode->next =NULL;
		list->count++;
	}
	 if(temp == prev)
		{
		newNode->next = list->first;
		list->first = newNode;
		list->count++;
	//	return;
		}
	
	else
	{
		prev->next = newNode;
		newNode->next  = temp;
		list->count++;
	}
	return;
	
}
	

List insertionSort(List list)
{
//iterative
//printf("list = \n");
	
//	printList1(list);
	List ls = (List) myalloc(sizeof(*ls)); 
	ls->count = 0;
	ls->first =NULL;
	ls->last = NULL;
	Node temp = list->first;
	int i = 0;
	Node t2;
	while(temp!=NULL)
	{
	t2 = temp;
	temp = temp->next;
	insertInOrder(ls,t2);
	}
	//printList1(ls);
	return ls;
}
double measureSortingTime(List list)
{
	struct timeval t1,t2,t3;
	gettimeofday(&t1,NULL);
	insertionSort(list);
	gettimeofday(&t2,NULL);
	double elapsedTime = (t2.tv_sec - t1.tv_sec)*1000.0;
	elapsedTime += (t2.tv_usec-t1.tv_usec)/1000.0;
} 
void * myalloc(int size)
{
	globalCounter +=size;
	void* theta =(void*) (malloc(size));
	return ((void*)theta);
}


void myfree(void* ptr)
{
	globalCounter -=sizeof(ptr);
	free(ptr);
}




