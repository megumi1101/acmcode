#include<bits/stdc++.h>
#define ll long long
const ll maxn=1e5+10;
const ll mod=1e9+7;
using namespace std;
ll sum[maxn],n,a[maxn],b[maxn],dp[maxn],ans;
vector<ll>v[maxn];
ll lb(ll x)
{
	return x&(-x);
}
void update(ll p,ll x)
{
	for(int i=p;i<=maxn;i+=lb(i))
	{
		sum[i]+=x;
		sum[i]%=mod;
	}
}
ll cx(ll p)
{
	ll res=0;
	for(ll i=p;i;i-=lb(i))
	{
		res+=sum[i];
		res%=mod;
	}
	return res;
}
int main()
{
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		b[i]=a[i];
	}
	sort(b+1,b+1+n);
	for(ll i=1;i<=n;i++)
	{
		a[i]=lower_bound(b+1,b+1+n,a[i])-b;
		dp[i]=1;
	}
	for(ll i=1;i<=n;i++)
	{
		if(v[a[i]].size())
		{
			update(a[i],-v[a[i]][v[a[i]].size()-1]);
		}
		dp[i]=dp[i]+cx(a[i]-1);
		dp[i]%=mod;
		update(a[i],dp[i]);
		v[a[i]].push_back(dp[i]);
	}
	for(ll i=1;i<=n;i++)
	{
		if(!v[i].size())
		{
			continue;
		}
		ans=ans+v[i][v[i].size()-1]-1;
		ans%=mod;
	}
	printf("%lld",ans);
	return 0;
}