#include <stdio.h>

int main()

{
int a[100],j,mid,n,i=0,key,flag=0;

printf("Enter number of elements");

scanf("%d",&n);

printf("Enter element \n");

for(i=0;i<n;i++) scanf("%d",&a[i]);
j=n-1;i=0;

printf("Enter key to search ");

scanf("%d",&key);

while(i<=j)
{
mid=i+j/2;

if(a[mid]==key) { flag=1;break;}

else if(a[mid]<key) i=mid+1;

else j=mid-1;

}

if (flag==1)
printf("Item found in array\n");

else printf("Item not found..\n");

}
