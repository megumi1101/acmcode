#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int w[maxn];
bool vis[maxn];
vector<int>ed[maxn<<1];
int f[maxn][22],g[maxn][22];
int n,d,m;
void dfs(int u,int fa)
{
	if(vis[u]) f[u][0]=g[u][0]=w[u];
	else f[u][0]=g[u][0]=0;
	for(int i=1;i<=d;i++)f[u][i]=w[u];
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i];
		if(v==fa)continue;
		dfs(v,u);
		for(int j=d;j>=0;j--)
		{
			f[u][j]=min(f[u][j]+g[v][j],g[u][j+1]+f[v][j+1]);
			f[u][j]=min(f[u][j],f[u][j+1]);
		}
		g[u][0]=f[u][0];
		for(int j=1;j<=d+1;j++)g[u][j]+=g[v][j-1];
		for(int j=1;j<=d+1;j++)g[u][j]=min(g[u][j],g[u][j-1]);
	}
}
int main()
{
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&w[i]);
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int x;
		scanf("%d",&x);
		vis[x]=1;
	}
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		ed[x].push_back(y);
		ed[y].push_back(x);
	}
	memset(f,0x3f,sizeof(f));
	dfs(1,0);
	printf("%d\n",g[1][0]);
}