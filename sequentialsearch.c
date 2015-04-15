#include <stdio.h>

int main()
{
int a[100],n,i,key,flag=0,j;

printf("Enter no of elements:\n");

scanf(" %d",&n);

printf("Enter %d elements \n",n);

for(i=0;i<n;i++) scanf("%d",&a[i]);

printf("Enter key to search:\n");

scanf("%d",&key);

for(i=0;i<n;i++){ if(a[i]==key) flag=1;j=i;}

if(flag==0) printf("Item not found");
else
printf("Item found at %d");
return 0;}
