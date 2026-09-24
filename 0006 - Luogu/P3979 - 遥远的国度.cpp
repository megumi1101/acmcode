#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,dep[N],fa[N][22],siz[N],son[N];
int top[N],id[N],dfn[N],mx,a[N];
int t[N<<2],tag[N<<2],cnt,rt;
vector<int>ed[N];
int inline read()
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
void dfs1(int u,int fat,int deep)
{
	dep[u]=deep;
	fa[u][0]=fat;
	siz[u]=1;
	int maxson=-1;
	for(int i=1;i<=mx;i++)
	{
		if(!fa[u][i-1])
		{
			break;
		}
		fa[u][i]=fa[fa[u][i-1]][i-1];
	}
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
}
void dfs2(int u,int topfa)
{
	top[u]=topfa;
	id[u]=++cnt;
	dfn[cnt]=u;
	if(!son[u])return;
	dfs2(son[u],topfa);
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i];
		if(v==fa[u][0]||v==son[u])continue;
		dfs2(v,v);
	}
}
void pushup(int u)
{
	t[u]=min(t[u<<1],t[u<<1|1]);
}
void build(int u,int l,int r)
{
	if(l==r)
	{
		t[u]=a[dfn[l]];
		return;
	}
	int mid=(l+r)>>1;
	build(u<<1,l,mid);
	build(u<<1|1,mid+1,r);
	pushup(u);
}
void down(int u)
{
	if(tag[u])
	{
		t[u<<1]=t[u<<1|1]=tag[u];
		tag[u<<1]=tag[u<<1|1]=tag[u];
		tag[u]=0;
	}
}
void update(int u,int l,int r,int cl,int cr,int x)
{
	if(cl<=l&&r<=cr)
	{
		t[u]=x;
		tag[u]=x;return;
	}
	int mid=(l+r)>>1;
	down(u);
	if(cl<=mid)update(u<<1,l,mid,cl,cr,x);
	if(cr>mid)update(u<<1|1,mid+1,r,cl,cr,x);
	pushup(u);
}
int cx(int u,int l,int r,int cl,int cr)
{
	if(cl<=l&&r<=cr)
	{
		return t[u];
	}
	int mid=(l+r)>>1;
	down(u);
	if(cr<=mid)return cx(u<<1,l,mid,cl,cr);
	else if(cl>mid)return cx(u<<1|1,mid+1,r,cl,cr);
	else return min(cx(u<<1,l,mid,cl,cr),cx(u<<1|1,mid+1,r,cl,cr));
}
void lupdate(int x,int y,int k)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		update(1,1,n,id[top[x]],id[x],k);
		x=fa[top[x]][0];
	}
	if(dep[x]<dep[y])swap(x,y);
	update(1,1,n,id[y],id[x],k);
}
int getfa(int x,int k)
{
	for(int i=mx;i>=0;i--)
		if(k>=(1<<i))
			x=fa[x][i],k-=(1<<i);
	return x;
}
int main()
{
	n=read();m=read();
	mx=(int)log2(n)+1;
	for(int i=1;i<n;i++)
	{
		int x,y;
		x=read();y=read();
		ed[x].push_back(y);
		ed[y].push_back(x);
	}
	for(int i=1;i<=n;i++)a[i]=read();
	dfs1(1,0,1);
	dfs2(1,1);
	rt=read();
	build(1,1,n);
	while(m--)
	{
		int opt=read();
		if(opt==1)
		{
			rt=read();
		}
		else if(opt==2)
		{
			int x,y,k;
			x=read();y=read();k=read();
			lupdate(x,y,k);
		}
		else
		{
			int x=read(),y;
			if(x==rt)printf("%d\n",t[1]);
			else
			{
				if(dep[x]<dep[rt]&&fa[y=getfa(rt,dep[rt]-dep[x]-1)][0]==x)
				{
					int tmp=cx(1,1,n,1,id[y]-1);
					if(id[y]+siz[y]<=n)
					{
						tmp=min(tmp,cx(1,1,n,id[y]+siz[y],n));
					}
					printf("%d\n",tmp);
				}
				else
				{
					printf("%d\n",cx(1,1,n,id[x],id[x]+siz[x]-1));
				}
			}
		}
	}
	return 0;
}