#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
       int num=0;
       num=num+(n/16)*9;
       num=num+(n%16/8)*3;
       num=num+(n%16%8/4)*1;
       printf("%d\n",num);
    }
    return 0;
}
