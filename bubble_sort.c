#include <stdio.h>
int main()
{
    int a[20],i,j,n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    printf("Enter array elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<=n-i-1;j++)
        {
            if(a[j]>a[j+1])
            { 
                int t = a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
    printf("After sorting: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}