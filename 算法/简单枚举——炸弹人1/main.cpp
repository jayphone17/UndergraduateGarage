#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

const int N =111; //��ͼ����С

int main()
{
    char graph[N][N];//�洢��ͼ�Ķ�ά����
    int n;//�ж�����
    int m;//�ж�����
    int p;//��¼����ը��x����
    int q;//��¼����ը��y����
    int sum;//��¼���������˸���
    int maxx=0;
    int x;
    int y;
    cout << "�������ͼ����n����m" << endl;
    cin >> n >> m;
    cout << "�������ͼ��" << endl;
    for(int i=0; i<=n-1; i++)
    {
        cin >> graph[i];
    }
    for(int i=0; i<=n-1; i++)
    {
        for(int j=0; j<=m-1; j++)
        {
            if(graph[i][j]=='.') //�жϴ�ʱλ���Ƿ���ƽ��
            {
                sum=0;//��ʼ����������������0
                //������i��j���Ƶ��±���x��y�У��Ա���������ͳ�ƿ������������
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
                if(sum>maxx)
                {
                    maxx=sum;
                    p=i;
                    q=j;
                }
            }
        }
    }
    cout << "��ը��������" <<"("<<p<<","<<q<< ")" <<"����������" << sum << "������"<< endl;
    return 0;
}
