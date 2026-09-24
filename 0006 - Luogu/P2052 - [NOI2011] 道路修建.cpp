#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e6+10;
bool vis[maxn];
int sum[maxn],n;
long long ans;
struct node
{
	int to,val;
};
vector<node>ed[maxn<<1];
void dfs(int u)
{
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i].to;
		if(vis[v])continue;
		vis[v]=1;
		dfs(v);
		sum[u]+=sum[v];
		int k=abs(n-sum[v]-sum[v]);
		ans+=ed[u][i].val*k;
	}
}
signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<n;i++)
	{
		int x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		ed[x].push_back((node){y,z});
		ed[y].push_back((node){x,z});
	}
	for(int i=1;i<=n;i++)
	{
		sum[i]=1;
	}
	vis[1]=1;
	dfs(1);
	printf("%lld",ans);
	return 0;
}