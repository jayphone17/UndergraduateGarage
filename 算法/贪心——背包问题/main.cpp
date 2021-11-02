#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
using namespace std;

const int M=1111111;

struct package
{
    int weight; //重量
    int value;//价值
    int cost_performance;//性价比
}s[M];

bool cmp(package a,package b)
{
    return a.cost_performance>b.cost_performance;
}
//将性价比从大到小排序，用于后面的sort函数中

int main()
{
    int n;//有n个宝物
    double m;// 马车最大运载量
    cout << "请输入宝物的数量和马车的最大运载量：" << endl;
    cin >> n>>m;
    cout << "请输入每个宝物的重量和价值，用空格分开" << endl;
    for (int i=0;i<n;i++)
    {
        cin >> s[i].weight >> s[i].value;
        s[i].cost_performance=s[i].value / s[i].weight;
        //每个宝物的单位性价比
    }
    sort(s,s+n,cmp);//将性价比从大到小排序
    double sum=0.0; //价值之和
    for(int i=0;i<n;i++)
    {
        if(s[i].weight<m)
        {
            sum+=s[i].value;
            m-=s[i].weight;
        }
        else //有剩余容量,分割带走
        {
            sum+=m*s[i].cost_performance;
            break;
        }
    }
    cout << "装入宝物的最大价值为：" <<sum << endl;
    return 0;
}
