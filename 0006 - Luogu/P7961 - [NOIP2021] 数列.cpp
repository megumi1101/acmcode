#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int ans,v[105],f[105][35][35][16],pv[105][35],c[35][35],n,m,K;
void init(int n)
{
	for(int i=0;i<=n;i++)c[i][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
}
int pp(int x)
{
	int res=0;
	while(x)res+=x&1,x>>=1;
	return res;
}
signed main()
{
	init(30);
	scanf("%lld%lld%lld",&n,&m,&K);
	for(int i=0;i<=m;i++)
	{
		scanf("%lld",&v[i]);
		pv[i][0]=1;
		for(int j=1;j<=n;j++)pv[i][j]=pv[i][j-1]*v[i]%mod;
	}
	f[0][0][0][0]=1;
	
	for(int i=0;i<=m;i++)
	for(int j=0;j<=n;j++)
	for(int k=0;k<=K;k++)
	for(int p=0;p<=n>>1;p++)
	for(int t=0;t<=n-j;t++)
	(f[i+1][j+t][k+((t+p)&1)][(t+p)>>1]+=f[i][j][k][p]*pv[i][t]%mod*c[n-j][t]%mod)%=mod;
	for(int k=0;k<=K;k++)
		for(int p=0;p<=n>>1;p++)
			if(k+pp(p)<=K)(ans+=f[m+1][n][k][p])%=mod;
	printf("%lld",ans);
	return 0;
}
