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
		while(l<q[i].l)del(l++);
		while(l>q[i].l)add(--l);
		while(r<q[i].r)add(++r);
		while(r>q[i].r)del(r--);
		if(opt==1)ans[id]=(s1&(s1<<x)).any();
		else if(opt==2)ans[id]=(s2&(s1<<(N-x))).any();
		else
		{
			for(int j=1;j*j<=x;j++)
				if(!(x%j))
					if(s1[j]&&s1[x/j]){ans[id]=1;break;}
		}
	}
	for(int i=1;i<=m;i++)
	{
		puts(ans[i]?"hana":"bi");
	}
	return 0;
}