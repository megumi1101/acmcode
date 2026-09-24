#include<bits/stdc++.h>
using namespace std;
int n,m;
const int maxn=1e7+10;
struct node
{
	int ml,mr,mv,sum;
}t[maxn];
void pushup(int u)
{
	t[u].mv=max(max(t[u<<1].mv,t[u<<1|1].mv),t[u<<1].mr+t[u<<1|1].ml);
	t[u].ml=max(t[u<<1].ml,t[u<<1].sum+t[u<<1|1].ml);
	t[u].mr=max(t[u<<1|1].mr,t[u<<1|1].sum+t[u<<1].mr);
	t[u].sum=t[u<<1].sum+t[u<<1|1].sum;
	//printf("t[%d].mv=%d\n",u,t[u].mv);
}
void build(int u,int l,int r)
{
	if(l==r)
	{
		scanf("%d",&t[u].mv);
		t[u].ml=t[u].mr=t[u].sum=t[u].mv;
		return;
	}
	int mid=(l+r)>>1;
	build(u<<1,l,mid);
	build(u<<1|1,mid+1,r);
	pushup(u);
}
void update(int u,int l,int r,int p,int val)
{
	if(l==r)
	{
		t[u].ml=t[u].mr=t[u].sum=t[u].mv=val;
		return;
	}
	int mid=(l+r)>>1;
	if(p<=mid)update(u<<1,l,mid,p,val);
	else update(u<<1|1,mid+1,r,p,val);
	pushup(u);
}
node cx(int u,int l,int r,int cl,int cr)
{
	if(cl<=l&&r<=cr)
	{
		return t[u];
	}
	int mid=(l+r)>>1;
	if(cr<=mid)return cx(u<<1,l,mid,cl,cr);
	else if(cl>mid)return cx(u<<1|1,mid+1,r,cl,cr);
	else
	{
		node tt;
		node a=cx(u<<1,l,mid,cl,cr);
		node b=cx(u<<1|1,mid+1,r,cl,cr);
		tt.mv=max(max(a.mv,b.mv),a.mr+b.ml);
		tt.ml=max(a.ml,a.sum+b.ml);
		tt.mr=max(b.mr,b.sum+a.mr);
		tt.sum=a.sum+b.sum;
		return tt;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	build(1,1,n);
	while(m--)
	{
		int k,x,y;
		scanf("%d%d%d",&k,&x,&y);
		if(k==1)
		{
			if(x>y)swap(x,y);
			printf("%d\n",cx(1,1,n,x,y).mv);
		}
		else update(1,1,n,x,y);
	}
	return 0;
}