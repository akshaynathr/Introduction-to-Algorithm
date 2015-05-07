#include<stdio.h>
#include <stdlib.h>
int hash(int n)
    { 
      int k;
      k=n%10;
      return (k);
    }
 
struct node
    {
    int data;
     struct node *link;
     }*ptr,*p,*k;
     
main()
    { struct node *new,*new1,*p;
     struct node * HT[10];int k,n,i,flag=0,flag2=0,op;
     for(i=0;i<10;i++) HT[i]=NULL;
     
     while(1){
     printf("MENU\n  1.Insert\n  2.Search\n  3.Exit\n");
     printf("Option :");
     scanf("%d",&op);
     switch(op)
     	{
         case 1:   
		     printf("Enter Number : ");
		     scanf("%d",&n);k=n;
		     i=hash(n);
		     
		     if(HT[i]!=NULL)
		       {  p=HT[i];
			  
			      while(p->link!=NULL){if(p->data==k)
			                       {printf("Already Exist...!\n");break;}
				                 p=p->link;
			                    }
			                   
			                
			   new=(struct node *)malloc(sizeof(struct node));
			   new->data=k;
			   new->link=NULL;
			   p->link=new;
			   printf("\nData inserted Successfully...\n");
		        }        
		      
		      if(HT[i]==NULL){
			   new=(struct node *)malloc(sizeof(struct node));
			   new->data=n;
			   new->link=NULL;
			   HT[i]=new;
			   printf("\nData inserted Successfully...\n");
			   }break;  
	case 2: printf("Enter data to search : ");
	        scanf("%d",&n) 	;
	         i=hash(n);
	      
	         if(HT[i]!=NULL){ 
	                    p=HT[i];
			  	        while(p!=NULL)
			    		 {printf("%d\n",p->data);
			    		  if(p->data==n){flag2=1;}
			     	 	   p=p->link;
			    		 }
		                    }
		 if(flag2==1) printf("Data found in Hash Table..!\n");       
		 else printf("Data not found in Hash Table...!\n");
		 break;
	case 3: exit(0);break;
	}	 
		 	    
	         
	        
	        	   
      }}        
        
