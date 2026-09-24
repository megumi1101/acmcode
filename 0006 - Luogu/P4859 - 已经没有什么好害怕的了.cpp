#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+9,maxn=2e3+10;
int n,ans,jc[maxn],c[maxn][maxn],a[maxn],b[maxn];
int dp[maxn][maxn],num[maxn],k;
void init()
{
	for(int i=1;i<=n;i++)
	{
		c[i][0]=c[i][i]=1;
		for(int j=1;j<i;j++)
		{
			c[i][j]=c[i-1][j]+c[i-1][j-1];
			c[i][j]%=mod;
		}
	}
	jc[1]=1;
	for(int i=2;i<=n;i++)
	{
		jc[i]=i*jc[i-1]%mod;
	}
}
signed main()
{
	scanf("%d%d",&n,&k);
	init();
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	k=(n+k)/2;
	sort(a+1,a+1+n);sort(b+1,b+1+n);int pos=0;
	for(int i=1;i<=n;i++)
	{
		while(pos<n&&b[pos+1]<a[i])pos++;
		num[i]=pos;
	}
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=i;j++)
		{
			if(j==0)dp[i][j]=dp[i-1][j];
			else
			{
				dp[i][j]=dp[i-1][j]+dp[i-1][j-1]*(num[i]-j+1);
				dp[i][j]%=mod;
			}
		}
	for(int i=0;i<=n;i++)dp[n][i]=dp[n][i]*jc[n-i]%mod;
	for(int i=k;i<=n;i++)
	{
		int sum=dp[n][i]*c[i][k]%mod;
		if((i-k)&1)ans+=mod-sum;
		else ans+=sum;
		ans%=mod;
	}
	printf("%lld",(ans+mod)%mod);
	return 0;
}