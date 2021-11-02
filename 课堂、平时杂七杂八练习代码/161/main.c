#include <stdio.h>
#include <stdlib.h>

int main()
{
    int k;
    while(scanf("%d",&k)!=EOF)
    {
        printf("%d\n",6*k*k-6*k+1);
    }
    return 0;
}
