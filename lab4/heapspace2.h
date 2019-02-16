#ifndef _heapspace
#define _heapspace
#include "ll.h"
int total_space;
extern node*  myalloc(int m);
extern void myfree(node* x,int size);
#endif

