#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "record.h"

record* createarray()
{
	record* arr= (record*)(malloc(sizeof(record)*5));
	arr->size = 5;
	return arr;
}

bool isFull(record* arr,int num)
{

	if(num<=arr->size)
	{
		return false;
	}
	else
		return true;
}

record* resize(record* arr,int num)
{
	if(isFull(arr,num))
	{
		arr->size = arr->size*2;
		arr = (record*) (realloc(arr,(sizeof(record)*arr->size)*2));
	}
	return arr;
}
void insertelements(record* arr, record x,int num)
{
	
		if(num>=arr->size)
		{
			arr = resize(arr,num);
		}
		else
		{
			(arr+num)->card_no = x.card_no;
			strcpy(x.bank_code,(arr+num)->bank_code);
			(arr+num)->expiry_month = x.expiry_month;
			(arr+num)->expiry_year = x.expiry_year;
			strcpy((arr+num)->first_name,x.first_name);
			strcpy((arr+num)->last_name,x.last_name);
			num++;
		}
	
}
 void insertinroder(record* arr,record* x,int n)
 {
 	 int  j;
 	 j = n-1; 
 	 record* key = x;
       while (j >= 0 && (arr+j)->card_no > key->card_no) 
       { 
           *(arr+j+1) = *(arr+j); 
           j = j-1; 
       } 
       *(arr+j+1) = *key; 
 
}
void insertion_sort(record* arr,int n)
{
	if (n<=1)	
	{
		return ;
	}
	
	insertion_sort(arr,n-1);
	record key = *(arr+n-1);
	int j = n-2;
	while(j >=0 && (arr+j)->card_no > key.card_no)
	{
	*(arr+j+1) = *(arr+j);
	j--;
	}
	*(arr+j+1) = key;
	printArray(arr,n);
	//record *x = (arr+n-1);
		//insertinorder(arr,x,(n-1));
	
}
void printArray(record* arr,int num)
{
	printf("\n Starting\n");
	for(int i=0;i<num;i++)
	{
	printf("%llu %s %u %u %s %s \n",(arr+i)->card_no,(arr+i)->bank_code,(arr+i)->expiry_month,(arr+i)->expiry_year,(arr+i)->first_name,(arr+i)->last_name);
	}
}
  
		
/*	int size;
	long long unsigned card_no;
	char bank_code[16];
	unsigned int expiry_month, expiry_year; 
	char first_name[50];
	char last_name[50];
*/	
