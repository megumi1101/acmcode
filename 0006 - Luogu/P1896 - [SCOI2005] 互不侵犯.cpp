#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,kk,cnt;
int s[600],gs[600];
int f[10][600][30];
void dfs(int x,int sum,int ws)
{
	if(ws>=n)
	{
		s[++cnt]=x;
		gs[cnt]=sum;
		return;
	}
	dfs(x,sum,ws+1);
	dfs(x+(1<<ws),sum+1,ws+2);
}
signed main()
{
	scanf("%lld%lld",&n,&kk);
	dfs(0,0,0);
	for(int i=1;i<=cnt;i++)
	{
		f[1][i][gs[i]]=1;
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=cnt;j++)
		{
			for(int k=1;k<=cnt;k++)
			{
				if(s[j]&s[k])continue;
				if((s[j]>>1)&s[k])continue;
				if((s[k]>>1)&s[j])continue;
				for(int num=kk;num>=gs[j];num--)
				{
					f[i][j][num]+=f[i-1][k][num-gs[j]];
				}
			}
		}
	}
	int ans=0;
	for(int i=1;i<=cnt;i++)
	{
		ans+=f[n][i][kk];
	}
	printf("%lld",ans);
	return 0;
}