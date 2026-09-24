#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6+10;
int siz[maxn],dep[maxn],f[maxn],n;
vector<int>ed[maxn<<1];
void dfs(int u,int fa)
{
	siz[u]=1;dep[u]=dep[fa]+1;
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i];
		if(v==fa)continue;
		dfs(v,u);
		siz[u]+=siz[v];
	}
}
void redfs(int u,int fa)
{
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i];
		if(v==fa)continue;
		f[v]=f[u]+n-2*siz[v];
		redfs(v,u);
	}
}
signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%lld%lld",&x,&y);
		ed[x].push_back(y);
		ed[y].push_back(x);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)
	{
		f[1]+=dep[i];
	}
	redfs(1,0);
	int mx=-1;
	int ans=1;
	for(int i=1;i<=n;i++)
	{
		if(mx<f[i])
		{
			mx=f[i];
			ans=i;
		}
	}
	printf("%lld",ans);
	return 0;
}