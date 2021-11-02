#include<bits/stdc++.h>

using namespace std;

int a[1111];
int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        if(n == 0)
            printf("0\n");
        else
        {
            for(int i = 0; i < n; i ++)
                scanf("%d", &a[i]);
            sort(a, a + n);
            if(a[0] < 0 && a[n - 1] < 0)
                printf("%d\n", -a[0]);
            else if(a[0] < 0 && a[n - 1] > 0)
            {
                if(-a[0] < a[n - 1])
                    printf("%d\n", -a[0] * 2 + a[n - 1]);
                else
                    printf("%d\n", -a[0] + 2 * a[n - 1]);
            }
            else if(a[0] > 0)
                printf("%d\n", a[n - 1]);
        }
    }
    return 0;
}