#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        if(n%16==0 && n>0)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
