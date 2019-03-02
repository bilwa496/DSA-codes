#include <stdio.h>
#include <stdlib.h>
void p()
{
	int a;
	printf("%u\t",&a) ;
}
void q()
{
	int a;
	printf("%u\t",&a) ;
	p();
	int b;
	printf("%u\t",&b) ;
	p();
}
int main()
{
	q();
}