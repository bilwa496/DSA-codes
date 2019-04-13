#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

stack* createstack()
{
	return NULL;
}
int isEmptyStack(stack* top)
{
	return top == NULL;
}
void push(stack* top,node* btree )
{
	stack* newnode = (stack*)(malloc(sizeof(stack)));
	if(!newnode)
		return ;
	newnode->value = btree;
	newnode->next = top;
	top = newnode;
}
node* pop(stack* top)
{
	stack* temp = top;
	node* data = (top)->value;
	top = (top)->next;
	free(temp);
	return data;	
}
node* top(stack* top)
{
	if(!isEmptyStack(top))
		return ((top)->value);
	return NULL; 
}
void deletestack(stack* top)
{
	while(!isEmptyStack(top))
	{
		stack* temp = top;
		top = top->next;
		free(temp);
	}
}
