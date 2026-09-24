#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,k,a[maxn],top,st[maxn],cnt;
int mx[maxn<<2],tag[maxn<<2],dfn[maxn],siz[maxn];
vector<int>ed[maxn];
void dfs(int u)
{
	dfn[u]=++cnt;
	siz[u]=1;
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i];
		dfs(v);siz[u]+=siz[v];
	}
}
void pushup(int u)
{
	mx[u]=max(mx[u<<1],mx[u<<1|1]);
}
void pushdown(int u)
{
	mx[u<<1]+=tag[u];
	mx[u<<1|1]+=tag[u];
	tag[u<<1]+=tag[u];
	tag[u<<1|1]+=tag[u];
	tag[u]=0;
}
void update(int u,int l,int r,int cl,int cr,int w)
{
	if(cl<=l&&r<=cr)
	{
		mx[u]+=w;tag[u]+=w;
		return;
	}
	pushdown(u);
	int mid=(l+r)>>1;
	if(cl<=mid)update(u<<1,l,mid,cl,cr,w);
	if(cr>mid)update(u<<1|1,mid+1,r,cl,cr,w);
	pushup(u);
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		while(top&&a[st[top]]<a[i])
		{
			ed[i].push_back(st[top]);
			top--;
		}
		st[++top]=i;
	}
	while(top)ed[n+1].push_back(st[top--]);
	dfs(n+1);
	for(int i=1;i<=k;i++)update(1,1,n+1,dfn[i],dfn[i]+siz[i]-1,1);
	printf("%d ",mx[1]);
	for(int i=k+1;i<=n;i++)
	{
		update(1,1,n+1,dfn[i],dfn[i]+siz[i]-1,1);
		update(1,1,n+1,dfn[i-k],dfn[i-k]+siz[i-k]-1,-1);
		printf("%d ",mx[1]);
	}
	return 0;
}
