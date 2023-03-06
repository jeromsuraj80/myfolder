/*Program to implement mathematical and bitwise operation using functions and switch case*/
#include<stdio_ext.h>
#include<stdlib.h>

//int Replace_101_111(int);
int Replace_101_111(int num)
{
	//printf("Started\n");
        int temp,i,y,count=0;
        temp=num;
        i=0;
        while(i<=(31-3))
        {
                if((num&(0x7<<i))==(0x5))
		{
			count++;
			num=((num|(0x7<<i)));
		}
		i++;
        }
	if(count==0)
	{
		printf("Not found\n");
		return 0;
	}
	else
		//printf("Completed\n");
		return num;
}

//int Count_the_zeros_ones(int *,int );
int * Count_the_zeros_ones(int *ptr,int num)
{
        int temp,i=0,count0=0,count1=0;
        temp=num;
	//printf("Started\n");
	if(ptr==NULL)
		printf("Invalid address\n");
	else
	{
		while(i<=31)
		{
			if((num&(0x1<<i))==0)
				count0++;
			else
				count1++;
			i++;
		}
		ptr[0]=count0;
		ptr[1]=count1;
		//printf("Completed\n");
		return ptr;
	}
}

//int Decimal_to_binary(int);
void Decimal_to_binary(int dec)
{
	//printf("Started\n");
	int i;
	i=0;
	while(i<=31)
	{
		printf("%d\n",((1&(dec>>i))));
		i++;
	}
	//printf("Completed\n");
}

//int swap_the_bit(int,int,int);
int swap_the_bit(int num,int a,int b)
{
	//printf("Started\n");
	int temp;
	((a>b))?(temp=a,a=b,b=temp):0;
	num=(num&(~((0x1<<b)|(0x1<<a))))|((num&(0x1<<a))<<(b-a))|((num&(0x1<<b))>>(b-a));
	//printf("Completed\n");
	return num;
}

//int Repeated_101_(int num);
int Repeated_101_(int num)
{
	//printf("Started\n");
	int i=0,temp,count=0,y;
	temp=num;
	while(i<=(31-3))
	{
		if(((num&(0x7<<i))>>i)==(0x5))
			count++;
		i++;
	}
	//printf("Completed\n");
	return count;
}

//int Reverse_number(int);
int Reverse_number(int num)
{
	//printf("Started\n");
	int temp,rem,sum=0;
	temp=num;
	while(temp!=0)
	{
		rem=temp%10;
		temp=temp/10;
		sum=sum*10+rem;
	}
	//printf("Completed\n");
	return sum;
}
//int Sum_digits(int);
int Sum_digits(int num)
{
	//printf("Started\n");
	int temp,rem,sum=0;
	temp=num;
	while(temp!=0)
	{
		rem=temp%10;
		temp=temp/10;
		sum=sum+rem;
	}
	//printf("Completed\n");
	return sum;
}

//int Count_the_digits(int);
int Count_the_digits(int num)
{
	//printf("Started\n");
	int temp=num,count=0;
	if(temp!=0)
	{
		while(temp>0)
		{
			temp=temp/10;
			count++;
		}
	}
	//printf("Completed\n");
	return count;
}


//int Palindrome_or_not(int);
int Palindrome_or_not(int num)
{
	//printf("Started\n");
	int temp,sum=0,rem;
	temp=num;
	while(temp!=0)
	{
		rem=temp%10;
		temp=temp/10;
		sum=sum*10+rem;
	}
	//printf("Completed\n");
	return sum;
}

//int Decimal_binary(int);
int Decimal_binary(int dec)
{
	//printf("Started\n");
	int temp,rem,bin=0,i=1;
	temp=dec;
	while(temp!=0)
	{
		rem=temp%2;
		temp=temp/2;
		bin=bin+i*rem;
		i=i*10;
	}
	//printf("Completed\n");
	return bin;
}
//int Binary_decimal(int);
int Binary_decimal(int bin)
{
	//printf("Started\n");
	int temp,rem,dec=0,i=1;
	temp=bin;
	while(temp!=0)
	{
		rem=temp%10;
		if(rem>1)
			return -1;
		dec=dec+i*rem;
		i=i*2;
		temp=temp/10;
	}
	//printf("Completed\n");
	return dec;
}

