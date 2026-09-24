#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+10;
int to[maxn],nex[maxn],head[maxn],top[maxn];
int fa[maxn],dep[maxn],siz[maxn],son[maxn],cnt;
int id[maxn],dfn[maxn],dis[maxn],ans;
bool vis[maxn];
int n,m;
struct node
{
	int to,val;
};
vector<node>ed[maxn];
void dfs1(int u,int fat,int deep)
{	
	fa[u]=fat;
	dep[u]=deep;
	siz[u]=1;
	int maxson=-1;
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i].to;
		if(v==fat)continue;
		dis[v]=dis[u]+ed[u][i].val;
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
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i].to;
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
int dist(int x,int y)
{
	return dis[x]+dis[y]-2*dis[lca(x,y)];
}
void dfs(int u)
{	
	dfn[u]=++cnt;
	id[cnt]=u;
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i].to;
		if(v==fa[u])continue;
		dfs(v);
	}
}
set<int>st;
set<int>::iterator it;
signed main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<n;i++)
	{
		int x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		ed[x].push_back((node){y,z});
		ed[y].push_back((node){x,z});
	}
	dfs1(1,0,1);
	dfs2(1,1);cnt=0;
	dfs(1);
	for(int i=1;i<=m;i++)
	{
		int x;
		scanf("%lld",&x);
		x=dfn[x];
		if(!vis[id[x]])st.insert(x);
		int y=id[(it=st.lower_bound(x))==st.begin() ?*--st.end():*--it];
		int z=id[(it=st.upper_bound(x))==st.end() ?*st.begin():*it];
		//printf("st.end=%d --%d ",*st.end(),*--st.end());
		//printf("i=%d x=%d y=%d z=%d ",i,x,y,z);
		if(vis[id[x]])st.erase(x);
		x=id[x];
		int d=dist(x,y)+dist(x,z)-dist(y,z);
		//printf("d=%d\n",d);
		if(!vis[x])vis[x]=1,ans+=d;
		else vis[x]=0,ans-=d;
		printf("%lld\n",ans);
	}
	return 0;
}