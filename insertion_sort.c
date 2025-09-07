#include <stdio.h>
int main()
{
    int a[20],i,n,current,prev;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    printf("Enter array elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1;i<n;i++)
    {
        current = a[i];
        prev = i-1;
        while(prev>=0 && current<a[prev])
        {
            a[prev+1]=a[prev];
            prev--;
        }
        a[prev+1]=current;
    }
    printf("After sorting: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}