#include <stdio.h>
#include <stdlib.h>

struct node
{
	char* value;
	struct node* child;
	struct node* sibling;
};
typedef struct node node;
extern node* tree_construct();
extern node* treeinsert(char *name, char* ip,node* root);
extern void printData(node* root);
extern void readData(FILE* fptr,node* root);
extern void search_tree(node* root, char* name);
extern void lookup(FILE* fp,node* root);


