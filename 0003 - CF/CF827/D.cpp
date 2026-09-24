#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10,inf=1e9+10;
int n,m,ans[maxn];
bool vis[maxn];
struct no
{
	int x,y,z;
}sw[maxn];
namespace tree
{
	int cnt=0;
	int fa[maxn],dep[maxn],siz[maxn],son[maxn];
	int val[maxn],top[maxn],id[maxn];
	int mx[maxn<<2],mn[maxn<<2],tag[maxn<<2];
	struct nod
	{
		int to,val;
	};
	vector<nod>ed[maxn<<1];
	void ad(int x,int y,int z)
	{
		ed[x].push_back((nod){y,z});
		ed[y].push_back((nod){x,z});
		//cerr<<"xxqz"<<' '<<x<<' '<<y<<endl;
	} 
	void dfs1(int u,int fat)
	{
		fa[u]=fat;
		dep[u]=dep[fat]+1;
		siz[u]=1;
//		cerr<<"chr"<<endl;
//		cerr<<fat<<endl;
		int mxs=-1;
		for(int i=0;i<ed[u].size();i++)
		{
			int v=ed[u][i].to;
			if(v==fat)continue;
			dfs1(v,u);
			siz[u]+=siz[v];
			if(siz[v]>mxs)mxs=siz[v],son[u]=v;
		}
	}
	void dfs2(int u,int topfa,int wth)
	{		
		id[u]=++cnt;
		val[cnt]=wth;
		top[u]=topfa;
		if(!son[u])return;
		for(int i=0;i<ed[u].size();i++)
		{
			int v=ed[u][i].to;
			if(v==son[u])dfs2(v,topfa,ed[u][i].val);
		}
		for(int i=0;i<ed[u].size();i++)
		{
			int v=ed[u][i].to;
			if(v==fa[u]||v==son[u])continue;
			dfs2(v,v,ed[u][i].val);
		}
	}
	void up1(int u)
	{
		mx[u]=max(mx[u<<1],mx[u<<1|1]);
	}
	void up2(int u)
	{
		mn[u]=min(mn[u<<1],mn[u<<1|1]);
	}
	void build(int u,int l,int r)
	{
		if(l==r)
		{
			mx[u]=val[l];
			return;
		}
		int mid=(l+r)>>1;
		build(u<<1,l,mid);
		build(u<<1|1,mid+1,r);
		up1(u);
	}
	void pd(int u)
	{
		if(tag[u]==-1)return;
		mn[u<<1]=min(mn[u<<1],tag[u]);
		mn[u<<1|1]=min(mn[u<<1|1],tag[u]);
		tag[u<<1]=(tag[u<<1]==-1?tag[u]:min(tag[u<<1],tag[u]));
		tag[u<<1|1]=(tag[u<<1|1]==-1?tag[u]:min(tag[u<<1|1],tag[u]));
		tag[u]=-1;
	}
	void upd(int u,int l,int r,int cl,int cr,int k)
	{
		if(cl<=l&&r<=cr)
		{
			mn[u]=min(mn[u],k);
			tag[u]=(tag[u]==-1?k:min(tag[u],k));
			return;
		}
		pd(u);
		int mid=(l+r)>>1;
		if(cl<=mid)upd(u<<1,l,mid,cl,cr,k);
		if(cr>mid)upd(u<<1|1,mid+1,r,cl,cr,k);
		up2(u);
	}
	void lupd(int x,int y,int val)
	{
		while(top[x]!=top[y])
		{
			if(dep[top[x]]<dep[top[y]])swap(x,y);
			upd(1,1,cnt,id[top[x]],id[x],val);
			x=fa[top[x]];
		}
		if(x==y)return;
		if(dep[x]>dep[y])swap(x,y);
		upd(1,1,cnt,id[x]+1,id[y],val);
	}
	int cx1(int u,int l,int r,int cl,int cr)
	{
		if(cl<=l&&r<=cr)return mx[u];
		int mid=(l+r)>>1;
		int res=0;
		if(cl<=mid)res=max(res,cx1(u<<1,l,mid,cl,cr));
		if(cr>mid)res=max(res,cx1(u<<1|1,mid+1,r,cl,cr));
		return res;
	}
	int cx2(int u,int l,int r,int p)
	{
		if(p==l&&p==r)return mn[u];
		int mid=(l+r)>>1;
		pd(u);
		up2(u);
		int res=inf;
		if(p<=mid)res=min(res,cx2(u<<1,l,mid,p));
		else res=min(res,cx2(u<<1|1,mid+1,r,p));
		return res;
	}
	int lcx1(int x,int y)
	{
		int res=0;
		while(top[x]!=top[y])
		{
			if(dep[top[x]]<dep[top[y]])swap(x,y);
			res=max(res,cx1(1,1,cnt,id[top[x]],id[x]));
			x=fa[top[x]];
		}
		if(x==y)return res;
		if(dep[x]>dep[y])swap(x,y);
		res=max(res,cx1(1,1,cnt,id[x]+1,id[y]));
		return res;
	}
	int lcx2(int x,int y)
	{
		if(dep[x]<dep[y])swap(x,y);
		return cx2(1,1,cnt,id[x]);
	}
	void sol()
	{
		memset(tag,-1,sizeof(tag));	
		dfs1(1,0);
		dfs2(1,1,0);
		for(int i=1;i<=(cnt<<2);i++)mn[i]=inf;
		build(1,1,cnt);
	}
}
namespace kls
{
	int cnt=1,tnt=0;
	int fa[maxn];
	struct node
	{
		int x,y,z,bh;
	}bn[maxn];
	int find(int x)
	{
		if(fa[x]==x)return x;
		return fa[x]=find(fa[x]);
	}
	bool cmp(node a,node b)
	{
		return a.z<b.z;
	}
	void add(int x,int y,int z,int bh)
	{
		bn[++tnt]=(node){x,y,z,bh};
	}
	void sol()
	{
		for(int i=1;i<=n;i++)fa[i]=i;
		sort(bn+1,bn+1+m,cmp);
		for(int i=1;i<=m;i++)
		{
			int fx=find(bn[i].x);
			int fy=find(bn[i].y);
			if(fx!=fy)
			{
				++cnt;fa[fx]=fy;
				tree::ad(bn[i].x,bn[i].y,bn[i].z);
				vis[bn[i].bh]=1;
			}
			if(cnt==n)break;
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&sw[i].x,&sw[i].y,&sw[i].z);
		kls::add(sw[i].x,sw[i].y,sw[i].z,i);
	}
	kls::sol();
	tree::sol();
	for(int i=1;i<=m;i++)
	{
		if(!vis[i])tree::lupd(sw[i].x,sw[i].y,sw[i].z);
	}
	for(int i=1;i<=m;i++)
	{
		if(vis[i])
		{
			ans[i]=tree::lcx2(sw[i].x,sw[i].y)-1;
			if(ans[i]>=inf-1)ans[i]=-1;
		}
		else ans[i]=tree::lcx1(sw[i].x,sw[i].y)-1;
	}
	for(int i=1;i<=m;i++)printf("%d ",ans[i]);
	return 0;
}
