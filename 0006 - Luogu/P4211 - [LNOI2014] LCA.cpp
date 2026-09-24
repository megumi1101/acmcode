#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=5e5+10;
const ll mod=201314;
vector<ll> ed[maxn];
ll n,m;
ll dep[maxn],siz[maxn],son[maxn],cnt;
ll dep2[maxn],id[maxn],top[maxn],pos;
ll sum[maxn],sum2[maxn],fa[maxn],ans[maxn];
struct node
{
	ll u,v,bh;
}xx[maxn<<1];
bool cmp(node a,node b)
{
	return a.u<b.u;
}
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
void dfs1(ll u,ll deep)
{
	dep[u]=deep;
	siz[u]=1;
	ll maxson=-1;
	for(ll i=0;i<ed[u].size();i++)
	{
		ll v=ed[u][i];
		dfs1(v,deep+1);
		siz[u]+=siz[v];
		if(siz[v]>maxson)
		{
			son[u]=v;
			siz[v]=maxson;
		}
	}	
}
void dfs2(ll u,ll topfa)
{
	id[u]=++cnt;
	dep2[id[u]]=dep[u];
	top[u]=topfa;
	if(!son[u])
	{
		return;
	}
	dfs2(son[u],topfa);
	for(ll i=0;i<ed[u].size();i++)
	{
		ll v=ed[u][i];
		if(v==son[u])
		{
			continue;
		}
		dfs2(v,v);
	}
}
void lnupdate(int x)
{
	while(x)
	{
		update(id[top[x]],id[x],1);
		x=fa[top[x]];
	}
}
ll lncx(int x)
{
	ll ret=0;
	while(x)
	{
		ret+=cx(id[top[x]],id[x]);
		x=fa[top[x]];
	}
	return ret;
}
int main()
{
	scanf("%lld%lld",&n,&m);
	for(ll i=2;i<=n;i++)
	{
		ll x;
		scanf("%lld",&x);
		x++;
		ed[x].push_back(i);
		fa[i]=x;
	}
	for(int i=2;i<=n;i++)
	{
		add(i,dep2[i]-dep2[i-1]);
	}
	fa[1]=0;
	dfs1(1,0);
	dfs2(1,1);
	for(ll i=1;i<=m;i++)
	{
		ll l,r,z;
		scanf("%lld%lld%lld",&l,&r,&z);
		l++,r++,z++;
		xx[2*i-1]=(node){r,z,2*i-1};
		xx[2*i]=(node){l-1,z,2*i};
	}
	sort(xx+1,xx+2*m+1,cmp);
	while(xx[pos].u==0&&pos<=2*m)
	{
		ll tmp=lncx(xx[pos].v);
		if(xx[pos].bh&1)
		{
			ans[(xx[pos].bh+1)>>1]+=tmp;
		}
		else
		{
			ans[(xx[pos].bh+1)>>1]-=tmp;
		}
		pos++;
	}
	for(ll i=1;i<=n;i++)
	{
		lnupdate(i);
		while(xx[pos].u==i&&pos<=2*m)
		{
			ll tmp=lncx(xx[pos].v);
			if(xx[pos].bh&1)
			{
				ans[(xx[pos].bh+1)>>1]+=tmp;
			}
			else
			{
				ans[(xx[pos].bh+1)>>1]-=tmp;
			}
			pos++;
		}
	}
	for(ll i=1;i<=m;i++)
	{
		printf("%lld\n",(ans[i]%mod+mod)%mod);
	}
	return 0;
}