#include <stdio.h>
int num1[1000],num2[1000];
main()
{
	int i=0,count1=0,count2=0,len=0;
	char a[1000],b[1000];
	scanf("%s%s",a,b);
	count1=strlen(a);
	count2=strlen(b);

	for(i=count1-1;i>=0;i--)
		num1[++num1[0]]=a[i]-'0';
	for(i=count2-1;i>=0;i--)
		num2[++num2[0]]=b[i]-'0';
}