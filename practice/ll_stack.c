#include <stdio.h>
#include <math.h>
#include <stdlib.h>
struct Node
{
	int data;
	struct Node* next;
};
typedef struct Node node;
node*  create_stack()
{
	node* head = malloc(sizeof(node));
	head->next = NULL;
	return head;
}
void push(node *head, int value)
{
	node* new_node = malloc(sizeof(node));
	new_node->data = value;
	
	if(head->next == NULL)
	{
		new_node->next = NULL;
		head->next = new_node;
		//printf("Head!");
	}
	else
	{
		node* temp  = head;
	/*	head->next  =new_node;
		printf("data is %d && %d", new_node->data, head->data);
		new_node-> next = temp-> next;
			printf("data is %d", new_node->data);
	*/
		new_node->next = head->next;
		head->next = new_node;
	}
}

int isEmpty(node *head)
{
	if( head->next == NULL)
		return 1;
	else
		return 0;
}
int pop(node* head)
{
  if(isEmpty(head))
  	{
  		printf("stack empty!\n");
  		return 0;
  	}
  	node *temp;
  	temp  = head->next;
  	int data = temp->data;
  	//temp = temp->next;
  	head->next = (head->next)->next;
  	free(temp);
  	//temp->next = NULL;
  	
  	//free(temp);

  return data;
}

int main()
	{
	printf("enter elements\n");
	node* head;
	head = create_stack();
	int t;
	while(scanf("%d",&t))
	{
		//(scanf("%d",&t));
		push(head, t);		
	}
	/*printf("%d",((head)->next)->data);
	printf("%d\n",isEmpty(head));*/
while(!isEmpty(head->next))
	{
		printf("%d-> ",pop(head));
	}
			printf("%d",pop(head));

}

