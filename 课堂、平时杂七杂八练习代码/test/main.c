#include <stdio.h>
float Fun(int x,int y)
{
    return(x+y);
}

int main()
{
    int a=2,b=5,c=8;
    printf("%3.0f\n",Fun((int)Fun(a+c,b),a-c));
    return 0;
}