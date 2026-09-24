#include<bits/stdc++.h>
using namespace std;
#define int long long 
int inline rid()
{
	int ans=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){ans=ans*10+ch-'0';ch=getchar();}
	return ans*f;
}
const int mod=998244353,inv=499122177,N=1<<18;
int add(int x,int y){return (x+=y)>=mod?x-mod:x;}
int n,m,f[N],g[N],t[N],s[N];
void build(int u,int l,int r)
{
	t[u]=1;if(l==r)return;int mid=(l+r)>>1;
	build(u<<1,l,mid);build(u<<1|1,mid+1,r);
}
void xg(int u,int x){g[u]=(g[u]*x+1-x+mod)%mod;t[u]=t[u]*x%mod;}
void pdn(int u){xg(u<<1,t[u]);xg(u<<1|1,t[u]);t[u]=1;} 
void up(int u,int op)
{
	if(op)s[u]=f[u];
	else s[u]=add(f[u],add(s[u<<1],s[u<<1|1]));
}
void update(int u,int l,int r,int cl,int cr)
{
	if(r<cl||cr<l)
	{
		f[u]=(f[u]+g[u])*inv%mod;
		up(u,l==r);return;
	}
	if(cl<=l&&r<=cr)
	{
		f[u]=(f[u]+1)*inv%mod;
		up(u,l==r);xg(u,inv);return;
	}
	pdn(u);
	f[u]=f[u]*inv%mod;g[u]=g[u]*inv%mod;
	int mid=(l+r)>>1;
	update(u<<1,l,mid,cl,cr);
	update(u<<1|1,mid+1,r,cl,cr);
	up(u,0);
}
signed main()
{
	n=rid(),m=rid();
	build(1,1,n);int sz=1;
	for(int i=1;i<=m;i++)
	{
		int op=rid();
		if(op==1)
		{
			int l=rid(),r=rid();
			update(1,1,n,l,r);sz=add(sz,sz);
		}
		else printf("%lld\n",sz*s[1]%mod);
	}
	return 0;
} 