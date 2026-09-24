#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int dp[2][1<<15][3],g[20][2],ans[20],siz[32768];
char xx[20];
int n,k;
int zh1()
{
	int s=0;
	for(int i=1;i<=k;i++)
		if(g[i][1]-g[i-1][1])s+=(1<<(i-1));
	return s;
}
void zh2(int s)
{
	for(int i=1;i<=k;i++)g[i][0]=(s>>(i-1))&1;
	for(int i=1;i<=k;i++)g[i][0]+=g[i-1][0];
}
void sol(int to,int s,int opt,char c,int w)
{
	zh2(s);
	for(int i=1;i<=k;i++)
		g[i][1]=max(g[i-1][1],max(g[i][0],g[i-1][0]+(c==xx[i])));
	int j=zh1();
	dp[to][j][opt]+=w;dp[to][j][opt]%=mod;
}
int main()
{
	scanf("%d%d",&n,&k);
	scanf("%s",xx+1);
	for(int i=1;i<(1<<k);i++)
	{
		siz[i]+=siz[i>>1]+(i&1);
	}
	dp[0][0][0]=1;
	for(int i=0;i<n;i++)
	{
		int u=i&1;int v=u^1;
		memset(dp[v],0,sizeof(dp[v]));
		for(int j=0;j<(1<<k);j++)
		{
			if(dp[u][j][0])
			{
				sol(v,j,1,'N',dp[u][j][0]);
				sol(v,j,0,'O',dp[u][j][0]);
				sol(v,j,0,'I',dp[u][j][0]);
			}
			if(dp[u][j][1])
			{
				sol(v,j,1,'N',dp[u][j][1]);
				sol(v,j,2,'O',dp[u][j][1]);
				sol(v,j,0,'I',dp[u][j][1]);
			}
			if(dp[u][j][2])
			{
				sol(v,j,1,'N',dp[u][j][2]);
				sol(v,j,0,'O',dp[u][j][2]);
			}
		}
	}
	for(int i=0;i<(1<<k);i++)
	{
		for(int j=0;j<=2;j++)
		{
			ans[siz[i]]=(ans[siz[i]]+dp[n&1][i][j])%mod;
		}
	}   
	for(int i=0;i<=k;i++)printf("%d\n",ans[i]);
	return 0;
}