#ifndef _records
#define _records
#include <stdio.h>
#include <stdlib.h>
struct Record
{
	int size;
	long long unsigned card_no;
	char bank_code[16];
	unsigned int expiry_month, expiry_year; 
	char first_name[50];
	char last_name[50];
} ;
typedef struct Record record;
extern record* createarray();
extern void insertion_sort(record* arr,int n);
extern  void insertinroder(record* arr,record* x,int n);
#endif

