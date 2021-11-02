#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
using namespace std;

const int M=1111111;
int x; //要查找的数字
int n; //n个数字
int i; //循环
int s[M];//用来存储数字串

int BinarySearch(int n,int s[],int x)
{
    int low=0; //确定下界
    int high=n-1; //确定上界
    while(low<=high)
    {
        int middle=(low+high)/2; //查找的数组中的中间值
        if(x==s[middle])
        {
            return middle; //查找成功，中间值就是要查找的元素
        }
        else if(x<s[middle])
        {
            high=middle-1;//没有查找成功，此时知道要查找的元素在中间值的左边，所以更新上界high的位置
        }
        else
        {
            low=middle+1; //没有查找成功，此时知道要查找的元素在中间值的右边，所以更新下界low的位置
        }
    }
    return -1;
}

int main()
{
    cout<<"请输入元素的个数 : " << endl;
    while(cin>>n)
    {
        cout << "请输入数列中的元素 ：" << endl;
        for (i=0 ; i<n ; i++)
        {
            cin>>s[i] ;
        }
        sort(s,s+n); //对存好的元素进行从小到大的排序
        cout << "排序好的数组是：" << endl;
        for (i=0;i<n;i++)
        {
            cout << s[i] << " ";
        }
        cout<< "请输入要查找的元素：" << endl;
        cin >> x;
        int number=BinarySearch(n,s,x);
        if(number==-1)
        {
            cout << "该数组中没有要查找的元素" << endl;
        }
        else
        {
            cout << "要查找的数字在" << number+1 << "位" << endl;
        }
    }
    return 0;
}
