#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,n;
    int f[30];
    while(scanf("%d%d%d",&a,&b,&n)!=EOF)
    {
        if(a<=10 && b<=10 && n<=30)
        {
            f[1]=a;
            f[2]=b;
            if(n>2)
            {
                for(int j=3; j<=n; j++)
                {
                    if(j%2==1) f[j]=f[j-1]+f[j-2];
                    else if(j%2==0) f[j]=f[j-1]+f[j-2]+f[j-3];
                }
                if(n%2==1)
                    f[n]=f[n-1]+f[n-2];
                else if(n%2==0)
                    f[n]=f[n-1]+f[n-2]+f[n-3];
            }
        }
        printf("%d\n",f[n]);
    }
    return 0;
}
