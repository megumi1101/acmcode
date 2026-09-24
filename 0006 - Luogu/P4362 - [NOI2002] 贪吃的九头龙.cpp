#include<bits/stdc++.h>
using namespace std;
const int maxn=305;
int n,m,K;
int f[maxn][maxn][2],tmp[maxn][2];
struct node
{
	int to,val;
};
vector<node>ed[maxn<<1];
void dfs(int u,int fa)
{
	f[u][0][0]=f[u][1][1]=0;
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i].to;
		int w=ed[u][i].val;
		if(v==fa)continue;
		dfs(v,u);
		memset(tmp,0x3f,sizeof(tmp));
		for(int j=0;j<=K;j++)
		{
			for(int k=0;k<=j;k++)
			{
				tmp[j][0]=min(tmp[j][0],min(f[v][k][0]+f[u][j-k][0]+(m==2)*w,f[v][k][1]+f[u][j-k][0]));
				tmp[j][1]=min(tmp[j][1],min(f[v][k][1]+f[u][j-k][1]+w,f[v][k][0]+f[u][j-k][1]));
			}
		}
		for(int j=0;j<=K;j++)
		{
			f[u][j][0]=tmp[j][0];
			f[u][j][1]=tmp[j][1];
		}
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&K);
	if(n-K<m-1)
	{
		printf("-1");
		return 0;
	}
	for(int i=1;i<n;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		ed[x].push_back((node){y,z});
		ed[y].push_back((node){x,z});
	}
	memset(f,0x3f,sizeof(f));
	dfs(1,0);
	printf("%d",f[1][K][1]);
	return 0;
}