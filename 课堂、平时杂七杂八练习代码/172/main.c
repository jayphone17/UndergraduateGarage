#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,temp;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        if(a<b) //如果a<b交换位置。
        {
            temp = a;
            a = b;
            b = temp;
        }
        while(a%b != 0) //运用辗转相除法。直到a%b=0。
        {
            temp = a%b;
            a = b;
            b = temp;
        }
        printf("%d\n",b);
    }
    return 0;
}
