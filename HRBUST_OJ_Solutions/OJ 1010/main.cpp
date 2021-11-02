#include<iostream>
#include<algorithm>
#include <stdio.h>
using namespace std;

bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    int num,i;
    int arr[10050];
    while(scanf("%d",&num)!=EOF)
    {
        for(i=0;i<num;i++)
            scanf("%d",arr[i]);

        sort(arr,arr+num,cmp);

        for(i=0;i<num;i++)
        {
            printf("%d\n",arr[(num-1)/2]);
        }
        //cout<<arr[(num-1)/2]<<endl;
    }
    return 0;
}