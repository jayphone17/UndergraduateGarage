#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=111;
int e[N][N];//�洢��
int matched[N];//�ж��Ƿ��Ѿ�ƥ��
int marked[N]; //�ж��Ƿ��Ѿ�����
int n;
int m;

int dfs(int u)
{
    for(int i=1;i<=n;i++)
    {
        if(marked[i]==0 && e[u][i]==1) //û�б����ʹ��ҿɴ�
        {
            marked[i]=1;
            if(matched[i]==0 || dfs(matched[i])) //���û����ԣ���i��u��ԡ�
                                                                //��dfs����һ��i������û����ԡ����û����ԣ�����0
            {
                matched[i]=u;
                return 1;//��Գɹ�����1.���ý���dfs
            }
        }
    }
    return 0;
}

int main()
{
    int edge1;
    int edge2;
    int sum=0;
    cout << "������n������m����" << endl;
    cin >> n >> m;
    cout << "���������пɽ�����ԵĶ��㣺 "<< endl;
    for (int i=1;i<=m;i++)
    {
        cin >> edge1 >> edge2;
        e[edge1][edge2]=1;//˵������������֮����ڱߡ�
    }
    //��ʼ��ƥ�����顣
    for (int i=1;i<=n;i++)
    {
        matched[i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            marked[j]=0; //����ϴ��������ʹ��ļ�¼
        }
        if(dfs(i))
        {
            sum++;
        }
    }
    cout << "���ƥ�����ǣ�"<< endl;
    cout << sum << endl;
    return 0;
}
