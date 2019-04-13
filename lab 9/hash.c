#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int hash(int tableSize, int base,char *x)
{
	int sum = 0;
	for(int i=0;i<strlen(x);i++)
	{
		sum+=((int)x[i]);
	}
	printf("%d\n",sum);
	int ans = (sum%base)%tableSize;
	return ans;
}
int collision_count(char **x, int n, int base, int tableSize)
{
	int ht[tableSize];
	for(int i=0;i<tableSize;i++)
	{
		ht[i] = 0;
	}
	int count = 0;
	for(int i=0;i<n;i++)
	{
	 	int theta = hash(tableSize,base, *(x+i));
	 	if(ht[theta] == 1)
	 		count++;
	 	else
	 	{
	 		ht[theta] = 1;
	 	}
	}	
	return count;
}
char** parsing()
{
	FILE* fp = fopen("aliceinwonderland.txt","r");
	int count = 0;
	char **book;
	int max = 1000;
	book =(char**)(malloc(sizeof(char*)*max));
	
	if(fp == NULL)
	{
		printf(" error\n");
		return book;
	}
	//int max = 1000;

	for(int i=0;i<max;i++)
	{
		book[i] = (char*)(malloc(sizeof(char)*50));//max string length
	}
	
	char* x;
	while(fscanf(fp," %s ",x)!=-1)
	{
		for(int j=0;j<strlen(x);j++)
		{
			if(!isalpha(x[j]))
			{
				printf("don't count as string\n");
			}
		}

			if(count == max)
			{
				int prev =  max;
				max *= 2;
				book =  (char**)(realloc(book, sizeof(char*)*max));
				for(int j = prev+1;j<max;j++)
				{
					book[j] = (char*) (malloc(sizeof(char)*50));
				}
			}
			
			strcpy((*book + count),x) ;			
			count++;
		
	}
	printf("%d\n",count);
	return book;
}
//need to figure out a way to take a string input of the exact length not length+2/3
int isPrime(int x)
{
	for(int i=2;i*i<=x;i++)
	{
		if(x%i==0)
			return 0;
	}
	return 1;
}	
int profiling()
{
	int table = 5000;
	char **in = parsing();
	char **tracker;
	tracker = in;
	int count = 0;
	mintable = 0;
	while((*tracker)!=NULL)
	{
		count++;
		(*tracker)++;
	}
	for(int t = 0;t<3;t++)
	{
	int x,count = 0;
	int temp,min =100000;
		for(int i = table;i<=2*table && count <3;i++)
		{
	
			if(isPrime(i))
			{
				count++;
		
				temp =  collision_count(in, count, i, table);
							printf("%d %d %d\n",temp,x,table);
	
				if(temp < min)
				{
					min = temp;
					
					mintable = table;
				}
			}
		}
		count = 0;
		x = 1000*table; 
		while(count<3)
		{
			if(isPrime(x))
			{
				temp =  collision_count(in, count, x, table);
				printf("%d %d %d\n",temp,x,table);
				if(temp < min)
				{
					min = temp;
					mintable = table;
				}
			}
			x++;
		}
		table *= 10;
	}
return mintable;
}



int main()
{
}
