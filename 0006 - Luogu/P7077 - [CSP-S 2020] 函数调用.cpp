#include<bits/stdc++.h>
using namespace std;
#define int long long
int inline rd()
{
	int ans=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){ans=ans*10+ch-'0';ch=getchar();}
	return ans*f;
}
const int N=100005,mod=998244353;
int n,m,Q;
vector<int> ed1[N],ed2[N];
int cnt[N];
int a[N],tp[N],mul[N],add[N],pos[N];
int rd1[N];
void topo1()
{
	queue<int> q;
	for(int i=0;i<=m;++i)
	{
		rd1[i]=ed2[i].size();
		if(rd1[i]==0)q.push(i);
	}
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=0;i!=ed1[u].size();++i)
		{
			int v=ed1[u][i];
			mul[v]=mul[v]*mul[u]%mod;
			--rd1[v];
			if(rd1[v]==0)q.push(v);
		}
	}
}
int rd2[N];
void topo2()
{
	queue<int> q;
	for(int i=0;i<=m;++i)
	{
		rd2[i]=ed1[i].size();
		if(rd2[i]==0)q.push(i);
	}
	while(!q.empty())
	{
		int u=q.front();
		int now_mul=1;
		q.pop();
		for(int i=ed2[u].size();i!=0;--i)
		{
			int v=ed2[u][i-1];
			cnt[v]=(cnt[v]+cnt[u]*now_mul)%mod;
			now_mul=now_mul*mul[v]%mod;
			--rd2[v];
			if(rd2[v]==0)q.push(v);
		}
	}
}
signed main()
{
	n=rd();
	for(int i=1;i<=n;++i)a[i]=rd();
	m=rd();mul[0]=1;
	for(int i=1;i<=m;++i)
	{
		tp[i]=rd();
		if(tp[i]==1)
		{
			pos[i]=rd(),add[i]=rd();
			mul[i]=1;
		}
		if(tp[i]==2)
			mul[i]=rd();
		if(tp[i]==3)
		{
			mul[i]=1;int len;len=rd();
			for(int j=0;j<len;++j)
			{
				int v;v=rd();
				ed1[v].push_back(i);
				ed2[i].push_back(v);
			}
		}
	}
	Q=rd();cnt[0]=1;
	for(int i=0;i<Q;++i)
	{
		int x;x=rd();
		ed2[0].push_back(x);
		ed1[x].push_back(0);
	}
	topo1();topo2();
	for(int i=1;i<=n;++i)a[i]=a[i]*mul[0]%mod;
	for(int i=1;i<=m;++i)
		if(tp[i]==1){a[pos[i]]=(a[pos[i]]+cnt[i]*add[i])%mod;}
	for(int i=1;i<=n;++i)
		printf("%d ",a[i]);
}