#include <stdio.h>
int main()
{
    int a[20],i,j,n,s;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    printf("Enter array elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        s=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[s])
            {
                s=j;
            }
        }
        int t = a[i];
        a[i]=a[s];
        a[s]=t;
    }
    printf("After sorting: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}