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
}
int main()
{
	p();
	q();
}