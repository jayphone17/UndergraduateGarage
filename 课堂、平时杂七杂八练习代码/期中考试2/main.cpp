#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int i;
        int sum=0;
        for(i=1;i<=n;i++)
        {
            sum=sum+i;
        }
        printf("%d\n\n",sum);
    }
    return 0;
}
