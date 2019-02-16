#ifndef _ll
#define _ll
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Node
{
	int value;
	struct Node* next;
};
typedef struct Node node;
extern node* createlist(int n);
extern node* createCycle(node* ls);
extern bool isCyclic(node* head);
extern bool linkreversal(node* head);
extern node* makeCircularList(node* head);
void printlist(node* head);

#endif

