#include <stdio.h>
void sort(int a[],int l,int m,int h)
{
    int t[20];
    int i = l,j = m + 1;
    int s=0,k;
    while(i<=m && j<=h)
    {
        if(a[i]<a[j])
        {
            t[s++]=a[i++];
        }
        else
        {
            t[s++]=a[j++];
        }
    }
     while(i<=m)
    {
        t[s++]=a[i++];
    }
    while(j<=h)
    {
        t[s++]=a[j++];
    }
    
    for(k=0;k<s;k++)
    {
        a[l+k]=t[k];
    }
}
void merge(int a[],int l,int h)
{
    int m;
    if(l<h)
    {
        m=(l+h)/2;
        merge(a,l,m);
        merge(a,m+1,h);
        sort(a,l,m,h);
    }
}
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
    merge(a,0,n-1);
    printf("After sorting: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }

}