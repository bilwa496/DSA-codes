
int search(int arr[],int n)
{
	int i;
	int min = arr[0];
	for(i = 0;i<n;i++)
	{
		if(min>arr[i])
		{
			min = arr[i];
		}}
	printf("In function minimum = %d",min);
	return min;
}
