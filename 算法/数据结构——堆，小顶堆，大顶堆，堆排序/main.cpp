#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int h[1111]; //用来存储二叉树的数组。
int n;//堆的大小

void swap(int x,int y)
{
    int temp;
    temp=h[x];
    h[x]=h[y];
    h[y]=temp;
    return;
}

void shiftdown(int i)
{
    int tmp; //临时变量，用来存储更新结点编号
    int flag=0;//用来标记此顶点需不需要向下调整，0是需要调整，1是不需要
    while(i*2<=n && flag==0)//当结点存在儿子时，至少存在左儿子，执行循环
    {
        //首先判断与左儿子的辨析，用tmp记录值较小的结点编号
        if(h[i]<h[i*2])
        {
            tmp=i*2; //用tmp记录较大的结点编号
        }
        else
        {
            tmp=i;
        }
        if(i*2+1<=n) //如果有右儿子，再对右儿子进行讨论
        {
            if(h[i*2+1]<h[tmp])
            {
                tmp=i*2+1;
            }
        }
        if(tmp!=i) //如果发现最小的结点不是自己，说明子结点中还有值更小的结点
        {
            swap(tmp,i);
            i=tmp; //更新刚才交换之后的儿子结点的编号，便于接下来向下调整。
        }
    }
    return;
}

void shiftup(int i)
{
    int flag=0;
    if(i==1)
        return;//此时是堆顶，不需要上调
    while(i!=1 && flag==0)
    {
        if(h[i]<h[i/2])
        {
            swap(i,i*2);
        }
        else
        {
            flag=1;
        }
        i=i/2;//更新编号i为它父结点的编号。
    }
    return;
}

void create()
{
    for(int i=n/2; i>=1; i--)
    {
        shiftdown(i);
    }
    return ;
}

void HeapSort() //交换思维的堆排序
{
    while(n>1)
    {
        swap(1,n); //将最小的元素放到堆顶，最大的元素放到h[n]，此时h[n]就是最大的元素。
        n--; //将堆的大小减小1
        shiftdown(1); //向下调整
    }
}

int main()
{
    int num;
    cout << "请输入元素的个数："<< endl;
    cin >> num;
    cout << "请输入各结点的元素：" << endl;
    for (int i=1;i<=num;i++)
    {
        cin >> h[i];
    }
    n=num;
    create();//建堆
    HeapSort();//排序
    for (int i=1;i<=num;i++)
    {
        cout << h[i];
    }
    cout << endl;
    return 0;
}
