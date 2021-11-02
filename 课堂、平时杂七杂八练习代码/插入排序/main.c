#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,n,insertnumber;
    scanf("%d",&n);
    int a[n+1];
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&insertnumber);
    for(i=n-1; i>=0; i--)
    {
        if(insertnumber>a[i])
        {
            break;
        }
        a[i+1]=a[i];
    }
    a[i+1]=insertnumber;
    for(i=0; i<=n; i++)
    {
        printf("%d ",a[i]);
    }
    return;
}




