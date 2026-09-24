#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
const int maxm=1e6+10;
vector<int>ed[maxm],ed2[maxm];
int n,m,cnt,tmp,ans,pos,a[maxn],ds[maxn],dt[maxn],rd[maxn];
queue<int> qq;
struct Queue{
	priority_queue<int>a,b;
	void push(int x){a.push(x);}
	void pop(int x){b.push(x);}
	int top(){while(!b.empty()&&a.top()==b.top())a.pop(),b.pop();return a.top();}
}q;
int main()
{
	scanf("%d%d",&n,&m);int u,v;
	for(int i=1;i<=m;i++)scanf("%d%d",&u,&v),ed[u].push_back(v),ed2[v].push_back(u),++rd[v];
	for(int i=1;i<=n;i++)if(!rd[i])qq.push(i);
	while(!qq.empty())
	{
		u=qq.front();qq.pop();a[++cnt]=u;
		for(int i=0;i<ed[u].size();i++)if(--rd[v=ed[u][i]]==0)qq.push(v);
	}
	for(int i=1;i<=n;i++)
	{
		u=a[i];for(int i=0;i<ed[u].size();i++)v=ed[u][i],dt[v]=max(dt[u]+1,dt[v]);
	}
	for(int i=n;i;i--)
	{
		u=a[i];for(int i=0;i<ed2[u].size();i++)v=ed2[u][i],ds[v]=max(ds[u]+1,ds[v]);
	}
	for(int i=1;i<=n;i++)q.push(ds[i]);
	ans=1e9;
	for(int k=1;k<=n;k++)
	{
		u=a[k],q.pop(ds[u]);
		for(int i=0;i<ed2[u].size();i++)v=ed2[u][i],q.pop(dt[v]+ds[u]+1);
		tmp=q.top();
		if(tmp<ans)ans=tmp,pos=u;
		else if(tmp==ans)pos=min(pos,u);
		for(int i=0;i<ed[u].size();i++)v=ed[u][i],q.push(dt[u]+ds[v]+1);
		q.push(dt[u]);
	}
	printf("%d %d\n",pos,ans);
	return 0;
}