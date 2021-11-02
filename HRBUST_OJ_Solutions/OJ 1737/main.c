#include<stdio.h>
int main()
{
    int t,a,b;
    while(~scanf("%d",&t))
    {
        while(t--)
        {
            scanf("%d%d",&a,&b);
            if(a>0&b>0&&a+b<=0||a<0&&b<0&&a+b>=0)
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }
        }
    }
    return 0;
}