#include<stdio.h>
int main()
{
    int T,n,Tc,Tf;
    scanf("%d",&T);
    char c;
    while(T--)
    {
        scanf("%d%c",&n,&c);
        if('C'==c)
        {
            Tf=((9/5)*n)+32;
            printf("%dF\n",Tf);
        }
        else if('F'==c)
        {
            Tc=(5/9)*(n-32);
            printf("%dC\n",Tc);
        }
    }
    return 0;
}