#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int size,ans,cnt;
int a[maxn],b[maxn];
int rt[maxn*40],ls[maxn*40],rs[maxn*40],sum[maxn*40];
int fa[maxn],dep[maxn],top[maxn],siz[maxn],son[maxn];
vector<int> ed[maxn<<1];
int insert(int pre,int l,int r,int x)
{
	int u=++cnt;
	ls[u]=ls[pre],rs[u]=rs[pre];
	sum[u]=sum[pre]+1;
	if(l<r)
	{
		int mid=(l+r)>>1;
		if(x<=mid)ls[u]=insert(ls[pre],l,mid,x);
		else rs[u]=insert(rs[pre],mid+1,r,x);
	}
	return u; 
}
void dfs1(int u,int fat,int deep)
{	
	fa[u]=fat;
	dep[u]=deep;
	siz[u]=1;
	rt[u]=insert(rt[fa[u]],1,size,a[u]);	
	int maxson=-1;
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i];
		if(v==fat)continue;
		dfs1(v,u,deep+1);
		siz[u]+=siz[v];
		if(siz[v]>maxson)
		{
			son[u]=v;
			maxson=siz[v];
		}
	}
}
void dfs2(int u,int topfa)
{
	top[u]=topfa;
	if(!son[u])return;
	dfs2(son[u],topfa);
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i];
		if(v==fa[u]||v==son[u])continue;
		dfs2(v,v);
	}
}
int lca(int x,int y)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	return x;
}
int cx(int u,int v,int y,int z,int l,int r,int k)
{
	if(l==r)return b[l];
	int x=sum[ls[u]]+sum[ls[v]]-sum[ls[y]]-sum[ls[z]];
	int mid=(l+r)>>1;
	if(x>=k)cx(ls[u],ls[v],ls[y],ls[z],l,mid,k);
	else cx(rs[u],rs[v],rs[y],rs[z],mid+1,r,k-x);
}
int cxxx(int u,int v,int k)
{
	int lca0=lca(u,v);
	return cx(rt[u],rt[v],rt[lca0],rt[fa[lca0]],1,size,k);
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(b+1,b+1+n);
	size=unique(b+1,b+1+n)-b;
	for(int i=1;i<=n;i++)
	{
		a[i]=lower_bound(b+1,b+1+size,a[i])-b;
	}
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		ed[x].push_back(y);
		ed[y].push_back(x);
	}
	dfs1(1,0,1);
	dfs2(1,1);
	for(int i=1;i<=m;i++)
	{
		int u,v,k;
		scanf("%d%d%d",&u,&v,&k);
		u^=ans;
		ans=cxxx(u,v,k);
		printf("%d\n",ans);	
	}
	return 0;
}