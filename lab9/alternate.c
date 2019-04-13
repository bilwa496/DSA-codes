/* Alternate implementation
void profiling()
{
	//int table = 5000;
	char **book = parsing();
	//char **tracker;
	int tsize = 5000;
	int y=0;
	int arr1[18],arr2[18],arr3[18];
	for(int i=0;i<3;i++,tsize*=10) {
		int count=0;
		int x = tsize;
		for(int j=1.5*x;j<2*x&&count!=3;j++) {
			if(isPrime(j)) {
				count++;
				arr1[y]=j;
				arr2[y]=tsize;
				arr3[y++]=collision_count(book,j,tsize);
				printf("Collision count of %d %d = %d\n",j,tsize,collision_count(book,j,tsize));
			}
		}
		count=0;
		x = 1000*tsize;
		for(int j=1.5*x;count!=3;j++) {
			if(isPrime(j)) {
				count++;
				arr1[y]=j;
				arr2[y]=tsize;
				arr3[y++]=collision_count(book,j,tsize);
				printf("Collision count of %d %d = %d\n",j,tsize,collision_count(book,j,tsize));
			}
		}
	}
	int small=0;
	for(int i=0;i<18;i++) {
		if(arr3[small]>arr3[i]) {
			small=i;
		}
	}
	printf("Best Collision count of %d %d = %d\n",arr1[small],arr2[small],arr3[small]);
}
*/
