#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxm=3e5+10,maxn=1e5+10,inf=2147483647000000;
int n,m,ds,cnt1,cnt2;
int faa[maxn],a[5],sm,csm,w[maxn<<1],ww[maxn<<1];
int dep[maxn<<1],siz[maxn<<1],son[maxn<<1];
int fa[maxn<<1],id[maxn<<1],top[maxn<<1];
vector<int>ed[maxn<<1];
template <typename T> inline void read(T &a) {
    a = 0;char c = getchar();long long f = 1;
    while(c < '0' || c > '9') {if(c == '-') f = -1;c = getchar();}
    while(c >= '0' && c <= '9') {a = (a << 3) + (a << 1) + (c ^ 48);c = getchar();}
    a *= f;
}
struct kls
{
	int x,y,z;
	bool has;
	friend bool operator<(kls a,kls b)
	{
		return a.z<b.z;
	}
}kk[maxm];
struct node
{
	int fi,se;
}tr[maxn<<3];
inline int find(int x)
{
	if(faa[x]==x)return x;
	faa[x]=find(faa[x]);
	return faa[x];
}
inline int klskr()
{
	int res=0;
	ds=n;
	for(int i=1;i<=n;i++)
	{
		faa[i]=i;
	}
	sort(kk+1,kk+1+m);
	for(int i=1;i<=m;i++)
	{
		int x=kk[i].x;
		int y=kk[i].y;
		if(find(x)==find(y))continue;
		faa[find(y)]=find(x);
		ds++;cnt1++;
		ed[ds].push_back(x);
		ed[ds].push_back(y);
		ed[x].push_back(ds);
		ed[y].push_back(ds);
		ww[ds]=kk[i].z;
		res+=kk[i].z;
		kk[i].has=1;
		if(cnt1==n-1)break;
	}
	return res;
}
inline void dfs1(int u,int fat ,int deep)
{
	dep[u]=deep;
	siz[u]=1;
	fa[u]=fat;
	int maxson=-1;
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i];
		if(v==fat)continue;
		dfs1(v,u,deep+1);
		siz[u]+=siz[v];
		if(siz[v]>maxson)
		{
			maxson=siz[v];
			son[u]=v;
		}
	}
}
inline void dfs2(int u,int topfa)
{
	id[u]=++cnt2;
	top[u]=topfa;
	w[cnt2]=ww[u];
	if(!son[u]) return;
	dfs2(son[u],topfa);
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i];
		if(v==fa[u]||v==son[u])continue;
		dfs2(v,v);
	}
}
inline node update(node u,node v)
{
	node tmp;
	tmp.se=0;
	a[1]=u.fi,a[2]=u.se,a[3]=v.fi,a[4]=v.se;
	sort(a+1,a+5);
	tmp.fi=a[4];
	for(int i=3;i>=1;i--)
	{
		if(a[i]!=a[4])
		{
			tmp.se=a[i];
			break;
		}
	}
	return tmp;
}
inline void build(int u,int l,int r)
{
	if(l==r)
	{
		tr[u].fi=w[l];
		tr[u].se=0;
		return;
	}
	int mid=(l+r)>>1;
	build(u<<1,l,mid);
	build(u<<1|1,mid+1,r);
	tr[u]=update(tr[u<<1],tr[u<<1|1]);
}
inline node cx(int u,int l,int r,int cl,int cr)
{
	node res1;
	res1.fi=0,res1.se=0;
	if(cl<=l&&r<=cr)
	{
		return tr[u];
	}
	int mid=(l+r)>>1;
	if(cl<=mid)res1=update(res1,cx(u<<1,l,mid,cl,cr));
	if(cr>mid)res1=update(res1,cx(u<<1|1,mid+1,r,cl,cr));
	return res1;
}
inline node lcx(int x,int y)
{
	node res;
	res.fi=0,res.se=0;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		res=update(res,cx(1,1,cnt2,id[top[x]],id[x]));
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	res=update(res,cx(1,1,cnt2,id[x],id[y]));
	return res;
}
signed main()
{
	read(n);read(m);
	for(int i=1;i<=m;i++)
	{
		read(kk[i].x);read(kk[i].y);read(kk[i].z);
	}
	sm=klskr();
	csm=inf;
	dfs1(1,0,1);
	dfs2(1,1);
	build(1,1,cnt2);
	for(int i=1;i<=m;i++)
	{
		if(kk[i].has)continue;
		int ww=kk[i].z;
		node tmp=lcx(kk[i].x,kk[i].y);
		if(tmp.fi!=ww)csm=min(csm,sm-tmp.fi+ww);
		else csm=min(csm,sm-tmp.se+ww);
	}
	printf("%lld",csm);
	return 0;
}