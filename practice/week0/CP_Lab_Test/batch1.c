/* C File template for execution */

#include<stdio.h>
#include<stdlib.h>

/* Link list node */

struct subject
{
   char course;
   int marks[3];
};


struct node
{
    int roll_no;
    struct subject sub[2];
    struct node* next;
};
//Following function is used to insert a node and thus create a linked list.
void add(struct node** head_ref, int rollno, int *mark,char course)
{
     int i=0;
     struct node* new_node = (struct node*) malloc(sizeof(struct node));
     new_node-> roll_no = rollno;
     if(course=='A'){
	new_node-> sub[0].course = 'A';
	new_node-> sub[1].course = '0';
	for(i=0;i<3;i++){
            new_node->sub[0].marks[i] = mark[i];
		new_node->sub[1].marks[i] = -1;
	}
     } else{
	new_node-> sub[1].course = 'B';
	new_node-> sub[0].course = '0';
	for(i=0;i<3;i++){
		new_node->sub[0].marks[i] = -1;
     		new_node->sub[1].marks[i] = mark[i];
	}
     }


     new_node->next = (*head_ref);
     (*head_ref) = new_node;
}

void printList(struct node *node ){
while (node != NULL)
    {   int i;
        printf ("%d ", node->roll_no);
	printf("%c ",node->sub[0].course);
	for(i=0;i<3;i++)
		printf("%d ",node->sub[0].marks[i]);
	printf("%c ",node->sub[1].course);
	for(i=0;i<3;i++)
		printf("%d ",node->sub[1].marks[i]);
	printf("\n");
        node = node->next;
    }

}
/* Question 1 */
struct node *getUnion(struct node *head1, struct node *head2)
{

     struct node* headref = (struct node*) malloc(sizeof(struct node));
     struct node* temp1;
     
     struct node* temp2;
	while(head1 != NULL)
	{
	temp2 = head2;
	temp1 = headref;
	temp1->next = NULL;	
	if(head1->sub[0].course = 'A') 
		{		
		add(&headref,head1->roll_no,(head1->sub[0]).marks, (head1->sub[0]).course);
		temp1 = headref;
		}/*
		int flag = -1;
		while(temp2!= NULL)
		{
		if(head1->roll_no == temp2->roll_no)
		{
		temp1->sub[1]= temp2->sub[1];
		temp2= temp2->next;
		}*/
		head1 = head1->next;
	}
	temp1 = headref;
	temp2 = head2;
		while(temp2!= NULL)
		{
		
			temp1 = headref;
			while(temp1!=NULL)
			{
				if(temp1->roll_no == temp2->roll_no)
				{
	
			
					temp1->sub[1] = temp2->sub[1];
					
				}
				temp1 = temp1->next;
			
			}
			temp2 = temp2->next;
		}
	temp2 = head2;
	temp1 = headref;
//	printf("check");
	
	while(temp2!=NULL)
	{
	int flag = -1;
//	printf(" %d ->",temp2->roll_no);
temp1 = headref;

	while(temp1!=NULL)
	{
//	printf(" %d ->",temp1->roll_no);

	if(temp2->roll_no== temp1->roll_no)
	{
//		printf(" %d ->",temp2->roll_no);

	flag = 1;
//	printf("flag = %d",temp2->roll_no);
//	add(&headref,temp2->roll_no,(temp2->sub[1]).marks,(temp2->sub[1]).course);
	}
	temp1 = temp1->next;
	}
	if(flag!=1)
	{
	add(&headref,temp2->roll_no,(temp2->sub[1]).marks,(temp2->sub[1]).course);
	}
	 temp2 = temp2->next;
	}
	
	temp2 = headref;
	while(temp2->next!=NULL)
	{
	temp2 = temp2->next;
	}
	temp2->next = NULL;
	temp2 = headref;
	//temp2= headref->next;
	/*while(temp2!= NULL)
	{
		printf("%d %c %d\n",temp2->roll_no,(temp2->sub[0]).course,(temp2->sub[0]).marks[1]);
		temp2 = temp2->next;
	}*/
	return temp2;

 /* Write body of this function. Upload this function on portal in corresponding textbox*/
}


/* Question 2 */
void printList_Marks(struct node *head1, struct node *head2)
{
while(head1 !=NULL)
{
		if((head1->sub[0]).marks[2] > 50)
		{
			printf("%d %c %d\n",head1->roll_no,(head1->sub[0]).course,(head1->sub[0]).marks[1]);
		}
		if((head1->sub[1]).marks[2] > 50)
		{
			printf("%d %c %d\n",head1->roll_no,(head1->sub[0]).course,(head1->sub[1]).marks[1]);
		}
	head1 = head1->next;
}
while(head2 !=NULL)
{
		if((head2->sub[0]).marks[2] > 50)
		{
			printf("%d %c %d\n",head2->roll_no,(head2->sub[1]).course,(head2->sub[1]).marks[1]);
		}
		if((head2->sub[1]).marks[2] > 50)
		{
			printf("%d %c %d\n",head2->roll_no,(head2->sub[1]).course,(head2->sub[1]).marks[1]);
		}
		head2 = head2->next;
	
}



 /* Write body of this function and upload it on the portal in corresponding textbox */
}

int main()
{
    /* Start with the empty list */
    struct node* head1 = NULL;
    struct node* head2 = NULL;
    struct node* unin = NULL;

    /*create a linked list for course A */
    int st1_mrA[3] = {80,85,92};
    add (&head1, 10, st1_mrA,'A');

    int st2_mrA[3] = {10,40,92};
    add (&head1, 20, st2_mrA,'A');
    int st3_mrA[3] = {25,43,91};
    add (&head1, 30, st3_mrA,'A');

    /*create a linked list for course B */
    int st1_mrB[3] = {73,45,92};
    add (&head2, 40, st1_mrB,'B');

    int st2_mrB[3] = {13,34,87};
    add (&head2, 20, st2_mrB,'B');

    int st3_mrB[3] = {30,54,29};
    add (&head2, 30, st3_mrB,'B');

    /* Calling a function for union */
    unin = getUnion (head1, head2);

    printf ("\nQuestion One Solution: Union list is \n");

    printList(unin);

    printf("\nQuestion Two Solution: \n");

    printList_Marks(head1, head2);

    return 0;
}
