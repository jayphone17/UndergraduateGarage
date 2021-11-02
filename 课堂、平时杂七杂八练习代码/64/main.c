#include <stdio.h>
#include <string.h>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int i,len;
        char a[30];
        scanf("%s",a);
        len=strlen(a);
        for(i=0; i<len-1; i++)
        {
            switch(a[i])
            {
                case '0':
                    printf("zero-");
                    break;
                case '1':
                    printf("one-");
                    break;
                case '2':
                    printf("two-");
                    break;
                case '3':
                    printf("three-");
                    break;
                case '4':
                    printf("four-");
                    break;
                case '5':
                    printf("five-");
                    break;
                case '6':
                    printf("six-");
                    break;
                case '7':
                    printf("seven-");
                    break;
                case '8':
                    printf("eight-");
                    break;
                case '9':
                    printf("nine-");
                    break;
            }
        }
        switch(a[len-1])
        {
            case '0':
                printf("zero");
                break;
            case '1':
                printf("one");
                break;
            case '2':
                printf("two");
                break;
            case '3':
                printf("three");
                break;
            case '4':
                printf("four");
                break;
            case '5':
                printf("five");
                break;
            case '6':
                printf("six");
                break;
            case '7':
                printf("seven");
                break;
            case '8':
                printf("eight");
                break;
            case '9':
                printf("nine");
                break;
        }
        printf("\n");
    }
    return 0;
}
