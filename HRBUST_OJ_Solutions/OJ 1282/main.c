#include<stdio.h>
int main()

{
    int i;
    int n = 40111;
    int ans=1;
    for(i = 1; i <= n; i++)
    {
        ans *=i;
        ans %= 40111;
        printf("%d\n",ans);
    }
    return 0;
}

