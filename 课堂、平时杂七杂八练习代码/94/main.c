#include <stdio.h>
#include <stdlib.h>
#define NUMBER 5
void bsort(int a[],int n)
{
    int i,j;
    for(i=0; i<n-1; i++)
    {
        for(j=n-1; j>i; j--)
        {
            if(a[j-1]>a[j])
            {
                int t;
                t=a[j];
                a[j]=a[j-1];
                a[j-1]=t;
            }
        }
    }
}

int main()
{
    int i;
    int height[NUMBER];
    printf("������%d�˵����.\n"��NUMBER);
    for(i=0; i<NUMBER; i++)
    {
        scanf("%d",&height[i]);
        printf("%2d��:",i+1);
    }
    bsort(height,NUMBER);
    puts("����������");
    for(i=0; i<NUMBER ; i++)
    {
        printf("%2d��:&d\n",i+1,height[i]);
    }
    return 0;
}
