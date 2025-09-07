#include <stdio.h>
int main()
{
    int a[20],i,n,k,num,flag=0;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    printf("Enter array elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the number to be searched: ");
    scanf("%d",&num);
    for(i=0;i<n;i++)
    {
        if(a[i]==num)
        {
            k=i;
            flag = 1;
            break;
        }
    }
    if(flag==1)
     printf("Number is found at position %d",k+1);
    else
     printf("Number not found");
     return 0;
}