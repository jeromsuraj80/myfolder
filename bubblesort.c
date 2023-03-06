#include<stdio.h>
#include<stdlib.h>


void bubblesort(int *ptr,int n)
{
	int i,j,temp;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(ptr[i]>ptr[j])
			{
				temp=ptr[i];
				ptr[i]=ptr[j];
				ptr[j]=temp;
			}
		}
	}
}

void print(int *ptr,int n)
{
	int i;
	printf("the sorted array is\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t\n",ptr[i]);
	}
}

int main()
{
	int arr[100],i,n;

	printf("enter the n value :");
	scanf("%d",&n);

	printf("enter elements in array:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}

	bubblesort(arr,n);
	print(arr,n);
	return 0;
}



