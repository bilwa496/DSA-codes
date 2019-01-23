#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE* f1 = fopen("fil1.txt","r");
	FILE* f2  = fopen("file2.txt","w");
	char c = fgetc(f1);
	while(c!= EOF)
	{
	 fputc(c,f2);
	 c = fgetc(f1);
	}
}

