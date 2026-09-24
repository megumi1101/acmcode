#include <cstdio>
#define int long long
const int mod=1e9+7,maxn=2e3+10;
int n,m,dp[maxn][maxn],sum,ans;
signed main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=m;i++)dp[1][i]=1;
	for(int i=2;i<=n;i++)
	{
		sum=0;
		dp[i][1]=1;
		for(int j=2;j<=m;j++)
		{
			(sum+=dp[i-1][j])%=mod;
			dp[i][j]=(dp[i][j-1]+sum)%mod;
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=2;j<=m;j++)
			(ans+=(dp[i][j]-dp[i-1][j]+mod)*dp[n-i+1][j]%mod*(m-j+1)%mod)%=mod;
	printf("%lld",ans);
	return 0;
}
