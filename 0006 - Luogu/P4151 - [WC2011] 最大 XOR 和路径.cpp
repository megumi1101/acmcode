#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+10;
int n,m;
int p[70],yh[maxn];
bool vis[maxn];
struct node
{
	int to,w;
};
vector<node>ed[maxn<<1];
void ins(int x)
{
	for(int i=62;i>=0;i--)
	{
		if(x&(1LL<<i))
		{
			if(!p[i])
			{
				p[i]=x;
				break;
			}
			else x^=p[i];
		}
	}
}
int qmax(int res)
{
	for(int i=62;i>=0;i--)
	{
		res=max(res,res^p[i]);
	}
	return res;
}
void dfs(int u,int res)
{
	yh[u]=res;
	vis[u]=1;
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i].to;
		int w=ed[u][i].w;
		if(!vis[v]) dfs(v,res^w);
		else ins(res^w^yh[v]);
	}
}
signed main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		ed[x].push_back((node){y,z});
		ed[y].push_back((node){x,z});
	}
	dfs(1,0);
	printf("%lld",qmax(yh[n]));
}