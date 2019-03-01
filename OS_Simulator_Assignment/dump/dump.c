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
