#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e4+10;
int n,m,fz,fm,has[maxn],c[maxn];
struct node
{
	int l,r,q,id;
}b[maxn];
struct qq
{
	int x1,x2;
}ans[maxn];
bool cmp(node a,node b)
{
	if(a.q==b.q)
	{
		if(a.q&1)return a.r<b.r;
		else return a.r>b.r;
	}
	return a.q<b.q;
}
int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
void add(int x)
{
	fz+=2*has[c[x]];
	has[c[x]]++;
}
void del(int x)
{
	fz-=2*(has[c[x]]-1);
	has[c[x]]--;
}
signed main()
{
	scanf("%lld%lld",&n,&m);
	int ql=n/(int)sqrt(m);
	for(int i=1;i<=n;i++)scanf("%lld",&c[i]);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld",&b[i].l,&b[i].r);
		b[i].q=(b[i].l-1)/ql+1;
		b[i].id=i;	
	}
	sort(b+1,b+1+m,cmp);
	int l=1,r=0;
	for(int i=1;i<=m;i++)
	{
		if(b[i].l==b[i].r)
		{
			ans[b[i].id]=(qq){0,1};continue; 
		}
		while(b[i].l<l)add(--l);
		while(l<b[i].l)del(l++);
		while(b[i].r<r)del(r--);
		while(r<b[i].r)add(++r);
		fm=(r-l+1)*(r-l);
		int gg=gcd(fm,fz);
		ans[b[i].id]=(qq){fz/gg,fm/gg};
	}
	for(int i=1;i<=m;i++)
	{
		printf("%lld/%lld\n",ans[i].x1,ans[i].x2);
	}
	return 0;
}