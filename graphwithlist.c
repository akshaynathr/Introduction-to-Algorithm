/*PROGRAM TO IMPLEMENT GRAPH USING LINKED LIST*/

#include<stdio.h>                                 
#include<stdlib.h>                               
void dfs();                                            
void bfs();                                            

struct link                                           
{
		struct node *next;
		struct link *adj;
};

struct node                                          
{
		int data,status;
		struct node *next;
		struct link *adj;
};

struct node *start,*p,*q;                   
struct link *l,*k;                        

void create()                              
{
		int dat,flag=0;         
	 	start=NULL;                     
	 	printf("Enter the nodes in the graph(-1 to end): ");
		while(1)
		{
				scanf("%d",&dat);      
		 		if(dat==-1)                    
						break;
				p=(struct node*)malloc(sizeof(struct node)); 
				p->data=dat;                                                       
				p->status=0;
				p->next=NULL;                                   
				p->adj=NULL;    
		 		if(flag==0)                                                          
				{
						start=p;
						q=p;
						flag++;
				} 
				else                                                                         
				{
						q->next=p;
						q=p;
				}
		}                                                                           
		p=start;                                                               
		while(p!=NULL)
		{                                                    
				printf("Enter the links to %d (-1 to end) : ",p->data);
				flag=0;                                                                 
				while(1)
				{
						scanf("%d",&dat);
						if(dat==-1)
								break;
						k=(struct link*)malloc(sizeof(struct link));         
						k->adj=NULL;
						if(flag==0)
						{
								p->adj=k;
								l=k;
								flag++;
						}
						else
						{
								l->adj=k;
								l=k;
						}
						q=start;
						while(q!=NULL)
						{
								if(q->data==dat)
										k->next=q;
								q=q->next;
						}
				}
				p=p->next;
		}
}

//Function for Breadth First Traversal of Graph 
void bfs()                        
{
		int q1[20],i=1,j=0;
		p=start;
		while(p!=NULL)
		{
				p->status=0;
				p=p->next;
		}
		p=start;
		q1[0]=p->data;
		p->status=1;
		while(1)
		{
				if(q1[j]==-1)
						break;
				p=start;
				while(p!=NULL)
				{
						if(p->data==q1[j])
								break;
						p=p->next;
				}
				k=p->adj;
				while(k!=NULL)
				{
						q=k->next;
						if(q->status==0)
						{
								q1[i]=q->data;
								q->status=1;
								q1[i+1]=-1;
								i++;
						}
						k=k->adj;
				}
				j++;
		}
		j=0;
		printf("Breadth First Search Results\n");
		while(q1[j]!=-1)                                               
		{
				printf("%d ",q1[j]);                     
				j++;
		}
}

//Function for Depth First Search(DFS) Traversal.
void dfs()
{
		int stack[20],top=1;
		printf("Deapth First Search Results\n");
		p=start;
		while(p!=NULL)
		{
				p->status=0;
				p=p->next;
		}
		p=start;
		stack[0]=-1;
		stack[top]=p->data;
		p->status=1;
		while(1)
		{
				if(stack[top]==-1)
						break;
				p=start;
				while(p!=NULL)
				{
						if(p->data==stack[top])
								break;
						p=p->next;
				}
				printf("%d ",stack[top]);        
				top--;
				k=p->adj;
				while(k!=NULL)
				{
						q=k->next;
						if(q->status==0)
						{
								top++;
								stack[top]=q->data;
								q->status=1;
						}
						k=k->adj;
				}
		}
}

int main()
{
		int ch;
		create();                               
		while(1)
		{
				printf("\n1: DFS\n2: BSF\n3: Exit\nEnter your choice: ");
				scanf("%d",&ch);              
				switch(ch)
				{
						case 1:
								dfs();                                   
								break;
						case 2:
								bfs();                                 
								break;
						case 3:
								exit(0);                             
								break;
						default:
								printf("Incorrect choice!\n");
				}
		}
		printf("\n");
		return 0;
}   	                                    

