#include <stdio.h>
#include <stdlib.h>
int gcd(int x,int y)
{
    if(y==0)   //当找到最大公约数的条件。
    {
        return x;  //最大公约数
    }
    else return gcd(y,x%y);
    //如果还没找到，就一直执行这个函数，知道找到最大公约数。
}

int gcb(int x,int y)  //求最小公倍数的函数。
{
    return x*y/gcd(x,y);
}

int gcb_2(int x,int y,int z)
{
    return gcb(gcb(x,y),z);
}

int main()
{
    int x,y,z;
    long long n;
    while(scanf("%d%d%d%lld",&x,&y,&z,&n)!=EOF)
    {
        printf("%lld\n",n/gcb_2(x,y,z));
    }
    return 0;
}
