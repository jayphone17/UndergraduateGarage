#include <iostream>
using namespace std;
const int N=11111;
struct Node //定义表结点
{
    int v; //结点编号
    int w;//权值
    Node *next; //指向下一个顶点的指针
};

struct HeadNode //定义头结点
{
    Node *first;//指向头结点
};

HeadNode Graph[N];
int n; //顶点数
int m;//边数
int i ;
int u;//顶点1
int  v;//顶点2
int w;//顶点之间的权值

void InsertEdge(HeadNode &p,int x ,int y) //插入一条边
{
    Node *q;
    q=new(Node);
    q->v=x;
    q->w=y;
    q->next=p.first;
    p.first=q;
    //注意！此处顺序很重要，必须先链接，再断开。
}

void Print(int n) //输出邻接表
{
    cout << "---------------------邻接表如下：----------------------" << endl;
    for (int i=1;i<=n;i++)
    {
        Node *t=Graph[i].first;
        cout <<"v" << i<<":   ";
        while(t!=NULL)
        {
            cout << "["<<t->v<<"   "<<t->w<<"]   ";
            t=t->next;
        }
        cout << endl;
    }
}

int main()
{
    cout << "请输入顶点数n和边数m"<< endl;
    cin >> n>> m;
    for (int i=1;i<=n;i++)
    {
        Graph[i].first=NULL;
    }
    cout << "请输入顶点u，v和顶点之间的权值w" << endl;
    for (i=0;i<m;i++)
    {
        cin >> u>> v>> w;
        InsertEdge(Graph[u],v,w);
    }
    Print(n);//输出邻接表
    return 0;
}
