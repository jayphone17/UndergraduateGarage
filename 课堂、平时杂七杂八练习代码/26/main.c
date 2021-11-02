#include<stdio.h>
int main()
{
    int L;
    while(scanf("%d,&L")!=EOF)
    {
        if(L%2==0)
        {
            printf("2\n");
        }
        else if(L%2!=0)
        {
            printf("1\n");
        }
    }
    return 0;
}
