#include <stdio.h>
void swap(int *a,int *b);


void main()
{ int a[100],n,i,j,small,k=0,flag=0,y;

printf("Enter the limit :\n");
scanf("%d",&n);
printf("Enter elements:");
for(i=0;i<n;i++) scanf("%d",&a[i]);

for(i=0;i<n;i++)
	{ small=a[i]; flag=0;

for(j=i+1;j<n;j++)
{ if(small>a[j])
	{ small=a[j]; k=j;flag=1;}
}
if(flag==0) break;

if(i!=k){ y=a[i]; a[i]=a[k]; a[k]=y;}
}

for(i=0;i<n;i++) printf("%d\t",a[i]);

}
