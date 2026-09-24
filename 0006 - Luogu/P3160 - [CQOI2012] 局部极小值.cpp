#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=12345678;
int n,m;
bool us[10][10],vis[10][10];
int dp[30][1<<9],num[1<<9],ans=0;
int fx[10][2]={{0,0},{1,1},{1,0},{1,-1},{0,1},{0,-1},{-1,1},{-1,0},{-1,-1}};
struct node
{
	int x,y;
}tmp[15];
bool pd(int x,int y)
{
	if(x>=1&&x<=n&&y>=1&&y<=m)return 1;
	return 0;
}
int gp()
{
	int cnt=0;
	memset(dp,0,sizeof(dp));memset(us,0,sizeof(us));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(vis[i][j])us[i][j]=1,tmp[++cnt]=(node){i,j};
		}
	}
	for(int i=0;i<(1<<cnt);i++)
	{
		int tot=0;memset(us,0,sizeof(us));
		for(int j=1;j<=cnt;j++)
		{
			if(!((1<<(j-1))&i))
			{
				if(!us[tmp[j].x][tmp[j].y])
				{
					tot++;
					us[tmp[j].x][tmp[j].y]=1;
				}
				for(int k=1;k<=8;k++)
				{
					int x=tmp[j].x+fx[k][0];
					int y=tmp[j].y+fx[k][1];
					if(pd(x,y)&&!us[x][y])
					{
						us[x][y]=1;tot++;
					}
				}
			}
		}
		num[i]=n*m-tot;
	}
	dp[0][0]=1;
	for(int i=1;i<=n*m;i++)
	{
		for(int j=0;j<(1<<cnt);j++)
		{
			dp[i][j]+=dp[i-1][j]*max(num[j]-i+1,(long long)0)%mod;
			dp[i][j]%=mod;
			for(int k=1;k<=cnt;k++)
			{
				if(!((1<<(k-1))&j))
				{
					dp[i][j|(1<<(k-1))]+=dp[i-1][j];
					dp[i][j|(1<<(k-1))]%=mod;
				}
			}
		}
	}
	return dp[n*m][(1<<cnt)-1];
}
void dfs(int x,int y,int op)
{
    if(x==n+1)
    {
        if(op%2)ans-=gp(),ans+=mod,ans%=mod;
        else ans+=gp(),ans%=mod;
        return;
    }
    if(y==m+1)
    {
        dfs(x+1,1,op);
        return;
    }
    dfs(x,y+1,op);
    if(!vis[x][y])
    {
        bool flag=0;
        for(int i=1;i<=8;i++)
        {
            int xx=x+fx[i][0];
            int yy=y+fx[i][1];
            if(vis[xx][yy])
            {
                flag=1;
                break;
            }
        }
        if(!flag)
        {
            vis[x][y]=1;
            dfs(x,y+1,op+1);
            vis[x][y]=0;
            return;
        }
    }
}
signed main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		char ch[10];
		scanf("%s",ch);
		for(int j=1;j<=m;j++)
		{
			vis[i][j]=(ch[j-1]=='X')?1:0;
		}
	}
	dfs(1,1,0);
	ans%=mod;ans+=mod;ans%=mod;
	printf("%lld\n",ans);
	return 0;
}
/*
3 2
X.
..
.X
*/