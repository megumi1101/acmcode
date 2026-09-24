#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int ans,c[2005][2005],a[1005],n,m;
void init()
{
	c[0][0]=1;
	for(int i=1;i<=2000;i++)
	{
		c[i][0]=1;
		for(int j=1;j<=i;j++)
		{
			c[i][j]=c[i-1][j]+c[i-1][j-1];
			c[i][j]%=mod;
		}	
	}
}
signed main()
{
	init();
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=m;i++)scanf("%lld",&a[i]);
	for(int i=0;i<=n-1;i++)
	{
		int res=1;
		for(int j=1;j<=m;j++)
		{
			res*=c[a[j]+n-i+-1][n-i-1];
			res%=mod;
		}
		if(i&1)res=mod-res;
		res*=c[n][i];res%=mod;
		ans+=res;
		ans%=mod;
	}
	printf("%lld",ans);
	return 0;
}