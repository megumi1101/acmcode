#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+9;
int n,h,ans;
int dp[1001][31][31][31][2];
signed main()
{
	scanf("%lld%lld",&n,&h);
	dp[1][1][1][1][1]=4;
	if(h==1){puts("4");return 0;}
	for(int i=2;i<=n;i++)
		for(int a=1;a<=h;a++)
			for(int b=1;b<=h;b++)
				for(int c=1;c<=h;c++)
					for(int p=0;p<2;p++)
					{
						int j=min(a+1,h),k=min(b+1,h),l=min(c+1,h);
						(dp[i][j][k][l][p]+=dp[i-1][a][b][c][p])%=mod;
						int d=(p?1:h);
						(dp[i][d][k][l][a<h]+=dp[i-1][a][b][c][p])%=mod;
						(dp[i][j][d][l][b<h]+=dp[i-1][a][b][c][p])%=mod;
						(dp[i][j][k][d][c<h]+=dp[i-1][a][b][c][p])%=mod;
					}
	for(int i=1;i<=h;i++)
		for(int j=1;j<=h;j++)
			for(int k=1;k<=h;k++)
				for(int l=0;l<2;l++)
					if(l||i<h||j<h||k<h)
						(ans+=dp[n][i][j][k][l])%=mod;
	printf("%lld",ans);
	return 0;
}
