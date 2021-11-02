#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,n;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        if((m%4==0&&m%100!=0)||(m%400==0))
        {
            switch(n)
            {
                case 1:printf("31\n");break;
                case 2:printf("29\n");break;
                case 3:printf("31\n");break;
                case 4:printf("30\n");break;
                case 5:printf("31\n");break;
                case 6:printf("30\n");break;
                case 7:printf("31\n");break;
                case 8:printf("31\n");break;
                case 9:printf("30\n");break;
                case 10:printf("31\n");break;
                case 11:printf("30\n");break;
                case 12:printf("31\n");break;
            }

        }
        else
        {
            switch(n)
            {
                case 1:printf("31\n");break;
                case 2:printf("28\n");break;
                case 3:printf("31\n");break;
                case 4:printf("30\n");break;
                case 5:printf("31\n");break;
                case 6:printf("30\n");break;
                case 7:printf("31\n");break;
                case 8:printf("31\n");break;
                case 9:printf("30\n");break;
                case 10:printf("31\n");break;
                case 11:printf("30\n");break;
                case 12:printf("31\n");break;
            }
        }
    }
    return 0;
}
