#include <stdio.h>
#include <stdlib.h>

//#define NULL ((void *)0)

void swap(int *p1,int *p2)
{
    int i;
    int *p=&i;   //这是一个没有初始化的指针。不知道p指向谁。
    *p=*p1;
    *p1=*p2;
    *p2=*p;
}


int main()
{
    int a;
    int b;
    int *pointer_1;
    int *pointer_2;
    scanf("%d%d",&a,&b);
    pointer_1=&a;
    pointer_2=&b;
    if(a<b)
        swap(pointer_1,pointer_2);
    printf("%d %d",a,b);

    return 0;
}
