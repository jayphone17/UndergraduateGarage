#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        while(~scanf("%d",&n))
        {
            float score;
            while(scanf("%f",&score)!=EOF)
            {
                bool a,b,c,d,e,f,g,h;
                a=score>=90;
                b=score<=89;
                c=score>=80;
                d=score<=79;
                e=score>=70;
                f=score<=69;
                g=score>=60;
                h=score<60;
                if(a==true)
                    printf("A ");
                if(b==true && c==true)
                    printf("B ");
                if(d==true && e==true)
                    printf("C ");
                if(f==true && g==true)
                    printf("D ");
                if(h==true)
                    printf("E ");
            }

        }
    }
    return 0;
}
