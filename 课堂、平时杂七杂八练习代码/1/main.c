#include<stdio.h>
#include<stdbool.h>
int main()
{
    float score;
    scanf("%f",&score);
    bool a,b,c,d,e,f,g,h,i;
    a=score>=60;
    b=score<=69;
    c=score>=70;
    d=score<=79;
    e=score>=80;
    f=score<=89;
    g=score>=90;
    h=score<=100;
    i=score<60;

    if(a==true && b==true)
        printf("The grade is C\n");

        else
          if(c==true && d==true)

            printf("The grade is C+\n");
        else

          if(e==true && f==true)

            printf("The Grade is B");
        else

          if(g==true && h==true)

            printf("The grade is A\n");
        else

            if(i==true)

            printf("成绩不及格");

    return 0;
}