#include<bits/stdc++.h>
using namespace std;
const int maxn=4e5+100;
int ans[maxn],mans[maxn],msum[maxn],sum[maxn],val[maxn],mval[maxn];
bool vis[maxn];
#define ls(i) ((i)<<1)
#define rs(i) ((i)<<1|1)
void pushup(int u)
{
	ans[u]=max(ans[ls(u)],ans[rs(u)]);
	mans[u]=max(mans[ls(u)],mans[rs(u)]);
}
void dsum(int u,int k,int mk)
{
	if(vis[u])
	{
		mval[u]=max(mval[u],val[u]+mk);
		mans[u]=max(mans[u],ans[u]+mk);
		ans[u]+=k;
		val[u]+=k;
	}
	else
	{
		msum[u]=max(msum[u],sum[u]+mk);
		mans[u]=max(mans[u],ans[u]+mk);
		ans[u]+=k;
		sum[u]+=k;
	}
	
}
void fz(int u,int k,int mk)
{
	if(vis[u])
	{
		mval[u]=max(mval[u],mk);
		mans[u]=max(mans[u],mk);
	}
	else
	{
		vis[u]=1;
		mval[u]=mk;
		mans[u]=max(mans[u],mk);
	}
	ans[u]=val[u]=k;
}
void pushdown(int u)
{
	dsum(ls(u),sum[u],msum[u]);
	dsum(rs(u),sum[u],msum[u]);
	sum[u]=msum[u]=0;
	if(vis[u])
	{
		fz(ls(u),val[u],mval[u]);
		fz(rs(u),val[u],mval[u]);
		vis[u]=0;
		val[u]=mval[u]=0;
	}
}
void build(int u,int l,int r)
{
	if(l==r)
	{
		int x;
		scanf("%d",&x);
		ans[u]=mans[u]=x;
		return;
	}
	int mid=(l+r)>>1;
	build(ls(u),l,mid);
	build(rs(u),mid+1,r);
	pushup(u);
}
void add(int u,int l,int r,int ql,int qr,int k)
{
	if(ql<=l&&qr>=r)
	{
		dsum(u,k,k);
		return;
	}
	pushdown(u);
	int mid=(l+r)>>1;
	if(ql<=mid)
	{
		add(ls(u),l,mid,ql,qr,k);
	}
	if(qr>mid)
	{
		add(rs(u),mid+1,r,ql,qr,k);
	}
	pushup(u);
}
void ff(int u,int l,int r,int ql,int qr,int k)
{
	if(ql<=l&&qr>=r)
	{
		fz(u,k,k);
		return;
	}
	pushdown(u);
	int mid=(l+r)>>1;
	if(ql<=mid)
	{
		ff(ls(u),l,mid,ql,qr,k);
	}
	if(qr>mid)
	{
		ff(rs(u),mid+1,r,ql,qr,k);
	}
	pushup(u);
}
int cx(int u,int l,int r,int ql,int qr)
{
	if(ql<=l&&qr>=r)
	{
		return ans[u];
	}
	pushdown(u);
	int mid=(l+r)>>1,res=-99999999;
	if(ql<=mid)
	{
		res=cx(ls(u),l,mid,ql,qr);
	}
	if(qr>mid)
	{
		res=max(res,cx(rs(u),mid+1,r,ql,qr));
	}
	return res;
}
int mcx(int u,int l,int r,int ql,int qr)
{
	if(ql<=l&&qr>=r)
	{
		return mans[u];
	}
	pushdown(u);
	int mid=(l+r)>>1,res=-99999999;
	if(ql<=mid)
	{
		res=mcx(ls(u),l,mid,ql,qr);
	}
	if(qr>mid)
	{
		res=max(res,mcx(rs(u),mid+1,r,ql,qr));
	}
	return res;
}
int main()
{
	int t,q,x,y,z;
	scanf("%d",&t);
	build(1,1,t);
	scanf("%d",&q);
	while(q--)
	{
		char c[2];
		scanf("%s%d%d",c,&x,&y);
		if(c[0]=='Q')
		{
			printf("%d\n",cx(1,1,t,x,y));
		}
		else if(c[0]=='A')
		{
			printf("%d\n",mcx(1,1,t,x,y));
		}
		else if(c[0]=='P')
		{
			scanf("%d",&z);
			add(1,1,t,x,y,z);
		}
		else
		{
			scanf("%d",&z);
			ff(1,1,t,x,y,z);
		}
	}
	return 0;
}