#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
	int i,num=0;
	for(i = 0;i<argc;i++)
	{
		if(i==0)
		{
		int j;
		for(int j=2;j<strlen(argv[i]);j++)
		{
			printf("%c",*(argv[i]+j));
		}
		printf("\t");
		}
		else
		{
		num = 0;
		int count = 0;
		
		if(*argv[i]>=48 && *argv[i]<=57)
		{
		
			num = atoi(argv[i]);
		//	printf("%d\t",((num)+3));
		
		}
		
		printf("%s\t",argv[i]);
		
		}
	}

}
