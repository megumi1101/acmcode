#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int mxn=105,mxm=2005;
int n,m,f[mxn][mxm*2],ans;
int sum[mxn],a[mxn][mxm],g[mxn][mxn];
signed main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%lld",&a[i][j]);
			sum[i]+=a[i][j];
			sum[i]%=mod;
		}
	}
	g[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(j==0)
			{
				g[i][j]=1;
				continue;
			}
			g[i][j]=g[i-1][j]+sum[i]*g[i-1][j-1];
			g[i][j]%=mod;
		}
	}
	for(int j=1;j<=n;j++)
	{
		ans+=g[n][j];
		ans%=mod;
	}
	for(int cal=1;cal<=m;cal++)
	{
		memset(f,0,sizeof(f));
		f[0][n]=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=n-i;j<=n+i;j++)
			{
				f[i][j]+=f[i-1][j]+a[i][cal]*f[i-1][j-1];
				f[i][j]%=mod;
				f[i][j]+=(sum[i]-a[i][cal])*f[i-1][j+1];
				f[i][j]%=mod;
			}
		}
		for(int j=1;j<=n;j++)
		{
			ans-=f[n][j+n];
			ans+=mod;
			ans%=mod;
		}
	}
	printf("%lld",ans);
}