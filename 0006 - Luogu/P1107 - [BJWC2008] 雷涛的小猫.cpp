#include<cstdio>
#include<iostream>
using namespace std;
int nn,hh,de,a[2050][5050],dp[4040][4040],pre[5020];
int main()
{
	scanf("%d%d%d",&nn,&hh,&de);
	for(int i=1;i<=nn;i++)
	{
		int tt,zz;
		scanf("%d",&tt);
		while(tt--)
		{
			scanf("%d",&zz);
			a[i][zz]++;
		}
	}
	int maxn=0;
	for(int j=hh;j>=1;j--)
	{
		for(int i=1;i<=nn;i++)
		{
			dp[i][j]=dp[i][j+1]+a[i][j];
			dp[i][j]=max(dp[i][j],pre[j+de]+a[i][j]);
			pre[j]=max(dp[i][j],pre[j]);
			maxn=max(maxn,dp[i][j]);
		}
	}
	printf("%d",maxn);
	return 0;
}