#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    int i,len;
    int str[30];
    scanf("%d",&T);
    len=strlen(str);
    for(i=0; i<len; i++)
    {
        scanf("%d",&str[i]);
        switch(str[i])
        {
            case '0':
                printf("Zero ");
                break;
            case '1':
                printf("One ");
                break;
            case '2':
                printf("Two ");
                break;
            case '3':
                printf("Three ");
                break;
            case '4':
                printf("Four ");
                break;
            case '5':
                printf("Five ");
                break;
            case '6':
                printf("Six ");
                break;
            case '7':
                printf("Seven ");
                break;
            case '8':
                printf("Eigth ");
                break;
            case '9':
                printf("Nine ");
                break;
        }
    }
    return 0;
}
