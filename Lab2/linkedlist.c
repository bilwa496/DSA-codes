#include "linkedlist.h"
#include <stdlib.h>
void insertFirst(linkedlist * head, int ele){
//create a node
 node *link = (node*) malloc (sizeof( node)); /* by this
you are creating a node whose address is being stored in the link pointer. */
link->element = ele;
//point it to old first node
link->next = head->first;
//point first to new first node
head -> first = link;
//printf("  %d    ",head -> count --);
	node* ptr=head->first;
	
}
node* deleteFirst(linkedlist *head)
{
	node* temp = head->first;
	
	head->first = temp->next;
	head->count++;
	//free(temp);
	return temp;
}
void printList(linkedlist* head)
{
	node* ptr = head->first;
	printf("\n[ ");
	while(ptr != NULL)
	{
		printf("%d ",ptr->element);
		ptr = ptr->next;
	}
	printf(" ] ");
}
int search(linkedlist* head, int ele)
{
	node *ptr = head->first;
	int flag =0;
	while(ptr!=NULL)
	{
	if(ptr->element == ele)
	{
	printf("Found!\n");
	flag = 1;
	return ele;
	}
	ptr=ptr->next;
	}

	printf("Not Found!");
	return -1;
}
node* delete(linkedlist* head, int ele)
{
	node *ptr = head->first;
	node* prev = head->first;
	
	while (ptr!=NULL)
	{
		if(ptr->element = ele)
		{
			prev->next = ptr->next;
			if(prev->next == head->first)
			{
			head->first = prev->next;
			}
			head->count++;
						
			return ptr;
		}
	}
	return ptr;
}

 

