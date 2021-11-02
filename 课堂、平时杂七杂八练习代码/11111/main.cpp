#include <iostream>
#include<cstdio>
using namespace std;
int a[1100];
int main()
{
    int C;
    scanf("%d",&C);
    while(C--)
    {
        int N,sum=0;
        scanf("%d",&N);
        for(int i=0; i<N; i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        double average=sum/N;
        int flag=0;
        for(int i=0; i<N; i++)
        {
            if(a[i]>average)
                flag++;
        }
        printf("%.3f%%\n",(double)flag/N*100);
    }
    return 0;
}
