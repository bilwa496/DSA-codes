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
node* insert(char** terms,int k node* root)
{
	node* current = root->child;
	node* prev = root->child;
	node* levelcurrent,levelprev;
	//k is size of terms array
	int i=0;
	//base case
	int level = 1;
	if(current==NULL)
	{
	for(int i=0;i<k;i++)
	{
		node* newnode = (node*)(malloc(sizeof(node)));
		strcpy(newnode->value,terms[i]);
		newnode->child = NULL;
		newnode->sibling = NULL;
		prev->child = newnode;
		current = newnode;
		prev = current;
		current = current->child;		
	}
			node* newnode = malloc(sizeof(node));
			newnode->value = (char*)(malloc(sizeof(char)*(1+strlen(ip))));
			newnode->value =ip;
			newnode->child = NULL;
			newnode->sibling = NULL;
		//	printf("ip = %s",ip);
			prev->child = newnode;
	}
	else
	{
	 levelcurrent = current;
	 levelprev = current;
	while(k>=level)
	{
	while(levelcurrent!=NULL)
	{
		if (strcmp(levelcurrent->value,x[level-1])!=0)
		{
			levelprev = levelcurrent;
			levelcurrent = levelcurrent->sibling;
		}
		else if (strcmp(levelcurrent->value,x[level-1])==0)
		{
			levelprev = levelcurrent;
			prev = levelprev;
			temp = levelcurrent->child;
			levelcurrent = levelcurrent->child;
			level++;
			continue;
		}
	}
	if(levelcurrent==NULL)
	{
		node* newnode =(node*)(malloc(sizeof(node)));
		newnode->value = (char*)(malloc(sizeof(char)*(strlen(x[level-1]+1)));
		newnode->child= NULL;
		newnode->sibling = NULL;
		strcpy(newnode->value,x[level-1]);
		levelprev->sibling = newnode;
		levelcurrent = newnode;
		temp = levelcurrent;
		prev = temp;
		temp = temp->child;
		while(temp==NULL && level<=k)
		{
			node* newnode = malloc(sizeof(node));
			prev->child = newnode;
			temp = newnode->child;
			newnode->value = (char*)(malloc(sizeof(char)*(strlen(x[level-1]+1)));
			strcopy(newnode->value,x[level-1]);
			newnode->child =NULL;
			newnode->sibling = NULL;
			prev= newnode;
			current = newnode->child;
			level++;		
		}
	}
	}
			node* newnode = malloc(sizeof(node));
			newnode->value = (char*)(malloc(sizeof(char)*(1+strlen(ip))));
			newnode->value =ip;
			newnode->child = NULL;
			newnode->sibling = NULL;
		//	printf("ip = %s",ip);
			prev->child = newnode;
	}
	 return root;	
}
void find(char* name,node* root)
{
	int i=0,j=0,k=0;
	char** x;
	x = (char**)(malloc(sizeof(char*)*strlen(name)+1));
	for(int i=0;i<strlen(name);i++)
	{
		x[i] = (char*)(malloc(sizeof(char)*100));
	}
	int n = strlen(name);
	int i = n-1;
	int k=0;
	while(i>=0)
	{
		while(name[i]!= '.' && i>=0)
		{
		x[k][j] = name[i];
		i--;
		j++;
		}
		
		if(name[i] == '.' && i>=0)
		{
			char tname[j];
			for(int l=0;l<j;l++)
			{
				tname[l] = x[k][l];
			}	
			for(int l=0;l<j;l++)
			{
				x[k][l]=tname[j-l-i];
			}
			
			i--;
			k++;
			j=0;
		}
	}
	int level=1;
	node* current = root->child;
	node* levelcurrent;
	int flag = 0;
	while(k>=level)
	{
		levelcurrent = current;
		while(levelcurrent)
		{
			if(strcmp(levelcurrent->value, x[level-1])!=0 )
			{
				levelcurrent = levelcurrent->sibling;
			}
			else
			{
				current = current->child;
				levelcurrent = current;
				level++;
			}
		}
		if(levelcurrent==NULL && k<level)
		{
		printf("Not Found\n");
		}
		else
		{
			printf("Found\n");		
		}

	}
	
}
node* splitdns(char* name, char* ip, node* root)
{
	int i=0,j=0,k=0;
	char** x;
	x = (char**)(malloc(sizeof(char*)*strlen(name)+1));
	for(int i=0;i<strlen(name);i++)
	{
		x[i] = (char*)(malloc(sizeof(char)*100));
	}
	int n = strlen(name);
	int i = n-1;
	int k=0;
	while(i>=0)
	{
		while(name[i]!= '.' && i>=0)
		{
		x[k][j] = name[i];
		i--;
		j++;
		}
		
		if(name[i] == '.' && i>=0)
		{
			char tname[j];
			for(int l=0;l<j;l++)
			{
				tname[l] = x[k][l];
			}	
			for(int l=0;l<j;l++)
			{
				x[k][l]=tname[j-l-i];
			}
			
			i--;
			k++;
			j=0;
		}
	}
	root = treeinsert(x,k,root);
	return root;
}


node* treeinsert(char *name, char* ip,node* root)
{

}
node* readData(FILE* fptr,node* root)
{

	int n;
	fscanf(fptr,"%d\n",&n);
	char name[n][1000];
	char ip[n][1000];
	for(int i=0;i<n;i++)
	{
		fscanf(fptr,"%s %s\n",name[i],ip[i]);
	//			printf("%s %s\n",name[i],ip[i]);
		/*if(root->value==NULL)
		{
		printf("Exists!");		
		}
		else
			printf("DNE");*/

		root = treeinsert(name[i],ip[i],root);
	}
	return root;
}
void search_tree(node* root, char* name)
{	
}	
void lookup(FILE* fp,node* root)
{
	char name[1000];
	fscanf(fp,"%s\n",name);
	//printf("\t%s\t",name);
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
		root = readData(fptr,root);
		node* temp = root->child;
		while(temp)
		{
		printf("%s ", temp->value);
		temp = temp->sibling;
		}
	}
	else if(x==2)
	{
	//printData(root);

	//	lookup(fptr,root);
	}
	else if(x==-1)
		return 0;
/*	else if(y==-1)
		return 0;*/
	}
}
