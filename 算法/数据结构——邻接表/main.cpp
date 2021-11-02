#include <iostream>
using namespace std;
const int N=11111;
struct Node //�������
{
    int v; //�����
    int w;//Ȩֵ
    Node *next; //ָ����һ�������ָ��
};

struct HeadNode //����ͷ���
{
    Node *first;//ָ��ͷ���
};

HeadNode Graph[N];
int n; //������
int m;//����
int i ;
int u;//����1
int  v;//����2
int w;//����֮���Ȩֵ

void InsertEdge(HeadNode &p,int x ,int y) //����һ����
{
    Node *q;
    q=new(Node);
    q->v=x;
    q->w=y;
    q->next=p.first;
    p.first=q;
    //ע�⣡�˴�˳�����Ҫ�����������ӣ��ٶϿ���
}

void Print(int n) //����ڽӱ�
{
    cout << "---------------------�ڽӱ����£�----------------------" << endl;
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
    cout << "�����붥����n�ͱ���m"<< endl;
    cin >> n>> m;
    for (int i=1;i<=n;i++)
    {
        Graph[i].first=NULL;
    }
    cout << "�����붥��u��v�Ͷ���֮���Ȩֵw" << endl;
    for (i=0;i<m;i++)
    {
        cin >> u>> v>> w;
        InsertEdge(Graph[u],v,w);
    }
    Print(n);//����ڽӱ�
    return 0;
}
