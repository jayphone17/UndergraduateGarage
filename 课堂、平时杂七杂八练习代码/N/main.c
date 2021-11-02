#include<stdio.h>
#include<string.h>
int a[10005];
int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }
        int F=0;
        for(int i=1; i<n; i++)
        {
            if(a[i]<=a[i-1])F=1;
        }
        if(!F)
            printf("yes\n");
        else printf("no\n");
    }
}
