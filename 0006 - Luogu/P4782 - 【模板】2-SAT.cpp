#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+1000;
int dfn[maxn],cnm[maxn],low[maxn],co[maxn],sta[maxn];
vector<int> a[maxn];
int top,num,col;
void tarjan(int u)
{
	dfn[u]=low[u]=++num;
	sta[++top]=u;
	for(int i=0;i<a[u].size();i++)
	{
		int v=a[u][i];
		if(!dfn[v])
		{
			tarjan(v);
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
		++cnm[col];
		while(sta[top]!=u)
		{
			++cnm[col];
			co[sta[top]]=col;
			top--;
		}
		top--;
	}
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,tx,y,ty;
		scanf("%d%d%d%d",&x,&tx,&y,&ty);
		a[x+n*tx].push_back(y+n*(ty^1));
		a[y+n*ty].push_back(x+n*(tx^1));
	}
	for(int i=1;i<=2*n;i++)
	{
		if(!dfn[i])
		{
			tarjan(i);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(co[i]==co[i+n])
		{
			printf("IMPOSSIBLE\n");
			return 0;
		}
	}
	printf("POSSIBLE\n");
	for(int i=1;i<=n;i++)
	{
		if(co[i]<co[i+n])
		{
			printf("1 ");
		}
		else
		{
			printf("0 ");
		}
	}
	return 0;
}