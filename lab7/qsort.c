
#include "qsort.h"
#include <stdio.h>
#include <stdlib.h>

stack* create_stack()
{
	stack* x = (stack*)malloc(sizeof(stack));
	x->size = 10;
	x->array = malloc(sizeof(pair)*x->size);
	x->top=-1;
//	printf("%d\n",x->top);
	
	return x;
}
int isEmpty(stack* x)
{
	if(x->top == -1)
	{
	printf("tr\t");
	return 1;
	}
	else
		return 0;
}
int isFull(stack* x)
{
//printf("%d\n",x->top);
	
	if(x->size-1 == x->top)
	{
		return 1;
	}
	else
		return 0;
}

stack* push(stack *x,pair value)
{
	if(isFull(x))
		resize(x);
	x->array[++x->top] = value;
	
	
	return x;
}
void pop(stack* x)
{
	if(!isEmpty(x))
	{
		
		x->top--;
	//	printf("%d\n",x->top);
	}
	else
		printf("Underflow!\n");
//	return theta;
}
pair topele(stack* x)
{
//	printf("%d %d\n",x->array[x->top].low, x->array[x->top].high);
	pair def;
	def.low = -1;def.high = -1;
	if(isEmpty(x))
		return def;
	return x->array[x->top];
}
stack* resize(stack* x)
{
	 x->array = (pair*)(realloc((x->array),sizeof(pair)*x->size*2));
	 x->size *=2;
	 return x;
}

int partition(record s[], int low,int high)
{
	record pivot = s[low];
	int left = low;
	int right = high;
	while(left<right)
	{
		while(s[left].empid<= pivot.empid)
			left++;
		while(s[right].empid > pivot.empid)
			right--;
		if(left<right)
		{
			record temp = s[left];
			s[left] = s[right];
			s[right] = temp;
		}		
	}
	record* temp;
	s[low] = s[right];
	 s[right] = pivot;
	 return right;
}	

record* quicksort(record s[],int size,int thresh)//thresh = size of sublist
{
	stack* x = create_stack(x);
	pair t;
	t.low = 0;
	t.high = size-1;
	x = push(x,t);
	
	while(!isEmpty(x))	
	{
	
		t = topele(x);
		pop(x);
		printf("t1 = %d %d\t",t.low,t.high);	
	
		int high = t.high;
		int low = t.low;
		printf("t val = %d %d",t.low,t.high); 
		if(high-low+1<thresh)
		{
			continue;
		}
		int q = partition(s,low,high);
//		printf("%d \t",q);
		if(q-1>low)
		{t.low = low;
		t.high = q-1;
		
	//	printf("t1 = %d %d\t",t.low,t.high);
		x = push(x,t);
		}
		
		if(q+1<high)
		{
			t.low = q+1;
			t.high = high;
			x = push(x,t);
		}
//			printf("%d %d\n",x->array[x->top].low, x->array[x->top].high);
//printf("\n");

	}
		printf("\nStarting\n");

	for(int i=0;i<size;i++)
	{
		printf("%s %ld\n",s[i].name , s[i].empid);
	}

	return s;
}	

record* insertionsort(record a[],int size)
{
	int i = 0,j;
	for(int i=1;i<size;i++)
	{
		j = i-1;
		record key = a[i];
		while(j>=0 && a[j].empid > key.empid)
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1]=key;
	}
	return a;
}
