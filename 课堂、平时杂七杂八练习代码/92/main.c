#include <stdio.h>
#include <stdlib.h>

int main()
{
    int f1,f2,n;
    while(scanf("%d%d%d",&f1,&f2,&n)!=EOF)
    {
        int i;
        int flag=0;
        for(i=0; i<30; i++)
        {
            if(f1<=n)
            {
                flag++;
            }
            f2=f1+f2;
            f1=f2-f1;
        }
        printf("%d\n",flag);
    }
    return 0;
}
