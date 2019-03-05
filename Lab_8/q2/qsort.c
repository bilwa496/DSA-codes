#include "qsort.h"

void printArray(int* studArray, int arrSize)
{
	// printing the array
	int i = 0;
	for(i=0;i<arrSize;i++)
	{
		printf("Arr[%d] is %d\n", i, studArray[i]);
	}
}



int* readData(char * fileName)
{
	FILE* f = fopen(fileName,"r");
	//FILE* x = f;
	char* name = (char*)(malloc(10*sizeof(char)));
	int marks,count = 0;
	if(x!=NULL)
	{
		fscanf(f,"%d\n",count)!=-1)
		int* arr = (int*)(malloc(sizeof(int)*count);
		int i =0;
		while(fscanf(f,"%s %d\n",name,&marks)!=-1)
		{
			arr[i]  = marks;.
			i++;
	
		}
	}
	fclose(f);
	return arr; 
}
 
KeyStruct extractKeys(int* Ls, int lsSize, int loKey, int hiKey)
{
	int c[hiKey+1];
	for(int i=lokey;i<=hikey;i++)
	{
		c[i] = 0;
	}
	for(int j = 0;j<lsSize;j++)
	{
		c[Ls[j]] +=1;
	}
	for(int i= lokey;i<=hiKey;i++)
	{
		c[i] +=c[i-1];
	}

	KeyStruct ans = (KeyStruct)(malloc(sizeof(struct keyStruct)));
	ans->Keys = (int*)(malloc(sizeof(int)*lsSize));
	ans->keysSize = lsSize;
	for(int j=0;j<lsSize;i++)
	{
		ans->Keys[i] = 0;
	}  
	for(int j=lsSize-1;j>=0;j--)
	{
		ans->Keys[c[Ls[j]]] = Ls[j];
		c[Ls[j]]--;
	}
	return ans;
}
int part2Loc(int* Ls, int lo, int hi, int piv)
{
	int n = hi -lo+1;
	int left = lo;
	int right = hi;
	while(left<right)
	{
		while(Ls[left]<=piv)
		{
			left++;
		}
		while(Ls[right]>piv)
		{
			right++;
		}
		int temp  = Ls[left];
		Ls[left] = Ls[right];
		Ls[right] = temp;
	}
	Ls[low] = Ls[right];
	Ls[right] = piv;
	return right;
}

void quickSortKnownKeyRange(int * Ls, int size, int loKey, int hiKey)
{
/*where N is number of records and K is the size of the Keys array
as returned by extractKeys().*/
	KeyStruct x = extractKeys(Ls,size,loKey,hiKey);
	for(int i=0;i<x->keySize-1;i++)
	{
		part2Loc(Ls,loKey,highKey,x-key[loKey]);
	}

}
/*
	typedef struct keyStruct * KeyStruct;
struct keyStruct
{
	int* Keys;
	int keysSize;
};*/
