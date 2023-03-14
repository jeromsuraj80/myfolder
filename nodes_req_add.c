#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL;
void insert_node(struct node *head1,int data)
{
	struct node *temp=(struct node *)malloc(1*sizeof(struct node));
	if(temp==NULL)
	{
		printf("failed to allocate memory\n");
		exit(0);
	}
	temp->data=data;
	temp->next=NULL;
	if(head==NULL)
	{
		//printf("\n%p",temp);
		head=temp;
		//printf("\n%p",head);
		return;
	}
	temp=head;
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=(struct node *)malloc(1*sizeof(struct node));
	temp->next->data=data;
	temp->next->next=NULL;
	return;
}
int add_req_nodes(int node1,int node2)
{
	struct node *temp=head;
	int x,y;
	if((node1<1 || node2<1))
	{
		printf("invalid input\n");
		exit(0);
	}
	node1--;
	while(node1)
	//while(temp->next!=NULL && node1)
	{
		node1--;
		temp=temp->next;
		if(temp==NULL)
		{
			printf("node is invalid\n");
			exit(0);
		}
	}
	x=temp->data;
	struct node *temp1=head;
	node2--;
	while(node2)
//	while(temp1->next!=NULL && node2)
	{
		node2--;
		temp1=temp1->next;
		if(temp1==NULL)
		{
			printf("node is invalid\n");
			exit(0);
		}
	}
	y=temp1->data;
	//x=x+y;
	return x+y;
}
int main()
{
	int lst_size,data,node1,node2,res;
	scanf("%d",&lst_size);
	for(int i=0;i<lst_size;i++)
	{
		printf("enter node data:");
		scanf("%d",&data);
		insert_node(head,data);
		//printf("head:%p\n",head);
	}
	printf("enter node 1 and node 2\n");
	scanf("%d%d",&node1,&node2);
	res=add_req_nodes(node1,node2);
	printf("result = %d",res);
return 0;
}
