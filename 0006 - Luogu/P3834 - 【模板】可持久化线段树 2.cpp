#include<bits/stdc++.h>
#define maxn 20000010
using namespace std;
int top;
int a[maxn],b[maxn],rt[maxn];
struct node
{
	int l,r,num;
}tree[maxn];
int clone(int xx)
{
	top++;
	tree[top]=tree[xx];
	return top;
}
int build(int ll,int rr)
{
	int bh=++top;
	int mid=(ll+rr)>>1;
	if(ll<rr)
	{
		tree[bh].l=build(ll,mid);
		tree[bh].r=build(mid+1,rr);
	}	
	return bh;
}
int update(int bh,int ll,int rr,int x)
{
	int tmp=clone(bh);
	tree[tmp].num++;
	if(ll<rr)
	{
		int mid=(ll+rr)>>1;
		if(x<=mid)
		{
			tree[tmp].l=update(tree[bh].l,ll,mid,x);
		}
		else
		{
			tree[tmp].r=update(tree[bh].r,mid+1,rr,x);
		}
	}
	return tmp;
}
int chaxun(int u,int v,int ll,int rr,int k)
{
	if(ll==rr)
	{
		return b[ll];
	}
	else
	{
		int t1l=tree[u].l;
		int t2l=tree[v].l;
		int t1r=tree[u].r;
		int t2r=tree[v].r;
		int mid=(ll+rr)>>1;
		int x=tree[t2l].num-tree[t1l].num;
		if(x>=k)
		{
			return chaxun(t1l,t2l,ll,mid,k);
		}				
		else
		{
			return chaxun(t1r,t2r,mid+1,rr,k-x);
		}
	}
	
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(b+1,b+1+n);
	int size=unique(b+1,b+1+n)-b-1;
	rt[0]=build(1,size);
	for(int i=1;i<=n;i++)
	{
		int x=lower_bound(b+1,b+1+size,a[i])-b;
		rt[i]=update(rt[i-1],1,size,x);
	}
	while(m--)
	{
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		printf("%d\n",chaxun(rt[l-1],rt[r],1,size,k));
	}
	return 0;
}