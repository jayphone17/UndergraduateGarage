#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

const int N=11111;
int maze[N][N]; //��ͼ����
int marked[N][N];//�������
int n; //��¼����
int m;//��¼����
int p;//��¼Ŀ�������
int q;//��¼Ŀ��������
int minn=9999999;

void dfs(int x,int y,int step)
{
    int tx;
    int ty;
    int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    //�ֱ��������ߣ������ߣ������ߣ������ߡ�

    if(x==p && y==q) //�ж������Ƿ����
    {
        if(step<minn)
        {
            minn=step; //������С����
        }
        return;
    }

    for (int k=0;k<=3;k++)
    {
        tx=x+next[k][0];
        ty=y+next[k][1];
        if(tx<1 || tx>n || ty<1 || ty>m)
        {
            continue;
        }
        if(maze[tx][ty]==0 && marked[tx][ty]==0) //�ж��Ƿ����ϰ�������Ƿ��Ѿ���·����
        {
            marked[tx][ty]=1;//˵��������Ѿ��߹���
            dfs(tx,ty,step+1);
            marked[tx][ty]=0;//���Խ�����ȡ�������ı�ǡ�
        }
    }
    return;
}

int main()
{
    int startx;
    int starty;
    cout << "�������ͼ�Ĵ�С��n��m" << endl;
    cin >> n>> m;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            cin >> maze[i][j];
        }
    }
    cout << "����������������յ�����꣺" << endl;
    cin >> startx >> starty >> p >> q;
    marked[startx][starty]=1;//��ʱ��������˵���Ѿ���·����
    dfs(startx,starty,0);
    cout << "Aͬѧ����Bͬѧλ�õ���̲����ǣ�" << endl;
    cout << minn<< endl;
    return 0;
}
