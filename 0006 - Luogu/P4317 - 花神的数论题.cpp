#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=51,mod=1e7+7;
int dp[N][2][N][N];
int x[N],ans[N],n,cnt;
int fp(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1)res=res*a%mod;
		a=a*a%mod,b>>=1;
	}
	return res;
}
int dfs(int ws,int op,int tmp,int sum)
{
	if(!ws)return tmp==sum;
	if(~dp[ws][op][tmp][sum])return dp[ws][op][tmp][sum];
	int lim=op?x[ws]:1;
	int res=0;
	for(int i=0;i<=lim;i++)
		res+=dfs(ws-1,op&&i==lim,tmp+(i==1),sum);
	return dp[ws][op][tmp][sum]=res;
}
int sol()
{
	while(n)x[++cnt]=n&1,n>>=1;
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<=50;i++)ans[i]=dfs(cnt,1,0,i);
	int res=1;
	for(int i=1;i<=50;i++)res=res*fp(i,ans[i])%mod;
	return res;
}
signed main()
{
	scanf("%lld",&n);
	printf("%lld\n",sol());
	return 0;
}