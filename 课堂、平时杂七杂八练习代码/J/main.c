#include<stdio.h>

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        double res = 0;
        for(int i=1; i<=n; i++)
        {
            if(i%2)res += (1.0/i);
            else res -= (1.0/i);
        }
        printf("%.2f\n",res);
    }
}
