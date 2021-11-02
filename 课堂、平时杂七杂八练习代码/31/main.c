#include <stdio.h>
int main()
{
    int a,b,temp;
    scanf("%d%d",&a,&b);
    if(a<b)
    {
        temp=a;
        a=b;
        b=temp;
    }
    while(a%b!=0)
    {
        temp=a%b;
        a=b;
        b=temp;
    }
    printf("%d\n",b);
    return 0;
}
