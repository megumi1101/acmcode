#include<bits/stdc++.h>
using namespace std;
int n,m,num=0,top=0,uu=0,ans=0,tot=0;
int to[50505],head[11000],nex[50505];
int dfn[50505],low[50505],sta[50505];
int col,si[50505],co[50505],de[50505];
void add(int x,int y)
{
	to[++tot]=y;
	nex[tot]=head[x];
	head[x]=tot;
}
void tar(int u)
{
	dfn[u]=low[u]=++num;
	sta[++top]=u;
	for(int i=head[u];~i;i=nex[i])
	{
		int v=to[i];
		if(!dfn[v])
		{
			tar(v);
			low[u]=min(low[u],low[v]);
		}
		else if(!co[v])
		{
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(low[u]==dfn[u])
	{
		co[u]=++col;
		++si[col];
		while(sta[top]!=u)
		{
			++si[col];
			co[sta[top]]=col;
			--top;
		}
		--top;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		head[i]=-1;
	}
	for(int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
	}
	for(int i=1;i<=n;i++)
	{
		if(!dfn[i])
		{
			tar(i);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=head[i];~j;j=nex[j])
		{
			if(co[i]!=co[to[j]])
			{
				de[co[i]]++;
			}
		}
	}
	for(int i=1;i<=col;i++)
	{
		if(!de[i])
		{
			uu++;
			ans=si[i];
		}
	}
	if(uu==1)
	{
		printf("%d",ans);
	}
	else
	{
		printf("0");
	}
	return 0;
}