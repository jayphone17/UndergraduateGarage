#include<stdio.h>
int main()
{
    int X,Y,Ability;
    while(scanf("%d%d",&X,&Y)!=EOF)
    {
        Ability=0.99*X+0.01*Y;

        printf("������ֵ=%.2d\n",Ability);
    }
    return 0;
}