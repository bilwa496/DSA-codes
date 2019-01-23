#include <stdio.h>
struct Node
{
	 int element;
	  struct Node* next;
};
typedef struct Node node ;

struct linkedList
{
int count;
struct Node* first;
};
typedef struct linkedList linkedlist ;
void insertFirst(linkedlist* head, int ele);
node* deleteFirst(linkedlist* head);
void printList(linkedlist* head);
int search(linkedlist* head,int ele);
node* delete(linkedlist* head, int ele);

