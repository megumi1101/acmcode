#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int top;
int rt[maxn],a[maxn];
int ls[maxn<<5],rs[maxn<<5],sum[maxn<<5];
void update(int p,int &u,int l,int r,int x)
{
	u=++top;
	ls[u]=ls[p];rs[u]=rs[p];sum[u]=sum[p];
	if(l==r){sum[u]=sum[p]+1;return;}
	int mid=(l+r)>>1;
	if(x<=mid) update(ls[p],ls[u],l,mid,x);
	else update(rs[p],rs[u],mid+1,r,x);
	sum[u]=sum[ls[u]]+sum[rs[u]];
}
int cx(int u,int v,int l,int r,int cl,int cr)
{
	
	if(cl<=l&&r<=cr)return sum[v]-sum[u];
	if(cl>r||cr<l)return 0;
	int mid=(l+r)>>1;
	if(cl>mid)return cx(rs[u],rs[v],mid+1,r,cl,cr);
	else if(cr<=mid)return cx(ls[u],ls[v],l,mid,cl,cr);
	else return cx(ls[u],ls[v],l,mid,cl,cr)+cx(rs[u],rs[v],mid+1,r,cl,cr);
}
int main()
{
	int n,m=0,q;
	scanf("%d%d",&n,&q);
	rt[0]=1,top++;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),m=max(m,a[i]);
	for(int i=1;i<=n;i++)update(rt[i-1],rt[i],0,m,a[i]);
	while(q--)
	{
		int b,x,l,r,ans=0;
		scanf("%d%d%d%d",&b,&x,&l,&r);
		for(int i=18;i>=0;i--)
		{
			if(b&(1<<i)&&!cx(rt[l-1],rt[r],0,m,ans-x,ans-x+(1<<i)-1)) ans+=(1<<i);
            if(!(b&(1<<i))&&cx(rt[l-1],rt[r],0,m,ans-x+(1<<i),ans-x+(1<<(i+1))-1)) ans+=(1<<i);
		}
		printf("%d\n",ans^b);
	}
	return 0;
}