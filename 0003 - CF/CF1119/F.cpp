// LUOGU_RID: 90382080
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e5+10;
struct node
{
	int fi,se;
};
vector<node>ed[N];
int rd[N],vis[N],f[N][2],n,X;
vector<int>del,tmp;
node xx[N];
bool cmp(node x ,node y){return rd[x.fi]>rd[y.fi];}
bool cmp2(node x,node y){return x.fi<y.fi;}
struct heap
{
	int sz;int sum;
	priority_queue<int>a,b;
	void push(int x){a.push(x);++sz;sum+=x;}
	void erase(int x){b.push(x);--sz;sum-=x;}
	void pre(){while(!a.empty()&&!b.empty()&&a.top()==b.top()){ a.pop();b.pop();}}
	int top(){pre();return a.top();}
	void pop(){pre();--sz;sum-=a.top();a.pop();}
	int size(){return sz;}
}h[N];
void die(int u)
{
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i].fi,w=ed[u][i].se;
		if(rd[v]<=X)break;
		h[v].push(w);
	}
}
void dfs(int u,int fa)
{
	vis[u]=X;
	int num=rd[u]-X;
	int res=0;
	for(;h[u].size()>num;h[u].pop());
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i].fi,w=ed[u][i].se;
		if(rd[v]<=X)break;
		if(v==fa)continue;
		dfs(v,u);
	}
	tmp.clear(),del.clear();
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i].fi,w=ed[u][i].se;
		if(v==fa)continue;
		if(rd[v]<=X)break;
		int x=f[v][1]+w-f[v][0];
		if(x<=0){--num;res+=f[v][1]+w;continue;}
		res+=f[v][0];h[u].push(x);del.push_back(x);
	}
	for(;h[u].size()&&h[u].size()>num;h[u].pop())tmp.push_back(h[u].top());
	f[u][0]=res+h[u].sum;
	for(;h[u].size()&&h[u].size()>num-1;h[u].pop())tmp.push_back(h[u].top());
	f[u][1]=res+h[u].sum;
	for(int i=0;i<tmp.size();i++)h[u].push(tmp[i]);
	for(int i=0;i<del.size();i++)h[u].erase(del[i]);
}
signed main()
{
	scanf("%lld",&n);int sum=0;
	for(int i=1;i<n;++i)
	{
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		ed[u].push_back((node){v,w});
		ed[v].push_back((node){u,w});
		rd[u]++;rd[v]++;sum+=w;
	}
	printf("%lld ",sum);
	for(int i=1;i<=n;++i)
		xx[i]=(node){rd[i],i},sort(ed[i].begin(),ed[i].end(),cmp);
	sort(xx+1,xx+n+1,cmp2);
	int ct=1;
	for(X=1;X<n;++X)
	{
		while(ct<=n&&xx[ct].fi==X)die(xx[ct].se),++ct;
		int ans=0;
		for(int j=ct;j<=n;++j)
		{
			int v=xx[j].se;
			if(vis[v]==X)continue;
			dfs(v,0),ans+=f[v][0];
		}
		printf("%lld ",ans);
	}
	return 0;
}
