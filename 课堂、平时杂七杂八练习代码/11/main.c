#include<stdio.h>
#include<math.h>
int main()
{
    int r,a,b;
    int diagonal;

    while(scanf("%d%d%d",&r,&a,&b)!=EOF)
    {
        diagonal=sqrt(a*a+b*b);
        if(diagonal<=r)
        {
            printf("YES\n");
        }
        else if(diagonal<r)
        {
            printf("NO\n");
        }

    }
    return 0;
}
