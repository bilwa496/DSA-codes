#ifndef _qsort
#define _qsort
#include <stdio.h>
#include <stdlib.h>
struct record
{
 char name[10];
 long int empid;
};
struct pair
{
	int low;
	int high;
};
struct stack
{
	struct pair* array;
	int top;
	int size;
	
};

typedef struct stack stack;
typedef struct pair pair;

typedef struct record record;
extern record* quicksort(record s[],int n,int thresh);
extern stack* create_stack();
extern int isEmpty(stack* x);
extern int isFull(stack* x);
extern stack* push(stack *x,pair value);
extern void pop(stack* x);
extern pair topele(stack* x);
extern stack* resize(stack* x);
extern int partition(record arr[], int low,int high);

extern record* insertionsort(record a[],int size);
#endif
