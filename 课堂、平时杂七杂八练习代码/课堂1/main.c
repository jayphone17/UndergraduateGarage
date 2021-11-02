/*#include <stdio.h>
#include <stdlib.h>

int main()
{
    int array[10];
    int i;
    int flag=0;
    for(i=0; i<10; i++)
    {
        scanf("%d",&array[i]);

        if(array[i]>=0)
            flag++;
    }
    printf("正数有：%d\n",flag);
    printf("负数有：%d\n",10-flag);
    return 0;
}*/






#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    int i;
    int sum=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        sum=sum+a[i];

    }
    printf("%d\n",sum);
    return 0 ;
}
