#include "lab.h"
// You need to create appropriate structures 
struct node* getNode(char *str)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    strcpy(node->str,str);
    node->no_of_child=0;
    node->children = (struct node**)malloc((node->no_of_child)*sizeof(struct node*));
    return node;    
}
void readData(struct node* root)
{
    char temp[100];
    scanf("%s",temp);
    char* token = strtok(temp,".");
    char** arr = (char**)malloc(sizeof(char*));
    int size=0;
    while(token!=NULL)
    {
        arr = realloc(arr,(size+1)*sizeof(char**));
        arr[size] = (char*)malloc(100*sizeof(char));
        strcpy(arr[size],token);
        size++;
        token = strtok(NULL,".");
    }
    
    //root->children = (struct node**)malloc(sizeof(struct node*));
    //root->no_of_child = 0;
    
    int j=size-1,flg=0;
    struct node* crawl = root;
    while(crawl->no_of_child!=0&&j>=0)
    {
        flg=0;
        for(int i=0;i<crawl->no_of_child;i++)
        {
            if(strcmp(crawl->children[i]->str,arr[j])==0)
            {
                crawl=crawl->children[i];
                j--;
                flg=1;
                break;
            }
        }
        if(flg==0)
            break;
    }
    
    if(flg==0)
    {
        while(j>=0)
        {
            crawl->children = realloc(crawl->children,((crawl->no_of_child)+1)*sizeof(struct node**));
            crawl->children[crawl->no_of_child] = getNode(arr[j--]);
            crawl->no_of_child++;
            crawl=crawl->children[(crawl->no_of_child)-1];
        }
    }
    
    char ip[100];                
    scanf("%s",ip);
    crawl->children = realloc(crawl->children,((crawl->no_of_child)+1)*sizeof(struct node**));
    crawl->children[crawl->no_of_child] = getNode(ip);        
    crawl->no_of_child++;            

}
        
void look_up(struct node* root,char* str)
{
    char** arr = (char**)malloc(sizeof(char*));
    int size=0;
    char* token = strtok(str,".");
    while(token!=NULL)
    {
        arr = realloc(arr,(size+1)*sizeof(char**));
        arr[size] = (char*)malloc(100*sizeof(char));
        strcpy(arr[size],token);
        size++;
        token=strtok(NULL,".");
    }
    struct node* crawl=root;
    int flg=0,j=size-1;
    int t_size=0;
    int* temp = (int*)malloc(t_size*sizeof(int));
    while((crawl->no_of_child)!=0&&j>=0)
    {
        flg=0;
        for(int i=0;i<crawl->no_of_child;i++)
        {
            if(strcmp(crawl->children[i]->str,arr[j])==0)
            {
                crawl=crawl->children[i];
                j--;
                flg=1;
                temp = realloc(temp,(t_size+1)*sizeof(int*));
                temp[t_size] = i;
                t_size++;
                break;
            }
        }
        if(flg==0)
            break;
    }
    if(j<0)
    {
        for(int i=0;i<crawl->no_of_child;i++)
        {
            if(crawl->children[i]->no_of_child==0)
            {
                printf("found!.... ip: %s\n",crawl->children[i]->str);
                break;
            }
        }
    }
    else
    {
        printf("Not found!\n");
        for(int i=0;i<t_size;i++)
            printf("%d ",temp[i]);
        printf("\n");
    }        
}
