#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

//no height balancing

node* add(node* root, int x)
{
	if(root==NULL)
	{
		root->key = x;
	}
	else
	{
		if(x<=root->key)
			root->left = add(root->left,x);
		else
			root->right = add(root->right,x);
	}
	return root;
}
node* find(node* root, int value)
{
	if(root->key==value)
		return root;
	else
	{
		if(value<=root->key)
		{
		 	return find(root->left, value);
		}
		else
		{
			return find(root->right,value);
		}
	}
}
int max( int a,int b)
{
	return (a>b) ? a :b;
}
node* immediate_predecessor(node* x)
{
	while(x->right!=NULL)
	{
		x = x->right;
	}
	return x;
}
node* delete(node* root, int key)
{
	if(root==NULL)//base case
		return  root;
	if(key<root->key)
	{
		root->left = delete(root->left, key);
	}
	else if(key>root->key)
	{
		root->right = delete(root->right,key);
	}
	else
	{
		//one child or no child
		if(root->left==NULL)
		{
			node* temp = root->right;
			free(root);
			return root;
		}
		else if (root->right == NULL)
		{
			 node* temp = root->left;
			 free(root);
			 return temp;
		}
		//if both have children node
		node* temp = immediate_predecessor(root->left);
		root->key = temp->key;
		free(temp);
		return root;
	}
}
void preorder(node* root)
{
	if(root)
	{
		printf("%d ",root->key);
		preorder(root->left);
		preorder(root->right);
	}
}
void nonrecursivepreorder(node* root)
{
	stack* s = createstack();
	while(1)
	{
		while(root)
		{
			printf("%d", root->key);
			push(s,root);
			root = root->left;
		}
		if(isEmptyStack(s))
			break;
		pop(s);
		root=  root->left;
	}
	deletestack(s);		
}


int height(node* x)
{
	if(x==NULL)
		return 0;
	return x->height;
}

int isAVL(node* root)
{
	int left,right;
	if(!root)
		return 0;
	left = isAVL(root->left);
	if(left == -1)
	{
		return left;
	}
	right =  isAVL(root->left);
	if(right == -1)
		return right;
	if(abs(left-right)>1)
	{
	return -1;
	}
	return max(left,right)+1;
}

node* right_rotate(node* x)
{
	node* y = x->left;
	node* t1 = y->left;
	node* t2 = y->right;
	node* z= x->right;
	node* temp = t2;
	y->right = x;
	x->left = temp;
	x->height = max(((x->left)->height),((x->right)->height))+1;
	y->height = max(((y->left)->height),((y->right)->height))+1;
	return y;
}

node* left_rotate(node* x)
{
	node* y = x->right;
	node* t1 = x->left;
	node* t2 = y->left;
	node* t3 = y->right;
	node* temp = t2;
	y->left = x;
	x->right = t2;
	x->height = max(((x->left)->height),((x->right)->height))+1;
	y->height = max(((y->left)->height),((y->right)->height))+1;
	return y;
}

int getBalance(node* x)
{
	if(!x)
		return 0;
	
	return (height(x->left))-(height(x->right));	
} 

node* avl_add(node* root, int x)
{
	if(root == NULL)
	{
		root->height = 1;
		return root;
	} 
	else 
	{
		if(x <= root->key)
		{
		root->height = 1+(max(height(root->left),height(root->right)));
		root->left = avl_add(root->left, x);
		}
		else
		{
		root->height++;
		root->right = avl_add(root->right,x);
		}
	}
}

node* avl_delete(node* x,int value) 
{
	if(x == NULL)
		return NULL;

	if(value< x->key)
	{
	 x->left= avl_delete(x->left,value);
	}
	else if(value > x->key)
	{
	 	x->right= avl_delete(x->right,value);
	}
	else
	{
		if(x->right == NULL)
		{
		node* temp  =x->left;
		*x = *temp;//copy contents
		free(temp);			
		}
		else if( x->left == NULL)
		{
		node* temp = x->right;
		*x = *temp;
		free(temp);
		}
		else //node has two children
		{
		node* temp = immediate_predecessor(x->left);
		x->key = temp->key;
		x->left = avl_delete(x->right,temp->key);
		}
	}
	//height update
	x->height = max(height(x->left),height(x->right))+1;
	//Calculate balance factor
	int bal = getBalance(x);
	// Multiple cases 
	// Left left
	if(bal>1 && getBalance(x->left) >=0)
	{
		return right_rotate(x);
	}
	//left right case
	else if(bal>1 && getBalance(x->left)<0)
	{
		x->left = left_rotate(x->left);
		return right_rotate(x);
	}
	//right left case
	else if(bal<-1 && getBalance(x->right) >0)
	{
		x->right = right_rotate(x->right);
		return left_rotate(x);	
	}
	//right right
	else if(bal<-1 && getBalance(x->right) <=0)
	{
		return left_rotate(x);
	}
}
// Rank Query (To Do : Non-recursive approach->use stacks and track popping actions kth element to be popped is the answer)
node* nonrecuresive_inorder(node* root, int k)
{
	stack* s =  createstack();
	int count =0;
	while(1)
	{
		while(root)
		{
		push(s,root); // save the root
		root = root->left; // go to left subtree for the given root
		}
		if(isEmptyStack(s))
			break;
		root = pop(s);
		if(count!=k) // at the given node
			count++;
		else
			return s->value;
		root = root->right;
	}
}
//last problem to be solved
node* inorder(node* root, int k,int count)
{
	//bst is always sorted
	if(root==NULL)
	{
		return NULL;
	}
	node* left = inorder(root->left,k,count);//search in left subtree
	if(left) // if found in left subtree return the node
		return left;
	else if(++count == k)	// if current element is the kth smallest element return it as the ans (tracking the count of that particular node)
		return root;
	return inorder(root->right,k,count);	//else search the right subtree	
}
// Range Query: Find all records in bt with keys in the given range
void rangeSearch(node* root, int low, int high)
{
	if(!root)//base case
	return;
	if(root->key<low)
	{
		rangeSearch(root->right, low,high);
	}
	else if(root->key>high)
	{
		rangeSearch(root->left, low,high);
	}
	else
	{
		rangeSearch(root->left, low, root->key);
		printf("%d", root->key);
		rangeSearch(root->right, root->key, high);
	}
	
}
int main()
{
}
