#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,p,a[11111111];
struct node
{
	ll num,prej,prec;
	ll l,r;
}t[44444444];


void build(ll l,ll r,ll bh)
{
	t[bh].l=l;
	t[bh].r=r;
	t[bh].prec=1;
	if(l==r)
	{
		t[bh].num=a[r]%p;
		return;
	}	
		ll mid=(l+r)/2;
		build(l,mid,bh*2);
		build(mid+1,r,bh*2+1);
		t[bh].num=(t[bh*2].num+t[bh*2+1].num)%p;
}


void push(ll bh)
{
	t[bh*2].num=(t[bh].prec*t[bh*2].num+(t[bh].prej*(t[bh*2].r-t[bh*2].l+1))%p)%p;
		t[bh*2+1].num=(t[bh].prec*t[bh*2+1].num+(t[bh].prej*(t[bh*2+1].r-t[bh*2+1].l+1))%p)%p;	
				
		t[bh*2].prec=(t[bh].prec*t[bh*2].prec)%p;
		t[bh*2+1].prec=(t[bh].prec*t[bh*2+1].prec)%p;
		
		t[bh*2].prej=(t[bh*2].prej*t[bh].prec+t[bh].prej)%p;
		t[bh*2+1].prej=(t[bh*2+1].prej*t[bh].prec+t[bh].prej)%p;
		
		t[bh].prec=1;
		t[bh].prej=0;
}


void changej(ll l,ll r,ll k,ll bh)
{
	if(l<=t[bh].l&&r>=t[bh].r)
	{
		push(bh);
		t[bh].prej=(k+t[bh].prej)%p;
		t[bh].num=(t[bh].num+k*(t[bh].r-t[bh].l+1))%p;
		return;
	}		
		push(bh);
		t[bh].num=(t[bh*2].num+t[bh*2+1].num)%p;
		if(l<=t[bh*2].r)
		{
			changej(l,r,k,bh*2);
		}
		if(r>=t[bh*2+1].l)
		{
			changej(l,r,k,bh*2+1);
		}
		t[bh].num=(t[bh*2].num+t[bh*2+1].num)%p;
}


void changec(ll l,ll r,ll k,ll bh)
{
	if(l<=t[bh].l&&r>=t[bh].r)
	{
		push(bh);
		t[bh].prec=(t[bh].prec*k)%p;
		t[bh].num=(t[bh].num*k)%p;
		return;
	}
		push(bh);
		t[bh].num=t[bh*2].num+t[bh*2+1].num;
		if(l<=t[bh*2].r)
		{
			changec(l,r,k,bh*2);
		}
		if(r>=t[bh*2+1].l)
		{
			changec(l,r,k,bh*2+1);
		}
		t[bh].num=(t[bh*2].num+t[bh*2+1].num)%p;
}


ll sum(ll l,ll r,ll bh)
{
	if(l<=t[bh].l&&r>=t[bh].r)
	{
		return t[bh].num;
	}		
		push(bh);
		ll ans=0;
		if(l<=t[bh*2].r)
		{
			ans=(ans+sum(l,r,bh*2))%p;
		}
		if(r>=t[bh*2+1].l)
		{
			ans=(ans+sum(l,r,bh*2+1))%p;
		}
		return ans;
}


int main()
{
	scanf("%lld%lld%lld",&n,&m,&p);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	build(1,n,1);
	for(int i=1;i<=m;i++)
	{
		ll q,x,y,z;
		scanf("%lld",&q);
		if(q==1)
		{
			scanf("%lld%lld%lld",&x,&y,&z);
			changec(x,y,z,1);
		}
		if(q==2)
		{
			scanf("%lld%lld%lld",&x,&y,&z);	
			changej(x,y,z,1);	
		}
		if(q==3)
		{
			scanf("%lld%lld",&x,&y);
			printf("%lld\n",sum(x,y,1));
		}
	}
	return 0;
}

