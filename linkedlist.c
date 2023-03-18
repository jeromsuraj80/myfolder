#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};

struct node *head=NULL;

void insert(int num);
void display();
void middlenode(struct node *head);
void recursiondis(struct node *head);
void main()
{
    struct node suraj;
    while(1)
    {
	    int opt,num;

	    printf("0.exit\n1.insertion\n2.display\n3.middle\n4.displayusigrecursion\n");
	    printf("enter the opt:");
	    scanf("%d",&opt);



	     
	   switch(opt)
	   {
		   case 0:exit(0);
		   case 1:printf("enter the num to insert:");
			 scanf("%d",&num);
			 insert(num);
			 break;
		   case 2:display();
			 break;
		   case 3:middlenode(head);
			  break;
		   case 4:recursiondis(head);
			  break;

		   default:printf("enter the valid option"); 
	   }
    }
}


void insert(int num)
{
	struct node *ptr=(struct node*)malloc(1*sizeof(struct node));

	if(ptr==NULL)
	{
		printf("heap memory is not allocated\n");
		exit(1);
	}

	ptr->data=num;
	ptr->link=head;
	head=ptr;
}

void display()
{
	struct node *temp;

	temp=head;

	if(temp==NULL)
	{
		printf("list is empty\n");
		exit(1);
	}
	do
	{
		printf("%d\n",temp->data);
		temp=temp->link;
	}while(temp!=NULL);
}

void middlenode(struct node* head)
{
	struct node *middle=head;

	int count=0;

	while(head!=NULL)
	{
		if(count%2==1)
		{
			middle=middle->link;
		}
		count++;
		head=head->link;
	}
	if(middle!=NULL)
	{
		printf("middle node is %d\n",middle->data);
	}
}

void recursiondis(struct node *head)
{
	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	}
	printf("%d\n",head->data);
	recursiondis(head->link);
}
