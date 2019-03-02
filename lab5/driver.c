#include <stdio.h>
#include <sys/time.h>
int main()
{

	struct timeval start, stop;
	double secs = 0;

	gettimeofday(&start, NULL);

	long long unsigned card_no;
	char bank_code[16];
	unsigned int expiry_d;
	unsigned int expiry_month;
	char first_name[50];
	char last_name[50];
	FILE* fp = fopen("10000","r"); 
	while(fscanf(fp,"\"%llu,%[^,],%u/%u,%[^,],%[^\"]\"\n",&card_no,bank_code,&expiry_d,&expiry_month,first_name,last_name)!=-1)
	{
		printf("%llu\t%s\t%u / %u\t%s\t%s\n",card_no,bank_code,expiry_d,expiry_month,first_name,last_name);
		record temp;
		temp.card_no = card_no;
		strcpy(temp.bank_code, bank_code);
		temp.expiry_month = expiry_d;
		temp.expiry_year = expiry_month;
		strcpy(temp.first_name,first_name);
		strcpy(temp.last_name, last_name);
		
	}

	gettimeofday(&stop, NULL);
	secs = (double)(stop.tv_sec - start.tv_sec);
	fprintf("time taken %f\n",secs);

}
	
