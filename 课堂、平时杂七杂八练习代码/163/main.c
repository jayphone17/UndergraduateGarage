#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int str[10000];
int main()
{
    int N;
    int i;
    scanf("%d",&N);
    while(N--)
    {
        for(i=0;i<N;i++)
        {
            scanf("%c",&str[i]);
        }
        srot(str,str+N);
        printf("%c",str[i-1]/2);
    }
    return 0;
}
