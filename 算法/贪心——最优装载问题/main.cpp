#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
const int N =111111;
double weight[N];//��Ʒ��������
int main()
{
    double carry;
    int n;
    cout << "�������������������c����Ʒ����n ��" << endl;
    cin >> carry>>n;
    cout << "������ÿ����Ʒ��������" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> weight[i];
    }
    sort(weight,weight+n);
    double temp=0.0;//�Ѿ�װ������Ʒ������
    int number=0;//�Ѿ�װ������Ʒ������
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
    cout << "��װ����Ʒ���������Ϊ��" << endl;
    cout << number << endl;
    return 0;
}
