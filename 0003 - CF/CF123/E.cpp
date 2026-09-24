#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,siz[maxn];
double s[maxn],t[maxn],S,ans,T;
vector<int>ed[maxn];
void dfs(int u,int fa)
{
	siz[u]=1;
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i];
		if(v==fa)continue;
		dfs(v,u);
		siz[u]+=siz[v];
		s[u]+=s[v];
		ans+=t[u]*s[v]*siz[v];
	}
	ans+=t[u]*(S-s[u])*(n-siz[u]);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		ed[x].push_back(y);
		ed[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lf%lf",&s[i],&t[i]);S+=s[i];T+=t[i];
	}
	dfs(1,0);
	printf("%.9lf",ans/S/T);
	return 0;
}
/*
3
1 2
1 3
1 0
0 2
0 3
*/
