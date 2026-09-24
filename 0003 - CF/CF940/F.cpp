#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
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
int n,m,a[N],b[N],bl,hs[N],cnt[N],tot[N];
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
int num[N],pos[N],tim,top,ans[N],sz,ct;
void add(int x)
{
	x=a[x];--tot[cnt[x]];
	++tot[++cnt[x]];
}
void del(int x)
{
	x=a[x];--tot[cnt[x]];
	++tot[--cnt[x]];
}
void wk(int x,int i)
{
	if(pos[x]>=q[i].l&&pos[x]<=q[i].r)
	{
		del(pos[x]);
		--tot[cnt[num[x]]];++tot[++cnt[num[x]]];
	}
	swap(num[x],a[pos[x]]);
}
int main()
{
	n=rd(),m=rd();
	bl=pow(n,0.66666666);
	for(int i=1;i<=n;i++)hs[i]=(i-1)/bl+1,a[i]=rd(),b[++ct]=a[i];
	for(int i=1;i<=m;i++)
	{
		int opt;scanf("%d",&opt);
		if(opt==2)++tim,pos[tim]=rd(),b[++ct]=num[tim]=rd();
		else ++top,q[top]=(node){rd(),rd(),tim,top};
	}
	sort(b+1,b+1+ct);
	sz=unique(b+1,b+1+ct)-b-1;
	for(int i=1;i<=n;i++)a[i]=lower_bound(b+1,b+1+ct,a[i])-b;
	for(int i=1;i<=tim;i++)num[i]=lower_bound(b+1,b+1+ct,num[i])-b;
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
		for(int j=1;j<=n;j++)if(!tot[j]){ans[q[i].id]=j;break;}
	}
	for(int i=1;i<=top;i++)printf("%d\n",ans[i]);
	return 0;
}
