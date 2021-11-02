#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    int positive=0;
    int negative=0;
    scanf("%d",&T);
    while(T--)
    {
        int i;
        int x;
        for(i=0; i<10; i++)
        {
            scanf("%d",&x);
            if(x<0)
            {
                negative++;
            }
            else if(x>0)
            {
                positive++;
            }

        }
        printf("positive:%d\n",positive);
        printf("negative:%d\n",negative);
    }
    return 0;
}
