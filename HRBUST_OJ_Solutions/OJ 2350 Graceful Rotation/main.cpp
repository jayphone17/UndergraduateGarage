#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int i;
        int j;
        int a[n][n];
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        for(i=0; i<n; i++)
        {
            for(j=n-1; j>=0; j--)
            {
                printf("%d",a[j][i]);
                if(j!=0) printf(" ");
                else printf("\n");
            }
        }
    }
    return 0;
}
