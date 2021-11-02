#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N=1111;
int father[N]={0};
int n;
int m;
int k;
int sum=0;

void initialize() //初始化函数，将father数组每个元素的下标等于自身的数字
{
    for (int i=1;i<=n;i++)
    {
        father[i]=i;
    }
}

int getfather(int v) //找祖宗递归函数
{
    if(father[v]==v) //如果编号等于祖宗的编号（或是自己的）算法结束
    {
        return v; //返回祖宗编号
    }
    else
    {
        //在返回时，把路上遇到的人的编号改为最后找到祖宗的编号
        //这是最最最祖宗的编号。
        //这样可以提高找到最最最最后的祖宗编号的速度。
        father[v]=getfather(father[v]); //否则递归查找祖宗编号
        return father[v]; //最终返回祖宗编号。
                                    //返回father[v]是可以用于递归查找。
    }
}

void Merge(int v,int u)
{
    int t1;
    int t2;
    t1=getfather(v); //第一个结点的编号
    t2=getfather(u); //第二个结点的编号
    if(t1!=t2) //如果编号不相等
    {
        father[t2]=t1; //将较小的编号赋予较大的编号，靠左原则。
    }
}

int main()
{
    int x;
    int y;
    int i;
    cout << "请输入盗贼的人数和目前知道的情报的条数" << endl;
    cin >> n>> m;
    initialize();
    cout << "请输入情报：谁和谁是同伙" << endl;
    for (i=1;i<=m;i++)
    {
        cin >> x>> y; //输入关系
        Merge(x,y); //将最终编号一样的结点合并。
    }
    for (i=1;i<=n;i++)
    {
        if(father[i]==i)
        {
            sum++;
        }
    }
    cout <<"犯罪团伙的个数有：" << endl;
    cout << sum;
    return 0;
}
