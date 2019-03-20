#include <stdio.h>
#include <stdlib.h>
struct heap
{
	int *array;
	int capacity;
	int count;
};
typedef struct heap heap;
heap* createheap(int capacity)
{
	heap* h = (heap*)(malloc(sizeof(heap)));
	if(h->array == NULL)
		return;

	h->count = 0;
	h->capacity = capacity;
	int* h->array = (int*)(malloc(sizeof(int)*capacity));
	if(h->array == NULL)
		return;
	return h;
}
int parent(heap* h, int i )
{
	if(i>h->count || i<0)
		return -1;
	return (i-1)/2; 
}
int left(heap* h, int i)
{
	left = 2*i+1;
	if(left>h->count)
	return;
	return left;

}
int right(heap* h, int i)
{

	right = 2*i+2;
	if(right>h->count)
	return;
	return right;
}
int getMax(heap* h)
{
	if(h->count == 0)
		return -1;
	return h->array[0];
}
void maxHeapify(heap* h,int i)
{
	int l = left(h,i), r = right(h,i),max;
	if(l!=-1 && h->array[l]>h->array[i])
	{
		max = l;
	}
	else
		max = i;
	if(r!=-1 && h->array[r]>max)
		max = r;
	if(max!=i)
	{
		int temp = h->array[i];
		h->array[i] = h->array[max];
		h->array[max] = temp;
		maxHeapify(h,i);
	}
}
int deleteMax(heap* h)
{
	if(h->count == 0)
		return -1;
	int data = h->array[0];
	h->array[0] = h->array[h->count-1];
	maxHeapify(h,0);
	return data;
}
void insert(heap *h, int data)
{
	if(h->count == h->capacity)
		resize(h);
	h->count++;
	int i = h->count -1;
	while(i>=0 && data>h->array[(i-1)/2])
	{
		h->array[i] = h->array[(i-1)/2];
		i = (i-1)/2;
	}
	h->array[i] = data;
	return i
}
void resize(heap* h)
{
	int *old = h->array;
	h->array = (int*)(malloc(sizeof(int)*h->capacity*2));
	if(h->array  == NULL)
		return;
	for(int i=0;i<h->capacity;i++)
	{
		h->array[i] = old[i];
	}
	free(old);
}
void destroyHeap(heap* h)
{
	if(h==NULL)
		return;
	free(h->array);
	h = NULL;
}
void buildHeap(heap* h int a[], int n)
{
	if(h==NULL)
		return;
	while(n>h->capcity)
		resize(h);
	for(int i=0;i<n;i++)
	{
		h->array[i] = a[i];
	}
	h->count =n;
	for(i= (n-1)/2;i>=0;i--)
		maxHeapify(h,i);
}
void heapsort(int a[],int n)
{
	heap* h = createheap(h);
	int old, temp;
	buildHeap(h,a,n);
	old = h->count;
	for(int i=n-1;i>=0;i--)
	{
		temp = h->array[0];
		h->array[0] = h->array[h->count-1];
		h->array[h->count-1] = temp;
		printf("%d",temp);
		h->count--;
		maxHeapify(h,i);
	}
	h->count =  old;
}
int main()
{
return 0;
}