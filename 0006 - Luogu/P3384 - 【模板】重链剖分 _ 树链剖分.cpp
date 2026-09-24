#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=1e5+10;
ll n,m,r,mod;
ll a[maxn],fa[maxn],dep[maxn],siz[maxn],son[maxn];
ll top[maxn],b[maxn],sum[maxn],sum2[maxn],id[maxn],cnt;
vector<ll>ed[maxn<<1];
ll lb(ll x)
{
	return x&-x;
}
void add(ll p,ll x)
{
	for(ll i=p;i<=n;i+=lb(i))
	{
		sum[i]+=x;
		sum2[i]+=p*x;
	}
}
void update(ll l,ll r,ll x)
{
	add(l,x);add(r+1,-x);
}
ll cx(ll l,ll r)
{
	ll ress=0;
	for(ll i=r;i;i-=lb(i))
	{
		ress+=(r+1)*sum[i]-sum2[i];
	}
	for(ll i=l-1;i;i-=lb(i))
	{
		ress-=l*sum[i]-sum2[i];
	}
	return ress;
}
void update1(ll x,ll y,ll k)
{
	k%=mod;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])
		{
			swap(x,y);
		}
		update(id[top[x]],id[x],k);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])
	{
		swap(x,y);
	}
	update(id[x],id[y],k);
}
ll cx1(ll x,ll y)
{
	ll tmp=0;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])
		{
			swap(x,y);
		}
		tmp+=cx(id[top[x]],id[x]);
		tmp%=mod;
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])
	{
		swap(x,y);
	}
	tmp+=cx(id[x],id[y]);
	tmp%=mod;
	return tmp;
}
void dfs1(ll u,ll fat,ll deep)
{
	dep[u]=deep;
	fa[u]=fat;
	ll maxson=-1;
	siz[u]=1;
	for(ll i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i];
		if(v==fat)
		{
			continue;
		}
		dfs1(v,u,deep+1);
		siz[u]+=siz[v];
		if(siz[v]>maxson)
		{
			son[u]=v;
			maxson=siz[v];
		}
	}
}
void dfs2(ll u,ll topfa)
{
	id[u]=++cnt;
	b[cnt]=a[u];
	top[u]=topfa;
	if(!son[u])
	{
		return;
	}
	dfs2(son[u],topfa);
	for(ll i=0;i<ed[u].size();i++)
	{
		ll v=ed[u][i];
		if(v==fa[u]||v==son[u])
		{
			continue;
		}
		dfs2(v,v);
	}
}
int main()
{
	scanf("%lld%lld%lld%lld",&n,&m,&r,&mod);
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(ll i=1;i<=n-1;i++)
	{
		ll x,y;
		scanf("%lld%lld",&x,&y);
		ed[x].push_back(y);
		ed[y].push_back(x);
	}
	dfs1(r,0,0);
	dfs2(r,r);
	for(ll i=1;i<=n;i++)
	{
		add(i,b[i]-b[i-1]);
	}
	while(m--)
	{
		ll opt,l,r,z;
		scanf("%lld%lld",&opt,&l);
		if(opt==1)
		{
			scanf("%lld%lld",&r,&z);
			update1(l,r,z);
		}
		else if(opt==2)
		{
			scanf("%lld",&r);
			printf("%lld\n",(cx1(l,r))%mod);
		}
		else if(opt==3)
		{
			scanf("%lld",&z);
			update(id[l],id[l]+siz[l]-1,z);
		}
		else
		{
			printf("%lld\n",(cx(id[l],id[l]+siz[l]-1))%mod);
		}
	}
	return 0;
}
