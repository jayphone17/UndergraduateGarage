#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int a[30],i;
        scanf("%c",&a);
        if(a[i]>='0' && a[i]<='9')
        {
            switch(a)
            {
            case 0:printf("zero");break;
            case 1:printf("one");break;
            case 2:printf("two");break;
            case 3:printf("three");break
            case 4:printf("four");break;
            case 5:printf("five");break;
            case 6:printf("six");break;
            case 7:printf("seven");break;
            case 8:printf("eight");break;
            case 9:printf("nine");break;

            }
        }
    }
    return 0;
}
