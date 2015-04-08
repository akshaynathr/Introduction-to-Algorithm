#include <stdio.h>
#include <stdlib.h>
struct node { int data ; struct node * left; struct node *right;};


struct node * newNode(int data)
	{
		struct node *temp;
		temp=(struct node *) malloc(sizeof(struct node ));
		temp->left=NULL;
		temp->right=NULL;	
		temp->data=data;
		return temp;
	}

struct node * insert(struct node * root,int data)
   {

	if(root==NULL){ root=newNode(data); } 

	else if(data<=root->data){ root->left=insert(root->left,data);}

	else { root->right=insert(root->right,data);}

	return root;
   }



void preorder(struct node * root)
	{
		printf("%d ",root->data);
		if(root->left) preorder(root->left);

		if(root->right) preorder(root->right);
	}


void postorder(struct node * root)
	{
		if(root->left)postorder(root->left);
		if(root->right) postorder(root->right);
		printf("%d ",root->data);
}

void inorder(struct node *root)
	{
		if(root->left) inorder(root->left);
		printf("%d ",root->data);
		if(root->right) inorder(root->right);
	}	

int main(){
int choice ,val;
	
		struct node * root=NULL;
		

while(choice!=5){
		printf("\nMenu --Binary search tree ");
		printf("\n 1. Insert\t 2. Preorder Traversal \t 3.Inorder Traversal \t4.Postorder traversal\n");
		scanf("%d",&choice);
		switch(choice)
			{ case 1:printf("\nEnter the number to insert:"); scanf("%d",&val);
				root=insert(root,val);printf("\tinserted successfully\n");break;
	 		  case 2: 	
				printf("\npreorder:");
				preorder(root);break;
	 		  case 4:
				printf("\n postorder:");
				postorder(root);break;
	 		  case 3: printf("\n inorder:"); inorder(root);break;
			  case 5: exit(0);
			  default: printf("\nEnter valid choice\n");
}

}



	}
