#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,m,cnt,R;
int siz[maxn],fa[maxn],dep[maxn],son[maxn],top[maxn];
int x[maxn],y[maxn],z[maxn],ans[maxn],rot[maxn];
int lt[maxn<<6],rt[maxn<<6],d[maxn<<6],t[maxn<<6];
vector<int>ed[maxn<<1];
void dfs1(int u,int fat,int deep)
{
	dep[u]=deep;
	int maxson=-1;
	siz[u]=1;
	fa[u]=fat;
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i];
		if(v==fa[u])continue;
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
	top[u]=topfa;
	if(!son[u])
	{
		return;
	}
	dfs2(son[u],topfa);
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i];
		if(son[u]==v||v==fa[u])continue;
		dfs2(v,v);
	}
}
int lca(int x,int y)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])
		{
			swap(x,y);
		}
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])
	{
		swap(x,y);
	}
	return x;
}
void pushup(int a)
{
	if(d[lt[a]]>=d[rt[a]])
	{
		d[a]=d[lt[a]];
		t[a]=t[lt[a]];
	}
	else
	{
		d[a]=d[rt[a]];
		t[a]=t[rt[a]];
	}
}
int update(int a,int l,int r,int p,int k)
{
	if(!a)
	{
		a=++cnt;
	}
	if(l==r)
	{
		d[a]+=k;
		t[a]=l;
		return a;
	}
	int mid=(l+r)>>1;
	if(p<=mid)
	{
		lt[a]=update(lt[a],l,mid,p,k);
	}
	else
	{
		rt[a]=update(rt[a],mid+1,r,p,k);
	}
	pushup(a);
	return a;
}
int hb(int a,int b,int l,int r)
{
	if(!a)return b;
	if(!b)return a;
	if(l==r)
	{
		d[a]+=d[b];
		t[a]=l;
		return a;
	}
	int mid=(l+r)>>1;
	lt[a]=hb(lt[a],lt[b],l,mid);
	rt[a]=hb(rt[a],rt[b],mid+1,r);
	pushup(a);
	return a;
}
void dfs(int u)
{
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i];
		if(v==fa[u])continue;
		dfs(v);
		rot[u]=hb(rot[u],rot[v],1,R);
	}
	if(d[rot[u]])
	{
		ans[u]=t[rot[u]];
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	{
		int xx,yy;
		scanf("%d%d",&xx,&yy);
		ed[xx].push_back(yy);
		ed[yy].push_back(xx);
	}
	dfs1(1,0,1);
	dfs2(1,1);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x[i],&y[i],&z[i]);
		R=max(R,z[i]);
	}
	for(int i=1;i<=m;i++)
	{   
		int lca0=lca(x[i],y[i]);
		rot[x[i]]=update(rot[x[i]],1,R,z[i],1);
		rot[y[i]]=update(rot[y[i]],1,R,z[i],1);
		rot[lca0]=update(rot[lca0],1,R,z[i],-1);
		if(fa[lca0])rot[fa[lca0]]=update(rot[fa[lca0]],1,R,z[i],-1);
	}
	dfs(1);
	for(int i=1;i<=n;i++)
	{
		printf("%d\n",ans[i]);
	}
	return 0;
}