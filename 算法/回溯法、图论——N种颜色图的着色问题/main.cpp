#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXX=111;//�趨�߽�
int map[MAXX][MAXX]; //�ڽӾ���洢ͼ
int x[MAXX]; //���������¼ɫ��
int sum=0; //��¼�ж����ַ���
int n; //�������
int m;//�ߵĸ���
int color_nums; //��ɫ����

void createmap() //�����ڽӾ���
{
    int u; //����1
    int v; //����2
    cout << "������ߵĸ���m��"<< endl;
    cin >> m;
    memset(map,0,sizeof(map));
    cout << "�������б���������������u��v��"<< endl;
    for (int i=1;i<=m;i++)
    {
        cin >> u>>v;
        map[u][v]=1;
        map[v][u]=1;
    }
}

bool OK(int t) //�ж�ɫ���Ƿ���ͬ�ĺ���
{
    for(int j=1;j<t;j++) //�ж�������չ��t��ǰ��t-1��������û��������
    {
        if(map[t][j]) //�������
        {
            if(x[j]==x[t]) //����ɫһ��
            {
                return false; //����false��������Ҫ����ɫ�ų���
            }
        }
    }
    return true; //���ɫ�Ų�һ������true
}

void backtrack(int t) //���ݡ����ƺ���
{
    if(t>n) //����Ҷ�ӽڵ�
    {
        sum++; //��������
        cout << "��"<< sum << "�ַ���"<< endl;
        for (int i=1;i<=n;i++)
        {
            cout << x[i] << "    ";
        }
        cout << endl;
    }
    else
    {
        for (int i=1;i<=color_nums;i++) //���Ա��ɫ��
        {
            x[t]=i;  //��¼ɫ��
            if(OK(t)) //���ɫ��û��ײ
            {
                backtrack(t+1); //���µ���
            }
        }
    }
}


int main()
{
    cout << "�����������n��"<< endl;
    cin >> n;
    cout << "��������ɫ��������"<< endl;
    cin >> color_nums;
    cout << "���������ڽӾ���洢��ͼ��"<< endl;
    createmap();
    backtrack(1);
    return 0;
}
