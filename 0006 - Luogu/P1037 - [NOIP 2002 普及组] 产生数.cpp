#include<bits/stdc++.h>
using namespace std;
char s[32];
int k,f[10][10],m[10];
void floyd()
{
	for(int k=0;k<=9;k++)
	{
		for(int i=0;i<=9;i++)
		{
			for(int j=0;j<=9;j++)
			{
				if(f[i][k]==1&&f[k][j]==1)
				{
					f[i][j]=1;
				}
			}
		}
	}
}
int main()
{
	for(int i=0;i<=9;i++)
	{
		for(int j=0;j<=9;j++)
		{
			f[i][j]=0;
		}
	}
	scanf("%s%d",s,&k);
	for(int i=1;i<=k;i++)
	{
		int m,n;
		scanf("%d%d",&m,&n);
		f[m][n]=1;
	}
	for(int i=0;i<=9;i++)
	{
		f[i][i]=1;
	}
	floyd();
	for(int i=0;i<=9;i++)
	{
		for(int j=0;j<=9;j++)
		{
			if(f[i][j]==1)
			{
				m[i]++;
			}	
		}
	}
	int num[120],len=2;
	for(int i=1;i<=111;i++)
	{
		num[i]=0;
	}
	num[1]=1;
	for(int i=0;i<strlen(s);i++)
	{
		for(int j=1;j<=100;j++)
		{
			num[j]*=m[s[i]-'0'];
		}
		for(int j=1;j<=100;j++)
		{
			if(num[j]>9)
			{
				num[j+1]+=num[j]/10;
				num[j]%=10;
			}
		}
		while(num[len])len++;
	}
	for(int i=len-1;i>=1;i--)
	{
		printf("%d",num[i]);
	}
	return 0;
}