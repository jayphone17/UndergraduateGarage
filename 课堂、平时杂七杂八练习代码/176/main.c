#include<stdio.h>
#include<string.h>
int main()
{
	int n;
	char s[1005];
	int num[1005];
	while(~scanf("%d",&n))
	{
		while(n--)
		{
			scanf("%s",s);
			int len =strlen(s);
			memset(num,0,sizeof(num));
			for(int i = 0; i < len; i++)
			{
				num[s[i]-'a']++;
			}
			char ans;
			int max = 0;
			for(int i = 0; i < 30; i++)
			{

				if(num[i] > max)
				{
					max = num[i];
					ans = i+'a';
				}
			}
			printf("%c\n",ans);
		}
	}
}
