#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int INF=999999999;
const int MX=11111;
int n; //机器零件的个数
int bestf; //最优加工零件时间
int f1; //在机器1加工的时间
int f2; //在机器2加工的时间
int x[MX]; //记录最优方案零件的编号
int bestx[MX]; //记录最优方案的加工顺序

struct node
{
    int x;//在第一台机器加工的时间
    int y;//在第二台机器加工的时间
}T[MX];
//结构体数组存储所有机器加工时间。

void backtrack(int t)
{
    if(t>n)
    {
        for(int i=1;i<=n;i++)
        {
            bestx[i]=x[i];//记录最优排列
        }
        bestf=f2; //更新最优值.
        return ;
    }
    for(int i=t;i<=n;i++) //枚举
    {
        f1+=T[x[i]].x;
        int temp=f2;
        f2=max(f1,f2)+T[x[i]].y;
        if(f2<bestf) //限界条件（剪枝函数）
        {
            swap(x[t],x[i]);
            backtrack(t+1);//继续深搜
            swap(x[t],x[i]);//复位，反操作
        }
        f1-=T[x[i]].x;
        f2=temp;
        //复位，反操作。
    }
}

int main()
{
    cout << "请输入零件的个数n"<< endl;
    cin >> n;
    cout << "请依次输出每个零件在第一台机器加工的时间x和在第二台机器加工的时间y"<< endl;
    for (int i=1;i<=n;i++)
    {
        cin >> T[i].x >> T[i].y;
        x[i]=i; //零件的编号
    }
    bestf=INF; //赋予∞
    f1=0;
    f2=0;
    memset(bestx,0,sizeof(bestx)); //清空数组
    memset(x,0,sizeof(x));
    backtrack(1); //从排列树第一个结点开始搜索
    cout << "最优的机器零件加工顺序为："<< endl;
    for (int i=1;i<=n;i++)
    {
        cout << bestx[i] <<" ";
    }
    cout << endl;
    cout << "最优的机器零件加工的时间为："<< endl;
    cout << bestf << endl;
    return 0;
}