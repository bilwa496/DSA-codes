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
int collision_count(char **x, int base, int tableSize)
{
	int ht[tableSize];
	for(int i=0;i<tableSize;i++)
	{
		ht[i] = 0;
	}
	int count = 0;
	for(int i=0;x[i]!=NULL;i++)
	{
	 	int theta = hash(tableSize,base,x[i]);
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
	
	char* x = (char*)(malloc(sizeof(char)*50));
	while(fscanf(fp," %s ",x)!=-1)
	{
		int flag = 0;
		for(int j=0;x[j]!='\0';j++)
		{
			if(!isalpha(x[j]))
			{
			flag = 1;
			break;
				//printf("don't count as string\n");
			}
		}
		if(!flag)
		{
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
		
	}
	printf("Number of words = %d\n",count);
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
	int mintable = 0;
	for(int t = 0;t<3;t++)
	{
	int x,count = 0;
	int temp,min =100000;
		for(int i = table;i<=2*table && count <3;i++)
		{
	
			if(isPrime(i))
			{
				count++;
		
				temp =  collision_count(in, i, table);
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
				temp =  collision_count(in,  x, table);
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
	char ** books;
	books = parsing();
	printf("%d",profiling());
	return 0;
}
