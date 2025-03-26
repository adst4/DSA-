//SET B
// write a program to sort n randomly generated elements using HeapSort Method

//HEAP SORT
#include<stdio.h>
#include<stdlib.h>
void Accept(int a[],int n)
{
	int i;
	printf("Enter The %d Elements : \n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
}

void display(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
}

void Heapify(int a[],int top,int last)
{
	int j,temp,key;
	key=a[top];
	j=2*top+1;
	if((j<last)&&(a[j]<a[j+1]))
		j=j+1;
	if((j<=last)&&(key<a[j]))
	{
		temp=a[top];
		a[top]=a[j];
		a[j]=temp;
		Heapify(a,j,last);
	}
}

void BuildHeap(int a[],int n)
{
	int i;
	for(i=n/2;i>=0;i--)
		Heapify(a,i,n-1);
}

void HeapSort(int a[],int n)
{
	int i,temp,top=0,last;
	BuildHeap(a,n);
	printf("Initial Heap = ");
	display(a,n);
	for(last=n-1;last>=1;last--)
	{
		temp=a[top];
		a[top]=a[last];
		a[last]=temp;
		printf("\nAfter Iteration %d : ",n-last);
		display(a,n);
		Heapify(a,top,last-1);
	}
}

int main()
{
	int *a,n;
	a=(int *)malloc(sizeof(int));
	printf("How Many Elements : ");
	scanf("%d",&n);
	Accept(a,n);
	printf("Random Array Is : ");
	display(a,n);
	printf("\n");
	HeapSort(a,n);
	printf("\nSorted Elements Are : ");
	display(a,n);
	return 0;
}

