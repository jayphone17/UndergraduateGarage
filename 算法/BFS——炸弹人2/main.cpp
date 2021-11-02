#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

char graph[21][21];//�洢��ͼ

struct node
{
    int x;
    int y;
};

int getnum(int i,int j) //������ȡ�������������ĺ���
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

int main()
{
    struct node que[444];//��������
    int head;
    int tail;
    int marked[21][21]={0};//����һ����Ƕ�ά���飬��ʼ��ȫ��Ϊ0
    int sum; //�������������
    int maxx=0;
    int n; //��n��
    int m; //��m��
    int startx; //��ʼ��x����
    int starty; //��ʼ��y����
    int tx; //bfs�ƽ�����
    int ty; //ͬ��
    int mx; //���շ���ը��x����
    int my; //���շ���ը��y����
    int next[4][2]= {{0,1},{1,0},{0,-1},{-1,0}}; //�����ĸ����������
    cout << "�������ͼ�Ĵ�С����n����m�������������x��y" << endl;
    cin >> n >> m >> startx >> starty;
    cout << "�������ͼ��"<< endl;
    for(int i=0; i<=n-1; i++)
    {
        cin >> graph[i];
    }
    //���г�ʼ��
    head=1;
    tail=1;
    //�������Ȳ�����ʼ������
    que[tail].x=startx;
    que[tail].y=starty;
    tail++;//tailָ�����
    marked[startx][starty]=1;//��ʼ���Ѿ��߹�
    maxx=getnum(startx,starty);
    mx=startx;
    my=starty;
    while(head<tail) //�����в�Ϊ��ʱ
    {
        //ö���ĸ�����
        for(int k=0; k<=3; k++)
        {
            tx=que[head].x+next[k][0];
            ty=que[head].y+next[k][1];
            //�жϱ߽�
            if(tx<1 || tx>n-1 || ty<1 || ty>m-1)
            {
                continue;
            }
            //�ж��Ƿ���ƽ�غ��Ƿ��Ѿ��߹���
            if(graph[tx][ty]=='.' && marked[tx][ty]==0)
            {
                marked[tx][ty]=1;
                que[tail].x=tx;
                que[tail].y=ty;
                tail++;
                sum=getnum(tx,ty);
                if(sum>maxx)
                {
                    maxx=sum;
                    mx=tx;
                    my=ty;
                }
            }
        }
        head++;//ǰ���Ѿ���չ�ĵ��ò����ˣ�����
    }
    cout << "��ը������" << "(" << mx << "," << my << ")"<< "���������������ˣ�" << maxx << endl;
    return 0;
}
