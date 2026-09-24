#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
const double eps=1e-8;
double ans,h[maxn],a[maxn];
int dep[maxn];
struct node
{
	int to;
	double val;
};
vector<node>ed[maxn<<1];
void dfs(int u)
{
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i].to;
		if(dep[v])continue;
		dep[v]=dep[u]+1;
		dfs(v);
		double k=h[v]*ed[u][i].val;
		h[u]=h[u]+k-h[u]*k;
	}
}
void redfs(int u)
{
	ans+=h[u];
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i].to;
		if(dep[u]>=dep[v])continue;
		if(fabs(h[v]*ed[u][i].val-1)<eps)
		{
			redfs(v);
			continue;
		}
		double pb=h[v]*ed[u][i].val;
		double k=(h[u]-pb)/(1-pb)*ed[u][i].val;
		h[v]=h[v]+k-h[v]*k;
		redfs(v);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int x,y;
		double z;
		scanf("%d%d%lf",&x,&y,&z);
		z/=100;
		ed[x].push_back((node){y,z});
		ed[y].push_back((node){x,z});
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lf",&h[i]);
		h[i]/=100;
	}
	dep[1]=1;
	dfs(1);
	redfs(1);
	printf("%.6lf",ans);
	return 0;
}