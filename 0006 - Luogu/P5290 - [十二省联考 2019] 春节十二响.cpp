#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
vector<int>ed[maxn],tmp;
int a[maxn],k,n;
priority_queue<int> q[maxn];
void hb(int x,int y)
{
	if(q[x].size()<q[y].size())swap(q[x],q[y]);
	while(q[y].size())
	{
		tmp.push_back(max(q[x].top(),q[y].top()));
		q[x].pop();q[y].pop();
	}
	while(tmp.size())
	{
		q[x].push(tmp.back());
		tmp.pop_back();
	}
}
void dfs(int u)
{
	for(int i=0;i<ed[u].size();i++)
	{
		dfs(ed[u][i]);
		hb(u,ed[u][i]);
	}
	q[u].push(a[u]);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&k);
		ed[k].push_back(i);
	}
	dfs(1);
	long long ans=0;
	while(q[1].size())
	{
		ans+=q[1].top();
		q[1].pop();
	}
	printf("%lld",ans);
	return 0;
}