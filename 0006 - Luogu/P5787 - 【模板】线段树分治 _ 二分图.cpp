#include<bits/stdc++.h>
#define maxn 1010100
using namespace std;
struct node
{
	int x,y;
}ed[maxn];
struct noo
{
	int x,y,ad;
}st[maxn];
int n,m,k;
vector<int> t[maxn];
int fa[maxn],hig[maxn],top;
int find(int x)
{
	if(x==fa[x])return x;
	return find(fa[x]);
}
void hb(int x,int y)
{
	int fx=find(x);
	int fy=find(y);
	if(hig[fx]>hig[fy])swap(fx,fy);
	fa[fx]=fy;
	st[++top]=(noo){fx,fy,hig[fx]==hig[fy]};
	if(hig[fx]==hig[fy])hig[fy]++;
}
void update(int u,int ll,int rr,int l,int r,int x)
{
	if(l>rr||r<ll)return;
	if(l<=ll&&r>=rr)
	{
		t[u].push_back(x);
		return;
	}
	int mid=(ll+rr)>>1;
	update(u<<1,ll,mid,l,r,x);
	update(u<<1|1,mid+1,rr,l,r,x);
}
void solve(int u,int l,int r)
{
	int ans=1;
	int tt=top;
	for(int i=0;i<t[u].size();i++)
	{
		int a=find(ed[t[u][i]].x);
		int b=find(ed[t[u][i]].y);
		if(a==b)
		{
			for(int j=l;j<=r;j++)
			{
				printf("No\n");
			}
			ans=0;
			break;
		}
		hb(ed[t[u][i]].x,ed[t[u][i]].y+n);
		hb(ed[t[u][i]].y,ed[t[u][i]].x+n);
	}
	if(ans)
	{
		if(l==r)printf("Yes\n");
		else
		{
			int mid=(l+r)>>1;
			solve(u<<1,l,mid);
			solve(u<<1|1,mid+1,r);
		}
	}
	while(top>tt)
	{
		hig[fa[st[top].x]]-=st[top].ad;
		fa[st[top].x]=st[top].x;
		top--;
	}
	return;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=2*n;i++)
	{
		fa[i]=i;
		hig[i]=1;
	}
	for(int i=1;i<=m;i++)
	{
		int l,r;
		scanf("%d%d%d%d",&ed[i].x,&ed[i].y,&l,&r);
		l++;
		update(1,1,k,l,r,i);
	}
	solve(1,1,k);
	return 0;
}