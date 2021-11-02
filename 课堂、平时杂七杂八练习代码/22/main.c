#include <stdio.h>
int main(void)
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int num;
        char cf;
        scanf("%d%c", &num, &cf);
        if(cf == 'C') printf("%d%c\n", num * 9 / 5 + 32, 'F');
        else printf("%d%c\n", (num - 32) * 5 / 9, 'C');
    }
    return 0;
}

