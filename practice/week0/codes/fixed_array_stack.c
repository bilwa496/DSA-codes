#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 5
int stack_arr[MAX];//Global
	int top = -1;
	
void push(int element)
{
	if(top==(MAX-1))
		printf("Stack Overflow!");
	else
	{
		top++;
		stack_arr[top] = element;
	}
}
int pop()
{
	if(top == -1)
	{
		printf("Stack Underflow!\n");
	}
	else
	{
		printf("popped element: %d\n",stack_arr[top]);
		top--;
	}
}
/*Display all stack elements*/
void display()
{
	if( top == -1)
		printf("stack is empty\n");
	else
	{
		for(int i = top;i>=0;i--)
		{
			printf("%d\n",stack_arr[i]);
		}
	}
} 

	
int main()
{
	printf("enter elements");
	int t;
	while(scanf(" %d",&t))
	{
		push(t);
	}
	printf("displaying stack: \t");
	display();
	printf("Popping output\t");
	while(top!= -1)
	{
	pop();
	}	
	//printf("")
	return 0;
}
