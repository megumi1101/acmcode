#include<stdio.h>
using namespace std;
#define int long long
const int mod=998244353;
const int maxn=5e3+50;
int n,m,sum,ans,jc[maxn],nn[maxn],inv[maxn];
void init(int mx)
{
	inv[1]=jc[0]=jc[1]=nn[0]=nn[1]=1;
	for(int i=2;i<=mx;i++)
	{
		jc[i]=jc[i-1]*i%mod;
		inv[i]=inv[mod%i]*(mod-mod/i)%mod;
		nn[i]=nn[i-1]*inv[i]%mod;
	}
}
int cc(int x,int y)
{
	return jc[x+y]*nn[x]%mod*nn[y]%mod;
}
int wa(int i,int j)
{
	return (cc(i,j-1)*cc(i-1,n-j))%mod;
}
int wb(int i,int k)
{
	return (cc(m-i-1,k)*cc(m-i,n-k-1))%mod;
}
signed main()
{
	init(5010);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=m-1;i++)
	{	sum=0;
		for(int j=n-1;j>=1;j--)
		{
			sum+=wb(i,j);sum%=mod;
			ans+=wa(i,j)*sum;ans%=mod;
		}
	}
	int t=n;n=m;m=t;
	for(int i=1;i<=m-1;i++)
	{	sum=0;
		for(int j=n-1;j>=1;j--)
		{
			ans+=wa(i,j)*sum;ans%=mod;
			sum+=wb(i,j);sum%=mod;
		}
	}
	ans<<=1;ans%=mod;
	printf("%lld",ans);
	return 0;
}
