#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

int a[111];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int  n;
        int  num=0;
        scanf("%d",&n);
        int i;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=0;i<n;i++)
        {
            if(a[i]==1)
                num++;
        }
        double percentage;
        percentage=(1.0*num)/(1.0*n);
        printf("%.2lf\n",percentage);

    }
    return 0;
}
