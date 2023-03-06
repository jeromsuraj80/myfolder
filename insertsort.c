#include<stdio.h>
#include<stdlib.h>

void insertion(int arr[],int n);
void print(int arr[],int n);

void main()
{
	int arr[]={18,20,19,4,5,6,1};
	int n=sizeof(arr)/sizeof(arr[0]);

	insertion(arr,n);
	print(arr,n);

}

void insertion(int arr[],int n)
{
	int i,j,key;

	for(i=1;i<n;i++)
	{
		key=arr[i];
		j=i-1;

		while(j>=0 && arr[j] > key)
		{
			arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j+1]=key;
	}
}

void print(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\t\n",arr[i]);
	}
}
