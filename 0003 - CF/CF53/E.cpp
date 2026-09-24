#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=(1<<12);
int cnt[maxn],n,m,k,dp[maxn][maxn];
vector<int> ed[15];
void init()
{
	for(int i=1;i<maxn;i++)
		for(int k=0;k<=15;k++)
			if(i&(1<<k))cnt[i]++;
}
signed main()
{
	init();
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int x,y;scanf("%lld%lld",&x,&y);x--;y--;
		ed[x].push_back(y);ed[y].push_back(x);
	}
	for(int i=1;i<=(1<<n)-1;i<<=1)dp[i][i]=1;
	for(int i=1;i<(1<<n);i++)
	{
		for(int j=i;j;--j&=i)
		{
			if(dp[i][j])
			{
				for(int u=0;u<n;u++)
				{
					if(i&(1<<u))
					{
						for(int k=0;k<ed[u].size();k++)
						{
							int v=ed[u][k],now;
							if(~i&(1<<v))
							{
								if(cnt[i]==1)now=i|(1<<v);
								else now=j&~(1<<u)|(1<<v);
								if(!(now>>v+1))dp[i|(1<<v)][now]+=dp[i][j];
							}
						}
					}
				}
			}
		}
	}
	int ans=0;
	for(int i=1;i<(1<<n);i++)
	{
		if(cnt[i]==k)ans+=dp[(1<<n)-1][i];
	}
	printf("%lld",ans);
	return 0;
}
