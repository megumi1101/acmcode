#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+10;
const int inf=0x3f3f3f3f3f3f3f3f;
int n,m;
int fa[maxn],id[maxn],dfn[maxn],en[maxn],son[maxn];
int dep[maxn],siz[maxn],top[maxn],a[maxn],cnt;
int f[maxn];
vector<int>ed[maxn<<1];
struct node
{
	int mat[2][2];
	node(){memset(mat,63,sizeof(mat));}
	friend node operator*(node a,node b)
	{
		node c;
		for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
		for(int k=0;k<2;k++)
		c.mat[i][j]=min(c.mat[i][j],a.mat[i][k]+b.mat[k][j]);
		return c;
	}
};
node tr[maxn<<2],val[maxn];
void pushup(int u)
{
	tr[u]=tr[u<<1]*tr[u<<1|1];
}
void build(int u,int l,int r)
{
	if(l==r)
	{
		tr[u]=val[dfn[l]];
		return;
	}
	int mid=(l+r)>>1;
	build(u<<1,l,mid);
	build(u<<1|1,mid+1,r);
	pushup(u);
}
void update(int u,int l,int r,int p)
{
	if(l==r)
	{
		tr[u]=val[dfn[l]];
		return;
	}
	int mid=(l+r)>>1;
	if(p<=mid)update(u<<1,l,mid,p);
	else update(u<<1|1,mid+1,r,p);
	pushup(u);
}
node cx(int u,int l,int r,int cl,int cr)
{	
	if(cl<=l&&r<=cr)return tr[u];
	int mid=(l+r)>>1;
	if(cr<=mid)return cx(u<<1,l,mid,cl,cr);
	else if(cl>mid)return cx(u<<1|1,mid+1,r,cl,cr);
	else return cx(u<<1,l,mid,cl,cr)*cx(u<<1|1,mid+1,r,cl,cr);
}
void lupdate(int u,int w)
{
	w+=a[u];
	if(id[u]==en[top[u]])val[u].mat[0][0]=w;
	else val[u].mat[0][1]=w;
	a[u]=w;
	node qian,hou;
	while(1)
	{
		qian=cx(1,1,n,id[top[u]],en[top[u]]);
		update(1,1,n,id[u]);
		hou=cx(1,1,n,id[top[u]],en[top[u]]);
		u=fa[top[u]];
		if(u==0)break;
		val[u].mat[0][0]+=hou.mat[0][0]-qian.mat[0][0];
	}
}
void dfs1(int u,int fat)
{
	dep[u]=dep[fat]+1;
	siz[u]=1;
	bool flag=0;
	fa[u]=fat;
	int res=0;
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i];
		if(v==fat)continue;
		dfs1(v,u);
		flag=1;
		siz[u]+=siz[v];
		if(siz[v]>siz[son[u]])son[u]=v;
		res+=f[v];
	}
	if(flag)f[u]=min(res,a[u]);
	else f[u]=a[u];
}
void dfs2(int u,int topfa)
{
	id[u]=++cnt;
	dfn[cnt]=u;
	top[u]=topfa;
	en[topfa]=max(en[topfa],cnt);
	if(son[u])dfs2(son[u],topfa);		
	if(!son[u])
	{
		val[u].mat[0][0]=a[u];val[u].mat[1][0]=0;
		return;
	}
	val[u].mat[0][0]=0;
	val[u].mat[0][1]=a[u];
	val[u].mat[1][0]=inf;
	val[u].mat[1][1]=0;
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i];
		if(v==fa[u]||v==son[u])continue;
		dfs2(v,v);
		val[u].mat[0][0]+=f[v];
	}
}
signed main()
{
	char s[2];
	scanf("%lld",&n);
	memset(f,63,sizeof(f));
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%lld%lld",&x,&y);
		ed[x].push_back(y);
		ed[y].push_back(x);
	}
	dfs1(1,0);
	dfs2(1,1);
	build(1,1,n);
	scanf("%lld",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%s",s);
		if(s[0]=='Q')
		{
			int x;
			scanf("%lld",&x);
			node ans=cx(1,1,n,id[x],en[top[x]]);
			printf("%lld\n",ans.mat[0][0]);
		}
		else
		{
			int x,w;
			scanf("%lld%lld",&x,&w);
			lupdate(x,w);
		}	
	}
	return 0;
}