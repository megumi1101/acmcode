#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[10101100],s[10110100],x,z,ans;
char k[10];
struct node
{
	ll l,r,pre,num;
}tr[44444444];
void pushup(ll bh)
{
	tr[bh].num=tr[bh<<1].num+tr[bh<<1|1].num;
}
void build(ll l,ll r,ll bh)
{
	tr[bh].l=l;
	tr[bh].r=r;
	if(l==r)
	{
		tr[bh].num=s[l];
		return;
	}
	ll mid=l+r>>1;
	build(l,mid,bh<<1);
	build(mid+1,r,bh<<1|1);
	pushup(bh);
}
void pushdown(ll bh)
{
	tr[bh<<1].num+=tr[bh].pre*(tr[bh<<1].r-tr[bh<<1].l+1);
	tr[bh<<1|1].num+=tr[bh].pre*(tr[bh<<1|1].r-tr[bh<<1|1].l+1);
	tr[bh<<1].pre+=tr[bh].pre;
	tr[bh<<1|1].pre+=tr[bh].pre;
	tr[bh].pre=0;
}
void change(ll l,ll r,ll k,ll bh)
{
	if(l<=tr[bh].l&&r>=tr[bh].r)
	{
		pushdown(bh);
		tr[bh].pre+=k;
		tr[bh].num+=tr[bh].pre*(tr[bh].r-tr[bh].l+1);
		return;
	}
	pushdown(bh);
	if(l<=tr[bh<<1].r)
	{
		change(l,r,k,bh<<1);
	}
	if(r>=tr[bh<<1+1].l)
	{
		change(l,r,k,bh<<1|1);
	}
	pushup(bh);
}
ll sum(ll l,ll r,ll bh)
{
	if(l<=tr[bh].l&&r>=tr[bh].r)
	{
		return tr[bh].num;
	}
	pushdown(bh);
	ll ans=0;
	if(l<=tr[bh<<1].r)
	{
		ans+=sum(l,r,bh<<1);
	}
	if(r>=tr[bh<<1|1].l)
	{
		ans+=sum(l,r,bh<<1|1);
	}
	return ans;
}
int main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
	}
	build(1,n,1);
	for(int i=1;i<=m;i++)
	{
		scanf("%s",k);
		if(k[0]=='Q')
		{
			scanf("%lld",&x);
			printf("%lld\n",sum(1,x,1));
		}
		else
		{
			scanf("%lld%lld",&x,&z);
			change(x,n,z-a[x],1);
			a[x]=z;
		}
	}
	return 0;
}