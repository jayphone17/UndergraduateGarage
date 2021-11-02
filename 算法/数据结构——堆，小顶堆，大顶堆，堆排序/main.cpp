#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int h[1111]; //�����洢�����������顣
int n;//�ѵĴ�С

void swap(int x,int y)
{
    int temp;
    temp=h[x];
    h[x]=h[y];
    h[y]=temp;
    return;
}

void shiftdown(int i)
{
    int tmp; //��ʱ�����������洢���½����
    int flag=0;//������Ǵ˶����費��Ҫ���µ�����0����Ҫ������1�ǲ���Ҫ
    while(i*2<=n && flag==0)//�������ڶ���ʱ�����ٴ�������ӣ�ִ��ѭ��
    {
        //�����ж�������ӵı�������tmp��¼ֵ��С�Ľ����
        if(h[i]<h[i*2])
        {
            tmp=i*2; //��tmp��¼�ϴ�Ľ����
        }
        else
        {
            tmp=i;
        }
        if(i*2+1<=n) //������Ҷ��ӣ��ٶ��Ҷ��ӽ�������
        {
            if(h[i*2+1]<h[tmp])
            {
                tmp=i*2+1;
            }
        }
        if(tmp!=i) //���������С�Ľ�㲻���Լ���˵���ӽ���л���ֵ��С�Ľ��
        {
            swap(tmp,i);
            i=tmp; //���¸ղŽ���֮��Ķ��ӽ��ı�ţ����ڽ��������µ�����
        }
    }
    return;
}

void shiftup(int i)
{
    int flag=0;
    if(i==1)
        return;//��ʱ�ǶѶ�������Ҫ�ϵ�
    while(i!=1 && flag==0)
    {
        if(h[i]<h[i/2])
        {
            swap(i,i*2);
        }
        else
        {
            flag=1;
        }
        i=i/2;//���±��iΪ�������ı�š�
    }
    return;
}

void create()
{
    for(int i=n/2; i>=1; i--)
    {
        shiftdown(i);
    }
    return ;
}

void HeapSort() //����˼ά�Ķ�����
{
    while(n>1)
    {
        swap(1,n); //����С��Ԫ�طŵ��Ѷ�������Ԫ�طŵ�h[n]����ʱh[n]��������Ԫ�ء�
        n--; //���ѵĴ�С��С1
        shiftdown(1); //���µ���
    }
}

int main()
{
    int num;
    cout << "������Ԫ�صĸ�����"<< endl;
    cin >> num;
    cout << "�����������Ԫ�أ�" << endl;
    for (int i=1;i<=num;i++)
    {
        cin >> h[i];
    }
    n=num;
    create();//����
    HeapSort();//����
    for (int i=1;i<=num;i++)
    {
        cout << h[i];
    }
    cout << endl;
    return 0;
}
