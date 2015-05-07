/*PROGRAM TO IMPLEMENT BINARY TREE USING ARRAY*/

#include<stdio.h>
#include<stdlib.h>

int a[100];
int count=0;

void insert()
{
		int n,i;
		printf("Enter the no.of elements to be  inserted:   ");
		scanf("%d",&n);
		printf("Enter the datas: ");
		for(i=0;i<n;i++)
				scanf("%d",&a[++count]);
				
}

void preorder(int p)
{
		if(p<=count)
		{
				printf("%d\t",a[p]);
				preorder(2*p);
				preorder((2*p)+1);
		}
}

void inorder(int p)
{
		if(p<=count)
		{
				inorder(2*p);
				printf("%d\t",a[p]);
				inorder((2*p)+1);
		}
}
		
void postorder(int p)
{
		if(p<=count)
		{
				postorder(2*p);
				postorder((2*p)+1);
				printf("%d\t",a[p]);
		}
}
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
								preorder(1);
								break;
						case 3:
								inorder(1);
								break;
						case 4:
								postorder(1);
								break;
						case 5:
								exit(0);
						default:
								printf("Invalid choice!!!\n");
				}
		}while(1);		
}
