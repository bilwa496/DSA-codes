#include "linkedlist.h"
#include <stdlib.h>

void push(linkedlist* head, int ele)
{
	node* temp = head->first;
	node* newnode= (node*)malloc(sizeof(node));
	newnode->element  =ele; 
	newnode->next = temp;
	head->first = newnode;
	head->count--;
}
node* pop(linkedlist* head)
{
	node* popper = head->first;
	head->first = popper->next;
	head->count++;
	return popper;
}
