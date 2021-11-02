#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=111;
char graph[N][N];
int marked[N][N];
int maxx;
int n;
int m;
int mx;
int my;

int getnum(int i,int j)//�����������������ĺ���
{
    int sum=0;
    int x;
    int y;
    x=i;
    y=j;
    while(graph[x][y]!='#')//ֻҪû�е��߽�
    {
        if(graph[x][y]=='G')//�ǵ���
        {
            sum++;//����������
        }
        x--;//��������Ѱ��
    }
    x=i;
    y=j;
    while(graph[x][y]!='#')//ֻҪû�е��߽�
    {
        if(graph[x][y]=='G')//�ǵ���
        {
            sum++;//����������
        }
        x++;//��������Ѱ��
    }
    x=i;
    y=j;
    while(graph[x][y]!='#')//ֻҪû�е��߽�
    {
        if(graph[x][y]=='G')//�ǵ���
        {
            sum++;//����������
        }
        y--;//��������Ѱ��
    }
    x=i;
    y=j;
    while(graph[x][y]!='#')//ֻҪû�е��߽�
    {
        if(graph[x][y]=='G')//�ǵ���
        {
            sum++;//����������
        }
        y++;//��������Ѱ��
    }
    return sum;
}

void DFS(int x,int y)
{
    int next[4][2]= {{0,1},{1,0},{0,-1},{-1,0}}; //�����ĸ����������
    int tx;
    int ty;
    int sum;
    sum=getnum(x,y);
    if(sum>maxx)
    {
        maxx=sum;
        mx=x;
        my=y;
    }
    for(int k=0; k<=3; k++)
    {
        tx=x+next[k][0];
        ty=y+next[k][1];
        if(tx<1 || tx>n-1 || ty<1 || ty>m-1)
        {
            continue;
        }
        if(graph[tx][ty]=='.' && marked[tx][ty]==0)
        {
            marked[tx][ty]=1;
            DFS(tx,ty);
        }
    }
    return ;
}

int main()
{
    int startx;
    int starty;
    cout << "�������ͼ������n������m�Լ���������"<< endl;
    cin >> n>> m>> startx>>starty;
    cout << "�������ͼ"<< endl;
    for(int i=0; i<=n-1; i++)
    {
        cin >> graph[i];
    }
    marked[startx][starty]=1;
    maxx=getnum(startx,starty);
    mx=startx;
    my=starty;
    DFS(startx,starty);
    cout << "��ը������" << "(" << mx << "," << my << ")"<< "���������������ˣ�" << maxx << endl;
    return 0;
}
