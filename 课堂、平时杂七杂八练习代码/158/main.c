#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    int m,n,product,z;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&m,&n);
        product=m*n;
        z=product%10000;
        printf("%04d\n",z);
    }
    return 0;
}