//int Even_odd(int num);
int Even_odd(int num)
{
	//printf("Started\n");
	int temp=num;
	if((num%2)==0)
		printf("%d-Even\n",num);
	else
		printf("%d-Odd\n",num);
	//printf("Completed\n");
	return num;
}

void main(void)
{
	int arr[2];
	int *res1;
	unsigned int num,bin,dec,res,opt,a,b;
	char sub_opt;
main:	while(1)
	{
		printf("Menu\n1.Bitwise operations\n2.Mathemtical operations\n0.exit\n");
		printf("Select the option: ");
		scanf("%d",&opt);
		__fpurge(stdin);
		switch(opt)
		{
			case 0:
				exit(0);
			case 1:
				while(1)
				{
					__fpurge(stdin);
					printf("Menu\na.Replace 101 with 111\nb.Count number of zeros&ones\nc.Decimal to binary\nd.Swapping the bits\ne.How many times 101 is repeated\nz.Main menu\n");
					printf("Select the option: ");
					scanf("%c",&sub_opt);
					__fpurge(stdin);
					switch(sub_opt)
					{
						case 'z':
							goto main;

						case 'a'://Replace 101 with 111
							printf("Enter the number: ");
							scanf("%d",&num);
							res=Replace_101_111(num);
							printf("%d\n",res);
							break;
						case 'b'://Count number of zeros&ones
							printf("Enter the number: ");
							scanf("%d",&num);
							res1=Count_the_zeros_ones(arr,num);
							printf("Zeros=%d\n",res1[0]);
							printf("Ones=%d\n",res1[1]);
							break;
						case 'c'://Decimal to binary
							printf("Enter the number: ");
							scanf("%d",&dec);
							Decimal_to_binary(dec);
							break;
						case 'd'://Swapping the bits
							printf("Enter the number: ");
							scanf("%x",&num);
							printf("Enter the bits to be swapped(a:b): ");
							scanf("%d:%d",&a,&b);
							res=swap_the_bit(num,a,b);
							printf("%x\n",res);
							break;
						case 'e'://How many times 101 is repeated
							printf("Enter the number: ");
							scanf("%d",&num);
							res=Repeated_101_(num);
							printf("%d\n",res);
							break;
					}
				}
				break;
			case 2:
				while(1)
				{
					__fpurge(stdin);
					printf("Menu\na.Reverse the number\nb.Sum of digits\nc.Count the number of digits\nd.Number is a palindrome or not\ne.Decimal to binary\nf.Binary to decimal\ng.Even/odd\nz.Main menu\n");
					printf("Select the option: ");
					scanf("%c",&sub_opt);
					__fpurge(stdin);
					switch(sub_opt)
					{
						case 'z':
							goto main;
						case 'a'://Reverse the number
							printf("Enter the number: ");
							scanf("%d",&num);
							res=Reverse_number(num);
							printf("%d\n",res);
							break;
						case 'b'://Sum of digits
							printf("Enter the value: ");
							scanf("%d",&num);
							res=Sum_digits(num);
							printf("%d\n",res);
							break;
						case 'c'://Count the number of digits
							printf("Enter the value: ");
							scanf("%d",&num);
							res=Count_the_digits(num);
							printf("%d\n",res);
							break;
						case 'd'://Number is palindrome or not
							printf("Enter the value: ");
							scanf("%d",&num);
							res=Palindrome_or_not(num);
							if(res==num)
							{
								printf("%d is a palindrome\n",res);
								break;
							}
							printf("%d is not a palindrome\n",num);
							break;
						case 'e'://Decimal to binary
							printf("Enter th decimal value: ");
							scanf("%d",&dec);
							res=Decimal_binary(dec);
							printf("%d\n",res);
							break;
						case 'f'://Binary to decimal
							printf("Enter the binary value: ");
							scanf("%d",&bin);
							res=Binary_decimal(bin);
							printf("%d\n",res);
							break;
						case 'g'://Even or odd number
							printf("Enter the value: ");
							scanf("%d",&num);
							res=Even_odd(num);
							printf("%d\n",num);
							break;
					}
				}
				break;
			default:
				printf("INVALID OPTION\n");
		}
	}
}











