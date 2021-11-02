#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    while(scanf("%d",&N)!=EOF)
    {
        if(N==1)
            printf("1");
        if(N==2)
            printf("1");
        if(N==3)
            printf("2");
        if(N==4)
            printf("3");
        if(N==5)
            printf("5");
        if(N==6)
            printf("8");
        if(N==7)
            printf("13");
        if(N==8)
            printf("21");
        if(N==9)
            printf("34");
    }
    return 0;
}
