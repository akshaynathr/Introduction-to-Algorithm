#include<stdio.h>

void frontenq();
void rearenq();
void frontdeq();
void reardeq();
void display();

void main()
	{
	 int a[10],i,j,n=0,k;
	 int ff=-1,rf=-1,fr=-1,rr=-1;
	 
	  while(1)
	 	{
	 	printf("___MENU___\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT\n\n");
	 		printf("Option : ");
	 		scanf("%d",&i);
	 		
	 		if(i==1){
		 		 	 printf("\nENQUEUE_MENU\n");
				 	 printf("1.Insert at front\n2.Insert at back\n");
				 	 printf("Option : ");
	 				 scanf("%d",&k);
	 				 if(k==1) frontenq(a,&ff,&fr,&n);
	 				 else if(k==2) rearenq(a,&rf,&rr,&n);
	 				 else printf("invalid Option...!\n");
	 				}		 
	 		else if(i==2)
	 			{    
	 				 printf("\nDEQUEUE_MENU\n");
				 	 printf("1.Delete at front\n2.Delete at back\n");
				 	 printf("Option : ");
	 				 scanf("%d",&k);
	 				 if(k==1) frontdeq(a,&ff,&fr,&n);
	 				 else if(k==2) reardeq(a,&rf,&rr,&n);
	 				 else printf("invalid Option...!\n");
	 			
	 			}	 			
	 	 			
	 		else if(i==3) 
	 				 {
	 				 
				 	  display(a,&ff,&fr,&rf,&rr);
	 				 
				 	 }
		}
		}
	
void frontenq(int a[],int *ffp,int *frp,int *n)
	{
	 int k;
	 if(*n>=10) printf("OVERFLOW...!\n");    // Queue is full
	 else
	  	 {
	  	  if(*ffp==-1 && *frp==-1) *ffp=0;
	  	  
	  	  *frp=*frp+1;
	  	  *n=*n+1;
	  	  printf("Enter data to insert : ");
	  	  scanf("%d",&a[*frp]);
	  	  printf("Data inserted successfully...\n");
	  	 }
    }		
				 	 
void rearenq(int a[],int *rfp,int *rrp,int *n)
	{
	 int k;
	 if(*n>=10) printf("OVERFLOW...!\n");    // Queue is full
	 else
	  	 {
	  	  if(*rfp==-1 && *rrp==-1) {*rfp=9;*rrp=10;}
	  	  
	  	  *rrp=*rrp-1;
	  	  *n=*n+1;
	  	  printf("Enter data to insert : ");
	  	  scanf("%d",&a[*rrp]);
	  	  printf("Data inserted successfully...\n");
	  	 }
    }						 	 
				 	 
void frontdeq(int a[],int *ffp,int *frp,int *n)
	{
		if(*ffp==-1) printf("UNDERFLOW...!\n");           //Queue is empty
		else
		  { if(*ffp==*frp) {*ffp=*frp=-1;}
		   else
			{ *ffp=*ffp+1;
			  printf("Item deleted Successfully...\n");
			}
		  }
     }		  
		  	
	
void reardeq(int a[],int *rfp,int *rrp,int *n)
	{
		if(*rfp==-1) printf("UNDERFLOW...!\n");           //Queue is empty
		else
		{
		if(*rfp==*rrp) {*rfp=*rrp=-1;}
		 else
		 	{ *rfp=*rfp-1;
			  printf("Item deleted Successfully...\n");
			}
	    }
	 }   					 	 
		
void display(int a[],int *fp1,int *rp1,int *fp2,int *rp2)
	
	{int i=0;
	 if(*fp1==-1)
	 	printf("FRONT QUEUE is Empty...!\n\n");    //checking whether empty or not
	 else
	 	{printf("FRONT QUEUE Elements are...\n");
	 	
	 	 i=*fp1;
	 	 
	 	 while(i<=*rp1)
	 	 	{printf("%d\n",a[i]);
	 	 	 i++;
	 	    }
	    }
	
	 if(*fp2==-1)
	 	printf("BACK QUEUE is Empty...!\n\n");    //checking whether empty or not
	 else
	 	{//printf("BACK QUEUE Elements are...\n");
	 	
	 	 i=*rp2;
	 	 
	 	 while(i>=*fp2)
	 	 	{printf("%d\n",a[i]);
	 	 	 i--;
	 	    }
	    }
	} 	 						
				 	 
