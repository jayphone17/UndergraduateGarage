#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
int a[1000000];
#include <string.h>
#include <algorithm>
using namespace std;
int main()

{
    int n,i;
    while (scanf("%d",&n)!=EOF)
    {
        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        for (i=0;i<n;i++)
        {
            printf("%d\n",a[i]);
        }
    }
    return 0;
}