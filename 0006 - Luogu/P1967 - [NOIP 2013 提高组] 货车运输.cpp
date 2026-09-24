#include<bits/stdc++.h>
using namespace std;
int n,m,xd;
const int maxn=1e5+10;
int faa[maxn],w[maxn],top[maxn];
int fa[maxn],dep[maxn],siz[maxn],son[maxn];
struct node
{
	int x,y,z;
	friend bool operator<(node a,node b)
	{
		return a.z>b.z;
	}
}kk[maxn];
int find(int x)
{
	if(faa[x]==x)return x;
	faa[x]=find(faa[x]);
	return faa[x];
}
vector<int> ed[maxn<<2];
void kls()
{
	xd=n;
	for(int i=1;i<=(n<<1);i++)
	{
		faa[i]=i;
	}
	sort(kk+1,kk+1+m);
	for(int i=1;i<=m;i++)
	{
		int x=find(kk[i].x);
		int y=find(kk[i].y);
		if(x==y)continue;
		xd++;
		w[xd]=kk[i].z;
		faa[x]=xd;
		faa[y]=xd;
		ed[xd].push_back(x);
		ed[xd].push_back(y);
	}
}
void dfs1(int u,int fat,int deep)
{
	dep[u]=deep;
	fa[u]=fat;
	siz[u]=1;
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
	return;
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
		if(dep[top[x]]<dep[top[y]])
		{
			swap(x,y);
		}
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	return x;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&kk[i].x,&kk[i].y,&kk[i].z);
	}
	kls();
	for(int i=1;i<=xd;i++)
	{
		if(faa[i]!=i)continue;
		if(dep[faa[i]])continue;
		dfs1(faa[i],0,1);
		dfs2(faa[i],faa[i]);
	}
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(find(x)!=find(y)) printf("-1\n");
		else printf("%d\n",w[lca(x,y)]);
	}
	return 0;
}