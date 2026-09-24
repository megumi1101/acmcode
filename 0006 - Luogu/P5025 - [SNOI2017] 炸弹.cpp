#include<bits/stdc++.h>
#define ll long long
const int maxn=5e5+10,mod=1e9+7;
ll x[maxn],f[maxn],l[maxn],r[maxn],ans;
using namespace std;
int main()
{
	ll n;
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld%lld",&x[i],&f[i]);
		l[i]=r[i]=i;
	}
	for(ll i=2;i<=n;i++)
	{
		while(l[i]>1&&x[i]-x[l[i]-1]<=f[i])
		{
			f[i]=max(f[i],f[l[i]-1]+x[l[i]-1]-x[i]);
			l[i]=l[l[i]-1];
		}
	}
	for(ll i=n-1;i>=1;i--)
	{
		while(r[i]<n&&x[r[i]+1]-x[i]<=f[i])
		{
			l[i]=min(l[i],l[r[i]+1]);
			r[i]=r[r[i]+1];
		}
	}
	for(ll i=1;i<=n;i++)
	{
		ans+=i*(r[i]-l[i]+1);
		ans%=mod;
	}
	printf("%lld\n",ans);
	return 0;
}