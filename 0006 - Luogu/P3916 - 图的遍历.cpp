#include<bits/stdc++.h>
using namespace std;
int n,m,a[101010];
vector<int> ve[101010];
void dfs(int x,int d)
{
	if(a[x])return;
	a[x]=d;
	for(int i=0;i<ve[x].size();i++)
	{
		dfs(ve[x][i],d);
	}
}
int main()
{
	memset(a,0,sizeof(a));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		ve[v].push_back(u);
	}
	for(int i=n;i>=1;i--)
	{
		dfs(i,i);
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}