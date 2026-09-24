#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=205;
int n,k,d[maxn],f[maxn][maxn],ans[maxn],sc[maxn],dis[maxn][maxn];
vector<int>ed[maxn<<1];
void fld()
{
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);		
}
void dfs(int u,int fa)
{
	for(int i=1;i<=n;i++)f[u][i]=d[dis[u][i]]+k;
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i];
		if(v==fa)continue;
		dfs(v,u);
		for(int j=1;j<=n;j++)f[u][j]+=min(f[v][ans[v]],f[v][j]-k);
	}
	ans[u]=1;
	for(int i=2;i<=n;i++)if(f[u][i]<f[u][ans[u]])ans[u]=i;
}
void cx(int u,int fa,int x)
{
	sc[u]=x;
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i];
		if(v==fa)continue;
		if(f[v][ans[v]]<f[v][x]-k)cx(v,u,ans[v]);
		else cx(v,u,x);
	}	
}
signed main()
{
	scanf("%lld%lld",&n,&k);	
	for(int i=1;i<n;i++)scanf("%lld",&d[i]);
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%lld%lld",&x,&y);
		dis[x][y]=1;dis[y][x]=1;
		ed[x].push_back(y);
		ed[y].push_back(x);
	}
	fld();
	dfs(1,0);
	printf("%lld\n",f[1][ans[1]]);
	cx(1,0,ans[1]);
	for(int i=1;i<=n;i++)printf("%lld ",sc[i]);
	return 0;
}
