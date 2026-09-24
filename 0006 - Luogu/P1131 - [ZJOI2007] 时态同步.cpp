#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+10;
int n,s,ans;
int sum[maxn],dd[maxn];
bool vis[maxn];
struct node
{
	int to,val;
};
vector<node>ed[maxn<<1];
void dfs(int u)
{
	vis[u]=1;
	int mx=-1;
	int cnt=0;
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i].to;
		if(vis[v])continue;
		cnt++;
		dfs(v);
		dd[v]+=ed[u][i].val;
		sum[u]+=dd[v];
		mx=max(mx,dd[v]);
	}
	ans+=mx*cnt-sum[u];
	dd[u]+=mx;
}
signed main()
{
	scanf("%lld%lld",&n,&s);
	for(int i=1;i<n;i++)
	{
		int x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		ed[x].push_back((node){y,z});
		ed[y].push_back((node){x,z});
	}
	dfs(s);
	printf("%lld",ans);
	return 0;
}