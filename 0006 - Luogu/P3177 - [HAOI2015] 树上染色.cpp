#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e3+5;
int n,m,siz[maxn];
int f[maxn][maxn];
struct node
{
	int to,val;
};
inline int read(void)
{
	int s = 0, w = 1;
	char ch = getchar();
	for(; ch < '0' || ch > '9'; ch = getchar()) if(ch == '-') w = -1;
	for(; ch <= '9' && ch >= '0'; ch = getchar()) s = s * 10 + ch - '0';
	return s * w;
}
vector<node>ed[maxn];
void dfs(int u,int fa)
{
	siz[u]=1;
	f[u][0]=f[u][1]=0;
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i].to;
		int w=ed[u][i].val;
		if(v==fa)continue;
		dfs(v,u);
		siz[u]+=siz[v];
		for(int j=min(m,siz[u]);j>=0;j--)
		{	
			for(int k=0;k<=min(j,siz[v]);k++)
			{
				int tot=k*(m-k)+(siz[v]-k)*(n-m-siz[v]+k);
				tot*=w;
				if(f[u][j-k]==-1)continue;
				f[u][j]=max(f[u][j],f[u][j-k]+f[v][k]+tot);
			}
		}
	}
}
signed main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<n;i++)
	{
		int x,y,z;
		x=read(),y=read(),z=read();
		ed[x].push_back((node){y,z});
		ed[y].push_back((node){x,z});
	}
	memset(f,-1,sizeof(f));
	dfs(1,0);
	printf("%lld",f[1][m]);
	return 0;
}