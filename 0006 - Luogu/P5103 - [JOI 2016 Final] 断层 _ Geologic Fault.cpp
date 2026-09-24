#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+10;
int n,q;
int tagx[maxn<<2],tagy[maxn<<2],x[maxn<<2],y[maxn<<2];
int xx[maxn],dd[maxn],ll[maxn];
struct node
{
	int x,y;
};
void build(int u,int l,int r)
{
	if(l==r)
	{
		x[u]=y[u]=l;
		return;
	}
	int mid=(l+r)>>1;
	build(u<<1,l,mid);
	build(u<<1|1,mid+1,r);
}
void pushdown(int u)
{
	tagx[u<<1]+=tagx[u];tagy[u<<1]+=tagy[u];
	tagx[u<<1|1]+=tagx[u];tagy[u<<1|1]+=tagy[u];
	tagx[u]=0;tagy[u]=0;
}
void add(int u,int l,int r,int cl,int cr,int vx,int vy)
{
	if(cl<=l&&r<=cr)
	{
		tagx[u]+=vx;
		tagy[u]+=vy;
		return;
	}
	pushdown(u);
	int mid=(l+r)>>1;
	if(cl<=mid)add(u<<1,l,mid,cl,cr,vx,vy);
	if(cr>mid)add(u<<1|1,mid+1,r,cl,cr,vx,vy);
}
node cx(int u,int l,int r,int pos)
{
	if(l==r)
	{
		x[u]+=tagx[u];
		y[u]+=tagy[u];
		tagx[u]=0;
		tagy[u]=0;
		return (node){x[u],y[u]};
	}
	int mid=(l+r)>>1;
	pushdown(u);
	if(pos>mid)return cx(u<<1|1,mid+1,r,pos);
	else return cx(u<<1,l,mid,pos);
}
void wk(int u,int l,int r)
{
	if(l==r)
	{
		x[u]+=tagx[u];
		y[u]+=tagy[u];
		printf("%lld\n",(x[u]-y[u])/2);
		return;
	}
	pushdown(u);
	int mid=(l+r)>>1;
	wk(u<<1,l,mid);
	wk(u<<1|1,mid+1,r);
}
signed main()
{
	scanf("%lld%lld",&n,&q);
	build(1,1,n);
	for(int i=q;i>=1;i--)scanf("%lld%lld%lld",&xx[i],&dd[i],&ll[i]);
	for(int i=1;i<=q;i++)
	{
		int x,d,l;
		x=xx[i];d=dd[i];l=ll[i];
		if(d==1)
		{
			node tmp;
			tmp=cx(1,1,n,1);
			if(tmp.x>x)continue;
			tmp=cx(1,1,n,n);
			if(tmp.x<=x)
			{
				add(1,1,n,1,n,0,-2*l);
				continue;
			}
			int ml=1,mr=n;
			while(ml<mr)
			{
				int mid=(ml+mr)>>1;
				tmp=cx(1,1,n,mid);
				if(tmp.x>x)mr=mid;
				else ml=mid+1;
			}
			ml--;
			add(1,1,n,1,ml,0,-2*l);
		}
		else
		{
			node tmp;
			tmp=cx(1,1,n,n);
			if(tmp.y<=x)continue;
			int ml=1,mr=n;
			while(ml<mr)
			{
				int mid=(ml+mr)>>1;
				tmp=cx(1,1,n,mid);
				if(tmp.y>x)mr=mid;
				else ml=mid+1;
			}
			add(1,1,n,ml,n,2*l,0);
		}
	}
	wk(1,1,n);
	return 0;
}
/*
10 3
17 1 1
4 1 1
0 2 1
*/