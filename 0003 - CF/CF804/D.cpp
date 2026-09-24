#include <bits/stdc++.h>
#define int long long
using namespace std;
 
int n,m,q,u,v,cnt=0,len=0,maxv=0;
int head[100005],size[100005],depth[100005],father[100005];
int pos[100005],up[100005],bestson[100005],dia[100005],top[100005];
 
vector<int> ve[100005];
vector<int> pre[100005];
map<pair<int,int>,double> ma;
 
struct edge
{
	int next;
	int to;
}e[200005];
 
struct node
{
	int u,v;
}a[100005];
 
inline void add_edge(int u,int v)
{
	cnt++;
	e[cnt].to=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}
 
inline int find(int x)
{
	if (x!=father[x])  father[x]=find(father[x]);
	return father[x];
}
 
inline void dfs(int now,int fath,int nowdis)
{
	up[now]=fath;
	size[now]=1;
	depth[now]=depth[fath]+1;
	
	int Maxv=0;
	if (nowdis>=maxv)  maxv=nowdis,u=now;
	for (int i=head[now];i;i=e[i].next)
	{
		if (e[i].to!=fath)
		{
			dfs(e[i].to,now,nowdis+1);
			size[now]+=size[e[i].to];
			if (size[e[i].to]>Maxv)  Maxv=size[e[i].to],bestson[now]=e[i].to;
		}
	}
}
 
inline void dfs1(int now,int fath,int nowtop)
{
	top[now]=nowtop;
	if (bestson[now])  dfs1(bestson[now],now,nowtop);
	for (int i=head[now];i;i=e[i].next)
	{
		if (e[i].to!=fath&&e[i].to!=bestson[now])  dfs1(e[i].to,now,e[i].to);
	}
}
 
inline void dfs2(int now,int fath,int nowdis)
{
	if (now==1)  return;
	if (nowdis>=maxv)  maxv=nowdis,v=now;
	for (int i=head[now];i;i=e[i].next)
	{
		if (e[i].to!=fath)  dfs2(e[i].to,now,nowdis+1);
	}
}
 
inline int LCA(int x,int y)
{
	while (top[x]!=top[y])
	{
		if (depth[top[x]]<depth[top[y]])  swap(x,y);
		x=up[top[x]];
	}
	if (depth[x]<depth[y])  return x;
	else return y;
}
//xxqzakioi wwyakioi
inline int dis(int x,int y)
{
	int tmp=LCA(x,y);
	return depth[x]-depth[tmp]+depth[y]-depth[tmp];
}
 
inline void dfs3(int now,int fath)
{
	ve[len].push_back(max(dis(now,u),dis(now,v)));
	for (int i=head[now];i;i=e[i].next)
	{
		if (e[i].to!=fath)  dfs3(e[i].to,now);
	}
}
 
signed main()
{
	cin>>n>>m>>q;
	for (int i=1;i<=n+1;i++)  father[i]=i;
	for (int i=1;i<=m;i++)
	{
		cin>>u>>v;
		u++,v++;
		if (u>v)  swap(u,v);
		father[find(u)]=find(v);
		a[i].u=u,a[i].v=v;
		add_edge(u,v);
		add_edge(v,u);
	}
	for (int i=1;i<=n+1;i++)  father[i]=find(father[i]);
	for (int i=2;i<=n+1;i++)
	{
		if (i==father[i])  add_edge(1,i),add_edge(i,1);
	}
	for (int i=head[1];i;i=e[i].next)
	{
		len++;
		pos[e[i].to]=len;
		
		maxv=0;
		dfs(e[i].to,1,0);
		dfs1(e[i].to,1,e[i].to);
		maxv=0;
		dfs2(u,1,0);
		dfs3(e[i].to,1);
		dia[e[i].to]=dis(u,v);
		
		sort(ve[len].begin(),ve[len].end());
		pre[len].push_back(ve[len][0]);
		for (int j=1;j<ve[len].size();j++)  pre[len].push_back(pre[len][j-1]+ve[len][j]);
	}
	while (q--)
	{
		cin>>u>>v;
		u++,v++;
		u=find(u),v=find(v);
		if (u==v)
		{
			cout<<-1<<endl;
			continue;
		}
		if (ve[pos[u]]>ve[pos[v]])  swap(u,v);
		if (ma[make_pair(u,v)])
		{
			cout<<ma[make_pair(u,v)]<<endl;
			continue;
		}
		int j=ve[pos[v]].size()-1,k=max(dia[u],dia[v]),ans=0,tmp;
		int posu=pos[u],posv=pos[v];
		int sizeu=ve[posu].size(),sizev=ve[posv].size();
		double tot;
		for (int i=0;i<sizeu;i++)
		{
			while (j>=1)
			{
				if (ve[pos[u]][i]+ve[pos[v]][j]+1<=k)  break;
				else j--;
			}
			if (j==0)  tmp=pre[posv][sizev-1];
			else tmp=pre[posv][sizev-1]-pre[posv][j-1];
			ans=ans+j*k+tmp+ve[posu][i]*(sizev-j)+(sizev-j);
		}
		tot=(double(ans))/(double(sizeu*sizev));
		ma[make_pair(u,v)]=tot;
		cout<<fixed<<setprecision(10)<<tot<<endl;
	}
	return 0;
}
