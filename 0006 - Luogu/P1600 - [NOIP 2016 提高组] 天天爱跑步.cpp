#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,m,cnt;
int siz[maxn],fa[maxn],dep[maxn],son[maxn],top[maxn],w[maxn];
int lt[maxn<<6],rt[maxn<<6],val[maxn<<6],ans[maxn],rot[maxn];
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
int update(int a,int l,int r,int p,int k)
{
	if(!a)a=++cnt;
	if(l==r)
	{
		val[a]+=k;
		return a;
	}
	int mid=(l+r)>>1;
	if(p<=mid)lt[a]=update(lt[a],l,mid,p,k);
	else rt[a]=update(rt[a],mid+1,r,p,k);
	return a;
}
int cx(int a,int l,int r,int p)
{
	if(!a)return 0;
	if(l==r)return val[a];
	int mid=(l+r)>>1;
	if(p<=mid)return cx(lt[a],l,mid,p);
	else return cx(rt[a],mid+1,r,p);
}
int hb(int a,int b,int l,int r)
{
	if(!a||!b)return a+b;
	if(l==r)
	{
		val[a]+=val[b];
		return a;
	}
	else
	{
		int mid=(l+r)>>1;
		lt[a]=hb(lt[a],lt[b],l,mid);
		rt[a]=hb(rt[a],rt[b],mid+1,r);
	}
	return a;
}
void dfs(int u)
{
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i];
		if(v==fa[u])continue;
		dfs(v);
		rot[u]=hb(rot[u],rot[v],1,n<<1);
	}
	if(w[u]&&n+dep[u]+w[u]<=2*n)
		ans[u]+=cx(rot[u],1,n<<1,n+dep[u]+w[u]);
	ans[u]+=cx(rot[u],1,n<<1,n+dep[u]-w[u]);
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
	for(int i=1;i<=n;i++)scanf("%d",&w[i]);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int lca0=lca(x,y);
		rot[x]=update(rot[x],1,n<<1,n+dep[x],1);
		rot[y]=update(rot[y],1,n<<1,n+2*dep[lca0]-dep[x],1);
		rot[lca0]=update(rot[lca0],1,n<<1,n+dep[x],-1);
		if(fa[lca0])
		{
			rot[fa[lca0]]=update(rot[fa[lca0]],1,n<<1,n+2*dep[lca0]-dep[x],-1);
		}
	}
	dfs(1);
	for(int i=1;i<=n;i++)
	{
		printf("%d ",ans[i]);
	}
	return 0;
}