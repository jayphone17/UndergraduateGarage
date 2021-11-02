#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

struct Meeting
{
    int begin;//记录开始的时间
    int end;//记录结束的时间
    int number;//记录会议的编号
}meet[11111];

bool cmp(Meeting x,Meeting y) //排序，先结束的会议排前。
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
    int n;//会议总数
    int ans ;//最大会议安排总数
};

int setMeet::init()
{
    int b,e;//表示会议开始和结束的时间
    cout << "请输入会议总数："<< endl;
    cin >> n;
    cout << "请输入会议开始和结束的时间，用空格分开" << endl;
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
    cout << " 排完序之后的会议时间如下："<< endl;
    cout << "会议编号  " <<"开始事件  "<<"结束时间  "<<endl;
    int i;
    for (i=0;i<n;i++)
    {
        cout << "   "<< meet[i].number <<"\t\t"<< meet[i].begin << "\t"<< meet[i].end<<endl;
    }
    cout << "--------------------------------------------------------------------------"<< endl;
    cout << "选择会议的过程"<< endl;
    cout << "选择第"<< meet[0].number<< "个会议"<< endl;
    ans=1;
    int last=meet[0].end;//设为第一个会议的结束时间。
    for (i=1;i<n;++i)
    {
        if(meet[i].begin>=last)//如果下一个会议的开始事件比上一个会议的结束时间要晚
        {
            ans++;
            last=meet[i].end;
            //更新last的值
            cout<< "选择第"<< meet[i].number<< "个会议"<< endl;
        }
    }
    cout <<"可以安排" << ans << "个会议"<< endl;
}

int main()
{
    setMeet sm;
    sm.init();
    sm.solve();
    return 0;
}
