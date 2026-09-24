#include<bits/stdc++.h>
using namespace std;
#define int long long
int inline rd()
{
	int ans=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		ans=ans*10+ch-'0';
		ch=getchar();
	}
	return ans*f;
}
const int N=2e5+10;
vector<int>ed[N];
int n,m,dep[N],siz[N],son[N],st[N],en[N],nim;
int fa[N],top[N],id[N];
void dfs1(int u,int fat,int deep)
{
	fa[u]=fat;st[u]=++nim;
	dep[u]=deep;id[nim]=u;
	siz[u]=1;
	int maxson=-1;
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i];
		if(v==fat)continue;
		dfs1(v,u,deep+1);
		siz[u]+=siz[v];
		if(siz[v]>maxson)
		{
			son[u]=v;maxson=siz[v];
		}
	}
	en[u]=++nim;id[nim]=u;
}
void dfs2(int u,int topfa)
{
	top[u]=topfa;
	if(!son[u])return;
	dfs2(son[u],topfa);
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i];
		if(v==fa[u]||v==son[u])continue;
		dfs2(v,v);
	}
}
int lca(int x,int y)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	return x;
}
int sum,a[N],cnt[N],use[N],hs[N],bl,ans[N],b[N];
int pos[N],num[N],V[N],W[N],qq,tim,tp;
void add(int x)
{
	sum+=V[a[x]]*W[++cnt[a[x]]];
}
void del(int x)
{
	sum-=V[a[x]]*W[cnt[a[x]]];cnt[a[x]]--;
}
void wk(int x)
{
	use[x]?del(x):add(x);
	use[x]^=1;
}
void up(int t)
{
	int x=pos[t];
	if(use[x])
	{
		wk(x);
		swap(a[x],num[t]);
		wk(x);
	}
	else
	{
		swap(a[x],num[t]);
	}
	return;
}
struct node
{
	int l,r,f,t,id;
	friend bool operator<(node a,node b)
	{
		if(hs[a.l]!=hs[b.l])return a.l<b.l;
		if(hs[a.r]!=hs[b.r])return a.r<b.r;
		return a.t<b.t;
	}
}q[N];
signed main()
{
	n=rd();m=rd();qq=rd();
	bl=sqrt(2*n);
	for(int i=1;i<=m;i++)V[i]=rd();
	for(int i=1;i<=n;i++)W[i]=rd();
	for(int i=1;i<n;i++)
	{
		int x,y;
		x=rd(),y=rd();
		ed[x].push_back(y);
		ed[y].push_back(x);
	}
	for(int i=1;i<=2*n;i++)hs[i]=(i-1)/bl+1;
	dfs1(1,0,1);
	dfs2(1,1);
	for(int i=1;i<=n;i++)a[i]=rd();
	for(int i=1;i<=qq;i++)
	{
		int opt,x,y;
		opt=rd();
		if(!opt)
		{
			++tim,pos[tim]=rd(),num[tim]=rd();
			continue;
		}
		x=rd();y=rd();++tp;
		if(st[x]>st[y])swap(x,y);
		q[tp].f=lca(x,y);q[tp].id=tp;q[tp].t=tim; 
		if(q[tp].f==x){q[tp].l=st[x],q[tp].r=st[y];q[tp].f=0;}
		else{q[tp].l=en[x],q[tp].r=st[y];}
	}	
	sort(q+1,q+1+tp);
	int l=1,r=0,t=0;
	for(int i=1;i<=tp;i++)
	{
		while(l<q[i].l)wk(id[l++]);
		while(l>q[i].l)wk(id[--l]);
		while(r<q[i].r)wk(id[++r]);
		while(r>q[i].r)wk(id[r--]);
		while(t<q[i].t)up(++t);
		while(t>q[i].t)up(t--);
		if(q[i].f)wk(q[i].f);
		ans[q[i].id]=sum;
		if(q[i].f)wk(q[i].f);
	}
	for(int i=1;i<=tp;i++)printf("%lld\n",ans[i]);
	return 0;
}