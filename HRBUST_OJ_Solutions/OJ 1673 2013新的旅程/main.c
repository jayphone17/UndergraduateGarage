#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n%222!=0)
            printf("Orz..\n");
        else
        {
            int key=n/222;
            if(key>5 && key<=11)
            {
                a=key-1;
                b=a-2;
                printf("%d\n",1*100+2*10+b);
            }
            else if(key>11 && key<=18)
            {
                a=key-1;
                b=a-9;
                printf("%d\n",1*100+b*10+9);
            }
            else if(key >18 && key <= 25)
            {
                a=key-9;
                b=a-8;
                printf("%d\n",b*100+8*10+9);
            }
            else
            {
                printf("Orz..\n");
            }
        }
    }
    return 0;
}
