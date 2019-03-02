#include <stdio.h>
#include <stdlib.h>
void p()
{
	int a;
	printf("%u\t",&a) ;

	int b;
	printf("%u\t",&b) ;
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
/*Expirment with the positions of the function
Use size ./a.out to see the memory layout
Points worth oting:
Each function has a stack off which the static variables are being allocated. When the function end is reached the stack is popped and emptied for the function.
Dynamic Memory Allocation(malloc and calloc) occurs in heap and follows similar ideas */