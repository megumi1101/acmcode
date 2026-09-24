#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
const int inf=1e8;
int f[maxn][2],fa[maxn],len[maxn];
#define c(v) (f[v][0]+len[v]-max(f[v][0],f[v][1]+len[v]))
int n;
struct node
{
	int to,val;
};
vector<node>ed[maxn<<1];
vector<int>dp[maxn][2],son[maxn],mx[maxn];
void dfs(int u,int fat)
{
	f[u][0]=0;
	f[u][1]=-inf;
	int mx1=-inf,mx2=-inf;
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i].to;
		if(v==fat)continue;
		int w=ed[u][i].val;
		len[v]=w;
		fa[v]=u;
		son[u].push_back(v);
		dfs(v,u);
		f[u][0]+=max(f[v][0],f[v][1]+len[v]);
		if(c(v)>mx1)mx2=mx1,mx1=c(v);
		else if(c(v)>mx2) mx2=c(v);
	}
	f[u][1]=f[u][0]+mx1;
	//printf("f[%d][1]=%d f[%d][0]=%d\n",u,f[u][1],u,f[u][0]);
	//printf("%d %d %d\n",u,mx1,mx2);
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i].to;
		if(v==fat)continue;
		dp[u][0].push_back(f[u][0]-max(f[v][0],f[v][1]+len[v]));
		if(c(v)==mx1)
		{
			dp[u][1].push_back(dp[u][0].back()+mx2);
			mx[u].push_back(mx2);
		}
		else
		{
			dp[u][1].push_back(dp[u][0].back()+mx1);
			mx[u].push_back(mx1);
		}
	}
}
int ans=f[1][0];
void dfs2(int u)
{
	for(int i=0;i<son[u].size();i++)
	{
		f[u][0]=dp[u][0][i];
		f[u][1]=dp[u][1][i];
		if(fa[u])
		{
			f[u][0]+=max(f[fa[u]][0],f[fa[u]][1]+len[u]);
			f[u][1]=f[u][0]+max(mx[u][i],f[fa[u]][0]+len[u]-max(f[fa[u]][0],f[fa[u]][1]+len[u]));
		}
		ans=max(ans,f[son[u][i]][0]+max(f[u][0],f[u][1]+len[son[u][i]]));
		dfs2(son[u][i]);	
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		ed[x].push_back((node){y,z});
		ed[y].push_back((node){x,z});
	}
	dfs(1,0);
	dfs2(1);
	printf("%d",ans);
	return 0;
}