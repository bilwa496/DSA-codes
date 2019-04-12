#include"node.h"
#include<stdio.h>
#include<stdlib.h>
//2016B1A70938P
Locality * ReadFileintoLists(char *filename)
{
 	FILE* fptr = fopen(filename,"r");
 	int id,count;
 	int locality;
 	if(fptr == NULL)
 	{
 		return NULL;
 	}
 	Locality* temp1;
 	Locality* head;
 	
 	for(int k = 0;k<N;k++)
 	{
 			fscanf(fptr,"%d,",&count);
 			//printf("%d,",count);
 			Locality* list = (Locality*)(malloc(sizeof(Locality*)));
 			if(k==0)
 			{
 			list->count = count;
 			list->first = NULL;
 			list->next = NULL;
 			temp1 = list;
 			head = list;
 			}
 			else if(k>0)
 			{
	 			list->count = count;
	 			list->first = NULL;
	 			list->next = NULL;
	 			temp1->next = list;
	 			temp1 = temp1->next;
	 		}
 			
 			
 			Member* temp;
 			for(int i=0;i<count;i++)
 			{
	 			if(i==count-1)
	 			{
	 				fscanf(fptr,"%d\n",&id);
	 			//	printf("%d\n",id);
	 			}
	 			else
	 			{
	 				fscanf(fptr,"%d,",&id);
	 		//		printf("%d, ",id);
	 			}
	 			if(i==0)
	 			{
	 				Member* newnode = (Member*)(malloc(sizeof(Member)));
	 				newnode->id = id;
	 				newnode->next = NULL;
	 				list->first = newnode;
	 				temp = newnode;
	 				
	 			}
	 			else
	 			{
	 				Member* newnode = (Member*)(malloc(sizeof(Member)));
	 				newnode->id = id;
	 				newnode->next = NULL;
	 				temp->next= newnode;
	 				temp = temp->next;
	 			}
	 				
	 		}
	 		//printf("first=  %d\n",list->first->id);
	 }
	 return head;
}	

void PrintLists (Locality *start)
{
	while(start!=NULL)
	{
	printf("%d->",start->count);
	Member* theta;
	theta = start->first;
	while(theta->next!=NULL)
	{
		printf("%d->",theta->id);
		theta = theta->next;
	}
	printf("%d",theta->id);
	theta = theta->next;
	printf("\n");
	/*printf("\n|");
	*/
	start = start->next;
	}	

}
/*typedef struct node1 Member;
typedef struct node2 Locality;
typedef enum { FALSE, TRUE} BOOL;
int * Arr[N];
int Num_Elements[N];
struct node1
{
  int id;
  Member * next;
};

struct node2
{
  int count;
  Member *first;
  Locality *next;
};
*/
