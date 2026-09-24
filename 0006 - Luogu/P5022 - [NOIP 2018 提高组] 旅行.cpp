#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+10;
int n,m;
vector<int>ed[maxn<<1];
int xx[maxn],yy[maxn];
int ans[maxn],cnt,res[maxn]; 
bool vis[maxn];
void dfs(int u)
{
	ans[++cnt]=u;
	vis[u]=1;
	for(int i=0;i<ed[u].size();i++)	
	{
		int v=ed[u][i];
		if(!vis[v])dfs(v);
	}
}
bool pd()
{
	for(int i=1;i<=n;i++)
		if(ans[i]!=res[i])
			return ans[i]>res[i];
	return 0;
}
int du,dv;
bool pd2(int u,int v)
{
	if((u==du&&v==dv)||(v==du&&u==dv))return 0;
	return 1;
}
void dfs2(int u)
{
	res[++cnt]=u;
	vis[u]=1;
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i];
		if(!vis[v]&&pd2(u,v))dfs2(v);
	}
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
		xx[i]=x,yy[i]=y;
	}
	if(n-1==m)
	{
		memset(ans,0,sizeof(ans));
		memset(vis,0,sizeof(vis));
		cnt=0;
		for(int i=1;i<=n;i++)sort(ed[i].begin(),ed[i].end());
		dfs(1);
		for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	}
	else
	{
		memset(ans,0x3f,sizeof(ans));
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++)sort(ed[i].begin(),ed[i].end());
		for(int i=1;i<=m;i++)
		{
			cnt=0;
			memset(res,0,sizeof(res));
			memset(vis,0,sizeof(vis));
			du=xx[i];
			dv=yy[i];
			dfs2(1);
			if(pd()&&cnt==n)memcpy(ans,res,sizeof(res));
		}
		for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	}
}