#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,s;
int dis[maxn],fa[maxn];
bool vis[maxn];
struct node
{
	int to,val;
};
vector<node> ed[maxn];
void dfs(int u)
{
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i].to;
		if(vis[v]||fa[u]==v)continue;
		fa[v]=u;
		dis[v]=dis[u]+ed[u][i].val;
		dfs(v);
	}
	return;
}
int main()
{
	scanf("%d%d",&n,&s);
	for(int i=1;i<n;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		ed[x].push_back((node){y,z});
		ed[y].push_back((node){x,z});
	}
	int l=1,l2=1;
	dis[1]=0;
	dfs(l);
	memset(fa,0,sizeof(fa));
	for(int i=1;i<=n;i++)
	{
		if(dis[l]<dis[i])
		{
			l=i;
		}
	}
	dis[l]=0;
	dfs(l);
	for(int i=1;i<=n;i++)
	{
		if(dis[l2]<dis[i])
		{
			l2=i;
		}
	}
	int ans=99999999,j=l2;
	for(int i=l2;i;i=fa[i])
	{
		while(fa[j]&&dis[i]-dis[fa[j]]<=s)
		{
			j=fa[j];
		}
		ans=min(ans,max(dis[l2]-dis[i],dis[j]));
	}
	for(int i=l2;i;i=fa[i])
	{
		vis[i]=1;
	}
	for(int i=l2;i;i=fa[i])
	{
		dis[i]=0;
		dfs(i);
	}
	for(int i=1;i<=n;i++)
	{
		ans=max(dis[i],ans);
	}
	printf("%d",ans);
	return 0;
}