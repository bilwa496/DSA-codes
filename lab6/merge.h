#ifndef _merge
#define _merge
#include <stdio.h>
#include <stdlib.h>
struct Element
{
	float cgpa;
	char name[10];
};
typedef struct Element Element;
extern void merge(Element Ls1[], int sz1, Element Ls2[], int sz2, Element Ls[]);
#endif
