#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
using namespace std;

int find_fake_coin(int coin_array[],int low,int high)
{
	int i=0;//��Ϊ�����ļ�����
	int result=0;//re��Ϊ����ֵ
	int sum1=0;
	int sum2=0;
	int sum3=0; //���������м����
	//���������ۼӵı���
	if(low+1==high)//���������������Ԫ�ص�ʱ��
	{
		if(coin_array[low]<coin_array[high])
		{
			result=low;
			return result;
		}
		else
		{
			result=high;
			return result;
		}
	}
	if((high-low+1)%2==0)//������Ϊż����ʱ��
	{
		for(i=low;i<=low+(high-low+1)/2-1;i++)//��ǰ������
		{
			sum1+=coin_array[i];
		}
		for(i=low+(high-low+1)/2;i<=high;i++)//�Ժ������
		{
			sum2+=coin_array[i];
		}
		if(sum1<sum2)//�ٱ���ǰ���
		{
			result=find_fake_coin(coin_array,low,low+(high-low+1)/2-1);
			return result;
		}
		else if(sum2<sum1)//�ٱ��ں���
		{
			result=find_fake_coin(coin_array,low+(high-low+1)/2,high);
			return result;
		}
	}
	else//������Ϊ������ʱ��
	{
		for(i=low;i<=low+(high-low)/2-1;i++)//��ǰ������
		{
			sum1+=coin_array[i];
		}
		for(i=low+(high-low)/2+1;i<=high;i++)//�Ժ������
		{
			sum2+=coin_array[i];
		}
		sum3=coin_array[low+(high-low)/2];//sum3���ڴ���м�����
		if(sum1<sum2)//�ٱ���ǰ���
		{
			result=find_fake_coin(coin_array,low,low+(high-low)/2-1);
			return result;
		}
		else if(sum2>sum1) //�ٱ��ں���
		{
			result=find_fake_coin(coin_array,low+(high-low)/2,high);
			return result;
		}
		else if(sum1+sum3==sum2+sum3)//�м���Ǹ����Ǽٱң�
		{
			result=(high-low)/2+1;
			return result;
		}
	}
}
int main()
{
	int coin_array[111];
	int n,i,result;
	cout<<"������Ӳ�ҵĸ�����"<< endl;
	cin>>n;
	cout<<"��ֱ��������"<<n<<"��Ӳ�ҵ�������"<<endl;
	for(i=1;i<=n;i++)
	{
		cin>>coin_array[i];
	}
	result=find_fake_coin(coin_array,1,n);
	cout<<"�ٱ��ǵ�"<<result<<"��Ӳ��"<<endl;
	return 0;
}