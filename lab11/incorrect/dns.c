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
	x =(char**) malloc(sizeof(char*)*(n1));
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
		//printf("%s\t",x[k]);
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
	char tname[j+1];	
	int end = j-1;
	int l =0;
	for(l=0;l<j+1;l++)
	{
		tname[l] = x[k][end];
		end--;
	}
	tname[l]='\0';
	strcpy(x[k],tname);
	node* temp = root->child;
	int level = 1;
	node* prev = root;
	node* levelprev;
	node* levelcurrent;
	levelprev = temp;
	levelcurrent = temp;
	if(temp == NULL)
	{
		while(k+1>=(level))
			{
				node* newnode = (node*)(malloc(sizeof(node)));
				newnode->value = (char*)(malloc(sizeof(char)*strlen(x[level-1])));
				strcpy(newnode->value,x[level-1]);
		//		printf("%s ",newnode->value);
				prev->child = newnode;
				temp = newnode;
				prev = temp;
				temp = temp->child;
				level++;
			}
		if(k+1<level)
		{
			node* newnode = malloc(sizeof(node));
			newnode->value = (char*)(malloc(sizeof(char)*strlen(ip)));
			newnode->value =ip;
			newnode->child = NULL;
			newnode->sibling = NULL;
		//	printf("ip = %s",ip);
			prev->child = newnode;
		}
	}
	else
	{
		
		while(k+1>=(level))
		{

			while(levelcurrent!=NULL)
			{
				if(strcmp(levelcurrent->value,x[level-1])!=0)
				{
					levelprev = levelcurrent;
					levelcurrent = levelcurrent->sibling;
				}
				else if(strcmp(levelcurrent->value,x[level-1]) == 0)
				{
			//		printf("%s\t",levelcurrent->value);
					levelprev = levelcurrent;
					prev= levelprev;
					temp = levelcurrent->child;
					levelcurrent = levelcurrent->child;
					level++;
					continue;
				}
			}
			if(levelcurrent == NULL)
			{
				node* newnode = (node*)(malloc(sizeof(node)));
				newnode->value = (char*)(malloc(sizeof(char)*strlen(x[level-1])));
				newnode->child = NULL;
				newnode->sibling = NULL;
				strcpy(newnode->value,x[level-1]);
			//	printf("%s ",newnode->value);	
				levelprev->sibling = newnode;
				levelcurrent = newnode;
		//		printf("%s\t",levelcurrent->value);
				temp = levelcurrent;
				prev = temp;
				temp = temp->child;
				while(temp==NULL && level<=k)
				{
					node* newnode= malloc(sizeof(node));
					prev->child = newnode;
					temp = newnode->child;
					newnode->value = (char*)(malloc(sizeof(char)*strlen(x[level-1])));
					strcpy(newnode->value,x[level-1]);
					//printf("%s ",newnode->value);
					levelcurrent = newnode;
		//			printf("%s\t",levelcurrent->value);
					levelcurrent = levelcurrent->child;
					prev = newnode;
					
					level++;
				}
			}
		}

		if(k+1<level)
		{
			node* newnode = malloc(sizeof(node));
			newnode->value = (char*)(malloc(sizeof(char)*strlen(ip)));
			newnode->value =ip;
			newnode->child = NULL;
			newnode->sibling = NULL;
	//		printf("ip = %s",ip);
			prev->child = newnode;
		}
	}
	node* tau = root->child;
	while(tau)
	{
	if(tau->sibling!=NULL)
	tau = tau->sibling;
	printf("%s ",tau->value);
	tau = tau->child;
	}
	printf("\n");
	return root;	
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
	int n1,n2;
	n1 = strlen(name);
	char **x;
	//printf("reached");
	x =(char**) malloc(sizeof(char*)*(n1));
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
		//printf("%s\t",x[k]);
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
	char tname[j+1];	
	int end = j-1;
	int l =0;
	for(l=0;l<j+1;l++)
	{
		tname[l] = x[k][end];
		end--;
	}
	tname[l]='\0';
	strcpy(x[k],tname);
	//printf("%s",x[k]);
	node* current = root->child;
	int flag=0;
	int level = 1;
	//node* levelcurrent;
	while(current!=NULL || k>=level)
	{
		flag =0;
		if(strcmp(current->value, x[level-1])==0)
		{
			current = current->child;
			level++;	
			flag = 1;
		//	printf("Found = %s\n", current->value);	
		}
		else 
		{
			current = current->sibling;
		//	flag = 0;
		}
	
	}	
	if(k<level && flag==1)
	{
		printf("Found!");
	}
	else if(k<level && flag == 0)
	{
		printf("Not exists\n");
	}
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

		lookup(fptr,root);
	}
	else if(x==-1)
		return 0;
/*	else if(y==-1)
		return 0;*/
	}
}
