#include <stdio.h>
#include <stdlib.h>
#include "ms2.h"
#include "merge.h"
#include "fl.h"
void read_files(int k)
{
	FILE* fptr = fopen("1024.txt","r");	
	FILE* stor = fopen("ans.txt","w");	
	Element* ls =(Element*) (malloc(sizeof(Element)*k));
	if(fptr == NULL || stor == NULL)
	{
		printf("Error!\n");
	}
	int i=0;
	while(fscanf(fptr,"%[^,],%f\n",ls[i].name,&ls[i].cgpa)!=-1 && i<k)
	{
		printf("%s,%f\n",ls[i].name,ls[i].cgpa);
		fprintf(stor,"%s,%f\n",ls[i].name,ls[i],cgpa);
		i++;
	}
	fclose(fptr);
	fclose(stor);	
}
/*     
open file F1;
open file F2;
open file Out;
read record r1 from F1;
read record r2 from F2;
repeat {
     if (r1.key <= r2.key) { 
          write r1 to Out;  read r1 from F1;
     } else {
	    write r2 to Out; read r2 from F2;
     }
  } until (F1 is empty OR F2 is empty);
  while (F1 is not empty) { read r1 from F1; write r1 to Out; }
  while (F2 is not empty) { read r2 from F2; write r2 to Out; }
  close files F1, F2, and Out.
  */
 void mergeFiles(char* f1,char* f2)
 {
	FILE* fptr1 = fopen(f1,"r");
	FILE* fptr2 = fopen(f2,"r");
	FILE* out = fopen("out.txt","w");
	Element* ls1 =(Element*) (malloc(sizeof(Element)));
	Element* ls2 =(Element*) (malloc(sizeof(Element)));
	while(1)
	{
		if(!feof(f1) && !feof(f2))
		{
		if(ls1.cgpa <= ls2.cgpa)
		{
			if(fscanf(fptr1,"%[^,],%f\n",ls1.name,&ls1.cgpa)!=-1)
				continue;
			fprintf(out,"%s,%f\n",ls1.name,ls1,cgpa);
			//printf("%s,%f\n",ls1[i].name,ls1[i].cgpa);
		}
		else
		{
			if(fscanf(fptr2,"%[^,],%f\n",ls2.name,&ls2.cgpa)!=-1)
				continue;
			fprintf(out,"%s,%f\n",ls2.name,ls2,cgpa);
		
		}
		}
		else if(!feof(f2))
		{
			if(fscanf(fptr2,"%[^,],%f\n",ls2.name,&ls2.cgpa)!=-1)
				continue;
			fprintf(out,"%s,%f\n",ls2.name,ls2,cgpa);
		}
		else if(!feof(f1))
		{
			if(fscanf(fptr1,"%[^,],%f\n",ls1.name,&ls1.cgpa)!=-1)
				continue;
			fprintf(out,"%s,%f\n",ls1.name,ls1,cgpa);
		}
		else 
			break;
	}
}   
void merge_sort_files(FILE* f)
{
	int m = 1024,k = 24;
	char * f0 = (char*)(malloc(sizeof(char)*15));
	char * f1 = (char*)(malloc(sizeof(char)*15));
	char * f2 = (char*)(malloc(sizeof(char)*15));
	for(int i = 1; i<k;i++)
	{
		sprintf(f0,"output%004d.txt",i);
		FILE* out = fopen(f0,"r");
		if(i==1)
		{
			sprintf(f1,"output%04d.txt",i);
		}
		else
		{
			sprintf(f1,"output%04d.txt",i);
		}
		FILE* fp1 = fopen(f1,"r");
		sprintf(f2,"output%03d.txt",i+1);
		FILE* fp2 = fopen(f2,"r");
		mergeFiles(fp1,fp2,out);
		remove(f2);
		remove(f1);
		fclose(out);
		
	}
}
		
	

 

