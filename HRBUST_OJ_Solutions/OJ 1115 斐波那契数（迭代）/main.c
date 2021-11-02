#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    int a1,a2,sum;
    scanf("%d",&N);
    a1 = 0;
    a2 = 1;
    a3 = 1;
    for(i = 1                                                                                                                                                                                                                                                                                                             ; i <= N; i++)
    {
        sum = a1 + a2 + a3;
        a1 = a2;
        a2 = a3;
        a3 = sum;
    }
    printf("%d\n",sum);
    return 0;
}
