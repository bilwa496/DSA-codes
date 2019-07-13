# Notes 

## TODO
Experiment with the positions of the function
Use size ./a.out to see the memory layout
Points worth noting:
Each function has a stack off which the static variables are being allocated. When the function end is reached the stack is popped and emptied for the function.
Dynamic Memory Allocation(malloc and calloc) occurs in heap and follows similar ideas 



## Other Important Points:
- **malloc allocates some extra metadata for tracking the memory it is supposed to allocate and deallocate (Internal feature of C). However, this information is highly unreliable.**


## Exercise:
- **Replace the code with void in place of node* and test. You would get simlar memory management done by malloc and calloc.(Pointing to the existence of metadata**
However as the metadata is not reliable (for implementation purposes) myfree and myalloc functions must be passed with size.
<br />

- Look at the implementation of myalloc and myfree functions for ideas about how malloc,sizeof and free functions work in C/C++.

Also note how the memory allocation occurs. It is important to note that stack grows up in size(You push onto the stack from above. This kind of an architecture helps limit stack space. (You can test this by setting your dataset to a size almost as big as the RAM of your system and seeing the behavior of your system)
