#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct Node
{
	int data;
	struct Node* next;
	//Stack * previous;
};
typedef struct Node node;
node* create_queue()
{
	node* head = (node*)malloc(sizeof(node));
	head->next = NULL;
	return head;
}

void enqueue(node* head, int data)
{
	//node *temp = head;
	node* new_node = (node*)malloc(sizeof(node));
	new_node->data = data;
	if(head->next == NULL)
	{
		head->next = new_node;
	}
	else
	{
		new_node->next = head->next;
		head->next = new_node;
	}
}
int dequeue(node* head)
{
	node *temp = head;
	node* prev;
	prev = temp;
	temp = temp->next;
	int data;
	while(temp->next !=NULL)
	{
		prev = temp;
		temp = temp->next;
	//	printf("%d\t",temp->data);
	} 
	
	prev->next = NULL;
	data = temp->data ;
	free(temp);

	return data;
	
}
void display(node* head)
{
	node *temp = head;
	while((temp->next)->next !=NULL)
	{
		temp = temp->next;
		printf("%d -> ", temp->data);
		
	}
	temp = temp->next;
	printf("%d ", temp->data);
//	free(temp);		
}
void delete_queue(node* head)
{
	node *t1 = head;
	node *t2;
	while(t1 != NULL)
	{
		t2 = t1;
		t1 = t1->next;
		printf("%d Deleted",t1->data);
		free(t2);
	}
	
		
}
int isEmpty(node* head)
{
	if(head->next == NULL)
		return 1;
	else
		return 0;
}
	
int main()
{
	int t;
	node* head = create_queue();

	while(scanf("%d",&t))
	{
		enqueue(head,t);
	}
	display(head);
	printf("\n Dequeue: ");
	while(!isEmpty(head->next))
	{
		printf("%d -> ",dequeue(head));
	}
	printf("%d",dequeue(head));
	
}
