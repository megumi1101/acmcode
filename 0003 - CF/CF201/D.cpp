#include<bits/stdc++.h>
using namespace std;

map<string,int>id;
const int maxn=5e5+10,inf=0x3f3f3f3f;
int n,m,s;
int a[maxn];
int mn[maxn][17];
int grt[1<<15][17];
int dp[300][1<<15];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		string x;cin>>x;id[x]=i;
	}
	scanf("%d",&m);
	int mx=-1,mxid;
	for(int pp=1;pp<=m;pp++)
	{
		scanf("%d",&s);
		for(int i=1;i<=s;i++)
		{
			string x;
			cin>>x;
			if(id.find(x)!=id.end())a[i]=id[x];
			else a[i]=0;
		}
		for(int j=1;j<=n;j++)mn[s+1][j]=inf;
		for(int i=s;i;i--)
		{
			for(int j=1;j<=n;j++)mn[i][j]=mn[i+1][j];
			mn[i][a[i]]=i;
		}
		memset(grt,-1,sizeof(grt));
		memset(dp,0x3f,sizeof(dp));
		dp[0][0]=0;
		for(int i=0;i<=n*(n-1)/2;i++)
		for(int j=0;j<1<<n;j++)
		{
			for(int k=1;k<=n;k++)
			if(j&1<<k-1)
			{
				if(grt[j][k]==-1)
				{
					grt[j][k]=0;
					for(int o=k+1;o<=n;o++)if(j&1<<o-1)grt[j][k]++;
				}
				if(i>=grt[j][k]&&dp[i-grt[j][k]][j^1<<k-1]<inf)
					dp[i][j]=min(dp[i][j],mn[dp[i-grt[j][k]][j^1<<k-1]+1][k]);
			}
		}
		for(int i=0;i<=n*(n-1)/2;i++)
			if(dp[i][(1<<n)-1]<inf)
				if(n*(n-1)/2-i+1>mx)mx=n*(n-1)/2-i+1,mxid=pp;;
	}
	if(mx==-1)puts("Brand new problem!");
	else
	{
		printf("%d\n",mxid);printf("[:");
		while(mx--)printf("|");
		printf(":]");
	}
	return 0;
}
