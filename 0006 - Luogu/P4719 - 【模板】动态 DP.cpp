#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,m;
int fa[maxn],id[maxn],dfn[maxn],en[maxn],son[maxn];
int dep[maxn],siz[maxn],top[maxn],a[maxn],cnt;
int f[maxn][2];
vector<int>ed[maxn<<1];
struct node
{
	int mat[2][2];
	node(){memset(mat,-63,sizeof(mat));}
	friend node operator*(node a,node b)
	{
		node c;
		for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
		for(int k=0;k<2;k++)
		c.mat[i][j]=max(c.mat[i][j],a.mat[i][k]+b.mat[k][j]);
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
	val[u].mat[1][0]+=w-a[u];
	a[u]=w;
	node qian,hou;
	while(1)
	{
		qian=cx(1,1,n,id[top[u]],en[top[u]]);
		update(1,1,n,id[u]);
		hou=cx(1,1,n,id[top[u]],en[top[u]]);
		u=fa[top[u]];
		if(u==0)break;
		val[u].mat[0][0]+=max(hou.mat[0][0],hou.mat[1][0])-max(qian.mat[0][0],qian.mat[1][0]);
		val[u].mat[0][1]=val[u].mat[0][0];
		val[u].mat[1][0]+=hou.mat[0][0]-qian.mat[0][0];
	}
}
void dfs1(int u,int fat)
{
	dep[u]=dep[fat]+1;
	siz[u]=1;
	fa[u]=fat;
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i];
		if(v==fat)continue;
		dfs1(v,u);
		siz[u]+=siz[v];
		if(siz[v]>siz[son[u]])son[u]=v;
	}
}
void dfs2(int u,int topfa)
{
	id[u]=++cnt;
	dfn[cnt]=u;
	top[u]=topfa;
	en[topfa]=max(en[topfa],cnt);
	f[u][0]=0;f[u][1]=a[u];
	val[u].mat[0][0]=0;
	val[u].mat[0][1]=0;
	val[u].mat[1][0]=a[u];
	if(son[u])
	{
		dfs2(son[u],topfa);
		int v=son[u];
		f[u][0]+=max(f[v][0],f[v][1]);
		f[u][1]+=f[v][0];
	}
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i];
		if(v==fa[u]||v==son[u])continue;
		dfs2(v,v);
		f[u][0]+=max(f[v][0],f[v][1]);
		f[u][1]+=f[v][0];
		val[u].mat[0][0]+=max(f[v][0],f[v][1]);
		val[u].mat[0][1]=val[u].mat[0][0];
		val[u].mat[1][0]+=f[v][0];
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		ed[x].push_back(y);
		ed[y].push_back(x);
	}
	dfs1(1,0);
	dfs2(1,1);
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		int u,w;
		scanf("%d%d",&u,&w);
		lupdate(u,w);
		node ans=cx(1,1,n,id[1],en[1]);
		printf("%d\n",max(ans.mat[0][0],ans.mat[1][0]));
	}
	return 0;
}