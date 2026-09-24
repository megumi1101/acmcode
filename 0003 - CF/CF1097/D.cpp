#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int dp[63][10005],ans=1;
int po(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1)res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
int inv(int x)
{
	return po(x,mod-2);
}
int sol(int x,int i,int j)
{
	if(i==0)
	{
		dp[i][j]=1;
		return 1;
	}
	if(j==0)
	{
		if(dp[i][j]==0)dp[i][j]=sol(x,i-1,j)*x%mod;
		return dp[i][j];
	}
	int res=0;
	for(int k=0;k<=i;k++)
	{
		if(dp[k][j-1]==0)dp[k][j-1]=sol(x,k,j-1);
		res+=dp[k][j-1];
		res%=mod;
	}
	res=res*inv(i+1)%mod;
	return res;
}
signed main()
{
	int n,cnt,K;
	scanf("%lld%lld",&n,&K);
	for(int i=2;i*i<=n;i++)
	{
		if(n%i!=0)continue;
		cnt=0;
		while(n%i==0)
		{
			cnt++;
			n/=i;
		}
		memset(dp,0,sizeof(dp));
		ans*=sol(i,cnt,K);
		ans%=mod;
	}
	memset(dp,0,sizeof(dp));
	if(n>1)ans*=sol(n,1,K),ans%=mod;
	printf("%lld",ans);
	return 0;
}
