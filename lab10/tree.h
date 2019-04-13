#include <stdio.h>
#include <stdlib.h>

struct node
{
	int key;
	struct node* left;	
	struct node* right;
	int height;
	
};
typedef struct node node;
struct stack
{
node* value;
struct stack* next;
};
typedef struct stack stack;
 
/* <0 left subtree taller
	>0 right subtree taller 
	=0 same height
	alternate bnode modelling
*/
extern node* add(node* root, int x);
extern node* find(node* x,int value);
extern int max(int a ,int b);
extern node* delete(node* root, int value);
extern int height(node* x);
extern node* right_rotate(node* x);
extern node* left_rotate(node* x);
extern int getBalance(node* x);
extern node* immediate_predecessor(node* x);
extern node* avl_add(node* root, int x);
extern node* avl_delete(node* x,int value);
extern node* inorder(node* root,int count, int k);
extern void rangeSearch(node* root, int low, int high);
extern node* nonrecuresive_inorder(node* root, int k);
extern stack* createstack();
extern node* top(stack* top);
extern node* pop(stack* top);
extern void push(stack* top,node* btree );
extern int isEmptyStack(stack* top);
extern void deletestack(stack* top);


