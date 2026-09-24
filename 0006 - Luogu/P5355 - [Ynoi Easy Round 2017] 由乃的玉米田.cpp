#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
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
bitset<N+5>s1,s2;
int n,m,ans[N],a[N],hs[N],cnt[N],bl;
struct node
{
	int opt,l,r,x,id;
	friend bool operator<(node a,node b)
	{
		if(hs[a.l]==hs[b.l])return a.r<b.r;
		return hs[a.l]<hs[b.l];
	}
}q[N];
void add(int x)
{
	x=a[x];
	if(!cnt[x])s1[x]=1,s2[N-x]=1;
	cnt[x]++;
}
void del(int x)
{
	x=a[x];cnt[x]--;
	if(!cnt[x])s1[x]=s2[N-x]=0;
}
vector<int>ed[N];
int pre[N],mxl[N];
void sol()
{
	for(int x=1;x<=bl;x++)
	{
		if(!ed[x].size())continue;
		int l=0;
		for(int i=1;i<=n;i++)
		{
			int y=a[i];
			pre[y]=i;
			if(x*y<=1e5)l=max(l,pre[x*y]);
			if(y%x==0)l=max(l,pre[y/x]);
			mxl[i]=l;
		}
		for(int i=0;i<ed[x].size();i++)
		{
			int v=ed[x][i];int id=q[v].id;
			ans[id]=(q[v].l<=mxl[q[v].r]);
		}
		memset(pre,0,sizeof(pre));
		memset(mxl,0,sizeof(mxl));
	}
}
int main()
{
	n=rd();m=rd();
	bl=sqrt(n);
	for(int i=1;i<=n;i++)hs[i]=(i-1)/bl+1,a[i]=rd();
	for(int i=1;i<=m;i++)q[i]=(node){rd(),rd(),rd(),rd(),i};
	int l=1,r=0;
	sort(q+1,q+1+m);
	for(int i=1;i<=m;i++)
	{
		int opt=q[i].opt,id=q[i].id,x=q[i].x;
		if(opt==4&&x<=bl){ed[x].push_back(i);continue;}
		while(l<q[i].l)del(l++);
		while(l>q[i].l)add(--l);
		while(r<q[i].r)add(++r);
		while(r>q[i].r)del(r--);
		if(opt==1)ans[id]=(s1&(s1<<x)).any();
		else if(opt==2)ans[id]=(s2&(s1<<(N-x))).any();
		else if(opt==3)
		{
			for(int j=1;j*j<=x;j++)
				if(!(x%j))
					if(s1[j]&&s1[x/j]){ans[id]=1;break;}
		}
		else
		{
			for(int i=1;i*x<=1e5;i++)
				if(s1[i]&&s1[i*x]){ans[id]=1;break;}
		}
	}
	sol();
	for(int i=1;i<=m;i++)
	{
		puts(ans[i]?"yuno":"yumi");
	}
	return 0;
}