#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
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

insertFirst(head,temp);
//printList(head);

}
// close the file pointer
fclose(fileptr);
printList(head);
deleteFirst(head);
printList(head);
printf("%d\t",search(head, 32));
node *temp = head->first;
FILE* f1 = fopen("answer.txt","w");
while(temp!=NULL)
{
	fprintf(f1,"%d -> ", temp->element);
	temp = temp->next;
}
fclose(f1);
//insertFirst(head, 94);
//printList(head);
// print the linked list.
// delete the first element of the linked list.
// print the linked list again to check if delete was successful.
// print the linked list to a new file.
}
