#include <stdio.h>

int main()
{

int a[100], i, j,n, temp;

printf("Enter the limit:\n");

scanf("%d",&n);

printf("enter the %d Numbers:\n",n);

for(i=0;i<n;i++) scanf("%d",&a[i]);
for(i=0;i<n;i++)
{ for(j=0;j<n-1;j++)
	{if(a[j]>a[j+1])
	 { temp=a[j];
	   a[j]=a[j+1];
	   a[j+1]=temp;}
	}
}

printf("Elements in sorted order are ..:\n");

for(i=0;i<n;i++) printf("%d\t",a[i]);
}
