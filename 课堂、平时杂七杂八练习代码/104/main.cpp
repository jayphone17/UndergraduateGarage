#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {

        scanf("%c%c",&a,&b);
        if ((int)(a-b)==0)
            printf("6\n");
        else
            printf("8\n");
    }
    return 0;
}
