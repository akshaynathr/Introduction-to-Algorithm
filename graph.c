/*PROGRAM TO IMPLEMENT GRAPH USING ARRAY*/

#include<stdio.h>
#include<stdlib.h>

#define MAX 100
#define initial 1
#define waiting 2
#define visited 3

int n,choice,top=-1;
int adj[MAX][MAX];
int stack[MAX];
int state[MAX];
int queue[MAX],front=-1,rear=-1;

int isempty_stack();
int delete_queue();
int isempty_queue();
int pop();
void push(int v);
void create_graph();
void BF_Traversal();
void BFS(int v);
void insert_queue(int vertex);
void DF_Traversal();
void DFS(int v);

main()
{
		create_graph();
		do
		{
				printf("\n1.Breadth first traversal\n2.depth first traversal\n3.Exit\nEnter your choice :  ");
				scanf("%d",&choice);
				switch(choice)
				{
						case 1:
								printf("\nBREADTH FIRST TRAVERSAL");
								BF_Traversal();
								break;
						case 2:
								printf("\nDEPTH FIRST TRAVERSAL");
								DF_Traversal();
								break;
						case 3:
								exit(0);
						default:
								printf("\nInvalid choice!!!\n");
				}
		}while(1);
}

void BF_Traversal()
{
		int v;
		for(v=0;v<n;v++)
				state[v]=initial;
		printf("\nEnter starting vertex for Breadth First Search  : ");
		scanf("%d",&v);
		BFS(v);
}

void BFS(int v)
{
		int i;
		insert_queue(v);
		state[v]=waiting;
		while(!isempty_queue())
		{
				v=delete_queue();
				printf("%d  ",v);
				state[v]=visited;
				for(i=0;i<n;i++)
				{
						if(adj[v][i]==1&&state[i]==initial)
						{	
								insert_queue(i);
								state[i]=waiting;
						}
				}
		}
		printf("\n");
}

void insert_queue(int vertex)
{
		if(rear==MAX-1)
				printf("queue overflow");
		else 
		{
				if(front==-1)front=0;
						rear=rear+1;
				queue[rear]=vertex;
		}
}

int isempty_queue()
{
		if(front==-1||front>rear)
				return 1;
		return 0;
}

int delete_queue()
{
		int del_item;
		if(front==-1||front>rear)
		{
				printf("queue underflow\n");
				exit(1);
		}
		del_item=queue[front];
		front=front+1;
		return del_item;
}

void create_graph()
{
		int i,max_edges,origin,destin;
		printf("Enter number of vertices :");
		scanf("%d",&n);
		max_edges=n*(n-1);
		for(i=1;i<=max_edges;i++)
		{
				printf("Enter edge %d( -1 -1 )to quit :",i);
				scanf("%d %d",&origin,&destin);
				if((origin==-1)&&(destin==-1))
						break;
				if(origin>=n||destin>=n||origin<0||destin<0)
				{
						printf("Invalid edge!\n");
						i--;
				}
				else
						adj[origin][destin]=1;
		}
} 

void DF_Traversal()
{
		int v;
		for(v=0;v<n;v++)
				state[v]=initial;
		printf("\nEnter starting node for depth first search :");
		scanf("%d",&v);
		DFS(v);
}

void DFS(int v)
{
		int i;
		push(v);
		while(!isempty_stack())
		{
				v=pop();
				if(state[v]==initial)
				{
						printf("%d  ",v);
						state[v]=visited;
				}
				for(i=n-1;i>=0;i--)
				{
						if(adj[v][i]==1&&state[i]==initial)
								push(i);
				}
		}
}		

void push(int v)
{
		if(top==(MAX-1))
		{
				printf("stack overflow\n");
				return;
		}	
		top=top+1;
		stack[top]=v;
}

int pop()
{
		int v;
		if(top==-1)
		{
				printf("stack underflow\n");
				exit(1);
		}
		else
		{
				v=stack[top];
				top--;
				return v;
		}
}

int isempty_stack()
{
		if(top==-1)
				return 1;
		return 0;
}
		
