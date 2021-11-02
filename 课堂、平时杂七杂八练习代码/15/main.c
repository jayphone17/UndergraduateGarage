#include<stdio.h>
int main()
{
    int x,y;
    while(scanf("%d%d",&x,&y)!=EOF)
    {
        float ability;

        ability=0.99*x+0.01*y;
        printf("%.2f\n",ability);
    }
    return 0;
}