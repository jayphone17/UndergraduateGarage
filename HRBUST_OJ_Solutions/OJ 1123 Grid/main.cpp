#include <cstdio>
using namespace std;
int main()
{
    int m,n;
    while(scanf("%d%d",&m,&n)!=EOF&&n!=0||m!=0)
    {
        int a=1,b=1;
        for(int i=m+n; i>n; i--)
            a*=i;
        for(int i=1; i<=m; i++)
        b*=i;
        printf("%d\n",a/b);
    }
}
