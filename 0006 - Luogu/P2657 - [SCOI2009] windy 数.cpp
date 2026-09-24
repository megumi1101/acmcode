#include<bits/stdc++.h>
using namespace std;
int l,r,a[15],dp[15][15];
void init()
{
	for(int i=0;i<=9;i++)
	{
		dp[1][i]=1;
	}
	for(int i=2;i<=10;i++)
	{
		for(int j=0;j<=9;j++)
		{
			for(int k=0;k<=9;k++)
			{
				if(abs(j-k)>=2)
				{
					dp[i][j]+=dp[i-1][k];
				}
			}
		}
	}
}
int dd(int x)
{
	memset(a,0,sizeof(a));
	int cnt=0,ans=0;
	while(x)
	{
		a[++cnt]=x%10;
		x/=10;
	}
	for(int i=1;i<=cnt-1;i++)
	{
		for(int j=1;j<=9;j++)
		{
			ans+=dp[i][j];
		}
	}
	for(int i=1;i<a[cnt];i++)
	{
		ans+=dp[cnt][i];
	}
	for(int i=cnt-1;i>=1;i--)
	{
		for(int j=0;j<=a[i]-1;j++)
		{
			if(abs(j-a[i+1])>=2)
			{
				ans+=dp[i][j];
			}
		}
		if(abs(a[i+1]-a[i])<2)
		{
			break;
		}
	}
	return ans;
}
int main()
{
	init();
	int l,r;
	scanf("%d%d",&l,&r);
	printf("%d",dd(r+1)-dd(l));
	return 0;
}