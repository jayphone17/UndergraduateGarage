#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if(a<b)
        printf("NO BRAINS\n");
        else
            printf("MMM BRAINS\n");
    }
    return 0;
}
