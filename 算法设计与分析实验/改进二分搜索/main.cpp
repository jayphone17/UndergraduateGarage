#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
using namespace std;

const int M=1111;
int x; //要查找的数字
int n; //n个数字
int number_array[M];//用来存储数字串

int linjiefeng_BinarySearch(int n,int number_array[],int x) //n是数组大小，number_array是存储数字的数组，x是要查找的数字
{
    int low=0; //确定下界
    int high=n-1; //确定上界
    int i=0;
    int j=0;
    while(low<=high)
    {
        int middle=(low+high)/2; //查找的数组中的中间值
        if(x==number_array[middle])
        {
            //查找成功，中间值就是要查找的元素
            i=middle;
            j=middle;
            cout << "查找成功，i,j的值是："<< i <<" "<< j << endl;
            return middle;
        }
        else if(x<number_array[middle])
        {
            high=middle-1;//没有查找成功，此时知道要查找的元素在中间值的左边，所以更新上界high的位置
        }
        else
        {
            low=middle+1; //没有查找成功，此时知道要查找的元素在中间值的右边，所以更新下界low的位置
        }
    }
    i=low;
    j=high;
    cout << "没有查找成功，i，j的值是："<< i << " " << j << endl;
    return -1;
}

int main()
{
    cout<<"请输入元素的个数 : " << endl;
    while(cin>>n)
    {
        cout << "请输入数列中的元素 ：" << endl;
        for (int i=0 ; i<n ; i++)
        {
            cin>>number_array[i] ;
        }
        cout<< "请输入要查找的元素：" << endl;
        cin >> x;
        int number=linjiefeng_BinarySearch(n,number_array,x);
   }
    return 0;
}
