/************************************************
*Name:Indraneel Ghosh							*    										  
*ID:2016B1A70938P							  	*
*												*
*												*
*************************************************/
#ifndef _linkedlist
#define _linkedlist
#include <stdio.h>
#include <stdlib.h>
#define MAX 700
int freed;

//points to the first memory location that is free
//define struct and function
struct ListHeader
{
	int head;
	//int headcount;
	int elementcount;
	//stores the index of head
};
typedef struct ListHeader listhead;

extern int createlist(int arr[],listhead head[],int count);
extern void createfreelist(int arr[]);

extern void sortedinsert(listhead h[],int count, int value,int arr[]);
extern listhead deletenode(int value,listhead h,int arr[]);
extern int totallist();
extern int countlist(listhead head);
extern void printalllist(listhead head[], int size,int arr[]);
extern void printfreelist();
extern void defrag(listhead h[],int count,int arr[]);


#endif
