#include <stdio.h>
#include <stdlib.h>

int main()
{
    int math1,English,math2;
    float Finalscore;
    scanf("%d%d%d",&math1,&English,&math2);
    Finalscore=(math1*5+English*1.5+math2*3.5)/10;
    printf("%.2f\n",Finalscore);
    return 0;
}
