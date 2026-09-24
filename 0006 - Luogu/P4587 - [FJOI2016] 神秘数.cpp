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
	if(l==r){sum[u]=sum[p]+x;return;}
	int mid=(l+r)>>1;
	if(x<=mid) update(ls[p],ls[u],l,mid,x);
	else update(rs[p],rs[u],mid+1,r,x);
	sum[u]=sum[ls[u]]+sum[rs[u]];
}
int cx(int u,int v,int l,int r,int cl,int cr)
{
	if(cl<=l&&r<=cr)return sum[v]-sum[u];
	int mid=(l+r)>>1;
	if(cl>mid)return cx(rs[u],rs[v],mid+1,r,cl,cr);
	else if(cr<=mid)return cx(ls[u],ls[v],l,mid,cl,cr);
	else return cx(ls[u],ls[v],l,mid,cl,cr)+cx(rs[u],rs[v],mid+1,r,cl,cr);
}
int main()
{
	int n,m=1e9,q;
	scanf("%d",&n);
	rt[0]=1,top++;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)update(rt[i-1],rt[i],0,m,a[i]);
	scanf("%d",&q);
	while(q--)
	{
		int l,r,ans=1;
		scanf("%d%d",&l,&r);
		while(1)
		{
			int res=cx(rt[l-1],rt[r],0,m,1,ans);
			if(res>=ans)ans=res+1;
			else break;
		}
		printf("%d\n",ans);
	}
	return 0;
}