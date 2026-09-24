#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
struct node
{
	int to,val;
};
bool vis[maxn];
vector<node>ed[maxn];
vector<int>ve[maxn];
queue<int> q;
int a[maxn],dep[maxn],fa[maxn],w[maxn];
int rd[maxn];
void dfs(int u,int fat,int val)
{
	fa[u]=fat;
	w[u]=val;
	dep[u]=dep[fat]+1;
	vis[u]=1;
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i].to;
		if(v==fat)continue;
		dfs(v,u,ed[u][i].val);
	}
}
void sol(int x)
{
	int y=a[x];
	vector<int> lx,ly;
	while(dep[x]<dep[y])
	{
		ly.push_back(w[y]);
		y=fa[y];
	}
	while(dep[y]<dep[x])
	{
		lx.push_back(w[x]);
		x=fa[x];
	}
	while(x!=y)
	{
		lx.push_back(w[x]);
		ly.push_back(w[y]);
		x=fa[x];
		y=fa[y];
	}
	for(int i=ly.size()-1;i>=0;i--)
	{
		lx.push_back(ly[i]);
	}
	for(int i=lx.size()-1;i>=1;i--)	
	{
		ve[lx[i-1]].push_back(lx[i]);
		rd[lx[i]]++;
	}
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		ed[x].push_back((node){y,i});
		ed[y].push_back((node){x,i});
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])dfs(i,0,0);
	}
	for(int i=1;i<=n;i++)sol(i);
	for(int i=1;i<=m;i++)
	{
		if(!rd[i])q.push(i);
	}
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		printf("%d ",u);
		for(int i=0;i<ve[u].size();i++)
		{
			int v=ve[u][i];
			rd[v]--;
			if(!rd[v])q.push(v);
		}
	}
	return 0;
}
