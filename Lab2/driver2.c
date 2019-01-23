#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
int main(int argc, char *argv[])
{
// Create a file pointer and open the file read as command line argument.
FILE* fileptr = fopen(argv[1], "r");
// Declare a pointer to a linked list (head) and allocate memory to it.
 linkedlist* head = ( linkedlist *) malloc(sizeof( linkedlist));
// In a loop read the file and insert elements into the linkedList.
while (!feof(fileptr))
{
// read the next element and store into the temp variable.
int temp;
fscanf(fileptr, "%d ", &temp);
//printf("%d\t",temp);
// insert temp into the linked list.
//printList(head);

push(head,temp);

//printList(head);

}
//printList(head);
while(head->count<0)
{
	node* x = pop(head);
	printf(" %d->",x->element);
}
}