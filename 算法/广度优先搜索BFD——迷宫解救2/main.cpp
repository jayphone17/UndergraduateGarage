#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=111;

struct note
{
    int x;//������
    int y;//������
    int step;//����
};

int next[4][3]= {{0,1},{1,0},{0,-1},{-1,0}};

int main()
{
    struct note que[N*N];//����
    int head;
    int tail;
    int maze[N][N]= {0}; //��ʼ����ͼ
    int marked[N][N]= {0}; //������飬�ж��Ƿ񱻷���
    int next[4][3]= {{0,1},{1,0},{0,-1},{-1,0}};//�������顣
    int n;
    int m;
    int startx;
    int starty;
    int p;
    int q;
    int tx;
    int ty;
    int flag;
    cout << "�������Թ�������n������m" << endl;
    cin >> n>> m;
    cout << "�������Թ�maze" << endl;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin >> maze[i][j];
        }
    }
    cout << "���������������Ŀ������꣺"<< endl;
    cin >> startx >> starty >> p >> q;
    head=1;
    tail=1;
    //ָ�����ͷ
    //�����в����Թ�������꣺
    //��һ������1��1��������У���Ϊ�˴�����㣬Ĭ���Ѿ��ڶ�����
    que[tail].x=1;
    que[tail].y=1;
    que[tail].step=0;
    tail++;//������
    marked[1][1]=1;//��ʱ��1��1���Ѿ����ʹ���
    flag=0;//��������Ƿ��Ѿ�����Ŀ��㡣

    while(head<tail)
    {
        //ö���ĸ�����
        for(int k=0; k<=3; k++)
        {
            tx=que[head].x+next[k][0];
            ty=que[head].y+next[k][1];
            //�ж��Ƿ�Խ�磺
            if(tx<1 || tx>n || ty<1 || ty>m)
            {
                continue;
            }
            //�ж��Ƿ����ϰ�����Ƿ��Ѿ����ʣ�
            if(maze[tx][ty]==0 && marked[tx][ty]==0)
            {
                marked[tx][ty]=1; //��ʱ�Ѿ����ʹ�
                que[tail].x=tx;
                que[tail].y=ty;
                que[tail].step=que[head].step+1;
                tail++;
            }
            if(tx==p && ty==q)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            break;
        }
        head++;//���Ѿ���չ���ĵ���С�
    }
    cout << "Aͬѧ�ҵ�Bͬѧ����̾����ǣ�"<< que[tail-1].step << endl;
    return 0;
}
