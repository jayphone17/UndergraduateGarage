#include <stdio.h>
#include <string.h>


int main()
{
    char a[1000000];
    long long b;
    while(~scanf("%s%lld",a,&b))
    {
        long long c=strlen(a);
        long long s=b%c;
        for(int i=c-s; i<c; i++)
            printf("%c",a[i]);
        for(int i=0; i<c-s; i++)
            printf("%c",a[i]);
        printf("\n");
    }
    return 0;
}
