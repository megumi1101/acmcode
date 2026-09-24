#include<bits/stdc++.h>
using namespace std;
#define int long long
int inline rd()
{
	char ch=getchar();
	int ans=0,f=1;
	while(!isdigit(ch))
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		ans=ans*10+ch-'0';
		ch=getchar();
	}
	return ans*f;
}
void op()
{
	freopen("three.in","r",stdin);
	freopen("three.out","w",stdout);
}
const int N=5e3+10;
int n,cnt[N],f[N][5],ans;
vector<int>ed[N];
void dfs(int u,int fa,int deep)
{
	cnt[deep]++;
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i];
		if(v==fa)continue;
		dfs(v,u,deep+1);
	}
}
signed main()
{	
	//op();
		n=rd();
		if(n==0){return 0;}
		for(int i=1;i<n;i++)
		{
			int x,y;x=rd(),y=rd();
			ed[x].push_back(y);
			ed[y].push_back(x);
		}
		for(int u=1;u<=n;u++)
		{
			memset(f,0,sizeof(f));
			for(int j=1;j<=n;j++)f[j][0]=1;
			for(int i=0;i<ed[u].size();i++)
			{
				memset(cnt,0,sizeof(cnt));
				int v=ed[u][i];
				dfs(v,u,1);
				for(int k=3;k>=1;k--)
					for(int j=1;cnt[j];j++)
						f[j][k]+=f[j][k-1]*cnt[j];
			}
			for(int j=1;f[j][3];j++)ans+=f[j][3];
		}
		printf("%lld\n",ans);ans=0;
		for(int i=1;i<=n;i++)ed[i].clear();
	return 0;
}