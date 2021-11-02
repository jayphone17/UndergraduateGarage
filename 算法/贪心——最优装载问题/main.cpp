#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
const int N =111111;
double weight[N];//物品重量数组
int main()
{
    double carry;
    int n;
    cout << "请输入最大载重量重量c和物品数量n ：" << endl;
    cin >> carry>>n;
    cout << "请输入每个物品的重量：" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> weight[i];
    }
    sort(weight,weight+n);
    double temp=0.0;//已经装进的物品的重量
    int number=0;//已经装进的物品的数量
    for(int i=0; i<n; i++)
    {
        temp+=weight[i];
        if(temp<carry)
        {
            number++;
        }
        else
        {
            break;
        }
    }
    cout << "能装入物品的最大数量为：" << endl;
    cout << number << endl;
    return 0;
}
