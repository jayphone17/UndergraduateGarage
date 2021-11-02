#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main()
{
    int x0,a,c,m,n,t;
    int x0, x1;
    while(~scanf("%d%d%d%d%d%d",&x0,&a,&c,&m,&n,&t))
    {
        for(int i=0; i<n; i++)
        {
            x1 = (x0 * a + c) % m;
            x0 = x1;
        }
        if(t == x1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
