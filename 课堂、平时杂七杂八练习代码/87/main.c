#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char a[20];
        scanf("%s",a);
        int i,len;
        len=strlen(a);
        for(i=len-1; i>=0; i--)
        {
            switch(a[i])
            {
            case '0':
            case '1':
                a[i]='O';
                break;
            case '2':
            case '3':
                a[i]='T';
                break;
            case '4':
            case '5':
                a[i]='F';
                break;
            case '6':
            case '7':
                a[i]='S';
                break;
            case '8':
                a[i]='E';
                break;
            case '9':
                a[i]='N';
                break;
            }
            printf("%c",a[i]);

        }
        printf("\n");

    }
    return 0;
}
