#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
vector<int>ed[maxn<<1];
int n,m,g[maxn][2],mx1[maxn],mx2[maxn],fa[maxn],ans;
bool vis[maxn];
void dfs(int u,int fat)
{
	fa[u]=fat;
	if(ed[u].size()==1&&vis[fa[u]])
	{
		g[u][0]=0;
		g[u][1]=0;
		return;
	}
	vis[u]=1;
	g[u][1]=ed[u].size()-1;
	mx1[u]=-1;mx2[u]=-1;
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i];
		if(v==fat)continue;
		dfs(v,u);
		if(g[v][1]>=mx1[u])
		{
			mx2[u]=max(mx2[u],mx1[u]);
			mx1[u]=max(mx1[u],g[v][1]);
		}
		else mx2[u]=max(mx2[u],g[v][1]);
	}
	int k=ed[u].size();
	g[u][0]=mx1[u]+mx2[u]+k-1;
	g[u][1]+=mx1[u];
	g[u][0]=max(g[u][0],g[u][1]);	
	ans=max(ans,g[u][0]+1);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		ed[x].push_back(y);
		ed[y].push_back(x);
	}
	dfs(1,0);
	printf("%d",ans+1);
	return 0;
}