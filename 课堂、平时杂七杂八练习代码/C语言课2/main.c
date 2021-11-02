#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    scanf("%d",&N);
    int i,j=1;
    for(i=0;i<N;i++)
    {
        j=j*i;
    }
    printf("%d",j);
    return 0;
}
