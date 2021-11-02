#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;
int str[10005];
int main()
{
    int N;
    int i;
    scanf("%d",&N);
    for(i=0; i<N; i++)
    {
        scanf("%d",&str[i]);
    }
    sort(str,str+N);
    printf("%d\n",str[i/2]);
    return 0;
}
