#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
using namespace std;

int find_fake_coin(int coin_array[],int low,int high)
{
	int i=0;//作为遍历的计数器
	int result=0;//re作为返回值
	int sum1=0;
	int sum2=0;
	int sum3=0; //用来访问中间变量
	//三个用来累加的变量
	if(low+1==high)//当遍历到最后两个元素的时候
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
	if((high-low+1)%2==0)//当长度为偶数的时候
	{
		for(i=low;i<=low+(high-low+1)/2-1;i++)//对前半段求和
		{
			sum1+=coin_array[i];
		}
		for(i=low+(high-low+1)/2;i<=high;i++)//对后半段求和
		{
			sum2+=coin_array[i];
		}
		if(sum1<sum2)//假币在前半段
		{
			result=find_fake_coin(coin_array,low,low+(high-low+1)/2-1);
			return result;
		}
		else if(sum2<sum1)//假币在后半段
		{
			result=find_fake_coin(coin_array,low+(high-low+1)/2,high);
			return result;
		}
	}
	else//当长度为奇数的时候
	{
		for(i=low;i<=low+(high-low)/2-1;i++)//对前半段求和
		{
			sum1+=coin_array[i];
		}
		for(i=low+(high-low)/2+1;i<=high;i++)//对后半段求和
		{
			sum2+=coin_array[i];
		}
		sum3=coin_array[low+(high-low)/2];//sum3用于存放中间数据
		if(sum1<sum2)//假币在前半段
		{
			result=find_fake_coin(coin_array,low,low+(high-low)/2-1);
			return result;
		}
		else if(sum2>sum1) //假币在后半段
		{
			result=find_fake_coin(coin_array,low+(high-low)/2,high);
			return result;
		}
		else if(sum1+sum3==sum2+sum3)//中间的那个就是假币！
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
	cout<<"请输入硬币的个数："<< endl;
	cin>>n;
	cout<<"请分别输入这个"<<n<<"个硬币的重量："<<endl;
	for(i=1;i<=n;i++)
	{
		cin>>coin_array[i];
	}
	result=find_fake_coin(coin_array,1,n);
	cout<<"假币是第"<<result<<"个硬币"<<endl;
	return 0;
}