#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int inline rd()
{
	int ans=0,f=1;
	char ch=getchar();
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
int n,m,a[N],bl,hs[N],cnt[N];
struct node
{
	int l,r,t,id;
	friend bool operator<(node a,node b)
	{
		if(hs[a.l]!=hs[b.l])return a.l<b.l;
		if(hs[a.r]!=hs[b.r])return a.r<b.r;
		return a.t<b.t;
	}
}q[N];
int pos[N],num[N],sum,tim,top,ans[N];
void add(int x)
{
	x=a[x];++cnt[x];
	if(cnt[x]==1)sum++;
}
void del(int x)
{
	x=a[x];--cnt[x];
	if(!cnt[x])sum--;
}
void wk(int x,int i)
{
	if(pos[x]>=q[i].l&&pos[x]<=q[i].r)
	{
		if(--cnt[a[pos[x]]]==0)sum--;
		if(++cnt[num[x]]==1)sum++;
	}
	swap(num[x],a[pos[x]]);
}
int main()
{
	n=rd(),m=rd();
	bl=pow(n,0.66666666);
	for(int i=1;i<=n;i++)hs[i]=(i-1)/bl+1,a[i]=rd();
	for(int i=1;i<=m;i++)
	{
		char s[2];scanf("%s",s);
		if(s[0]=='R')++tim,pos[tim]=rd(),num[tim]=rd();
		else ++top,q[top]=(node){rd(),rd(),tim,top};
	}
	sort(q+1,q+1+top);
	int l=1,r=0,t=0;
	for(int i=1;i<=top;i++)
	{
		while(l<q[i].l)del(l++);
		while(l>q[i].l)add(--l);
		while(r<q[i].r)add(++r);
		while(r>q[i].r)del(r--);
		while(t<q[i].t)wk(++t,i);
		while(t>q[i].t)wk(t--,i);
		ans[q[i].id]=sum;
	}
	for(int i=1;i<=top;i++)printf("%d\n",ans[i]);
	return 0;
}