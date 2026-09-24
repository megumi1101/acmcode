#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int n,m,t,ans=1;
int a[310][310];
int fapow(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1)
		{
			res=res*a%mod;
		}
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
void work()
{
	int inv,tmp;
	for(int i=2;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(!a[i][i]&&a[j][i])
			{
				swap(a[i],a[j]);
				ans=-ans;break;
			}
		}
		inv=fapow(a[i][i],mod-2);
		for(int j=i+1;j<=n;j++)
		{
			tmp=a[j][i]*inv%mod;
			for(int k=i;k<=n;k++)
			{
				a[j][k]-=(a[i][k]*tmp)%mod;
				a[j][k]+=mod;
				a[j][k]%=mod;
			}
		}
	}
}
signed main()
{
	scanf("%lld%lld%lld",&n,&m,&t);
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		if(!t)
		{
			a[x][x]+=z;a[x][x]%=mod;
			a[y][y]+=z;a[y][y]%=mod;
			a[x][y]-=z;a[x][y]%=mod;
			a[y][x]-=z;a[y][x]%=mod;
		}
		else
		{
			a[y][y]+=z;a[y][y]%=mod;
			a[x][y]-=z;a[x][y]%=mod;
		}
	}
	work();
	for(int i=2;i<=n;i++)
	{
		ans=ans*a[i][i]%mod;
	}
	ans%=mod;
	ans=(ans+mod)%mod;
	printf("%lld",ans);
	return 0;
}