#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=10000020;
int cnt=1;
int n,m,s,t;
int head[maxn],nex[maxn],to[maxn],dep[maxn];
ll w[maxn];
ll ans;
queue<int> q;
void add(int x,int y,ll val)
{
	to[++cnt]=y;
	w[cnt]=val;
	nex[cnt]=head[x];
	head[x]=cnt;
}
bool bfs()
{
	memset(dep,0,sizeof(dep));
	while(!q.empty())
	{
		q.pop();
	}
	q.push(s);
	dep[s]=1;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=head[u];~i;i=nex[i])
		{
			int v=to[i];
			if(w[i]&&!dep[v])
			{
				dep[v]=dep[u]+1;
				q.push(v);
			}
		}
	}
	return dep[t];
}
ll dfs(int u,ll in)
{
	if(u==t)
	{
		return in;
	}
	ll out=0;
	for(int i=head[u];~i&&out<in;i=nex[i])
	{
		int v=to[i];
		if(w[i]&&dep[v]==dep[u]+1)
		{
			ll res=dfs(v,min(in,w[i]));
			if(!res)
			{
				dep[v]=0;
				continue;
			}
			w[i]-=res;
			w[i^1]+=res;
			in-=res;
			out+=res;
		}
	}
	return out;
}
int get(int i,int j)
{
	return (i-1)*m+j;
}
int main()
{
	scanf("%d%d",&n,&m);
	ll x;
	s=1;t=n*m;
	memset(head,-1,sizeof(head));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<m;j++)
		{
			scanf("%lld",&x);
			add(get(i,j),get(i,j+1),x);
			add(get(i,j+1),get(i,j),x);
		}
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%lld",&x);
			add(get(i,j),get(i+1,j),x);
			add(get(i+1,j),get(i,j),x);
		}
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<m;j++)
		{
			scanf("%lld",&x);
			add(get(i,j),get(i+1,j+1),x);
			add(get(i+1,j+1),get(i,j),x);
		}
	}
	while(bfs())
	{
		ans+=dfs(s,1e18);
	}
	printf("%lld",ans);
	return 0;
}