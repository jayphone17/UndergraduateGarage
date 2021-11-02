1927ма╨ю

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        char a[1],b[1];
        scanf("%c%c",&a,&b);
        if((a[1]=='A' && b[1]=='A') || (a[1]=='B' && b[1]=='B') || (a[1]=='C' && b[1]=='C')
            )
        {
            printf("6\n");
        }
        else
        {
            printf("4\n");
        }
    }

    return 0;
}
