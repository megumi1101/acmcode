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
int n,m,a[N],ans[N],lst[N],c[N];
bool vis[N];
struct node
{
	int l,r,id;
	friend bool operator<(node a,node b)
	{
		return a.r<b.r;
	}
}xx[N];
int lb(int x){return x&(-x);}
void add(int p,int x)
{
	for(;p<=n;p+=lb(p))c[p]+=x;
}
int cx(int p)
{
	int res=0;
	for(;p;p-=lb(p))res+=c[p];
	return res;
}
int main()
{
	n=rd();
	for(int i=1;i<=n;i++)a[i]=rd();
	m=rd();
	for(int i=1;i<=m;i++)xx[i].l=rd(),xx[i].r=rd(),xx[i].id=i;
	sort(xx+1,xx+1+m);
	for(int i=1;i<=m;i++)
	{
		if(xx[i].r!=xx[i-1].r)
		{
			for(int j=xx[i-1].r+1;j<=xx[i].r;j++)
			{
				if(!vis[a[j]])
				{
					vis[a[j]]=1;
					lst[a[j]]=j;
					add(j,1);
				}
				else
				{
					add(lst[a[j]],-1);
					lst[a[j]]=j;
					add(j,1);
				}
			}
		}
		ans[xx[i].id]=cx(xx[i].r)-cx(xx[i].l-1);
	}
	for(int i=1;i<=m;i++)
		printf("%d\n",ans[i]);
	return 0;
}