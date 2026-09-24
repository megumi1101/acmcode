#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e3+10;
const int mod=998244353;
int mx[maxn],a[maxn],n,sum[maxn];
int jc[maxn],jnc[maxn],inv[maxn],f[maxn];
void init()
{
	jc[0]=jnc[0]=inv[1]=jc[1]=jnc[1]=1;
	for(int i=2;i<=n;i++)
	{
		inv[i]=inv[mod%i]*(mod-mod/i)%mod;
		jc[i]=i*jc[i-1]%mod;
		jnc[i]=inv[i]*jnc[i-1]%mod;
	}
}
signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);mx[1]=0;
	if (a[n]<a[n-1]*2) {puts("0"); return 0;}
	for(int i=2,j=0;i<=n;i++)
	{
		while((a[j+1]*2)<=a[i]&&j<i)j++;
		mx[i]=j;
	}
	init();
	f[0]=1;
	sum[0]=jc[n-1]%mod;	
	for(int i=1;i<=n;i++)
	{
		f[i]=jnc[n-1-mx[i]]*sum[mx[i]]%mod;
		sum[i]+=sum[i-1]+jc[n-mx[i]-2]*f[i]%mod;sum[i]%=mod;
	}
	printf("%lld",f[n]);
	return 0;
}
