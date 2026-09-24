#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=3e5+10;
int cnt,siz,n,m,q,pos,rt[maxn],ls[maxn*40],rs[maxn*40],sm[maxn*40];
vector<int>ed[maxn];
int cx(int u,int l,int r,int val)
{
	if(l==r)return l;
	int mid=(l+r)>>1;
	int tmp=mid-l+1-sm[ls[u]];
	if(val<=tmp)return cx(ls[u],l,mid,val);
	return cx(rs[u],mid+1,r,val-tmp);
}
void updt(int &u,int l,int r,int p)
{
	if(!u)u=++cnt;sm[u]++;
	if(l==r) return;
	int mid=(l+r)>>1;
	if(p<=mid)updt(ls[u],l,mid,p);
	else updt(rs[u],mid+1,r,p);
}
int wk1(int x,int y)
{
	pos=cx(rt[n+1],1,siz,x);
	updt(rt[n+1],1,siz,pos);
	int ans=pos<=n?pos*m:ed[n+1][pos-n-1];
	ed[n+1].push_back(y?y:ans);
	return ans;
}
int wk2(int x,int y)
{
	pos=cx(rt[x],1,siz,y);
	updt(rt[x],1,siz,pos);
	int ans=pos<m?(x-1)*m+pos:ed[x][pos-m];
	ed[x].push_back(wk1(x,ans));
	return ans;
}
signed main()
{
	scanf("%lld%lld%lld",&n,&m,&q);
	siz=max(n,m)+q;
	while(q--)
	{
		int x,y;
		scanf("%lld%lld",&x,&y);
		if(y==m)printf("%lld\n",wk1(x,0));
		else printf("%lld\n",wk2(x,y));
	}
}