#include<bits/stdc++.h>
using namespace std;
int inline rd()
{
	int ans=0,f=1;char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		ans=ans*10+ch-'0';
		ch=getchar();
	}
	return ans*f;
}
const int N=1e5+10;
int n,m,a[N],bl,a1[N],a2[N];
int c1[N],c2[N],cnt[N],hs[N];
int lb(int x)
{
	return x&-x;
}
void add1(int p,int x)
{
	for(;p<=n;p+=lb(p))c1[p]+=x;
}
void add2(int p,int x)
{
	for(;p<=n;p+=lb(p))c2[p]+=x;
}
int cx1(int p)
{
	int res=0;
	for(;p;p-=lb(p))res+=c1[p];
	return res;
}
int cx2(int p)
{
	int res=0;
	for(;p;p-=lb(p))res+=c2[p];
	return res;
}
void add(int x)
{
	x=a[x];
	if(!cnt[x])add2(x,1);
	add1(x,1);cnt[x]++;
}
void del(int x)
{
	x=a[x];
	add1(x,-1);cnt[x]--;
	if(!cnt[x])add2(x,-1);
}
struct node
{
	int l,r,a,b,id;
	friend bool operator<(node a,node b)
	{
		if(hs[a.l]==hs[b.l])return a.r<b.r;
		return hs[a.l]<hs[b.l];
	}
}q[N];
int main()
{
	n=rd();m=rd();bl=sqrt(n);
	for(int i=1;i<=n;i++)hs[i]=(i-1)/bl+1,a[i]=rd();
	for(int i=1;i<=m;i++)q[i]=(node){rd(),rd(),rd(),rd(),i};
	sort(q+1,q+1+m);
	int l=1,r=0;
    for(int i=1;i<=m;i++)
    {
    	int id=q[i].id,a=q[i].a,b=q[i].b;
		while(l<q[i].l)del(l++);
    	while(l>q[i].l)add(--l);
    	while(r<q[i].r)add(++r);
    	while(r>q[i].r)del(r--);
    	a1[id]=cx1(b)-cx1(a-1);
    	a2[id]=cx2(b)-cx2(a-1);
	}
	for(int i=1;i<=m;i++)
		printf("%d %d\n",a1[i],a2[i]);
	return 0;
}