int estimateCutoff(record arr[],int n)//Objective is to find the first occurence
{
	double results[2];

	record newarr[n];

	int min=0;
	int max=n;

	int mid=(min+max)/2;
	int prevmid = -1;

	double resultleft,resultcenter,resultright;

	while(mid!= prevmid){
		prevmid = mid;
		fflush(stdout);
		for(int i=0;i<(min+mid)/2;i++){ //we're only sorting the first "mid" elements anyway, so there's no point copying more than that
			newarr[i]=arr[i];
		}
		// I assume that a plot of abs(IStime-QStime) will be U-shaped, with a well defined minumum
		testRun(newarr, (min+mid)/2, results);
		resultleft=fabs(results[0]-results[1]);
		
		for(int i=0;i<mid;i++){ //we're only sorting the first "mid" elements anyway, so there's no point copying more than that
			newarr[i]=arr[i];
		}
		testRun(newarr, mid, results);
		resultcenter=fabs(results[0]-results[1]);
		
		for(int i=0;i<(mid+max)/2;i++){ //we're only sorting the first "mid" elements anyway, so there's no point copying more than that
			newarr[i]=arr[i];
		}
		testRun(newarr, (mid+max)/2, results);
		resultright=fabs(results[0]-results[1]);

		printf("mid is %d, %lf,%lf,%lf\n",mid,resultleft,resultcenter,resultright);

		if(resultcenter<=resultleft && resultcenter <= resultright){
			//We've found our minimum
			return mid;
		}
		else{
			if(resultleft<=resultcenter){
				max = mid; //go left
			}
			else{
				min = mid;
			}
		}
		mid = (min+max)/2;
	}
	return mid; //mid is equal to prevmid, so return mid
	
}







//record newarr[n];
	int min =0;
	int max = n-1;
	double result[2];
	int mid = (max+min)/2;
	double left,right,center;
	int cutoff;
	//printf("%d %d %d\t",max,min,mid);			
	
	while(max>=min && mid>0)
	{
		mid = (max+min)/2;
		record newarr[mid];
		for(int i =0;i<mid;i++)
			newarr[i] = arr[i];
		testRun(newarr,mid,result);
		
		center = fabs(result[0]-result[1]);
		if(center!=0.00000)
		{
				max = mid-1;
		//	printf("entered");
	
		}
		//	printf("exited");
			printf("%d %d %d\t",max,min,mid);			
	
		if(center==0.00000)
		{
		//	printf("entered");
	
			cutoff = mid ;
			min = mid+1;	
			printf("%d %d %d\t",max,min,mid);			
	
			printf("cutoff %d\t",cutoff);			
		}		
	}
	return cutoff;	
