#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a[11111];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        while(n--)
        {
            int i;
            for(i=0; i<9; i++)
            {
                scanf("%d",&a[i]);
            }
            printf("%d %d %d\n",a[0],a[3],a[6]);
            printf("%d %d %d\n",a[1],a[4],a[7]);
            printf("%d %d %d\n\n",a[2],a[5],a[8]);
        }
    }
    return 0;
}
