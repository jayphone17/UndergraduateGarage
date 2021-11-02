#include <stdio.h>
#include <stdlib.h>

int main()
{
    int month,day,num;
    int sum;
    while(scanf("%d%d",&month,&day)!=EOF)
    {
        if(month==2 && day==29)
        {
            num=1154;
        }
        else
        {
            num=0;

            switch(month)
            {
                case 1:
                    sum=0;
                    break;
                case 2:
                    sum=31;
                    break;
                case 3:
                    sum=59;
                    break;
                case 4:
                    sum=90;
                    break;
                case 5:
                    sum=120;
                    break;
                case 6:
                    sum=151;
                    break;
                case 7:
                    sum=181;
                    break;
                case 8:
                    sum=212;
                    break;
                case 9:
                    sum=243;
                    break;
                case 10:
                    sum=273;
                    break;
                case 11:
                    sum=304;
                    break;
                case 12:
                    sum=334;
                    break;
            }

        }
        printf("%d\n",(num+sum+(day-1))*10);
    }
    return 0;
}
