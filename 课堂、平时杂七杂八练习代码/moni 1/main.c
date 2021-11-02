#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    int N;
    int sum;
    scanf("%d",&N);
    while(N--)
    {
        scanf("%d%d",&a,&b);
        sum=a+b;
        printf("%d\n",sum);
    }
    return 0;
}
