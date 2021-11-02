#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

#define maxx 11111
#define M 111 //定义重量和价值数组的最大范围

int c[M][maxx]; //表示房间购物车的最大价值。比如说c[i][j]表示i个物品放进容量为j的购物车获得的最大价值
int v[M]; //价值数组
int w[M]; //重量数组
int x[M]; //标记数组

int main()
{
    int i;//循环条件
    int j;//循环条件
    int n;//物品的个数
    int W;//购物车最大容量
    cout << "请输入物品的个数n"<< endl;
    cin >> n;
    cout << "请输入购物车的最大容量W" <<endl;
    cin >> W;
    cout << "请输入物品的重量和价值，用空格隔开" << endl;
    for (i=1;i<=n;i++)
    {
        cin >> w[i] >> v[i];
    }
    for (i=0;i<=n;i++)
    {
        c[i][0]=0;//初始化第0列为0
    }
    for (j=0;j<=W;j++)
    {
        c[0][j]=0;//初始化第0行为0
    }
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=W;j++)
        {
            if(w[i]>j) //此时物品的重量大于最大容量
            {
                c[i][j]=c[i-1][j]; //故只将i-1件物品装进购物车
            }
            else
            {
                c[i][j]=max(c[i-1][j],c[i-1][j-w[i]]+v[i]);
                //此时能装进购物车内，比较此物品，放与不放谁的价值高，选择价值最高的那一个。
            }
        }
    }
    cout << "装入购物车的最大价值为："<< c[n][W] << endl;//根据矩阵，此时c[n][W]的值就是购物车能装进的最大价值、
    //接下来通过x[i]数组逆向求解装进了哪些物品。
    j=W;
    for (i=n;i>0;i--)
    {
        if(c[i][j]>c[i-1][j]) //若此时最大价值更高，加进购物车。
        {
            x[i]=1; //标记数组标记为1
            j=j-w[i]; //最大重量减去加入购物车的物品的重量得到购物车剩余容量
        }
        else
        {
            x[i]=0;//此时没有加进购物车
        }
    }
    for (i=1;i<=n;i++)
    {
        if(x[i]==1)
        {
            cout << i << "  ";
            //输出哪件物品加进了购物车
        }
    }
    return 0;
}
