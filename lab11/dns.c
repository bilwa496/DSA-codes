#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dns.h"

node* tree_construct()
{
	node* root = malloc(sizeof(node));
	root->child = NULL;
	root->sibling = NULL;
	root->value = NULL;
	return root;
}

node* treeinsert(char *name, char* ip,node* root)
{
	int n1,n2;
	n1 = strlen(name);
	n2 = strlen(ip);
	char **x;
	//printf("reached");
	x =(char**) malloc(sizeof(char*)*n1);
	for(int i=0;i<n1;i++)
	{
		x[i] = (char*)(malloc(sizeof(char)*30));
	}
	 int j = 0;
	 int k=0;
	//tokenizing
	int i = n1-1;
	while(i>=0)
	{	while(name[i]!='.' && i>=0)
		{
		//printf("%d %d %d\t", k ,j ,i);
				x[k][j] = name[i];
				j++;
				i--;
		}
			char tname[j+1];
		//reversing the string
		if(name[i] == '.')
		{
			int end = j-1;
			int l =0;
			for(l=0;l<j+1;l++)
			{
				tname[l] = x[k][end];
				end--;
			}
			tname[l]='\0';
			strcpy(x[k],tname);
			//printf("%s %d \t",x[k],k);
			 j = 0;
			 k++;
			 i--;
		}
	}
	//root = root->child;
	node* temp = root->child;
	int level = 1;
	node* prev = root;
	if(temp == NULL)
	{
		while(k>=level)
			{
				temp = (node*)(malloc(sizeof(node)));
				temp->value = (char*)(malloc(sizeof(char)*strlen(x[level-1])));
				strcpy(temp->value,x[level-1]);
				prev->child = temp;
				prev = temp;
				temp = temp->child;
				level++;
			}
	}
	else
	{

			
		}
		while(temp==NULL && level<=k)
		{
			node* newnode= malloc(sizeof(node));
			prev->child = newnode;
			temp = newnode->child;
			newnode->value = (char*)(malloc(sizeof(char)*strlen(x[level-1])));
			strcpy(newnode->value,x[level-1]);
			prev = newnode;
			level++;
		}
	}
	return root;	
}
//Print all the nodes
void printData(node* root)
{
	printf("%s ", root->value);
	if(root->sibling)
	{
		printData(root->sibling);
	}
	printf("\n");
	if(root->child)
	{
		printData(root->child);
	}
}
void readData(FILE* fptr,node* root)
{

	int n;
	fscanf(fptr,"%d\n",&n);
	char name[n][1000];
	char ip[n][1000];
	for(int i=0;i<n;i++)
	{
		fscanf(fptr,"%s %s\n",name[i],ip[i]);
				printf("%s %s\n",name[i],ip[i]);
		/*if(root->value==NULL)
		{
		printf("Exists!");		
		}
		else
			printf("DNE");*/

		treeinsert(name[i],ip[i],root);
	}
}
void search_tree(node* root, char* name)
{
	int n1 = strlen(name);
	char **x;
	x =(char**) malloc(sizeof(char*)*n1);
	for(int i=0;i<n1;i++)
	{
		x[i] = (char*)(malloc(sizeof(char)*30));
	}
	 int j = 0;
	 int k=0;
	//tokenizing
	for(int i=n1-1;i>=0;i--)
	{
	
		while(name[i]!='.')
		{
				x[k][j] = name[i];
				j++;
		}
		char tname[j];
		//reversing the string
		if(name[i] == '.')
		{
		
			for(int l=0;l<j;l++)
			{
				tname[j-l-1] = x[k][l];
			}
			for(int l=0;l<n1;l++)
			{
				x[k][l] = tname[l];
			}
			 j = n1-1;
			 k++;
		}
	}
	
}	
void lookup(FILE* fp,node* root)
{
	char name[1000];
	fscanf(fp,"%s\n",name);
	search_tree(root,name);
	//write the search function
}

int main()
{

	int x;
	FILE* fptr = fopen("file.txt","r");
	node* root;
	while(!feof(fptr))
	{
	fscanf(fptr,"%d",&x);
	if(x==1)
	{ 
		root = tree_construct();
		readData(fptr,root);
	}
	else if(x==2)
	{
		lookup(fptr,root);
	}
	else if(x==-1)
		return 0;
/*	else if(y==-1)
		return 0;*/
	}
}
