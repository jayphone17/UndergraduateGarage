#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{
    int x1,y1,x2,y2,x3,y3,T;
    double len1,len2,len3,s,area;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&x1,&y1);
        scanf("%d%d",&x2,&y2);
        scanf("%d%d",&x3,&y3);
        len1=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        len2=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
        len3=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
        s=(len1+len2+len3)/2;
        area=sqrt(s*(s-len1)*(s-len2)*(s-len3));
        if((len1+len2)>len3 && fabs(len1-len2)<len3 && (len2+len3)>len1 && fabs(len2-len3)<len1 && (len1+len3)>len2 && fabs(len1-len3)<len2)
        {
            printf("%.2f",area);
        }
        else
        {
            printf("fail\n");
        }
    }
    return 0;
}
