#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;
int a[11111];
int b[11111];
bool cpm(int a,int b)
{
    return a>b;
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int i;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        int maxn,minn;
        sort (a,a+n);



    }
    return 0;
}
