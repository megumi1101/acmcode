#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n,m;
vector<int>ed[3][maxn];
int idom[maxn],sdom[maxn],mn[maxn],ans[maxn];
int dfn[maxn],fa[maxn],ff[maxn];
int co,id[maxn];
void dfs(int u)
{
	dfn[u]=++co;
	id[co]=u;
	for(int i=0;i<ed[0][u].size();i++)
	{
		int v=ed[0][u][i];
		if(!dfn[v])
		{
			fa[v]=u;
			dfs(v);
		}
	}
}
int find(int x)
{
	if(ff[x]==x)return x;
	int res=find(ff[x]);
	if(dfn[sdom[mn[ff[x]]]]<dfn[sdom[mn[x]]])mn[x]=mn[ff[x]];
	return ff[x]=res;
}
void zps()
{
	for(int i=1;i<=n;i++)
	{
		mn[i]=sdom[i]=ff[i]=i;
	}
	for(int i=co;i>=2;i--)
	{
		int u=id[i];
		for(int i=0;i<ed[1][u].size();i++)
		{
			int v=ed[1][u][i];
			if(!dfn[v])continue;
			find(v);
			if(dfn[sdom[mn[v]]]<dfn[sdom[u]]) sdom[u]=sdom[mn[v]];
		}
		ff[u]=fa[u];
		ed[2][sdom[u]].push_back(u);
		u=fa[u];
		for(int i=0;i<ed[2][u].size();i++)
		{
			int v=ed[2][u][i];
			find(v);
			idom[v]=u==sdom[mn[v]]?u:mn[v];
		}
		ed[2][u].clear();
	}
	for(int i=2;i<=co;i++)
	{
		int u=id[i];
		if(idom[u]!=sdom[u])
		{
			idom[u]=idom[idom[u]];
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	while(m--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		ed[0][x].push_back(y);
		ed[1][y].push_back(x);
	}
	dfs(1);
	zps();
	for(int i=co;i>=2;i--)
	{
		int u=id[i];
		ans[idom[u]]+=++ans[u];
	}
	ans[1]++;
	for(int i=1;i<=n;i++)
	{
		printf("%d ",ans[i]);
	}
}