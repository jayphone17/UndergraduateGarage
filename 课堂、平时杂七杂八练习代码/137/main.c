#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;


int main()
{
    int i,j;
    int n;
    int a[n+1];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",a[i]);
    }
    sort(1,n)
    for(i=0;i<n;i++)\
    {
        printf("%d",a[i]);
        printf("\n");
    }
    return 0;

}
