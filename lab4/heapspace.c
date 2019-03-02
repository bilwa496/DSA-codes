#include <stdio.h>
#include <stdlib.h>
#include "ll.h"
#include "heapspace2.h"
int total_space  = 0;
node* myalloc(int m)
{
	node* a = (node*)(malloc(m));
	
	if(a==NULL)
	{
		printf("Failure\n");
		return a;
	}
	total_space += m;
	printf("Call = %d\t",total_space);
	for(int i=0;i<m;i++)
	{
		printf("%u \t",a+i);
	}
	return a;
}
void myfree(node* x,int size)
{

	total_space -= size;
	printf("%d\t",total_space);
	free(x);	
}
/*Important Points:
malloc allocates some extra metadata for tracking the memory it is supposed to allocate and deallocate (Internal feature of C)
Exercise:
Replace the code with void in place of node* and test. You would get simlar memory management done by malloc and calloc.(Pointing to the existence of metadata)
 However as the metadata is not reliable myfree and myalloc functions must be passed with size.


Also note how the memory allocation occurs. It is important to note that stack grows up in size(You push onto the stack from above. This kind of an architecture helps limit stack space. (You can test this by setting your dataset to a size almost as big as the RAM of your system and seeing the behavior of your system)
  */
