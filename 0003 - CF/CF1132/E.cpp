#include<bits/stdc++.h>
#define int long long
using namespace std;
int cnt[10];
int f[10][8400],ans;
signed main()
{
	int w;
	scanf("%lld",&w);
	for(int i=1;i<=8;i++)
	{
		scanf("%lld",&cnt[i]);
	}
	memset(f,-1,sizeof(f));
	f[1][0]=0;
	for(int i=1;i<=8;i++)
	{
		for(int j=0;j<=8*840;j++)
		{
			if(f[i][j]==-1)continue;
			int gs=840/i;
			if(cnt[i]<gs)gs=cnt[i];
			for(int k=0;k<=gs;k++)
			{
				f[i+1][j+i*k]=max(f[i+1][j+i*k],f[i][j]+(cnt[i]-k)/(840/i));			
			}
		}
	}
	for(int j=1;j<=8*840;j++)
	{
		if(j>w||f[9][j]==-1)continue;
		ans=max(ans,j+840*min(f[9][j],(w-j)/840));
	}
	printf("%lld",ans);
	return 0;
}
