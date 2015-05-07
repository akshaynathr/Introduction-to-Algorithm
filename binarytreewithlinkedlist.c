/*PROGRAM TO IMPLEMENT BINARY TREE USING LINKED LIST*/

#include<stdio.h>
#include<stdlib.h>

struct node
{		
	int data;
	struct node *lptr;
	struct node *rptr;
};

struct node *root=NULL;
struct node *que[100];
int front=-1,rear=-1;

void insert_queue(struct node *v);
void delete_queue();
void insert();
void preorder(struct node *ptr);
void postorder(struct node *ptr);
void inorder(struct node *ptr);

int main()
{
	int ch;
	do
	{
		printf("\nMENU\n.......\n1.Insert\n2.Preorder Traversal\n3.Inorder Traversal\n4.Postorder Traversal\n5.Exit\nEnter your choice:  ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insert();
				break;
			case 2:
				preorder(root);
				break;
			case 3:
				inorder(root);
				break;
			case 4:
				postorder(root);
				break;
			case 5:
				exit(0);
			default:
				printf("Invalid choice!!!\n");
		}
	}while(1);		
}

void insert_queue(struct node *v)
{
	if(rear==99)
		return;
	else
	{	
		if(front==-1)
			front=0;
		rear=rear+1;
		que[rear]=v;
	}	
}

void delete_queue()
{
	if(front==-1||front>rear)
		return;
	front++;
}	

void insert()
{
	struct node *c,*temp;
	int n,i,dat;
	printf("Enter the no.of data to be inserted: ");
	scanf("%d",&n);
	printf("Enter the elements: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&dat);
		temp=(struct node*)malloc(sizeof(struct node));
		temp->data=dat;
		temp->lptr=NULL;
		temp->rptr=NULL;
		if(root==NULL)
			root=temp;
		else
		{
			c=que[front];
			if(c->lptr==NULL)
			 	c->lptr=temp;
			else
			{
				delete_queue();
				c->rptr=temp;
			}
		}
		insert_queue(temp);
	}				
}		

void preorder(struct node *ptr)
{
	if(ptr!=NULL)
	{
		printf("%d\t",ptr->data);
		preorder(ptr->lptr);
		preorder(ptr->rptr);
	}
}

void postorder(struct node *ptr)
{
	if(ptr!=NULL)
	{
		postorder(ptr->lptr);
		postorder(ptr->rptr);
		printf("%d\t",ptr->data);
	}
}

void inorder(struct node *ptr)
{
	if(ptr!=NULL)
	{
		inorder(ptr->lptr);
		printf("%d\t",ptr->data);
		inorder(ptr->rptr);	
	}
}



