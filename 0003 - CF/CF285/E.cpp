#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2010,mod=1e9+7;
int dp[maxn][maxn][2][2],f[maxn],ans;
int jc[maxn],jj[maxn],inv[maxn];
int n,k;
void init()
{
	jj[0]=jj[1]=inv[1]=jc[0]=jc[1]=1;
	for(int i=2;i<=n;i++)
	{
		jc[i]=jc[i-1]*i%mod;
		inv[i]=inv[mod%i]*(mod-mod/i)%mod;
		jj[i]=jj[i-1]*inv[i]%mod;
	}
}
signed main()
{
	scanf("%lld%lld",&n,&k);
	init();
	dp[1][0][0][0]=1;dp[1][1][0][1]=1;
	for(int i=2;i<n;i++)
	{
		dp[i][0][0][0]=1;
		for(int j=1;j<=i;j++)
		{
			dp[i][j][0][0]+=dp[i-1][j-1][0][0];
			dp[i][j][1][0]+=dp[i-1][j-1][0][1];
			dp[i][j][0][1]+=dp[i-1][j-1][0][0]+dp[i-1][j-1][1][0];
			dp[i][j][1][1]+=dp[i-1][j-1][0][1]+dp[i-1][j-1][1][1];
			dp[i][j][0][0]+=dp[i-1][j][0][0]+dp[i-1][j][1][0];
			dp[i][j][1][0]+=dp[i-1][j][0][1]+dp[i-1][j][1][1];
			dp[i][j][0][0]%=mod;dp[i][j][0][1]%=mod;dp[i][j][1][0]%=mod;dp[i][j][1][1]%=mod;
		}			
	}
	dp[n][0][0][0]=1;
	for(int j=1;j<=n;j++)
	{
		dp[n][j][0][0]+=dp[n-1][j-1][0][0];
		dp[n][j][1][0]+=dp[n-1][j-1][0][1];
		dp[n][j][0][0]+=dp[n-1][j][0][0]+dp[n-1][j][1][0];
		dp[n][j][1][0]+=dp[n-1][j][0][1]+dp[n-1][j][1][1];
		dp[n][j][0][0]%=mod;dp[n][j][0][1]%=mod;dp[n][j][1][0]%=mod;dp[n][j][1][1]%=mod;
	}
	for(int i=k;i<=n;i++)
	{
		f[i]=(dp[n][i][0][0]+dp[n][i][1][0])%mod*jc[n-i]%mod;
	}
	int op=-1;
	for(int i=k;i<=n;i++)
	{
		op=-op;
		ans+=(jc[i]*jj[k]%mod*jj[i-k]%mod)*f[i]%mod*op;
		ans+=mod;ans%=mod;
	}
	printf("%lld",ans);
	return 0;
}
//7 4
