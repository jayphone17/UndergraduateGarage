#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        char a[2],b[2];
        scanf("%s%s",a,b);
        if(strcmp(a,b)==0)
        {
            printf("6\n");
        }
        else
        {
            printf("5\n");
        }
    }
    return 0;
}
