#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE* f1 = fopen("fil1.txt","r");
	FILE* f2  = fopen("file3.txt","w");
	char c;
	//fflush(stdin);
	
	while(fscanf(f1,"%c",&c)==1)	
	{
	 fprintf(f2,"%c",c);
	// printf("%c",c);
	 //fflush(stdin);
	//fscanf(f1,"%c",&c);
	
	}
	fclose(f1);
	fclose(f2);
	return 0;
}

