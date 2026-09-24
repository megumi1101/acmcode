#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=1e6+10,inf=1e15;
ll n,ans,f[maxn],g[maxn],deg[maxn];
queue<ll> q;
ll to[maxn],w[maxn];
ll dfs(ll x)
{
	ll m1=f[x],m2=f[x];
	ll end=x;
	ll t1=g[x],t2=-inf,pre=w[x];
	x=to[x];	
	while(x!=end)
	{
		deg[x]=0;
		t1=max(t1,f[x]+pre+m1);
		t2=max(t2,f[x]-pre+m2);
		t1=max(t1,g[x]);
		m1=max(m1,f[x]-pre);
		m2=max(m2,f[x]+pre);
		pre+=w[x];
		x=to[x];
	}
	return max(t1,t2+pre);
}
int main()
{
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld%lld",&to[i],&w[i]);
		deg[to[i]]++;		
	}
	for(ll i=1;i<=n;i++)if(!deg[i])q.push(i);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		ll v=to[x];
		g[v]=max(g[v],f[x]+w[x]+f[v]);
		g[v]=max(g[v],g[x]);
		f[v]=max(f[v],f[x]+w[x]);
		deg[v]--;
		if(!deg[v])q.push(v);
	}
	for(ll i=1;i<=n;i++)
	{
		if(deg[i])
		{
			ans+=dfs(i);
		}
	}
	printf("%lld",ans);
	return 0;
}