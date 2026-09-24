#include<bits/stdc++.h>
#define maxn 1000099
using namespace std;
int n,m,s;
int cnt,cnt2;
int to[maxn],nex[maxn],head[maxn],top[maxn];
int fa[maxn],dep[maxn],siz[maxn],son[maxn];
void add(int x,int y)
{
	to[++cnt]=y;
	nex[cnt]=head[x];
	head[x]=cnt;
}
void dfs1(int u,int fat,int deep)
{
	dep[u]=deep;
	fa[u]=fat;
	siz[u]=1;
	int maxson=-1;
	for(int i=head[u];~i;i=nex[i])
	{
		int v=to[i];
		if(v==fat)continue;
		dfs1(v,u,deep+1);
		siz[u]+=siz[v];
		if(siz[v]>maxson)
		{
			son[u]=v;
			maxson=siz[v];
		}
	}
}
void dfs2(int u,int topfa)
{
	top[u]=topfa;
	if(!son[u])return;
	dfs2(son[u],topfa);
	for(int i=head[u];~i;i=nex[i])
	{
		int v=to[i];
		if(v==fa[u]||v==son[u])continue;
		dfs2(v,v);
	}
}
int lca(int x,int y)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])
		{
			swap(x,y);
		}
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	return x;
}
int main()
{
	scanf("%d%d%d",&n,&m,&s);
	memset(head,-1,sizeof(head));
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	dfs1(s,0,1);
	dfs2(s,0);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",lca(x,y));
	}
	return 0;
}