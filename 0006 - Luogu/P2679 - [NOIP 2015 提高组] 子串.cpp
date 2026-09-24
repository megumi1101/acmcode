#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
long long dp[201][201],sum[201][201],n,m,kk;
char a[1002],b[202];
int main()
{
	scanf("%lld%lld%lld",&n,&m,&kk);
	scanf("%s%s",a+1,b+1);
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=1;j--)
		{
			for(int k=kk;k>=1;k--)
			{
				sum[j][k]=a[i]==b[j]?sum[j-1][k]+dp[j-1][k-1]:0;
				sum[j][k]%=mod;
				dp[j][k]+=sum[j][k];
				dp[j][k]%=mod;
			}
		}
	}
	printf("%lld",dp[m][kk]);
	return 0;
}