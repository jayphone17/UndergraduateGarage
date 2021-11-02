#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int one,two=0,three;
        one=8;
        two=12*(n-2);
        three=6*(n-2)*(n-2);
        printf("%d\n",one);
        printf("%d\n",two);
        printf("%d\n",three);
    }
    return 0;
}
