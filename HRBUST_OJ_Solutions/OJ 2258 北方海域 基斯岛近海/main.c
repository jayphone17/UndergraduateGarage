#include <stdio.h>
#include <stdlib.h>

int main()
{
    int p,n; //概率。。要获得的经验。。
    while(~scanf("%d%d",&p,&n))
    {
        int zuishao,zuiduo;
        int a,b;
        if(p!=100)
        {
            zuishao=n/(3*384);  //如果是MVP的话，总共有3.5倍经验。
            zuiduo=n/(1.5*384); //如果不是MVP，就只有战舰的1.5倍经验。
            a=n%(3*384);
            b=n%576;
            if(b!=0)
            {
                zuiduo++;
            }
            if(a!=0)
            {
                zuishao++;
            }
        }
        if(p==100)
        {
            zuishao=n/3/384; //一定是MVP。最少次数直接用N除以能获得的经验。
            b=n%(384*3);
            if(b!=0)
                zuishao++;
            zuiduo=zuishao;
        }
        printf("%d %d\n",zuishao,zuiduo);
    }
    return 0;
}
