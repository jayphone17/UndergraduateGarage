#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        int str[100];
        scanf("%d",&n);
        int i;
        for(i=0;i<n;i++)
        {
            scanf("%d",&str[i]);
            int m;
            m=str[i]/10;
            switch(m)
            {
            case 10:
            case 9:printf("A ");break;
            case 8:printf("B ");break;
            case 7:printf("C ");break;
            case 6:printf("D ");break;
            default:printf("E ");break;
            }
        }
        printf("\n");
    }
    return 0;
}
