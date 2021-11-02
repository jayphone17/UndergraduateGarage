#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int N;
    long long int geshu;
    while(~scanf("%ld",&N))
    {
        geshu=(1+(2*N-1)*(2*N-1));
        printf("%ld\n",geshu);
    }
    return 0;
}

