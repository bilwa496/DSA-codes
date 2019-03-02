#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "record.h"
static int num=0;
record* createarray()
{
	record* arr= (record*)(malloc(sizeof(record)*5));
	arr->size = 5;
	return arr;
}

bool isFull(record* arr)
{

	if(num<=arr->size)
	{
		return false;
	}
	else
		return true;
}

record* resize(record* arr)
{
	if(isFull(arr))
	{
		arr = (record*) (realloc(arr,sizeof(record)*arr->size*2));
		arr->size*=2;
	}
	return arr;
}
record* insertelements(record* arr, record x)
{
	
		if(num>=arr->size)
		{
			arr = resize(arr);
		}
		else
		{
			(arr+num)->card_no = x.card_no;
			strcpy(x.card_no,(arr+num)->bank_code);
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
	else
	{
	insertion_sort(arr,n-1);
	record key = *(arr+n-1);
	int j = n-2;
	while(j >=0 && (arr+j)->card_no > key.card_no)
	{
	*(arr+j+1) = *(arr+j);
	j--;
	}
	*(arr+j+1) = key;
	record *x = (arr+n-1);
		//insertinorder(arr,x,(n-1));
	}
}
		
  
		
	
