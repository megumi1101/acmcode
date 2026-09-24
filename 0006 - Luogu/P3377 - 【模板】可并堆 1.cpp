#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,m,opt,x,y;
int ls[maxn],rs[maxn],dis[maxn],fa[maxn];
bool de[maxn];
int find(int x)
{
	if(x==fa[x])return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
struct node
{
	int id,v;
	friend bool operator<(node a,node b)
	{
		if(a.v==b.v)
		{
			return a.id<b.id;
		}
		return a.v<b.v;
	}
}v[maxn];
int hb(int x,int y)
{
	if(!x||!y)return x+y;
	if(v[y]<v[x])
	{
		swap(x,y);
	}
	rs[x]=hb(rs[x],y);
	if(dis[ls[x]]<dis[rs[x]])
	{
		swap(ls[x],rs[x]);
	}
	dis[x]=dis[rs[x]]+1;
	return x;
}
int main()
{
	dis[0]=-1;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&v[i].v);
		fa[i]=i;
		v[i].id=i;
	}
	while(m--)
	{
		scanf("%d%d",&opt,&x);
		if(opt==1)
		{
			scanf("%d",&y);
			if(de[x]||de[y])continue;
			x=find(x);
			y=find(y);
			if(x!=y)
			{
				fa[x]=fa[y]=hb(x,y);
			}
		}
		else
		{
			if(de[x])
			{
				printf("-1\n");
				continue;
			}
			x=find(x);
			de[x]=1;
			printf("%d\n",v[x].v);
			fa[ls[x]]=fa[rs[x]]=fa[x]=hb(ls[x],rs[x]);
			ls[x]=rs[x]=dis[x]=0;
		}
	}
	return 0;
}