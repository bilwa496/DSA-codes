#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int* create()
{
	int tableSize = profiling();
	int* ht =(int*)(malloc(sizeof(int)* tableSize));
	return ht;
}
int* insert(char** a, int j)
{
	if(a[j]!= '\0')
	{
	}
}


