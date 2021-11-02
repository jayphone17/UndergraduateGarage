#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

struct Meeting
{
    int begin;//��¼��ʼ��ʱ��
    int end;//��¼������ʱ��
    int number;//��¼����ı��
}meet[11111];

bool cmp(Meeting x,Meeting y) //�����Ƚ����Ļ�����ǰ��
{
    if(x.end==y.end)
    {
        return x.begin>y.begin;
    }
    else
    {
        return x.end<y.end;
    }
}

class setMeet
{
public :
    int init();
    int solve();
private:
    int n;//��������
    int ans ;//�����鰲������
};

int setMeet::init()
{
    int b,e;//��ʾ���鿪ʼ�ͽ�����ʱ��
    cout << "���������������"<< endl;
    cin >> n;
    cout << "��������鿪ʼ�ͽ�����ʱ�䣬�ÿո�ֿ�" << endl;
    for (int i=0;i<n;i++)
    {
        cin >> b>>e;
        meet[i].begin=b;
        meet[i].end=e;
        meet[i].number=i+1;
    }
}

int setMeet :: solve ()
{
    sort(meet,meet+n,cmp);
    cout << " ������֮��Ļ���ʱ�����£�"<< endl;
    cout << "������  " <<"��ʼ�¼�  "<<"����ʱ��  "<<endl;
    int i;
    for (i=0;i<n;i++)
    {
        cout << "   "<< meet[i].number <<"\t\t"<< meet[i].begin << "\t"<< meet[i].end<<endl;
    }
    cout << "--------------------------------------------------------------------------"<< endl;
    cout << "ѡ�����Ĺ���"<< endl;
    cout << "ѡ���"<< meet[0].number<< "������"<< endl;
    ans=1;
    int last=meet[0].end;//��Ϊ��һ������Ľ���ʱ�䡣
    for (i=1;i<n;++i)
    {
        if(meet[i].begin>=last)//�����һ������Ŀ�ʼ�¼�����һ������Ľ���ʱ��Ҫ��
        {
            ans++;
            last=meet[i].end;
            //����last��ֵ
            cout<< "ѡ���"<< meet[i].number<< "������"<< endl;
        }
    }
    cout <<"���԰���" << ans << "������"<< endl;
}

int main()
{
    setMeet sm;
    sm.init();
    sm.solve();
    return 0;
}
