#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e4+10;
int n,q,g[maxn];
vector<int>ed[maxn<<1];
int p[maxn<<2][65],w[maxn];
int dep[maxn],siz[maxn],son[maxn],top[maxn];
int id[maxn],cnt,fa[maxn];
int tans[65],ans[65];
void ins(int *a,int x)
{
	for(int i=61;i>=0;i--)
	{
		if(x&(1LL<<i))
		{
			if(!a[i])
			{
				a[i]=x;
				break;	
			}
			else x^=a[i];
		}
	}
}
void dfs1(int u,int fat,int deep)
{
	dep[u]=deep;
	siz[u]=1;
	fa[u]=fat;
	int maxson=-1;
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i];
		if(v==fat)continue;
		dfs1(v,u,deep+1);
		siz[u]+=siz[v];
		if(siz[v]>maxson)
		{
			maxson=siz[v];
			son[u]=v;
		}
	}
}
void dfs2(int u,int topfa)
{
	id[u]=++cnt;
	top[u]=topfa;
	w[cnt]=g[u];
	if(!son[u])return;
	dfs2(son[u],topfa);
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i];
		if(v==fa[u]||son[u]==v)continue;
		dfs2(v,v);
	}
}
void merge(int *a,int *b)
{
	for(int i=61;i>=0;i--)
	{
		if(b[i])ins(a,b[i]);
	}
}
void pushup(int u)
{
	merge(p[u],p[u<<1]);
	merge(p[u],p[u<<1|1]);
}
void build(int u,int l,int r)
{
	if(l==r)
	{
		ins(p[u],w[l]);
		return;
	}
	int mid=(l+r)>>1;
	build(u<<1,l,mid);
	build(u<<1|1,mid+1,r);
	pushup(u);
}
void cx(int u,int l,int r,int cl,int cr)
{
	if(cl<=l&&r<=cr)
	{
		merge(tans,p[u]);
		return;
	}
	int mid=(l+r)>>1;
	if(cl<=mid)cx(u<<1,l,mid,cl,cr);
	if(cr>mid)cx(u<<1|1,mid+1,r,cl,cr);
}
int qmax()
{
	int res=0;
	for(int i=61;i>=0;i--)
	{
		res=max(res,res^ans[i]);
	}
	return res;
}
int lncx(int x,int y)
{
	memset(ans,0,sizeof(ans));
	while(top[x]!=top[y])
	{
		memset(tans,0,sizeof(tans));
		if(dep[top[x]]<dep[top[y]])
		{
			swap(x,y);
		}
		cx(1,1,n,id[top[x]],id[x]);
		merge(ans,tans);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	memset(tans,0,sizeof(tans));
	cx(1,1,n,id[x],id[y]);
	merge(ans,tans);
	return qmax();
}
signed main()
{
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++)scanf("%lld",&g[i]);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%lld%lld",&x,&y);
		ed[x].push_back(y);
		ed[y].push_back(x);
	}
	dfs1(1,0,1);
	dfs2(1,1);
	build(1,1,n);
	for(int i=1;i<=q;i++)
	{
		int x,y;
		scanf("%lld%lld",&x,&y);
		printf("%lld\n",lncx(x,y));
	}
	return 0;
}