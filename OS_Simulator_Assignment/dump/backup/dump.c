void sortedinsert(listhead h[],int count, int value,int arr[])
{
		printf("freed= %d\t",freed);
	
	int header = h.head;//stores head and traverses	
	while(header!=-1)
	{
		if(value<arr[header] && (arr[header+1])!=-1)//not the last node
			{	
				header = arr[header+1];
			}
			

		else if(value<arr[header] && arr[header+1]==-1)//last node and still smaller we add before last node
		{
//			printf("in loop")
			if(freed !=-1)
			{
					int temp = freed;
					arr[freed] = value;
					freed = arr[freed+1];//freed updated
					arr[temp+1]=header;
					arr[temp+2] = arr[header+2];
					arr[header+2] = temp;
					h.elementcount++; 
					printf("1. %d",h.elementcount);
					break;
			}
			else
			{
				printf("FAILURE0: MEMORY NOT AVAILABLE\n");
				break;
			}
		}
		else//insertion in between the list
		{
			if(freed != -1)
				{
					int tempprev = arr[header+2];
					int tempnext = arr[header+1];
					//create and insert node
					int temp = freed;
					arr[freed] = value;
					freed = arr[freed+1];//freed updated
					arr[temp+1] = tempnext;
					arr[temp+2] = header;
					arr[header+1] = temp;
					h.elementcount++; 
					header = temp;
					printf("2. %d",h.elementcount);
					break;
				} 
				else
				{
						printf("FAILURE1: MEMORY NOT AVAILABLE\n");
						break;
				}
		}
	}
			printf("freed= %d\t",freed);

	return h;
}


void defrag(listhead h[],int count,int arr[])
{
	int a[3*MAX];//local copy
	for(int i=0;i<(3*MAX-2);i+=3)
	{
		a[i+1] = i+3;
		a[i+2] = -1;
	}
	a[3*MAX-2]= -1;
	//initialized the array to a free list
	//Objective is to work with every free list and populate and return the modified list
	int x,header = 0;
	for(int i=0;i<count;i++)
	{
		if(h[i].head!=-1)
		{
			a[header+2] = -1;
			x = h[i].head;//can be used for traversing the original list
			h[i].head = header;//head modified
			int marker = x; //marking the head  
			while(x!=-1)
			{
				a[header] = arr[x];
				if(marker==x)
				{
					arr[header+2] = -1;
				}
				else
				{
					arr[header+2] = header - 3;
				}
			//	int temp = arr[header+1];
				x = arr[x+1];//travel forward in arr
				printf("%d",header);
				header+=3;
			}  
			header-=3;
			arr[header+1] = -1;
			if(header>=3 && h[i].elementcount>1)
			{
				a[header+2] = header-3;
			}
			else
			{
				a[header+2] = -1;
			}
		}
	}

	freed = header+3;//new position of freed
	printf("%d\t",h[count-1].head);

	printf("SUCCESS\n");

	for(int i=0;i<3*MAX;i++)
	{
		arr[i] = a[i];
	}
	 printalllist(h,count, arr);

}