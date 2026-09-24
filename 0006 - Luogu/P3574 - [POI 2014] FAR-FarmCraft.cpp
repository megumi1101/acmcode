#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int n,c[maxn],siz[maxn],t[maxn],f[maxn];
vector<int>ed[maxn];
bool cmp(int x,int y)
{
	return siz[x]-f[x]<siz[y]-f[y];
}
void dfs(int u,int fa)
{
	if(u!=1)f[u]=c[u];
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i];
		if(v!=fa)dfs(v,u);
	}
	int cnt=0;
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i];
		if(v!=fa)t[++cnt]=v;
	}
	sort(t+1,t+1+cnt,cmp);
	for(int i=1;i<=cnt;i++)
	{
		f[u]=max(f[u],f[t[i]]+siz[u]+1);
		siz[u]+=siz[t[i]]+2;
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
	}
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		ed[x].push_back(y);
		ed[y].push_back(x);
	}
	dfs(1,0);
	printf("%d",max(f[1],c[1]+siz[1]));
}