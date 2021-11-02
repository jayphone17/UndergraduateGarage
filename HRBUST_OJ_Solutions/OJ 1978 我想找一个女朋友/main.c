#include<stdio.h>
int main()
{
    int n;
    while(scanf("%d",&n) != EOF)
    {
        int i;
        int flag=0;
        for(i=1; i<=n; i++)
        {
            int b=i;
            while(b)
            {
                int a=b%10;
                if(a==1)
                    flag++;
                b/=10;
            }
        }
        printf("%d\n",flag);
    }
    return 0;
}
