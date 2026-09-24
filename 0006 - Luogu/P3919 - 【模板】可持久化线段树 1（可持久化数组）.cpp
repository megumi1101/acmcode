#include<bits/stdc++.h>
#define maxn 40000005
using namespace std;
int top=0,a[maxn],root[maxn];
struct node
{
	int l,r,val;
}tree[maxn];
int clone(int x)
{
	top++;
	tree[top]=tree[x];
	return top;
}
int build(int bh,int ll,int rr)
{
	bh=++top;
	if(ll==rr)
	{
		tree[bh].val=a[ll];
		return top;
	}
	int mid=(ll+rr)>>1;
	tree[bh].l=build(tree[bh].l,ll,mid);
	tree[bh].r=build(tree[bh].r,mid+1,rr);
	return bh;
}
int update(int bh,int ll,int rr,int x,int val)
{
	bh=clone(bh);
	if(ll==rr)
	{
		tree[bh].val=val;
	}
	else
	{
		int mid=(ll+rr)>>1;
		if(x<=mid)
		{
			tree[bh].l=update(tree[bh].l,ll,mid,x,val);
		}
		else
		{
			tree[bh].r=update(tree[bh].r,mid+1,rr,x,val);
		}
	}
	return bh;
}
int chaxun(int bh,int ll,int rr,int x)
{
	if(ll==rr)
	{
		return tree[bh].val;
	}
	else
	{
		int mid=(ll+rr)>>1;
		if(x<=mid)
		{
			return chaxun(tree[bh].l,ll,mid,x);
		}				
		else
		{
			return chaxun(tree[bh].r,mid+1,rr,x);
		}
	}
	
}
int main()
{
	int n,m,bb,opt,x,y;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	root[0]=build(0,1,n);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&bb,&opt,&x);
		if(opt==1)
		{
			scanf("%d",&y);
			root[i]=update(root[bb],1,n,x,y);
		}
		if(opt==2)
		{
			printf("%d\n",chaxun(root[bb],1,n,x));
			root[i]=root[bb];
		}
	}
	return 0;
}