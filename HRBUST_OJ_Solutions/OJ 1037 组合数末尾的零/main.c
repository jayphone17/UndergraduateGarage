#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int m,n;
    int differ=m-n;
    int sum=1;  //m!
    int temp=1; //n!
    int flag=1; //(m-n)!int v;
    int ans[11111];
    int Fuck;
    int v;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&m,&n);
        for(int i=m; i>0; i--)
        {
            sum=sum*i;
        }
        for(int j=n; j>0; j--)
        {
            temp=temp*j;
        }
        for(int r=differ; r>0; r--)
        {
            flag=flag*r;
        }
        int conbination=sum/(temp*flag);
        while(conbination>0)
        {
            Fuck=conbination%2;
            conbination=conbination/2;
            v=0;
            ans[v]=Fuck;
            v=v+1;
            int count=0;
            for(int z=0; z<=v; z++)
            {
                if(ans[z]=='0')
                    count++;
            }
            printf("%d",count);
        }
        return 0;
    }
}
