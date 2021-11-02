#include<stdio.h>
int main()
{
    int n;
    int i;
    int ans;
    int x;
    while(~scanf("%d",&n))
    {
        ans=1;
        for(i=0; i<n; i++)
        {
            scanf("%d",&x);
            if(x%2==1)
            {
                ans=ans*x;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
