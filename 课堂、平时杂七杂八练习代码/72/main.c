#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a[100];
        int n;
        scanf("%d",&n);
        int i;
        for(i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
            int m;
            m=a[i]/10;
            switch(m)
            {
                case 10:
                case 9:
                    printf("A ");
                    break;
                case 8:
                    printf("B ");
                    break;
                case 7:
                    printf("C ");
                    break;
                case 6:
                    printf("D ");
                    break;
                default:
                    printf("E ");
                    break;
            }
        }
        printf("\n");
    }
    return 0;
}

