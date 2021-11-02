#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int a1,a2,a3,a4;
        scanf("%d%d%d%d",&a1,&a2,&a3,&a4);
        if(a1+a2>a3&&a1+a3>a2&&a2+a3>a1 ||a1+a2>a4&&a1+a4>a2&&a2+a4>a1 ||a2+a3>a4&&a2+a4>a3&&a3+a4>a2 ||a1+a3>a4&&a1+a4>a3&&a3+a4>a1)
        {
            printf("T\n");
        }
        else if(a1+a2==a3||a1+a3==a2||a2+a3==a1||a1+a2==a4||a1+a4==a2||a2+a4==a1||a2+a3==a4||a2+a4==a3||a3+a4==a2)
        {
            printf("S\n");
        }
        else
        {
            printf("I\n");
        }

    }
    return 0;
}
