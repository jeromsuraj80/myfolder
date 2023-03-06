#include<stdio.h>
#include<stdlib.h>

void selection(int *ptr,int n);
void print(int *ptr,int n);

void main()
{
	int arr[30];

	int n,i;

	printf("enter the n value:");
	scanf("%d",&n);

	printf("enter the elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}


	selection(arr,n);
	print(arr,n);
}

void selection(int *ptr,int n)
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
	 for(i=0;i<n;i++)
	 {
		 printf("%d\t",ptr[i]);
	 }
}
        
	
	

