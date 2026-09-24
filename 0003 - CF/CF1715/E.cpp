// LUOGU_RID: 92452776
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define db double
const int inf=1e18+10,N=1e5+10;
int inline rid()
{
	int ans=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){ans=ans*10+ch-'0';ch=getchar();}
	return ans*f;
}
int n,m,k,f[N],q[N],dis[N];
struct node
{
	int to,val;
	friend bool operator<(node a,node b){return a.val>b.val;}
};
bool vis[N];
vector<node>ed[N];
priority_queue<node>pq;
void dij()
{
	for(int i=1;i<=n;i++)dis[i]=inf;
	memset(vis,0,sizeof(vis));
	dis[0]=0;
	pq.push((node){(int)0,(int)0});
	while(!pq.empty())
	{
		int u=pq.top().to;
		pq.pop();
		if(vis[u])continue;
		vis[u]=1;
		int siz=ed[u].size();
		for(int i=0;i<siz;i++)
		{
			int v=ed[u][i].to,w=ed[u][i].val;
			if(dis[u]+w<dis[v])
			{
				dis[v]=dis[u]+w;
				pq.push((node){v,dis[v]});
			}
		}
	}
}
db X(int x){return x;}
db Y(int x){return dis[x]+x*x;}
db xl(int i,int j){return (Y(i)-Y(j))/(X(i)-X(j));}
void dp()
{
	int l=1,r=0;
	q[++r]=1;
	for(int i=2;i<=n;i++)
	{
		while(l<r&&xl(q[l],q[l+1])<2*i)l++;
		f[i]=min(dis[i],dis[q[l]]+(i-q[l])*(i-q[l]));
		while(l<r&&xl(q[r-1],q[r])>xl(q[r],i))r--;
		q[++r]=i;
	}
	l=1,r=0;
	q[++r]=1;
	reverse(f+1,f+1+n);reverse(dis+1,dis+1+n);
	for(int i=2;i<=n;i++)
	{
		while(l<r&&xl(q[l],q[l+1])<2*i)l++;
		f[i]=min(f[i],dis[q[l]]+(i-q[l])*(i-q[l]));
		while(l<r&&xl(q[r-1],q[r])>xl(q[r],i))r--;
		q[++r]=i;
	}
	reverse(f+1,f+1+n);reverse(dis+1,dis+1+n);
	int siz=ed[0].size();
	for(int i=0;i<siz;i++)ed[0][i].val=f[i+1];
}
void wk()
{
	n=rid();m=rid();k=rid();
	for(int i=1;i<=m;i++)
	{
		int u=rid(),v=rid(),z=rid();
		ed[u].push_back((node){v,z});
		ed[v].push_back((node){u,z});
	}
	ed[0].push_back((node){1,0});
	for(int i=2;i<=n;i++)ed[0].push_back((node){i,inf});
	for(int i=1;i<=k;i++){dij();dp();}
	dij();
	for(int i=1;i<=n;i++)printf("%lld ",dis[i]);
}
signed main()
{
	wk();
	return 0;
}
////
