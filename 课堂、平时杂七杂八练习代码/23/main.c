#include<stdio.h>
int main(void)
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        char c;
        int n,Tc,Tf;
        scanf("%d%c",&n,&c);
        if(c=='C')
        {
            Tf=n*9/5+32;
            printf("%dF\n",Tf);
        }
        else if(c=='F')
        {
            Tc=(n-32)*5/9;
            printf("%dC\n",Tc);
        }
    }
    return 0;
}