#include <stdio.h>
#include <string.h>
int main()
{
	int arr[10];
	memset(arr,-1,10*sizeof(int));//use this command
	
	for(int i=0;i<10;i++)
	{
		printf("%d ", arr[i]);
	}
}