#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=100;
    int b=10;
    int *pointer1;
    int *pointer2;
    pointer1=&a;
    pointer2=&b;
    printf("a=%d\n",a);
    printf("b=%d\n",b);
    printf("*pointer1=%d\n",*pointer1);
    printf("*pointer2=%d\n",*pointer2);
    return 0;
}
