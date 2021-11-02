#include<stdio.h>
#include<string.h>
#include<algorithm>//调用sort需要头文件algorithm
using namespace std;//调用C++中的函数需要域名std
struct node
{
    int damage;
    int price;
    char name[105];
};
node gun[100005];
bool cmp(node a,node b)
{
    if (a.damage==b.damage)
    {
        if (a.price==b.price)
        {
            return strcmp(a.name,b.name)<0;
        }
        else return a.price<b.price;
    }
    else return a.damage>b.damage;
}
int main()
{
    int n;
    while (~scanf("%d",&n))
    {
        for (int i=0;i<n;i++)
        scanf("%s%d%d",gun[i].name,&gun[i].damage,&gun[i].price);
        sort(gun,gun+n,cmp);//如果自定义了排序方法，即使没有重载小于号也可以使用sort函数
        for (int i=0;i<n;i++)
            printf("%s\n",gun[i].name);
    }
}
