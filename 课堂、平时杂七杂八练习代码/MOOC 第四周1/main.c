#include<math.h>
#include<stdio.h>
int main()
{

        printf("Input a/b, c/d:");
        int a,b,c,d;
        scanf("%d/%d,%d/%d",&a,&b,&c,&d);
        int n,m;
        n=a*d;
        m=c*b;
        if(n>m)
        {
            printf("%d/%d>%d/%d\n",a,b,c,d);
        }
        else if(n==m)
        {
            printf("%d/%d=%d/%d\n",a,b,c,d);
        }
        else if(n<m)
        {
            printf("%d/%d<%d/%d\n",a,b,c,d);
        }

}
