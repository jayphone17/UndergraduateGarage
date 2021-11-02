#include<stdio.h>
int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        getchar();
        char a[n];
        gets(a);
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum = sum * 2 + a[i] - '0';
            if(sum >= 5)
                sum %= 5;
        }
        if(sum == 0)
            printf("Yes!\n");
        else
            printf("No!\n");
    }
}
